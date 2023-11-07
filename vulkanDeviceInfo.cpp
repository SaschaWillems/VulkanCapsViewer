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

#include "vulkanDeviceInfo.h"

std::vector<VulkanLayerInfo> VulkanDeviceInfo::getLayers()
{
    return layers;
}

void VulkanDeviceInfo::readExtensions()
{
    assert(device != NULL);
    qInfo() << "Reading extensions";
    VkResult vkRes;
    do {
        uint32_t extCount;
        vkRes = vkEnumerateDeviceExtensionProperties(device, NULL, &extCount, NULL);
        assert(!vkRes);
        std::vector<VkExtensionProperties> exts(extCount);
        vkRes = vkEnumerateDeviceExtensionProperties(device, NULL, &extCount, &exts.front());
        for (auto& ext : exts)
            extensions.push_back(ext);
    } while (vkRes == VK_INCOMPLETE);
    assert(!vkRes);
}

bool VulkanDeviceInfo::vulkanVersionSupported(uint32_t major, uint32_t minor)
{
    uint32_t deviceMajor = VK_API_VERSION_MAJOR(props.apiVersion);
    uint32_t deviceMinor = VK_API_VERSION_MINOR(props.apiVersion);
    return ((deviceMajor > major) || ((deviceMajor == major) && (deviceMinor >= minor)));
}

bool VulkanDeviceInfo::extensionSupported(const char* extensionName)
{
    for (auto& ext : extensions) {
        if (strcmp(ext.extensionName, extensionName) == 0) {
            return true;
        }
    }
    return false;
}

void VulkanDeviceInfo::readLayers()
{
    assert(device != NULL);
    qInfo() << "Reading layers";
    VkResult vkRes;
    do {
        uint32_t layerCount;
        vkRes = vkEnumerateDeviceLayerProperties(device, &layerCount, NULL);
        std::vector<VkLayerProperties> props(layerCount);
        if (layerCount > 0)
        {
            vkRes = vkEnumerateDeviceLayerProperties(device, &layerCount, &props.front());

        }
        for (auto& prop : props)
        {
            VulkanLayerInfo layerInfo;
            layerInfo.properties = prop;
            // Get Layer extensions
            VkResult vkRes;
            do {
                uint32_t extCount;
                vkRes = vkEnumerateDeviceExtensionProperties(device, prop.layerName, &extCount, NULL);
                assert(!vkRes);
                if (extCount > 0) {
                    std::vector<VkExtensionProperties> exts(extCount);
                    vkRes = vkEnumerateDeviceExtensionProperties(device, prop.layerName, &extCount, &exts.front());
                    for (auto& ext : exts)
                        layerInfo.extensions.push_back(ext);
                }
            } while (vkRes == VK_INCOMPLETE);
            assert(!vkRes);
            // Push to layer list
            layers.push_back(layerInfo);
        }
    } while (vkRes == VK_INCOMPLETE);
}

void VulkanDeviceInfo::readSupportedFormats()
{
    assert(device != NULL);
    qInfo() << "Reading formats";
    // Base formats
    int32_t firstFormat = VK_FORMAT_R4G4_UNORM_PACK8;
    int32_t lastFormat = VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
    for (int32_t format = firstFormat; format <= lastFormat; format++) {
        VulkanFormatInfo formatInfo = {};
        formatInfo.format = (VkFormat)format;
        vkGetPhysicalDeviceFormatProperties(device, formatInfo.format, &formatInfo.properties);
        formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
        formats.push_back(formatInfo);
    }
    // VK_KHR_sampler_ycbcr_conversion
    if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
        for (int32_t format = VK_FORMAT_G8B8G8R8_422_UNORM; format < VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM; format++) {
            VulkanFormatInfo formatInfo = {};
            formatInfo.format = (VkFormat)format;
            vkGetPhysicalDeviceFormatProperties(device, formatInfo.format, &formatInfo.properties);
            formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
            formats.push_back(formatInfo);
        }
    }
    // VK_IMG_FORMAT_PVRTC_EXTENSION_NAME
    if (extensionSupported(VK_IMG_FORMAT_PVRTC_EXTENSION_NAME)) {
        for (int32_t format = VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG; format < VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG; format++) {
            VulkanFormatInfo formatInfo = {};
            formatInfo.format = (VkFormat)format;
            vkGetPhysicalDeviceFormatProperties(device, formatInfo.format, &formatInfo.properties);
            formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
            formats.push_back(formatInfo);
        }
    }
}

void VulkanDeviceInfo::readQueueFamilies()
{
    assert(device != NULL);
    qInfo() << "Reading queue families";
    uint32_t queueFamilyCount;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
    assert(queueFamilyCount > 0);
    std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, &queueFamilyProperties.front());
    uint32_t index = 0;
    for (auto& queueFamilyProperty : queueFamilyProperties)
    {
        VulkanQueueFamilyInfo queueFamilyInfo{};
        queueFamilyInfo.properties = queueFamilyProperty;
        if ((vulkanContext.surface != VK_NULL_HANDLE) && (vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR)) {
            vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR(device, index, vulkanContext.surface, &queueFamilyInfo.supportsPresent);
        }
        queueFamilies.push_back(queueFamilyInfo);
        index++;
    }
}

std::string VulkanDeviceInfo::getDriverVersion()
{
    // NVIDIA
    if (props.vendorID == 4318)
    {
        // 10 bits = major version (up to r1023)
        // 8 bits = minor version (up to 255)
        // 8 bits = secondary branch version/build version (up to 255)
        // 6 bits = tertiary branch/build version (up to 63)

        uint32_t major = (props.driverVersion >> 22) & 0x3ff;
        uint32_t minor = (props.driverVersion >> 14) & 0x0ff;
        uint32_t secondaryBranch = (props.driverVersion >> 6) & 0x0ff;
        uint32_t tertiaryBranch = (props.driverVersion) & 0x003f;

        return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(secondaryBranch) + "." + std::to_string(tertiaryBranch);
    }
    else
    {
       // todo : Add mappings for other vendors
       return vulkanResources::versionToString(props.driverVersion);
    }
}

QJsonArray UUIDToJson(uint8_t* UUID)
{
    QJsonArray jsonArray;
    for (uint32_t i = 0; i < VK_UUID_SIZE; i++) {
        jsonArray.append(UUID[i]);
    }
    return jsonArray;
}

QJsonArray LUIDToJson(uint8_t* UUID)
{
    QJsonArray jsonArray;
    for (uint32_t i = 0; i < VK_LUID_SIZE; i++) {
        jsonArray.append(UUID[i]);
    }
    return jsonArray;
}

