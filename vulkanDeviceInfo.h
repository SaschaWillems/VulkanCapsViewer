/*
*
* Vulkan hardware capability viewer
*
* Device information class
*
* Copyright (C) 2015 by Sascha Willems (www.saschawillems.de)
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

#ifndef VULKANDEVICEINFO_H
#define VULKANDEVICEINFO_H

#include <vector>
#include <assert.h>
#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <utility>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

#include "vulkan/vulkan.h"
#include "vulkanresources.h"
#include "vulkanLayerInfo.hpp"
#include "vulkanFormatInfo.hpp"
#include "vulkansurfaceinfo.hpp"
#include "vulkanpfn.h"

#ifdef __ANDROID__
#include <sys/system_properties.h>
#endif

#include "vulkanandroid.h"

struct OSInfo
{
    std::string name;
    std::string version;
    std::string architecture;
};

struct VulkanQueueFamilyInfo
{
    VkQueueFamilyProperties properties;
    VkBool32 supportsPresent;
};

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

class VulkanDeviceInfo
{
private:
    std::vector<VulkanLayerInfo> layers;
    QString toHexQString(VkDeviceSize deviceSize);
    VkPhysicalDeviceFeatures2 initDeviceFeatures2(void *pNext);
    VkPhysicalDeviceProperties2 initDeviceProperties2(void * pNext);
    template<typename T>
    void pushProperty2(const char* extension, std::string name, T value) {
        properties2.push_back(Property2(name, QVariant(value), extension));
    };
    void pushFeature2(const char* extension, std::string name, bool supported);
    void readPhysicalFeatures_KHR();
    void readPhysicalFeatures_EXT();
    void readPhysicalFeatures_NV();
    void readPhysicalProperties_KHR();
    void readPhysicalProperties_EXT();
    void readPhysicalProperties_AMD();
    void readPhysicalProperties_NV();
    bool vulkan_1_1();
    bool extensionSupported(const char* extensionName);
#if defined(__ANDROID__)
    std::string getSystemProperty(const char* propname);
#endif
public:
    uint32_t id;
    QVariantMap properties;
    QVariantMap sparseProperties;
    QVariantMap limits;
    QVariantMap features;
    std::map<std::string, std::string> platformdetails;
    std::vector<Feature2> features2;
    std::vector<Property2> properties2;
    VkPhysicalDevice device;
    VkDevice dev = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties props;
    VkPhysicalDeviceMemoryProperties memoryProperties;
    VkPhysicalDeviceFeatures deviceFeatures;
    bool hasSubgroupProperties = false;
    QVariantMap subgroupProperties;
    VkPhysicalDeviceProperties2KHR deviceProperties2;
    VkPhysicalDeviceFeatures2KHR deviceFeatures2;
    std::vector<VkExtensionProperties> extensions;
    std::vector<VulkanQueueFamilyInfo> queueFamilies;
    std::vector<VulkanFormatInfo> formats;
    VulkanSurfaceInfo surfaceInfo;
    OSInfo os;
    std::string reportVersion;
    std::vector<VulkanLayerInfo> getLayers();
    std::string getDriverVersion();
    void readExtensions();
    void readLayers();
    void readSupportedFormats();
    void readQueueFamilies();
    void readPhysicalProperties();
    void readPhysicalFeatures();
    void readPhysicalLimits();
    void readPhysicalMemoryProperties();
    void readSurfaceInfo(VkSurfaceKHR surface, std::string surfaceExtension);
    void readPlatformDetails();
    QJsonObject toJson(std::string fileName, std::string submitter, std::string comment);
};

#endif // VULKANDEVICEINFO_H
