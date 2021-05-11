/*
* Vulkan hardware capability viewer
*
* THIS HEADER IS AUTO-GENERATED, DO NOT CHANGE
* See https://github.com/SaschaWillems/VulkanCapsViewerGenerator for the generator
*
* Copyright (C) by Sascha Willems (www.saschawillems.de)
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
*/

#include "VulkanDeviceInfoExtensions.h"

bool VulkanDeviceInfoExtensions::extensionSupported(const char* extensionName)
{
    for (auto& ext : extensions) {
        if (strcmp(ext.extensionName, extensionName) == 0) {
            return true;
        }
    }
    return false;
}

VkPhysicalDeviceProperties2 VulkanDeviceInfoExtensions::initDeviceProperties2(void * pNext) {
    VkPhysicalDeviceProperties2 props2{};
    props2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
    props2.pNext = pNext;
    return props2;
}

{{implementation_properties2_functions}}

void VulkanDeviceInfoExtensions::readExtendedProperties() {
{{implementation_properties_function_calls}}
}

VkPhysicalDeviceFeatures2 VulkanDeviceInfoExtensions::initDeviceFeatures2(void *pNext) {
    VkPhysicalDeviceFeatures2 features2{};
    features2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
    features2.pNext = pNext;
    return features2;
}

void VulkanDeviceInfoExtensions::pushFeature2(const char* extension, std::string name, bool supported) {
    features2.push_back(Feature2(name, supported, extension));
}

{{implementation_features2_functions}}

void VulkanDeviceInfoExtensions::readExtendedFeatures() {
{{implementation_features_function_calls}}
}