void VulkanDeviceInfo::readPhysicalProperties()
{
    assert(device != NULL);
    vkGetPhysicalDeviceProperties(device, &props);

    qInfo().nospace() << "Device \"" << props.deviceName << "\"";

    properties.clear();
    properties["deviceName"] = props.deviceName;
    properties["driverVersion"] = props.driverVersion;
    properties["driverVersionText"] = QString::fromStdString(getDriverVersion());
    properties["apiVersion"] = props.apiVersion;
    properties["apiVersionText"] = QString::fromStdString(vulkanResources::versionToString(props.apiVersion));
    properties["headerversion"] = VK_HEADER_VERSION;
    properties["vendorID"] = props.vendorID;
    properties["deviceID"] = props.deviceID;
    properties["deviceType"] = props.deviceType;
    properties["deviceTypeText"] = QString::fromStdString(vulkanResources::physicalDeviceTypeString(props.deviceType));

    // Sparse residency properties
    sparseProperties.clear();
    sparseProperties["residencyStandard2DBlockShape"] = props.sparseProperties.residencyStandard2DBlockShape;
    sparseProperties["residencyStandard2DMultisampleBlockShape"] = props.sparseProperties.residencyStandard2DMultisampleBlockShape;
    sparseProperties["residencyStandard3DBlockShape"] = props.sparseProperties.residencyStandard3DBlockShape;
    sparseProperties["residencyAlignedMipSize"] = props.sparseProperties.residencyAlignedMipSize;
    sparseProperties["residencyNonResidentStrict"] = props.sparseProperties.residencyNonResidentStrict;

    // VK_KHR_get_physical_device_properties2
    if (vulkanContext.vkGetPhysicalDeviceProperties2KHR) {

        readExtendedProperties();

        // VK 1.1 core
        if (vulkanVersionSupported(1,1)) {
            VkPhysicalDeviceProperties2KHR deviceProps2{};
            deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
            VkPhysicalDeviceSubgroupProperties extProps{};
            extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
            deviceProps2.pNext = &extProps;
            vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            hasSubgroupProperties = true;
            subgroupProperties.clear();
            subgroupProperties["subgroupSize"] = extProps.subgroupSize;
            subgroupProperties["supportedStages"] = extProps.supportedStages;
            subgroupProperties["supportedOperations"] = extProps.supportedOperations;
            subgroupProperties["quadOperationsInAllStages"] = QVariant(bool(extProps.quadOperationsInAllStages));
            // VK_KHR_maintenance3
            if (extensionSupported(VK_KHR_MAINTENANCE3_EXTENSION_NAME)) {
                const char* extName(VK_KHR_MAINTENANCE3_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceMaintenance3Properties extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxPerSetDescriptors", QVariant::fromValue(extProps.maxPerSetDescriptors), extName));
                properties2.push_back(Property2("maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize), extName));
            }
        }

        // VK 1.2 core
        if (vulkanVersionSupported(1,2)) {
            // Vulkan 1.2 introduced dedicated structures for properties promoted to core in 1.1 and 1.2
            // Fetching the core 1.1 properties also requires a Vulkan 1.2 (or later) implementation

            VkPhysicalDeviceProperties2KHR deviceProps2{};
            deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;

            // Core 1.1
            qInfo() << "Reading Vulkan 1.1 core properties";

            VkPhysicalDeviceVulkan11Properties coreProps11{};
            coreProps11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
            deviceProps2.pNext = &coreProps11;
            vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);

            core11Properties.clear();
            core11Properties["deviceUUID"] = UUIDToJson(coreProps11.deviceUUID);
            core11Properties["driverUUID"] = UUIDToJson(coreProps11.driverUUID);
            core11Properties["deviceLUID"] = LUIDToJson(coreProps11.deviceLUID);
            core11Properties["deviceNodeMask"] = coreProps11.deviceNodeMask;
            core11Properties["deviceLUIDValid"] = coreProps11.deviceLUIDValid;
            core11Properties["subgroupSize"] = coreProps11.subgroupSize;
            core11Properties["subgroupSupportedStages"] = coreProps11.subgroupSupportedStages;
            core11Properties["subgroupSupportedOperations"] = coreProps11.subgroupSupportedOperations;
            core11Properties["subgroupQuadOperationsInAllStages"] = coreProps11.subgroupQuadOperationsInAllStages;
            core11Properties["pointClippingBehavior"] = coreProps11.pointClippingBehavior;
            core11Properties["maxMultiviewViewCount"] = coreProps11.maxMultiviewViewCount;
            core11Properties["maxMultiviewInstanceIndex"] = coreProps11.maxMultiviewInstanceIndex;
            core11Properties["protectedNoFault"] = coreProps11.protectedNoFault;
            core11Properties["maxPerSetDescriptors"] = coreProps11.maxPerSetDescriptors;
            core11Properties["maxMemoryAllocationSize"] = QVariant::fromValue(coreProps11.maxMemoryAllocationSize);


            // Core 1.2
            qInfo() << "Reading Vulkan 1.2 core properties";

            VkPhysicalDeviceVulkan12Properties coreProps12{};
            coreProps12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
            deviceProps2.pNext = &coreProps12;
            vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);

            core12Properties.clear();
            core12Properties["driverID"] = coreProps12.driverID;
            core12Properties["driverName"] = QString(coreProps12.driverName);
            core12Properties["driverInfo"] = QString(coreProps12.driverInfo);
            core12Properties["conformanceVersion"] =  QString::fromStdString(vulkanResources::conformanceVersionKHRString(coreProps12.conformanceVersion));
            core12Properties["denormBehaviorIndependence"] = coreProps12.denormBehaviorIndependence;
            core12Properties["roundingModeIndependence"] = coreProps12.roundingModeIndependence;
            core12Properties["shaderSignedZeroInfNanPreserveFloat16"] = coreProps12.shaderSignedZeroInfNanPreserveFloat16;
            core12Properties["shaderSignedZeroInfNanPreserveFloat32"] = coreProps12.shaderSignedZeroInfNanPreserveFloat32;
            core12Properties["shaderSignedZeroInfNanPreserveFloat64"] = coreProps12.shaderSignedZeroInfNanPreserveFloat64;
            core12Properties["shaderDenormPreserveFloat16"] = coreProps12.shaderDenormPreserveFloat16;
            core12Properties["shaderDenormPreserveFloat32"] = coreProps12.shaderDenormPreserveFloat32;
            core12Properties["shaderDenormPreserveFloat64"] = coreProps12.shaderDenormPreserveFloat64;
            core12Properties["shaderDenormFlushToZeroFloat16"] = coreProps12.shaderDenormFlushToZeroFloat16;
            core12Properties["shaderDenormFlushToZeroFloat32"] = coreProps12.shaderDenormFlushToZeroFloat32;
            core12Properties["shaderDenormFlushToZeroFloat64"] = coreProps12.shaderDenormFlushToZeroFloat64;
            core12Properties["shaderRoundingModeRTEFloat16"] = coreProps12.shaderRoundingModeRTEFloat16;
            core12Properties["shaderRoundingModeRTEFloat32"] = coreProps12.shaderRoundingModeRTEFloat32;
            core12Properties["shaderRoundingModeRTEFloat64"] = coreProps12.shaderRoundingModeRTEFloat64;
            core12Properties["shaderRoundingModeRTZFloat16"] = coreProps12.shaderRoundingModeRTZFloat16;
            core12Properties["shaderRoundingModeRTZFloat32"] = coreProps12.shaderRoundingModeRTZFloat32;
            core12Properties["shaderRoundingModeRTZFloat64"] = coreProps12.shaderRoundingModeRTZFloat64;
            core12Properties["maxUpdateAfterBindDescriptorsInAllPools"] = coreProps12.maxUpdateAfterBindDescriptorsInAllPools;
            core12Properties["shaderUniformBufferArrayNonUniformIndexingNative"] = coreProps12.shaderUniformBufferArrayNonUniformIndexingNative;
            core12Properties["shaderSampledImageArrayNonUniformIndexingNative"] = coreProps12.shaderSampledImageArrayNonUniformIndexingNative;
            core12Properties["shaderStorageBufferArrayNonUniformIndexingNative"] = coreProps12.shaderStorageBufferArrayNonUniformIndexingNative;
            core12Properties["shaderStorageImageArrayNonUniformIndexingNative"] = coreProps12.shaderStorageImageArrayNonUniformIndexingNative;
            core12Properties["shaderInputAttachmentArrayNonUniformIndexingNative"] = coreProps12.shaderInputAttachmentArrayNonUniformIndexingNative;
            core12Properties["robustBufferAccessUpdateAfterBind"] = coreProps12.robustBufferAccessUpdateAfterBind;
            core12Properties["quadDivergentImplicitLod"] = coreProps12.quadDivergentImplicitLod;
            core12Properties["maxPerStageDescriptorUpdateAfterBindSamplers"] = coreProps12.maxPerStageDescriptorUpdateAfterBindSamplers;
            core12Properties["maxPerStageDescriptorUpdateAfterBindUniformBuffers"] = coreProps12.maxPerStageDescriptorUpdateAfterBindUniformBuffers;
            core12Properties["maxPerStageDescriptorUpdateAfterBindStorageBuffers"] = coreProps12.maxPerStageDescriptorUpdateAfterBindStorageBuffers;
            core12Properties["maxPerStageDescriptorUpdateAfterBindSampledImages"] = coreProps12.maxPerStageDescriptorUpdateAfterBindSampledImages;
            core12Properties["maxPerStageDescriptorUpdateAfterBindStorageImages"] = coreProps12.maxPerStageDescriptorUpdateAfterBindStorageImages;
            core12Properties["maxPerStageDescriptorUpdateAfterBindInputAttachments"] = coreProps12.maxPerStageDescriptorUpdateAfterBindInputAttachments;
            core12Properties["maxPerStageUpdateAfterBindResources"] = coreProps12.maxPerStageUpdateAfterBindResources;
            core12Properties["maxDescriptorSetUpdateAfterBindSamplers"] = coreProps12.maxDescriptorSetUpdateAfterBindSamplers;
            core12Properties["maxDescriptorSetUpdateAfterBindUniformBuffers"] = coreProps12.maxDescriptorSetUpdateAfterBindUniformBuffers;
            core12Properties["maxDescriptorSetUpdateAfterBindUniformBuffersDynamic"] = coreProps12.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
            core12Properties["maxDescriptorSetUpdateAfterBindStorageBuffers"] = coreProps12.maxDescriptorSetUpdateAfterBindStorageBuffers;
            core12Properties["maxDescriptorSetUpdateAfterBindStorageBuffersDynamic"] = coreProps12.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
            core12Properties["maxDescriptorSetUpdateAfterBindSampledImages"] = coreProps12.maxDescriptorSetUpdateAfterBindSampledImages;
            core12Properties["maxDescriptorSetUpdateAfterBindStorageImages"] = coreProps12.maxDescriptorSetUpdateAfterBindStorageImages;
            core12Properties["maxDescriptorSetUpdateAfterBindInputAttachments"] = coreProps12.maxDescriptorSetUpdateAfterBindInputAttachments;
            core12Properties["supportedDepthResolveModes"] = coreProps12.supportedDepthResolveModes;
            core12Properties["supportedStencilResolveModes"] = coreProps12.supportedStencilResolveModes;
            core12Properties["independentResolveNone"] = coreProps12.independentResolveNone;
            core12Properties["independentResolve"] = coreProps12.independentResolve;
            core12Properties["filterMinmaxSingleComponentFormats"] = coreProps12.filterMinmaxSingleComponentFormats;
            core12Properties["filterMinmaxImageComponentMapping"] = coreProps12.filterMinmaxImageComponentMapping;
            core12Properties["maxTimelineSemaphoreValueDifference"] = QString::number(coreProps12.maxTimelineSemaphoreValueDifference);
            core12Properties["framebufferIntegerColorSampleCounts"] = coreProps12.framebufferIntegerColorSampleCounts;

        }

        // Vulkan 1.3
        if (vulkanVersionSupported(1,3)) {
            // Core 1.3
            qInfo() << "Reading Vulkan 1.3 core properties";

            VkPhysicalDeviceProperties2KHR deviceProps2{};
            deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;

            VkPhysicalDeviceVulkan13Properties coreProps13{};
            coreProps13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
            deviceProps2.pNext = &coreProps13;
            vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);

            core13Properties.clear();
			core13Properties["minSubgroupSize"] = coreProps13.minSubgroupSize;
			core13Properties["maxSubgroupSize"] = coreProps13.maxSubgroupSize;
			core13Properties["maxComputeWorkgroupSubgroups"] = coreProps13.maxComputeWorkgroupSubgroups;
			core13Properties["requiredSubgroupSizeStages"] = coreProps13.requiredSubgroupSizeStages;
			core13Properties["maxInlineUniformBlockSize"] = coreProps13.maxInlineUniformBlockSize;
			core13Properties["maxPerStageDescriptorInlineUniformBlocks"] = coreProps13.maxPerStageDescriptorInlineUniformBlocks;
			core13Properties["maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks"] = coreProps13.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks;
			core13Properties["maxDescriptorSetInlineUniformBlocks"] = coreProps13.maxDescriptorSetInlineUniformBlocks;
			core13Properties["maxDescriptorSetUpdateAfterBindInlineUniformBlocks"] = coreProps13.maxDescriptorSetUpdateAfterBindInlineUniformBlocks;
			core13Properties["maxInlineUniformTotalSize"] = coreProps13.maxInlineUniformTotalSize;
			core13Properties["integerDotProduct8BitUnsignedAccelerated"] = coreProps13.integerDotProduct8BitUnsignedAccelerated;
			core13Properties["integerDotProduct8BitSignedAccelerated"] = coreProps13.integerDotProduct8BitSignedAccelerated;
			core13Properties["integerDotProduct8BitMixedSignednessAccelerated"] = coreProps13.integerDotProduct8BitMixedSignednessAccelerated;
			core13Properties["integerDotProduct4x8BitPackedUnsignedAccelerated"] = coreProps13.integerDotProduct4x8BitPackedUnsignedAccelerated;
			core13Properties["integerDotProduct4x8BitPackedSignedAccelerated"] = coreProps13.integerDotProduct4x8BitPackedSignedAccelerated;
			core13Properties["integerDotProduct4x8BitPackedMixedSignednessAccelerated"] = coreProps13.integerDotProduct4x8BitPackedMixedSignednessAccelerated;
			core13Properties["integerDotProduct16BitUnsignedAccelerated"] = coreProps13.integerDotProduct16BitUnsignedAccelerated;
			core13Properties["integerDotProduct16BitSignedAccelerated"] = coreProps13.integerDotProduct16BitSignedAccelerated;
			core13Properties["integerDotProduct16BitMixedSignednessAccelerated"] = coreProps13.integerDotProduct16BitMixedSignednessAccelerated;
			core13Properties["integerDotProduct32BitUnsignedAccelerated"] = coreProps13.integerDotProduct32BitUnsignedAccelerated;
			core13Properties["integerDotProduct32BitSignedAccelerated"] = coreProps13.integerDotProduct32BitSignedAccelerated;
			core13Properties["integerDotProduct32BitMixedSignednessAccelerated"] = coreProps13.integerDotProduct32BitMixedSignednessAccelerated;
			core13Properties["integerDotProduct64BitUnsignedAccelerated"] = coreProps13.integerDotProduct64BitUnsignedAccelerated;
			core13Properties["integerDotProduct64BitSignedAccelerated"] = coreProps13.integerDotProduct64BitSignedAccelerated;
			core13Properties["integerDotProduct64BitMixedSignednessAccelerated"] = coreProps13.integerDotProduct64BitMixedSignednessAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating8BitSignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating8BitSignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating16BitUnsignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating16BitSignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating16BitSignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating32BitUnsignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating32BitSignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating32BitSignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating64BitUnsignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating64BitSignedAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating64BitSignedAccelerated;
			core13Properties["integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated"] = coreProps13.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated;
            core13Properties["storageTexelBufferOffsetAlignmentBytes"] = QVariant::fromValue(coreProps13.storageTexelBufferOffsetAlignmentBytes);
			core13Properties["storageTexelBufferOffsetSingleTexelAlignment"] = coreProps13.storageTexelBufferOffsetSingleTexelAlignment;
            core13Properties["uniformTexelBufferOffsetAlignmentBytes"] = QVariant::fromValue(coreProps13.uniformTexelBufferOffsetAlignmentBytes);
            core13Properties["uniformTexelBufferOffsetSingleTexelAlignment"] = QVariant::fromValue(coreProps13.uniformTexelBufferOffsetSingleTexelAlignment);
            core13Properties["maxBufferSize"] = QVariant::fromValue(coreProps13.maxBufferSize).toString();
        }
    }
}

