<?php

/*
 *
 * Vulkan hardware capability viewer
 * 
 * Copyright (C) 2016-2022 by Sascha Willems (www.saschawillems.de)
 *
 * This code is free software, you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * Please review the following information to ensure the GNU Lesser
 * General Public License version 3 requirements will be met:
 * http://opensource.org/licenses/lgpl-3.0.html
 *
 * The code is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU LGPL 3.0 for more details.
 *
 */

 /*
  * Generator for creating the VulkanDeviceInfoExtensions.h/.cpp source files used by the caps viewer to fetch device extensions
  */

 class TypeContainer
{

    public $property_types;
    public $feature_types;
    public $aliases;

    private function getActualType($type, $xml)
    {
        if ($type['alias']) {
            foreach ($xml->types->type as $alias_type) {
                if ($alias_type['name'] && strcasecmp($alias_type['name'], $type['alias']) === 0) {
                    $this->aliases[(string)$type['name']] = $alias_type;
                    return $alias_type;
                }
            }
        }
        return $type;
    }

    function __construct($xml)
    {
        // We're only interested in types extending VkPhysicalDeviceProperties2 or VkPhysicalDeviceFeatures2
        foreach ($xml->types->type as $type) {
            $actual_type = $this->getActualType($type, $xml);
            if (($actual_type['structextends']) && (strcasecmp($actual_type['structextends'], 'VkPhysicalDeviceProperties2') === 0)) {
                $this->property_types[] = $actual_type;
            }
            if (($actual_type['structextends']) && (stripos($actual_type['structextends'], 'VkPhysicalDeviceFeatures2') !== false)) {
                $this->feature_types[] = $actual_type;
            }
        }
    }

    /**
     * Checks if the given type is aliased, and returns the type name to look for
     */
    private function getActualTypeName($type_name)
    {
        $actual_name = $type_name;
        if ($this->aliases[(string)$type_name]) {
            $actual_name = $this->aliases[(string)$type_name]['name'];
        }
        return $actual_name;
    }

    public function getProperties2Type($name)
    {
        $actual_name = $this->getActualTypeName($name);
        foreach ($this->property_types as $property_type) {
            if (strcasecmp($property_type['name'], $actual_name) === 0) {
                return $property_type;
            }
        }
        return null;
    }

    public function getFeatures2Type($name)
    {
        $actual_name = $this->getActualTypeName($name);
        foreach ($this->feature_types as $feature_type) {
            if (strcasecmp($feature_type['name'], $actual_name) === 0) {
                return $feature_type;
            }
        }
        return null;
    }

    public static function getsType($node)
    {
        foreach ($node->member as $member) {
            if ($member['values'] && (stripos((string)$member['values'], 'VK_STRUCTURE_TYPE_') !== false)) {
                return $node->member['values'];
            }
        }
    }
}

class Extension
{
    public $name;
    public $stype;
    public $group;
    public $features2;
    public $properties2;
}

class ExtensionContainer
{
    public $extensions = [];

    function __construct($xml, $typecontainer)
    {
        foreach ($xml->extensions->extension as $ext_node) {
            $features2_node = null;
            $properties2_node = null;
            // We're only interested in extensions with property or feature types                
            foreach ($ext_node->require as $require) {
                foreach ($require as $requirement) {
                    if (strcasecmp($requirement->getName, 'type')) {
                        $ft2 = $typecontainer->getFeatures2Type((string)$requirement['name']);
                        if (!$features2_node && $ft2) {
                            $features2_node = $ft2;
                        }
                        $prop2 = $typecontainer->getProperties2Type((string)$requirement['name']);
                        if (!$properties2_node && $prop2) {
                            $properties2_node = $prop2;
                        }
                    }
                }
            }
            if ($features2_node || $properties2_node) {
                $ext = new Extension();
                $ext->name = (string)$ext_node['name'];
                $ext->group = substr($ext->name, 3, strpos($ext->name, '_', 3) - 3);
                $ext->features2 = $features2_node;
                $ext->properties2 = $properties2_node;
                $this->extensions[] = $ext;
            }
        }
    }
}

class CppBuilder
{

    private $header_functions = [];
    private $vk_header_version = null;

    function __construct($vk_header_version)
    {
        $this->vk_header_version = $vk_header_version;
    }

    public function generateFeatures2CodeBlock($extension)
    {
        $sType = TypeContainer::getsType($extension->features2);
        $res = "\tif (extensionSupported(\"{$extension->name}\")) {\n";
        $res .= "\t\tconst char* extension(\"{$extension->name}\");\n";
        $res .= "\t\t{$extension->features2['name']} extFeatures { $sType };\n";
        $res .= "\t\tVkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));\n";
        $res .= "\t\tvulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);\n";
        foreach ($extension->features2->member as $member) {
            // Skip types that are not related to feature details
            $type = (string)$member->type;
            if (in_array($type, ['VkStructureType', 'void'])) {
                continue;
            }
            $name = (string)$member->name;
            $res .= "\t\tpushFeature2(extension, \"$name\", extFeatures.$name);\n";
        }
        $res .= "\t}\n";
        return $res;
    }

