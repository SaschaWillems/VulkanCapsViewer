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

#ifndef VULKANDEVICEINFOEXTENSIONS_H
#define VULKANDEVICEINFOEXTENSIONS_H

#include <vector>
#include <string>
#include <QVariant>

#include "vulkan/vulkan.h"
#include "VulkanContext.h"
#include "vulkanresources.h"

#ifdef __ANDROID__
#include <sys/system_properties.h>
#include "vulkanandroid.h"
#endif

struct Feature2 {
    std::string name;
    VkBool32 supported;
    const char* extension;
    Feature2(std::string n, VkBool32 supp, const char* ext) : name(n), supported(supp), extension(ext) {}
};

struct Property2 {
    std::string name;
    QVariant value;
    const char* extension;
    Property2(std::string n, QVariant val, const char* ext) : name(n), value(val), extension(ext) {}
};

class VulkanDeviceInfoExtensions
{
private:
    VkPhysicalDeviceFeatures2 initDeviceFeatures2(void *pNext);
    VkPhysicalDeviceProperties2 initDeviceProperties2(void * pNext);
    template<typename T>
    void pushProperty2(const char* extension, std::string name, T value) {
        properties2.push_back(Property2(name, QVariant(value), extension));
    };
    template<typename T>
    QVariantList arrayToQVariantList(T array, size_t size) {
        QVariantList res;
        for (size_t i = 0; i < size; i++) {
            res.push_back(QVariant(array[i]));            
        }
        return res;
    };
    void pushFeature2(const char* extension, std::string name, bool supported);
    bool extensionSupported(const char* extensionName);
{{header_functions}}
public:
    const uint32_t vkHeaderVersion = {{VK_HEADER_VERSION}};
    std::vector<Feature2> features2;
    std::vector<Property2> properties2;
    std::vector<VkExtensionProperties> extensions;
    VkPhysicalDevice device;
    void readExtendedFeatures();
    void readExtendedProperties();
};

#endif // VULKANDEVICEINFOEXTENSIONS_H