void VulkanDeviceInfo::readPhysicalFeatures()
{
    assert(device != NULL);
    qInfo() << "Reading physical feattures";
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    features.clear();
    features["robustBufferAccess"] = deviceFeatures.robustBufferAccess;
    features["fullDrawIndexUint32"] = deviceFeatures.fullDrawIndexUint32;
    features["imageCubeArray"] = deviceFeatures.imageCubeArray;
    features["independentBlend"] = deviceFeatures.independentBlend;
    features["geometryShader"] = deviceFeatures.geometryShader;
    features["tessellationShader"] = deviceFeatures.tessellationShader;
    features["sampleRateShading"] = deviceFeatures.sampleRateShading;
    features["dualSrcBlend"] = deviceFeatures.dualSrcBlend;
    features["logicOp"] = deviceFeatures.logicOp;
    features["multiDrawIndirect"] = deviceFeatures.multiDrawIndirect;
    features["drawIndirectFirstInstance"] = deviceFeatures.drawIndirectFirstInstance;
    features["depthClamp"] = deviceFeatures.depthClamp;
    features["depthBiasClamp"] = deviceFeatures.depthBiasClamp;
    features["fillModeNonSolid"] = deviceFeatures.fillModeNonSolid;
    features["depthBounds"] = deviceFeatures.depthBounds;
    features["wideLines"] = deviceFeatures.wideLines;
    features["largePoints"] = deviceFeatures.largePoints;
    features["alphaToOne"] = deviceFeatures.alphaToOne;
    features["multiViewport"] = deviceFeatures.multiViewport;
    features["samplerAnisotropy"] = deviceFeatures.samplerAnisotropy;
    features["textureCompressionETC2"] = deviceFeatures.textureCompressionETC2;
    features["textureCompressionASTC_LDR"] = deviceFeatures.textureCompressionASTC_LDR;
    features["textureCompressionBC"] = deviceFeatures.textureCompressionBC;
    features["occlusionQueryPrecise"] = deviceFeatures.occlusionQueryPrecise;
    features["pipelineStatisticsQuery"] = deviceFeatures.pipelineStatisticsQuery;
    features["vertexPipelineStoresAndAtomics"] = deviceFeatures.vertexPipelineStoresAndAtomics;
    features["fragmentStoresAndAtomics"] = deviceFeatures.fragmentStoresAndAtomics;
    features["shaderTessellationAndGeometryPointSize"] = deviceFeatures.shaderTessellationAndGeometryPointSize;
    features["shaderImageGatherExtended"] = deviceFeatures.shaderImageGatherExtended;
    features["shaderStorageImageExtendedFormats"] = deviceFeatures.shaderStorageImageExtendedFormats;
    features["shaderStorageImageMultisample"] = deviceFeatures.shaderStorageImageMultisample;
    features["shaderStorageImageReadWithoutFormat"] = deviceFeatures.shaderStorageImageReadWithoutFormat;
    features["shaderStorageImageWriteWithoutFormat"] = deviceFeatures.shaderStorageImageWriteWithoutFormat;
    features["shaderUniformBufferArrayDynamicIndexing"] = deviceFeatures.shaderUniformBufferArrayDynamicIndexing;
    features["shaderSampledImageArrayDynamicIndexing"] = deviceFeatures.shaderSampledImageArrayDynamicIndexing;
    features["shaderStorageBufferArrayDynamicIndexing"] = deviceFeatures.shaderStorageBufferArrayDynamicIndexing;
    features["shaderStorageImageArrayDynamicIndexing"] = deviceFeatures.shaderStorageImageArrayDynamicIndexing;
    features["shaderClipDistance"] = deviceFeatures.shaderClipDistance;
    features["shaderCullDistance"] = deviceFeatures.shaderCullDistance;
    features["shaderFloat64"] = deviceFeatures.shaderFloat64;
    features["shaderInt64"] = deviceFeatures.shaderInt64;
    features["shaderInt16"] = deviceFeatures.shaderInt16;
    features["shaderResourceResidency"] = deviceFeatures.shaderResourceResidency;
    features["shaderResourceMinLod"] = deviceFeatures.shaderResourceMinLod;
    features["sparseBinding"] = deviceFeatures.sparseBinding;
    features["sparseResidencyBuffer"] = deviceFeatures.sparseResidencyBuffer;
    features["sparseResidencyImage2D"] = deviceFeatures.sparseResidencyImage2D;
    features["sparseResidencyImage3D"] = deviceFeatures.sparseResidencyImage3D;
    features["sparseResidency2Samples"] = deviceFeatures.sparseResidency2Samples;
    features["sparseResidency4Samples"] = deviceFeatures.sparseResidency4Samples;
    features["sparseResidency8Samples"] = deviceFeatures.sparseResidency8Samples;
    features["sparseResidency16Samples"] = deviceFeatures.sparseResidency16Samples;
    features["sparseResidencyAliased"] = deviceFeatures.sparseResidencyAliased;
    features["variableMultisampleRate"] = deviceFeatures.variableMultisampleRate;
    features["inheritedQueries"] = deviceFeatures.inheritedQueries;

    // VK_KHR_get_physical_device_properties2
    if (vulkanContext.vkGetPhysicalDeviceFeatures2KHR) {

        readExtendedFeatures();

        // Vulkan 1.1
        if (vulkanVersionSupported(1,1)) {
            VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
            deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

            // VK_KHR_shader_draw_parameters
            if (extensionSupported(VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME)) {
                VkPhysicalDeviceShaderDrawParameterFeatures extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
                deviceFeatures2.pNext = &extFeatures;
                vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("shaderDrawParameters", extFeatures.shaderDrawParameters, VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME));
            }
        }

        // Vulkan 1.2
        if (vulkanVersionSupported(1,2)) {
            // Vulkan 1.2 introduced dedicated structures for features promoted to core in 1.1 and 1.2
            // Fetching the core 1.1 features also requires a Vulkan 1.2 (or later) implementation

            VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
            deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

            // Core 1.1
            qInfo() << "Reading Vulkan 1.1 core features";

            VkPhysicalDeviceVulkan11Features coreFeatures11{};
            coreFeatures11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
            deviceFeatures2.pNext = &coreFeatures11;
            vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);

            core11Features.clear();
            core11Features["storageBuffer16BitAccess"] = coreFeatures11.storageBuffer16BitAccess;
            core11Features["uniformAndStorageBuffer16BitAccess"] = coreFeatures11.uniformAndStorageBuffer16BitAccess;
            core11Features["storagePushConstant16"] = coreFeatures11.storagePushConstant16;
            core11Features["storageInputOutput16"] = coreFeatures11.storageInputOutput16;
            core11Features["multiview"] = coreFeatures11.multiview;
            core11Features["multiviewGeometryShader"] = coreFeatures11.multiviewGeometryShader;
            core11Features["multiviewTessellationShader"] = coreFeatures11.multiviewTessellationShader;
            core11Features["variablePointersStorageBuffer"] = coreFeatures11.variablePointersStorageBuffer;
            core11Features["variablePointers"] = coreFeatures11.variablePointers;
            core11Features["protectedMemory"] = coreFeatures11.protectedMemory;
            core11Features["samplerYcbcrConversion"] = coreFeatures11.samplerYcbcrConversion;
            core11Features["shaderDrawParameters"] = coreFeatures11.shaderDrawParameters;

            // Core 1.2
            qInfo() << "Reading Vulkan 1.2 core features";

            VkPhysicalDeviceVulkan12Features coreFeatures12{};
            coreFeatures12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
            deviceFeatures2.pNext = &coreFeatures12;
            vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);

            core12Features.clear();
            core12Features["samplerMirrorClampToEdge"] = coreFeatures12.samplerMirrorClampToEdge;
            core12Features["drawIndirectCount"] = coreFeatures12.drawIndirectCount;
            core12Features["storageBuffer8BitAccess"] = coreFeatures12.storageBuffer8BitAccess;
            core12Features["uniformAndStorageBuffer8BitAccess"] = coreFeatures12.uniformAndStorageBuffer8BitAccess;
            core12Features["storagePushConstant8"] = coreFeatures12.storagePushConstant8;
            core12Features["shaderBufferInt64Atomics"] = coreFeatures12.shaderBufferInt64Atomics;
            core12Features["shaderSharedInt64Atomics"] = coreFeatures12.shaderSharedInt64Atomics;
            core12Features["shaderFloat16"] = coreFeatures12.shaderFloat16;
            core12Features["shaderInt8"] = coreFeatures12.shaderInt8;
            core12Features["descriptorIndexing"] = coreFeatures12.descriptorIndexing;
            core12Features["shaderInputAttachmentArrayDynamicIndexing"] = coreFeatures12.shaderInputAttachmentArrayDynamicIndexing;
            core12Features["shaderUniformTexelBufferArrayDynamicIndexing"] = coreFeatures12.shaderUniformTexelBufferArrayDynamicIndexing;
            core12Features["shaderStorageTexelBufferArrayDynamicIndexing"] = coreFeatures12.shaderStorageTexelBufferArrayDynamicIndexing;
            core12Features["shaderUniformBufferArrayNonUniformIndexing"] = coreFeatures12.shaderUniformBufferArrayNonUniformIndexing;
            core12Features["shaderSampledImageArrayNonUniformIndexing"] = coreFeatures12.shaderSampledImageArrayNonUniformIndexing;
            core12Features["shaderStorageBufferArrayNonUniformIndexing"] = coreFeatures12.shaderStorageBufferArrayNonUniformIndexing;
            core12Features["shaderStorageImageArrayNonUniformIndexing"] = coreFeatures12.shaderStorageImageArrayNonUniformIndexing;
            core12Features["shaderInputAttachmentArrayNonUniformIndexing"] = coreFeatures12.shaderInputAttachmentArrayNonUniformIndexing;
            core12Features["shaderUniformTexelBufferArrayNonUniformIndexing"] = coreFeatures12.shaderUniformTexelBufferArrayNonUniformIndexing;
            core12Features["shaderStorageTexelBufferArrayNonUniformIndexing"] = coreFeatures12.shaderStorageTexelBufferArrayNonUniformIndexing;
            core12Features["descriptorBindingUniformBufferUpdateAfterBind"] = coreFeatures12.descriptorBindingUniformBufferUpdateAfterBind;
            core12Features["descriptorBindingSampledImageUpdateAfterBind"] = coreFeatures12.descriptorBindingSampledImageUpdateAfterBind;
            core12Features["descriptorBindingStorageImageUpdateAfterBind"] = coreFeatures12.descriptorBindingStorageImageUpdateAfterBind;
            core12Features["descriptorBindingStorageBufferUpdateAfterBind"] = coreFeatures12.descriptorBindingStorageBufferUpdateAfterBind;
            core12Features["descriptorBindingUniformTexelBufferUpdateAfterBind"] = coreFeatures12.descriptorBindingUniformTexelBufferUpdateAfterBind;
            core12Features["descriptorBindingStorageTexelBufferUpdateAfterBind"] = coreFeatures12.descriptorBindingStorageTexelBufferUpdateAfterBind;
            core12Features["descriptorBindingUpdateUnusedWhilePending"] = coreFeatures12.descriptorBindingUpdateUnusedWhilePending;
            core12Features["descriptorBindingPartiallyBound"] = coreFeatures12.descriptorBindingPartiallyBound;
            core12Features["descriptorBindingVariableDescriptorCount"] = coreFeatures12.descriptorBindingVariableDescriptorCount;
            core12Features["runtimeDescriptorArray"] = coreFeatures12.runtimeDescriptorArray;
            core12Features["samplerFilterMinmax"] = coreFeatures12.samplerFilterMinmax;
            core12Features["scalarBlockLayout"] = coreFeatures12.scalarBlockLayout;
            core12Features["imagelessFramebuffer"] = coreFeatures12.imagelessFramebuffer;
            core12Features["uniformBufferStandardLayout"] = coreFeatures12.uniformBufferStandardLayout;
            core12Features["shaderSubgroupExtendedTypes"] = coreFeatures12.shaderSubgroupExtendedTypes;
            core12Features["separateDepthStencilLayouts"] = coreFeatures12.separateDepthStencilLayouts;
            core12Features["hostQueryReset"] = coreFeatures12.hostQueryReset;
            core12Features["timelineSemaphore"] = coreFeatures12.timelineSemaphore;
            core12Features["bufferDeviceAddress"] = coreFeatures12.bufferDeviceAddress;
            core12Features["bufferDeviceAddressCaptureReplay"] = coreFeatures12.bufferDeviceAddressCaptureReplay;
            core12Features["bufferDeviceAddressMultiDevice"] = coreFeatures12.bufferDeviceAddressMultiDevice;
            core12Features["vulkanMemoryModel"] = coreFeatures12.vulkanMemoryModel;
            core12Features["vulkanMemoryModelDeviceScope"] = coreFeatures12.vulkanMemoryModelDeviceScope;
            core12Features["vulkanMemoryModelAvailabilityVisibilityChains"] = coreFeatures12.vulkanMemoryModelAvailabilityVisibilityChains;
            core12Features["shaderOutputViewportIndex"] = coreFeatures12.shaderOutputViewportIndex;
            core12Features["shaderOutputLayer"] = coreFeatures12.shaderOutputLayer;
            core12Features["subgroupBroadcastDynamicId"] = coreFeatures12.subgroupBroadcastDynamicId;
        }

        // Vulkan 1.3
        if (vulkanVersionSupported(1,3)) {
            // Core 1.3
            qInfo() << "Reading Vulkan 1.3 core features";

            VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
            deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

            VkPhysicalDeviceVulkan13Features coreFeatures13{};
            coreFeatures13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
            deviceFeatures2.pNext = &coreFeatures13;
            vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);

            core13Features.clear();
            core13Features["robustImageAccess"] = coreFeatures13.robustImageAccess;
            core13Features["inlineUniformBlock"] = coreFeatures13.inlineUniformBlock;
            core13Features["descriptorBindingInlineUniformBlockUpdateAfterBind"] = coreFeatures13.descriptorBindingInlineUniformBlockUpdateAfterBind;
            core13Features["pipelineCreationCacheControl"] = coreFeatures13.pipelineCreationCacheControl;
            core13Features["privateData"] = coreFeatures13.privateData;
            core13Features["shaderDemoteToHelperInvocation"] = coreFeatures13.shaderDemoteToHelperInvocation;
            core13Features["shaderTerminateInvocation"] = coreFeatures13.shaderTerminateInvocation;
            core13Features["subgroupSizeControl"] = coreFeatures13.subgroupSizeControl;
            core13Features["computeFullSubgroups"] = coreFeatures13.computeFullSubgroups;
            core13Features["synchronization2"] = coreFeatures13.synchronization2;
            core13Features["textureCompressionASTC_HDR"] = coreFeatures13.textureCompressionASTC_HDR;
            core13Features["shaderZeroInitializeWorkgroupMemory"] = coreFeatures13.shaderZeroInitializeWorkgroupMemory;
            core13Features["dynamicRendering"] = coreFeatures13.dynamicRendering;
            core13Features["shaderIntegerDotProduct"] = coreFeatures13.shaderIntegerDotProduct;
            core13Features["maintenance4"] = coreFeatures13.maintenance4;
        }

    }
}