    public function generateProperties2CodeBlock($extension)
    {
        $sType = TypeContainer::getsType($extension->properties2);
        $res = "\tif (extensionSupported(\"{$extension->name}\")) {\n";
        $res .= "\t\tconst char* extension(\"{$extension->name}\");\n";
        $res .= "\t\t{$extension->properties2['name']} extProps { $sType };\n";
        $res .= "\t\tVkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));\n";
        $res .= "\t\tvulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);\n";
        // @todo: QVariant vs. QVariant::fromValue
        foreach ($extension->properties2->member as $member) {
            // Skip types that are not related to feature details
            $type = (string)$member->type;
            if (in_array($type, ['VkStructureType', 'void'])) {
                continue;
            }
            $name = (string)$member->name;
            $vktype = (string)$member->type;
            if ($type == "VkExtent2D") {
                $res .= "\t\tpushProperty2(extension, \"$name\", QVariant::fromValue(QVariantList({ extProps.$name.width, extProps.$name.height })));\n";
                continue;
            }
            if ($type == "size_t") {
                $res .= "\t\tpushProperty2(extension, \"$name\", QVariant::fromValue(extProps.$name));\n";
                continue;
            }
            // Properties can be arrays
            $dim = 0;
            if (!empty(trim((string)$member))) {
                $m = (string)$member;
                // Special case enum in dim
                if ($member->enum) {
                    // @todo: Take size from xml
                    $enum_dim = 0;
                    switch ((string)$member->enum) {
                        case 'VK_UUID_SIZE':
                        case 'VK_UUID_SIZE_KHR':
                            $enum_dim = 16;
                            break;
                        case 'VK_LUID_SIZE':
                        case 'VK_LUID_SIZE_HR':
                            $enum_dim = 8;
                            break;
                    }
                    if ($enum_dim > 0) {
                        $res .= "\t\tpushProperty2(extension, \"$name\", QVariant::fromValue(arrayToQVariantList(extProps.$name, $enum_dim)));\n";
                        continue;
                    }
                } else {
                    $dim = (int) filter_var($m, FILTER_SANITIZE_NUMBER_INT);
                }
            }
            if ($dim == 0) {
                switch ($vktype) {
                    case 'VkBool32':
                        $qtype = "QVariant(bool(extProps.$name))";
                        break;
                    case 'VkConformanceVersionKHR':
                        $qtype = "QString::fromStdString(vulkanResources::conformanceVersionKHRString(extProps.$name))";
                        break;
                    case 'VkDeviceSize':
                    case 'uint64_t':
                        $qtype = "QVariant::fromValue(extProps.$name)";
                        break;
                    default:
                        $qtype = "QVariant(extProps.$name)";
                }
                $res .= "\t\tpushProperty2(extension, \"$name\", $qtype);\n";
            } else {
                $vars = [];
                for ($i = 0; $i < $dim; $i++) {
                    $vars[] = "extProps." . $name . "[" . $i . "]";
                }
                $qlist = implode(', ', $vars);
                $res .= "\t\tpushProperty2(extension, \"$name\", QVariant::fromValue(QVariantList({ $qlist })));\n";
            }
        }
        $res .= "\t}\n";
        return $res;
    }

    public function addHeaderFunction(string $function_name)
    {
        $this->header_functions[] = $function_name;
    }

    public function writeHeader(string $file_name, string $output_dir)
    {
        if (!file_exists('templates/VulkanDeviceInfoExtensions.h')) {
            echo "Template $file_name does not exist!\n";
            return;
        }
        $header_source = file_get_contents('templates/VulkanDeviceInfoExtensions.h');
        $header_replace = '';
        foreach ($this->header_functions as $header_func) {
            $header_replace .= "    void $header_func();\n";
        }
        $header_source = str_replace('{{header_functions}}', $header_replace, $header_source);
        $header_source = str_replace('{{VK_HEADER_VERSION}}', $this->vk_header_version, $header_source);
        file_put_contents("$output_dir/VulkanDeviceInfoExtensions.h", $header_source);
    }

