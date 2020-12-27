/*
*
* Vulkan hardware capability viewer
*
* Device information class
*
* Copyright (C) 2016-2020 by Sascha Willems (www.saschawillems.de)
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
#include "VulkanDeviceInfoExtensions.h"
#include "vulkanpfn.h"

#ifdef __ANDROID__
#include <sys/system_properties.h>
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
#include <QX11Info>
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

class VulkanDeviceInfo: public VulkanDeviceInfoExtensions
{
private:
    std::vector<VulkanLayerInfo> layers;
    bool vulkan_1_1();
    bool vulkan_1_2();
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
    VkDevice dev = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties props;
    VkPhysicalDeviceMemoryProperties memoryProperties;
    VkPhysicalDeviceFeatures deviceFeatures;
    QVariantMap core11Features;
    QVariantMap core12Features;
    bool hasSubgroupProperties = false;
    QVariantMap subgroupProperties;
    QVariantMap core11Properties;
    QVariantMap core12Properties;
    std::vector<VulkanQueueFamilyInfo> queueFamilies;
    std::vector<VulkanFormatInfo> formats;
    VulkanSurfaceInfo surfaceInfo;
    OSInfo os;
    std::string appVersion;
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
    QJsonObject toJson(std::string submitter, std::string comment);
};

#endif // VULKANDEVICEINFO_H