void VulkanDeviceInfo::readPhysicalLimits()
{
    qInfo() << "Reading limits";
    using vulkanResources::toHexQString;

    limits.clear();
    limits["maxImageDimension1D"] = props.limits.maxImageDimension1D;
    limits["maxImageDimension2D"] = props.limits.maxImageDimension2D;
    limits["maxImageDimension3D"] = props.limits.maxImageDimension3D;
    limits["maxImageDimensionCube"] = props.limits.maxImageDimensionCube;
    limits["maxImageArrayLayers"] = props.limits.maxImageArrayLayers;
    limits["maxTexelBufferElements"] = props.limits.maxTexelBufferElements;
    limits["maxUniformBufferRange"] = props.limits.maxUniformBufferRange;
    limits["maxStorageBufferRange"] = props.limits.maxStorageBufferRange;
    limits["maxPushConstantsSize"] = props.limits.maxPushConstantsSize;
    limits["maxMemoryAllocationCount"] = props.limits.maxMemoryAllocationCount;
    limits["maxSamplerAllocationCount"] = props.limits.maxSamplerAllocationCount;
    limits["bufferImageGranularity"] = toHexQString(props.limits.bufferImageGranularity);
    limits["sparseAddressSpaceSize"] = toHexQString(props.limits.sparseAddressSpaceSize);
    limits["maxBoundDescriptorSets"] = props.limits.maxBoundDescriptorSets;
    limits["maxPerStageDescriptorSamplers"] = props.limits.maxPerStageDescriptorSamplers;
    limits["maxPerStageDescriptorUniformBuffers"] = props.limits.maxPerStageDescriptorUniformBuffers;
    limits["maxPerStageDescriptorStorageBuffers"] = props.limits.maxPerStageDescriptorStorageBuffers;
    limits["maxPerStageDescriptorSampledImages"] = props.limits.maxPerStageDescriptorSampledImages;
    limits["maxPerStageDescriptorStorageImages"] = props.limits.maxPerStageDescriptorStorageImages;
    limits["maxPerStageDescriptorInputAttachments"] = props.limits.maxPerStageDescriptorInputAttachments;
    limits["maxPerStageResources"] = props.limits.maxPerStageResources;
    limits["maxDescriptorSetSamplers"] = props.limits.maxDescriptorSetSamplers;
    limits["maxDescriptorSetUniformBuffers"] = props.limits.maxDescriptorSetUniformBuffers;
    limits["maxDescriptorSetUniformBuffersDynamic"] = props.limits.maxDescriptorSetUniformBuffersDynamic;
    limits["maxDescriptorSetStorageBuffers"] = props.limits.maxDescriptorSetStorageBuffers;
    limits["maxDescriptorSetStorageBuffersDynamic"] = props.limits.maxDescriptorSetStorageBuffersDynamic;
    limits["maxDescriptorSetSampledImages"] = props.limits.maxDescriptorSetSampledImages;
    limits["maxDescriptorSetStorageImages"] = props.limits.maxDescriptorSetStorageImages;
    limits["maxDescriptorSetInputAttachments"] = props.limits.maxDescriptorSetInputAttachments;
    limits["maxVertexInputAttributes"] = props.limits.maxVertexInputAttributes;
    limits["maxVertexInputBindings"] = props.limits.maxVertexInputBindings;
    limits["maxVertexInputAttributeOffset"] = props.limits.maxVertexInputAttributeOffset;
    limits["maxVertexInputBindingStride"] = props.limits.maxVertexInputBindingStride;
    limits["maxVertexOutputComponents"] = props.limits.maxVertexOutputComponents;
    limits["maxTessellationGenerationLevel"] = props.limits.maxTessellationGenerationLevel;
    limits["maxTessellationPatchSize"] = props.limits.maxTessellationPatchSize;
    limits["maxTessellationControlPerVertexInputComponents"] = props.limits.maxTessellationControlPerVertexInputComponents;
    limits["maxTessellationControlPerVertexOutputComponents"] = props.limits.maxTessellationControlPerVertexOutputComponents;
    limits["maxTessellationControlPerPatchOutputComponents"] = props.limits.maxTessellationControlPerPatchOutputComponents;
    limits["maxTessellationControlTotalOutputComponents"] = props.limits.maxTessellationControlTotalOutputComponents;
    limits["maxTessellationEvaluationInputComponents"] = props.limits.maxTessellationEvaluationInputComponents;
    limits["maxTessellationEvaluationOutputComponents"] = props.limits.maxTessellationEvaluationOutputComponents;
    limits["maxGeometryShaderInvocations"] = props.limits.maxGeometryShaderInvocations;
    limits["maxGeometryInputComponents"] = props.limits.maxGeometryInputComponents;
    limits["maxGeometryOutputComponents"] = props.limits.maxGeometryOutputComponents;
    limits["maxGeometryOutputVertices"] = props.limits.maxGeometryOutputVertices;
    limits["maxGeometryTotalOutputComponents"] = props.limits.maxGeometryTotalOutputComponents;
    limits["maxFragmentInputComponents"] = props.limits.maxFragmentInputComponents;
    limits["maxFragmentOutputAttachments"] = props.limits.maxFragmentOutputAttachments;
    limits["maxFragmentDualSrcAttachments"] = props.limits.maxFragmentDualSrcAttachments;
    limits["maxFragmentCombinedOutputResources"] = props.limits.maxFragmentCombinedOutputResources;
    limits["maxComputeSharedMemorySize"] = props.limits.maxComputeSharedMemorySize;
    limits["maxComputeWorkGroupCount"] = QVariant::fromValue(QVariantList({ props.limits.maxComputeWorkGroupCount[0], props.limits.maxComputeWorkGroupCount[1], props.limits.maxComputeWorkGroupCount[2] }));
    limits["maxComputeWorkGroupInvocations"] = props.limits.maxComputeWorkGroupInvocations;
    limits["maxComputeWorkGroupSize"] = QVariant::fromValue(QVariantList({ props.limits.maxComputeWorkGroupSize[0], props.limits.maxComputeWorkGroupSize[1], props.limits.maxComputeWorkGroupSize[2] }));
    limits["subPixelPrecisionBits"] = props.limits.subPixelPrecisionBits;
    limits["subTexelPrecisionBits"] = props.limits.subTexelPrecisionBits;
    limits["mipmapPrecisionBits"] = props.limits.mipmapPrecisionBits;
    limits["maxDrawIndexedIndexValue"] = props.limits.maxDrawIndexedIndexValue;
    limits["maxDrawIndirectCount"] = props.limits.maxDrawIndirectCount;
    limits["maxSamplerLodBias"] = props.limits.maxSamplerLodBias;
    limits["maxSamplerAnisotropy"] = props.limits.maxSamplerAnisotropy;
    limits["maxViewports"] = props.limits.maxViewports;
    limits["maxViewportDimensions"] = QVariant::fromValue(QVariantList({ props.limits.maxViewportDimensions[0], props.limits.maxViewportDimensions[1] }));
    limits["viewportBoundsRange"] = QVariant::fromValue(QVariantList({ props.limits.viewportBoundsRange[0], props.limits.viewportBoundsRange[1] }));
    limits["viewportSubPixelBits"] = props.limits.viewportSubPixelBits;
    limits["minMemoryMapAlignment"] = toHexQString(props.limits.minMemoryMapAlignment);
    limits["minTexelBufferOffsetAlignment"] = toHexQString(props.limits.minTexelBufferOffsetAlignment);
    limits["minUniformBufferOffsetAlignment"] = toHexQString(props.limits.minUniformBufferOffsetAlignment);
    limits["minStorageBufferOffsetAlignment"] = toHexQString(props.limits.minStorageBufferOffsetAlignment);
    limits["minTexelOffset"] = props.limits.minTexelOffset;
    limits["maxTexelOffset"] = props.limits.maxTexelOffset;
    limits["minTexelGatherOffset"] = props.limits.minTexelGatherOffset;
    limits["maxTexelGatherOffset"] = props.limits.maxTexelGatherOffset;
    limits["minInterpolationOffset"] = props.limits.minInterpolationOffset;
    limits["maxInterpolationOffset"] = props.limits.maxInterpolationOffset;
    limits["subPixelInterpolationOffsetBits"] = props.limits.subPixelInterpolationOffsetBits;
    limits["maxFramebufferWidth"] = props.limits.maxFramebufferWidth;
    limits["maxFramebufferHeight"] = props.limits.maxFramebufferHeight;
    limits["maxFramebufferLayers"] = props.limits.maxFramebufferLayers;
    limits["framebufferColorSampleCounts"] = props.limits.framebufferColorSampleCounts;
    limits["framebufferDepthSampleCounts"] = props.limits.framebufferDepthSampleCounts;
    limits["framebufferStencilSampleCounts"] = props.limits.framebufferStencilSampleCounts;
    limits["framebufferNoAttachmentsSampleCounts"] = props.limits.framebufferNoAttachmentsSampleCounts;
    limits["maxColorAttachments"] = props.limits.maxColorAttachments;
    limits["sampledImageColorSampleCounts"] = props.limits.sampledImageColorSampleCounts;
    limits["sampledImageIntegerSampleCounts"] = props.limits.sampledImageIntegerSampleCounts;
    limits["sampledImageDepthSampleCounts"] = props.limits.sampledImageDepthSampleCounts;
    limits["sampledImageStencilSampleCounts"] = props.limits.sampledImageStencilSampleCounts;
    limits["storageImageSampleCounts"] = props.limits.storageImageSampleCounts;
    limits["maxSampleMaskWords"] = props.limits.maxSampleMaskWords;
    limits["timestampComputeAndGraphics"] = props.limits.timestampComputeAndGraphics;
    limits["timestampPeriod"] = props.limits.timestampPeriod;
    limits["maxClipDistances"] = props.limits.maxClipDistances;
    limits["maxCullDistances"] = props.limits.maxCullDistances;
    limits["maxCombinedClipAndCullDistances"] = props.limits.maxCombinedClipAndCullDistances;
    limits["discreteQueuePriorities"] = props.limits.discreteQueuePriorities;
    limits["pointSizeRange"] = QVariant::fromValue(QVariantList({ props.limits.pointSizeRange[0], props.limits.pointSizeRange[1] }));
    limits["lineWidthRange"] = QVariant::fromValue(QVariantList({ props.limits.lineWidthRange[0], props.limits.lineWidthRange[1] }));
    limits["pointSizeGranularity"] = props.limits.pointSizeGranularity;
    limits["lineWidthGranularity"] = props.limits.lineWidthGranularity;
    limits["strictLines"] = props.limits.strictLines;
    limits["standardSampleLocations"] = props.limits.standardSampleLocations;
    limits["optimalBufferCopyOffsetAlignment"] = toHexQString(props.limits.optimalBufferCopyOffsetAlignment);
    limits["optimalBufferCopyRowPitchAlignment"] = toHexQString(props.limits.optimalBufferCopyRowPitchAlignment);
    limits["nonCoherentAtomSize"] = toHexQString(props.limits.nonCoherentAtomSize);
}

