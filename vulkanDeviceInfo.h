/*
*
* Vulkan hardware capability viewer
*
* Device information class
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
#include "VulkanContext.h"
#include "profiles/vulkan_profiles.hpp"

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

struct VulkanProfileInfo
{
    std::string profileName;
    uint32_t specVersion;
    bool supported = false;
};

class VulkanDeviceInfo: public VulkanDeviceInfoExtensions
{
private:
    std::vector<VulkanLayerInfo> layers;
    bool vulkanVersionSupported(uint32_t major, uint32_t minor);
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
    QVariantMap core13Features;
    bool hasSubgroupProperties = false;
    bool hasFeaturModifyingTool = false;
    QVariantMap subgroupProperties;
    QVariantMap core11Properties;
    QVariantMap core12Properties;
    QVariantMap core13Properties;
    std::vector<VulkanQueueFamilyInfo> queueFamilies;
    std::vector<VulkanFormatInfo> formats;
    VulkanSurfaceInfo surfaceInfo;
    std::vector<VulkanProfileInfo> profiles;
    OSInfo os;
    QString appVersion;
    QString reportVersion;
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
    void readSurfaceInfo();
    void readPlatformDetails();
    void readProfiles();
    QJsonObject toJson(QString submitter, QString comment);
};

#endif // VULKANDEVICEINFO_H