    public function writeImplementation(string $file_name, string $output_dir, $extension_container)
    {
        if (!file_exists('templates/VulkanDeviceInfoExtensions.cpp')) {
            echo "Template $file_name does not exist!\n";
            return;
        }
        $impl_source = file_get_contents('templates/VulkanDeviceInfoExtensions.cpp');

        $fn_calls = array_map(function ($fn) {
            return "    " . $fn . "();";
        }, $this->header_functions);

        $function_calls_features2 = array_filter($fn_calls, function ($fn) {
            return (stripos($fn, "readPhysicalFeatures_") !== false);
        });
        $impl_source = str_replace('{{implementation_features_function_calls}}', implode("\n", $function_calls_features2), $impl_source);

        $function_calls_properties2 = array_filter($fn_calls, function ($fn) {
            return (stripos($fn, "readPhysicalProperties_") !== false);
        });
        $impl_source = str_replace('{{implementation_properties_function_calls}}', implode("\n", $function_calls_properties2), $impl_source);

        // Get extension groups (ext, khr, nv, etc.)
        $ext_groups = [];
        foreach ($extension_container->extensions as $ext) {
            if (!in_array($ext->group, $ext_groups)) {
                $ext_groups[] = $ext->group;
            }
        }
        sort($ext_groups);

        $cpp_features_block = '';
        $cpp_properties_block = '';
        foreach ($ext_groups as $ext_group) {
            // Features2
            $ext_arr = array_filter($extension_container->extensions, function ($ext) use ($ext_group) {
                return ($ext->group == $ext_group && $ext->features2);
            });
            if (count($ext_arr) > 0) {
                $cpp_features_block .= "void VulkanDeviceInfoExtensions::readPhysicalFeatures_$ext_group() {\n";
                foreach ($ext_arr as $extension) {
                    $cpp_features_block .= $this->generateFeatures2CodeBlock($extension);
                }
                $cpp_features_block .= "}\n";
            }
            // Properties2
            $ext_arr = array_filter($extension_container->extensions, function ($ext) use ($ext_group) {
                return ($ext->group == $ext_group && $ext->properties2);
            });
            if (count($ext_arr) > 0) {
                $cpp_properties_block .= "void VulkanDeviceInfoExtensions::readPhysicalProperties_$ext_group() {\n";
                foreach ($ext_arr as $extension) {
                    $cpp_properties_block .= $this->generateProperties2CodeBlock($extension);
                }
                $cpp_properties_block .= "}\n";
            }
        }

        if (!empty($cpp_features_block)) {
            $impl_source = str_replace('{{implementation_features2_functions}}', $cpp_features_block, $impl_source);
        }
        if (!empty($cpp_properties_block)) {
            $impl_source = str_replace('{{implementation_properties2_functions}}', $cpp_properties_block, $impl_source);
        }

        file_put_contents("$output_dir/VulkanDeviceInfoExtensions.cpp", $impl_source);
    }
}

$xml = simplexml_load_file("..\\Vulkan-Headers\\registry\\vk.xml") or exit("Could not read vk.xml");
$header_version_node = $xml->xpath("./types/type/name[.='VK_HEADER_VERSION']/..");
$vk_header_version = filter_var($header_version_node[0], FILTER_SANITIZE_NUMBER_INT);

$output_dir = "..\\";
if (!is_dir($output_dir)) {
    mkdir($output_dir);
}
if (file_exists($output_dir."VulkanDeviceInfoExtensions.cpp")) {
    echo "Warning: Output files will be overwritten\n";
}

echo "Generating C++ files for header version $vk_header_version...\n";

$type_container = new TypeContainer($xml);
$extension_container = new ExtensionContainer($xml, $type_container);

// Get extension groups (ext, khr, nv, etc.)
$ext_groups = [];
foreach ($extension_container->extensions as $ext) {
    if (!in_array($ext->group, $ext_groups)) {
        $ext_groups[] = $ext->group;
    }
}
sort($ext_groups);

// Generate CPP Code
$cpp_builder = new CppBuilder($vk_header_version);
foreach ($ext_groups as $ext_group) {
    // Features2
    $ext_arr = array_filter($extension_container->extensions, function ($ext) use ($ext_group) {
        return ($ext->group == $ext_group && $ext->features2);
    });
    if (count($ext_arr) > 0) {
        $cpp_builder->addHeaderFunction("readPhysicalFeatures_$ext_group");
    }
    // Properties2
    $ext_arr = array_filter($extension_container->extensions, function ($ext) use ($ext_group) {
        return ($ext->group == $ext_group && $ext->properties2);
    });
    if (count($ext_arr) > 0) {
        $cpp_builder->addHeaderFunction("readPhysicalProperties_$ext_group");
    }
}
$cpp_builder->writeHeader("$output_dir/VulkanDeviceInfoExtensions.h", $output_dir);
$cpp_builder->writeImplementation("$output_dir/VulkanDeviceInfoExtensions.cpp", $output_dir, $extension_container);

// Output extension list for changelog
$extenstion_list_file = $output_dir . "/extensionlist.txt";
if (file_exists($extenstion_list_file)) {
    unlink($extenstion_list_file);
}
foreach ($ext_groups as $ext_group) {
    $ext_arr = array_filter($extension_container->extensions, function ($ext) use ($ext_group) {
        return ($ext->group == $ext_group && ($ext->features2 || $ext->properties2));
    });
    if (count($ext_arr) > 0) {
        file_put_contents($extenstion_list_file, "$ext_group\n", FILE_APPEND);
        foreach ($ext_arr as $ext) {
            file_put_contents($extenstion_list_file, "$ext->name\n", FILE_APPEND);
        }
    }
}

echo "C++ files written to $output_dir";