void VulkanDeviceInfo::readPhysicalMemoryProperties()
{
    assert(device != NULL);
    qInfo() << "Reading memory properties";
    vkGetPhysicalDeviceMemoryProperties(device, &memoryProperties);
}

void VulkanDeviceInfo::readSurfaceInfo()
{
    assert(device != NULL);
    qInfo() << "Reading surface info";
    surfaceInfo.validSurface = (vulkanContext.surface != VK_NULL_HANDLE);
    surfaceInfo.surfaceExtension = vulkanContext.surfaceExtension;
    surfaceInfo.get(device, vulkanContext.surface);
}

#if defined(__ANDROID__)
std::string VulkanDeviceInfo::getSystemProperty(const char* propname)
{
    char prop[PROP_VALUE_MAX+1];
    int len = __system_property_get(propname, prop);
    if (len > 0) {
        return std::string(prop);
    } else {
        return "";
    }
}
#endif

void VulkanDeviceInfo::readPlatformDetails()
{
    // Android specific build info
#if defined(__ANDROID__)
    qInfo() << "Reading platform details";
    platformdetails["android.ProductModel"] = getSystemProperty("ro.product.model");
    platformdetails["android.ProductManufacturer"] = getSystemProperty("ro.product.manufacturer");
    platformdetails["android.BuildID"] = getSystemProperty("ro.build.id");
    platformdetails["android.BuildVersionIncremental"] = getSystemProperty("ro.build.version.incremental");
    properties["displayName"] = QString::fromStdString(platformdetails["android.ProductManufacturer"] + " " + platformdetails["android.ProductModel"]);
#endif
}

void VulkanDeviceInfo::readProfiles()
{
    qInfo() << "Reading profiles";

    std::vector<VpProfileProperties> availableProfiles{};
    uint32_t profilesCount;
    if (vpGetProfiles(&profilesCount, nullptr) == VK_SUCCESS) {
        availableProfiles.resize(profilesCount);
        vpGetProfiles(&profilesCount, availableProfiles.data());
    }

    profiles.clear();
    for (VpProfileProperties& profile : availableProfiles) {
        qInfo() << "Reading profile" << profile.profileName;
        VkBool32 supported = VK_FALSE;
        vpGetPhysicalDeviceProfileSupport(vulkanContext.instance, device, &profile, &supported);
        VulkanProfileInfo profileInfo{};
        profileInfo.profileName = profile.profileName;
        profileInfo.specVersion = profile.specVersion;
        profileInfo.supported = supported;
        profiles.push_back(profileInfo);
    }
}

QJsonObject VulkanDeviceInfo::toJson(QString submitter, QString comment)
{
    QJsonObject root;

    // Device properties
    QJsonObject jsonProperties;
    jsonProperties = QJsonObject::fromVariantMap(properties);
    jsonProperties["sparseProperties"] = QJsonObject::fromVariantMap(sparseProperties);
    jsonProperties["subgroupProperties"] = QJsonObject::fromVariantMap(subgroupProperties);
    jsonProperties["limits"] = QJsonObject::fromVariantMap(limits);
    // Pipeline cache UUID
    QJsonArray jsonPipelineCache;
    for (uint32_t i = 0; i < VK_UUID_SIZE; i++) {
        QJsonValue jsonVal;
        jsonVal = props.pipelineCacheUUID[i];
        jsonPipelineCache.append(jsonVal);
    }
    jsonProperties["pipelineCacheUUID"] = jsonPipelineCache;
    root["properties"] = jsonProperties;

    // Device features
    QJsonObject jsonFeatures;
    root["features"] = QJsonObject::fromVariantMap(features);

    // Core 1.1
    if ((!core11Properties.empty()) || (!core11Features.empty())) {
        QJsonObject jsonCore11;
        if (!core11Properties.empty()) {
            jsonCore11["properties"] = QJsonObject::fromVariantMap(core11Properties);
        }
        if (!core11Features.empty()) {
            jsonCore11["features"] = QJsonObject::fromVariantMap(core11Features);
        }
        root["core11"] = jsonCore11;
    }

    // Core 1.2
    if ((!core12Properties.empty()) || (!core12Features.empty())) {
        QJsonObject jsonCore12;
        if (!core12Properties.empty()) {
            jsonCore12["properties"] = QJsonObject::fromVariantMap(core12Properties);
        }
        if (!core12Features.empty()) {
            jsonCore12["features"] = QJsonObject::fromVariantMap(core12Features);
        }
        root["core12"] = jsonCore12;
    }

    // Core 1.3
    if ((!core13Properties.empty()) || (!core13Features.empty())) {
        QJsonObject jsonCore13;
        if (!core13Properties.empty()) {
            jsonCore13["properties"] = QJsonObject::fromVariantMap(core13Properties);
        }
        if (!core13Features.empty()) {
            jsonCore13["features"] = QJsonObject::fromVariantMap(core13Features);
        }
        root["core13"] = jsonCore13;
    }

    // Extensions
    QJsonArray jsonExtensions;
    for (auto& ext : extensions)
    {
        QJsonObject jsonExt;
        jsonExt["extensionName"] = ext.extensionName;
        jsonExt["specVersion"] = int(ext.specVersion);
        jsonExtensions.append(jsonExt);
    }
    root["extensions"] = jsonExtensions;

    // Formats
    QJsonArray jsonFormats;
    for (auto& format : formats)
    {
        QJsonArray jsonFormat;
        jsonFormat.append((QJsonValue(format.format)));
        QJsonObject jsonFormatFeatures;
        jsonFormatFeatures["linearTilingFeatures"] = int(format.properties.linearTilingFeatures);
        jsonFormatFeatures["optimalTilingFeatures"] = int(format.properties.optimalTilingFeatures);
        jsonFormatFeatures["bufferFeatures"] = int(format.properties.bufferFeatures);
        jsonFormatFeatures["supported"] = format.supported;
        jsonFormat.append(jsonFormatFeatures);
        jsonFormats.append(jsonFormat);
    }
    root["formats"] = jsonFormats;

    // Layers
    QJsonArray jsonLayers;
    for (auto& layer : layers)
    {
        QJsonObject jsonLayer;
        jsonLayer["layerName"] = layer.properties.layerName;
        jsonLayer["description"] = layer.properties.description;
        jsonLayer["specVersion"] =  int(layer.properties.specVersion);
        jsonLayer["implementationVersion"] =  int(layer.properties.implementationVersion);
        QJsonArray jsonLayerExtensions;
        for (auto& ext : layer.extensions)
        {
            QJsonObject jsonExt;
            jsonExt["extensionName"] = ext.extensionName;
            jsonExt["specVersion"] = int(ext.specVersion);
            jsonLayerExtensions.append(jsonExt);
        }
        jsonLayer["extensions"] = jsonLayerExtensions;
        jsonLayers.append(jsonLayer);
    }
    root["layers"] = jsonLayers;

    // Queues
    QJsonArray jsonQueues;
    for (auto& queueFamily : queueFamilies)
    {
        QJsonObject jsonQueue;
        jsonQueue["queueFlags"] = int(queueFamily.properties.queueFlags);
        jsonQueue["queueCount"] = int(queueFamily.properties.queueCount);
        jsonQueue["timestampValidBits"] = int(queueFamily.properties.timestampValidBits);
        QJsonObject minImageTransferGranularity;
        minImageTransferGranularity["width"] =  int(queueFamily.properties.minImageTransferGranularity.width);
        minImageTransferGranularity["height"] =  int(queueFamily.properties.minImageTransferGranularity.height);
        minImageTransferGranularity["depth"] =  int(queueFamily.properties.minImageTransferGranularity.depth);
        jsonQueue["minImageTransferGranularity"] = minImageTransferGranularity;
        jsonQueue["supportsPresent"] = bool(queueFamily.supportsPresent);
        jsonQueues.append(jsonQueue);
    }
    root["queues"] = jsonQueues;

    // Memory properties
    QJsonObject jsonMemoryProperties;
    // Available memory types
    jsonMemoryProperties["memoryTypeCount"] = int(memoryProperties.memoryTypeCount);
    QJsonArray memtypes;
    for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++)
    {
        QJsonObject memtype;
        memtype["propertyFlags"] = int(memoryProperties.memoryTypes[i].propertyFlags);
        memtype["heapIndex"] = int(memoryProperties.memoryTypes[i].heapIndex);
        memtypes.append(memtype);
    }
    jsonMemoryProperties["memoryTypes"] = memtypes;
    // Memory heaps
    jsonMemoryProperties["memoryHeapCount"] = int(memoryProperties.memoryHeapCount);
    QJsonArray heaps;
    for (uint32_t i = 0; i < memoryProperties.memoryHeapCount; i++)
    {
        QJsonObject memheap;
        memheap["flags"] = int(memoryProperties.memoryHeaps[i].flags);
        memheap["size"] = QString::number(memoryProperties.memoryHeaps[i].size, 16).prepend("0x");
        heaps.append(memheap);
    }
    jsonMemoryProperties["memoryHeaps"] = heaps;
    root["memory"] = jsonMemoryProperties;

    // Surface capabilities
    QJsonObject jsonSurfaceCaps;
    jsonSurfaceCaps["validSurface"] = bool(surfaceInfo.validSurface);
    if (surfaceInfo.validSurface)
    {
        jsonSurfaceCaps["surfaceExtension"] = QString::fromStdString(surfaceInfo.surfaceExtension);
        jsonSurfaceCaps["minImageCount"] = int(surfaceInfo.capabilities.minImageCount);
        jsonSurfaceCaps["maxImageCount"] = int(surfaceInfo.capabilities.maxImageCount);
        jsonSurfaceCaps["maxImageArrayLayers"] =int(surfaceInfo.capabilities.maxImageArrayLayers);

        QJsonObject minImageExtent;
        minImageExtent["width"] = int(surfaceInfo.capabilities.minImageExtent.width);
        minImageExtent["height"] = int(surfaceInfo.capabilities.minImageExtent.height);
        jsonSurfaceCaps["minImageExtent"] = minImageExtent;

        QJsonObject maxImageExtent;
        maxImageExtent["width"] = int(surfaceInfo.capabilities.maxImageExtent.width);
        maxImageExtent["height"] = int(surfaceInfo.capabilities.maxImageExtent.height);
        jsonSurfaceCaps["maxImageExtent"] = maxImageExtent;

        jsonSurfaceCaps["supportedUsageFlags"] = int(surfaceInfo.capabilities.supportedUsageFlags);
        jsonSurfaceCaps["supportedTransforms"] = int(surfaceInfo.capabilities.supportedTransforms);
        jsonSurfaceCaps["supportedCompositeAlpha"] = int(surfaceInfo.capabilities.supportedCompositeAlpha);
        QJsonArray presentModes;
        for (uint32_t i = 0; i < surfaceInfo.presentModes.size(); i++) {
            presentModes.append(int(surfaceInfo.presentModes[i]));
        }
        jsonSurfaceCaps["presentmodes"] = presentModes;
        QJsonArray surfaceFormats;
        for (uint32_t i = 0; i < surfaceInfo.formats.size(); i++)
        {
            QJsonObject surfaceFormat;
            surfaceFormat["format"] = int(surfaceInfo.formats[i].format);
            surfaceFormat["colorSpace"] = int(surfaceInfo.formats[i].colorSpace);
            surfaceFormats.append(surfaceFormat);
        }
        jsonSurfaceCaps["surfaceformats"] = surfaceFormats;
    }
    root["surfacecapabilites"] = jsonSurfaceCaps;

    // Profiles
    QJsonArray jsonProfiles;
    for (auto& profile : profiles)
    {
        QJsonObject jsonProfile;
        jsonProfile["profileName"] = QString::fromStdString(profile.profileName);
        jsonProfile["specVersion"] = int(profile.specVersion);
        jsonProfile["supported"] = profile.supported;
        jsonProfiles.append(jsonProfile);
    }
    root["profiles"] = jsonProfiles;

    // Platform specific details
    QJsonObject jsonPlatformDetail;
    for (auto& detail : platformdetails)
    {
        jsonPlatformDetail[QString::fromStdString(detail.first)] = QString::fromStdString(detail.second);
    }
    root["platformdetails"] = jsonPlatformDetail;

    // Environment
    QJsonObject jsonEnv;
    jsonEnv["name"] = QString::fromStdString(os.name);
    jsonEnv["version"] = QString::fromStdString(os.version);
    jsonEnv["architecture"] = QString::fromStdString(os.architecture);
    jsonEnv["submitter"] = submitter;
    jsonEnv["comment"] = comment;
    jsonEnv["reportversion"] = reportVersion;
    jsonEnv["appversion"] = appVersion;
    root["environment"] = jsonEnv;

    QJsonObject jsonExtended;

    // VK_KHR_get_physical_device_properties2
    // Device properties 2
    QJsonArray jsonProperties2;
    for (auto& property2 : properties2) {
        QJsonObject jsonProperty2;
        jsonProperty2["name"] = QString::fromStdString(property2.name);
        jsonProperty2["extension"] = QString::fromUtf8(property2.extension);        
        if (property2.value.canConvert(QMetaType::QVariantList)) {
            jsonProperty2["value"] = QJsonArray::fromVariantList(property2.value.toList());
        } else {
            jsonProperty2["value"] = property2.value.toString();
        }
        jsonProperties2.append(jsonProperty2);
    }
    jsonExtended["deviceproperties2"] = jsonProperties2;

    // Device features 2
    QJsonArray jsonFeatures2;
    for (auto& feature2 : features2) {
        QJsonObject jsonFeature2;
        jsonFeature2["name"] = QString::fromStdString(feature2.name);
        jsonFeature2["extension"] = QString::fromUtf8(feature2.extension);
        jsonFeature2["supported"] = bool(feature2.supported);
        jsonFeatures2.append(jsonFeature2);
    }
    jsonExtended["devicefeatures2"] = jsonFeatures2;

    root["extended"] = jsonExtended;

    return root;
}
