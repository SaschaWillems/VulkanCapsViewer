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

#pragma once

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
public:
	uint32_t id;

    QVariantMap properties;
    QVariantMap sparseProperties;

    QVariantMap limits;
    QVariantMap features;
    std::map<std::string, std::string> platformdetails;

    // VK_KHR_get_physical_device_properties2
    std::vector<Feature2> features2;
    std::vector<Property2> properties2;

	VkPhysicalDevice device;
	VkDevice dev;

	VkPhysicalDeviceProperties props;
	VkPhysicalDeviceMemoryProperties memoryProperties;
	VkPhysicalDeviceFeatures deviceFeatures;

    bool hasSubgroupProperties = false;
    QVariantMap subgroupProperties;

    VkPhysicalDeviceProperties2KHR deviceProperties2;
    VkPhysicalDeviceFeatures2KHR deviceFeatures2;

	std::vector<VkExtensionProperties> extensions;
    std::vector<VulkanQueueFamilyInfo> queueFamilies;

	int32_t supportedFormatCount;
	std::vector<VulkanFormatInfo> formats;

    VulkanSurfaceInfo surfaceInfo;

	OSInfo os;

	std::string reportVersion;

	std::vector<VulkanLayerInfo> getLayers()
	{
		return layers;
	}

    /// <summary>
    ///	Returns true if device supports Vulkan 1.1 (or above)
    /// </summary>
    bool vulkan_1_1()
    {
        uint32_t major = VK_VERSION_MAJOR(props.apiVersion);
        uint32_t minor = VK_VERSION_MINOR(props.apiVersion);
        return ((major > 1) || ((major == 1) && (minor >= 1)));
    }

	/// <summary>
	///	Get list of global extensions for this device (not specific to any layer)
	/// </summary>
	void readExtensions()
	{
		assert(device != NULL);
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

    /// <summary>
    ///	Checks if the given extension is supported on this device
    /// </summary>
    bool extensionSupported(const char* extensionName)
    {
        for (auto& ext : extensions) {
            if (strcmp(ext.extensionName, extensionName) == 0) {
                return true;
            }
        }
        return false;
    }

	/// <summary>
	///	Get list of available device layers
	/// </summary>
	void readLayers()
	{
		assert(device != NULL);
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

	/// <summary>
	///	Get list of all supported image formats
	/// </summary>
	void readSupportedFormats()
	{
		supportedFormatCount = 0;
		assert(device != NULL);
        // Base formats
        for (int32_t format = VK_FORMAT_BEGIN_RANGE+1; format < VK_FORMAT_END_RANGE+1; format++) {
			VulkanFormatInfo formatInfo = {};
			formatInfo.format = (VkFormat)format;
			vkGetPhysicalDeviceFormatProperties(device, formatInfo.format, &formatInfo.properties);
			formatInfo.supported =
				(formatInfo.properties.linearTilingFeatures != 0) |
				(formatInfo.properties.optimalTilingFeatures != 0) |
				(formatInfo.properties.bufferFeatures != 0);			
			formats.push_back(formatInfo);
			if (formatInfo.supported)
				supportedFormatCount++;
		}
        // VK_KHR_sampler_ycbcr_conversion
        if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
            for (int32_t format = VK_FORMAT_G8B8G8R8_422_UNORM; format < VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM; format++) {
                VulkanFormatInfo formatInfo = {};
                formatInfo.format = (VkFormat)format;
                vkGetPhysicalDeviceFormatProperties(device, formatInfo.format, &formatInfo.properties);
                formatInfo.supported =
                    (formatInfo.properties.linearTilingFeatures != 0) |
                    (formatInfo.properties.optimalTilingFeatures != 0) |
                    (formatInfo.properties.bufferFeatures != 0);
                formats.push_back(formatInfo);
                if (formatInfo.supported)
                    supportedFormatCount++;
            }
        }
	}

	/// <summary>
    ///	Get list of available device queue families
	/// </summary>
    void readQueueFamilies()
	{
		assert(device != NULL);
		uint32_t queueCount;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, NULL);
		assert(queueCount > 0);
		std::vector<VkQueueFamilyProperties> qs(queueCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, &qs.front());
        uint32_t index = 0;
		for (auto& q : qs)
        {
            VulkanQueueFamilyInfo queueFamilyInfo{};
            queueFamilyInfo.properties = q;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
            queueFamilyInfo.supportsPresent = vkGetPhysicalDeviceWin32PresentationSupportKHR(device, index);
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
            // On Android all physical devices and queue families must support present
            queueFamilyInfo.supportsPresent = true;
#elif defined(VK_USE_PLATFORM_XCB_KHR)
            // todo
//            queueFamilyInfo.supportsPresent = PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR(device, index);
#endif
            queueFamilies.push_back(queueFamilyInfo);
            index++;
        }
	}

    /// <summary>
    ///	Convert raw driver version read via api depending on
    /// vendor conventions
    /// </summary>
    std::string getDriverVersion()
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

	/// <summary>
	///	Request physical device properties
	/// </summary>
	void readPhysicalProperties()
	{
		assert(device != NULL);
		vkGetPhysicalDeviceProperties(device, &props);

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
        if (pfnGetPhysicalDeviceProperties2KHR) {
            // VK_KHR_multiview
            if (extensionSupported(VK_KHR_MULTIVIEW_EXTENSION_NAME)) {
                const char* extName(VK_KHR_MULTIVIEW_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceMultiviewPropertiesKHR extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxMultiviewViewCount", QString::number(extProps.maxMultiviewViewCount), extName));
                properties2.push_back(Property2("maxMultiviewInstanceIndex", QString::number(extProps.maxMultiviewInstanceIndex), extName));
            }
            // VK_KHR_push_descriptor
            if (extensionSupported(VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDevicePushDescriptorPropertiesKHR extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxPushDescriptors", QString::number(extProps.maxPushDescriptors), VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME));
            }
            // VK_EXT_discard_rectangles
            if (extensionSupported(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceDiscardRectanglePropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxDiscardRectangles", QString::number(extProps.maxDiscardRectangles), VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME));
            }
            // VK_NVX_multiview_per_view_attributes
            if (extensionSupported(VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("perViewPositionAllComponents", QVariant(bool(extProps.perViewPositionAllComponents)), VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME));
            }
            // VK_EXT_conservative_rasterization
            if (extensionSupported(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME)) {
                const char* extName(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceConservativeRasterizationPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("primitiveOverestimationSize", QString::number(extProps.primitiveOverestimationSize), extName));
                properties2.push_back(Property2("maxExtraPrimitiveOverestimationSize", QString::number(extProps.maxExtraPrimitiveOverestimationSize), extName));
                properties2.push_back(Property2("extraPrimitiveOverestimationSizeGranularity", QString::number(extProps.extraPrimitiveOverestimationSizeGranularity), extName));
                properties2.push_back(Property2("primitiveUnderestimation", QVariant(bool(extProps.primitiveUnderestimation)), extName));
                properties2.push_back(Property2("conservativePointAndLineRasterization", QVariant(bool(extProps.conservativePointAndLineRasterization)), extName));
                properties2.push_back(Property2("degenerateTrianglesRasterized", QVariant(bool(extProps.degenerateTrianglesRasterized)), extName));
                properties2.push_back(Property2("degenerateLinesRasterized", QVariant(bool(extProps.degenerateLinesRasterized)), extName));
                properties2.push_back(Property2("fullyCoveredFragmentShaderInputVariable", QVariant(bool(extProps.fullyCoveredFragmentShaderInputVariable)), extName));
                properties2.push_back(Property2("conservativeRasterizationPostDepthCoverage", QVariant(bool(extProps.conservativeRasterizationPostDepthCoverage)), extName));
            }
            // VK_EXT_sampler_filter_minmax
            if (extensionSupported(VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("filterMinmaxSingleComponentFormats", QVariant(bool(extProps.filterMinmaxSingleComponentFormats)), VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME));
                properties2.push_back(Property2("filterMinmaxImageComponentMapping", QVariant(bool(extProps.filterMinmaxImageComponentMapping)), VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME));
            }
            // VK_EXT_sample_locations
            if (extensionSupported(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME)) {
                const char* extName(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceSampleLocationsPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("sampleLocationSampleCounts", QString::number(extProps.sampleLocationSampleCounts), extName));
                properties2.push_back(Property2("maxSampleLocationGridSize.width", QString::number(extProps.maxSampleLocationGridSize.width), extName));
                properties2.push_back(Property2("maxSampleLocationGridSize.height", QString::number(extProps.maxSampleLocationGridSize.height), extName));
                properties2.push_back(Property2("sampleLocationCoordinateRange[0]", QString::number(extProps.sampleLocationCoordinateRange[0]), extName));
                properties2.push_back(Property2("sampleLocationCoordinateRange[1]", QString::number(extProps.sampleLocationCoordinateRange[1]), extName));
                properties2.push_back(Property2("sampleLocationSubPixelBits", QString::number(extProps.sampleLocationSubPixelBits), extName));
                properties2.push_back(Property2("variableSampleLocations", QVariant(bool(extProps.variableSampleLocations)), extName));
            }
            // VK_EXT_blend_operation_advanced
            if (extensionSupported(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME)) {
                const char* extName(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("advancedBlendMaxColorAttachments", QVariant(extProps.advancedBlendMaxColorAttachments), extName));
                properties2.push_back(Property2("advancedBlendIndependentBlend", QVariant(bool(extProps.advancedBlendIndependentBlend)), extName));
                properties2.push_back(Property2("advancedBlendNonPremultipliedSrcColor", QVariant(bool(extProps.advancedBlendNonPremultipliedSrcColor)), extName));
                properties2.push_back(Property2("advancedBlendNonPremultipliedDstColor", QVariant(bool(extProps.advancedBlendNonPremultipliedDstColor)), extName));
                properties2.push_back(Property2("advancedBlendCorrelatedOverlap", QVariant(bool(extProps.advancedBlendCorrelatedOverlap)), extName));
                properties2.push_back(Property2("advancedBlendAllOperations", QVariant(bool(extProps.advancedBlendAllOperations)), extName));
            }
            // VK_KHR_sampler_ycbcr_conversion
            if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkSamplerYcbcrConversionImageFormatPropertiesKHR extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("combinedImageSamplerDescriptorCount", QVariant(extProps.combinedImageSamplerDescriptorCount), VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME));
            }
            // VK_EXT_descriptor_indexing
            if (extensionSupported(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)) {
                const char* extName(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceDescriptorIndexingPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxUpdateAfterBindDescriptorsInAllPools", QVariant(extProps.maxUpdateAfterBindDescriptorsInAllPools), extName));
                properties2.push_back(Property2("shaderUniformBufferArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderUniformBufferArrayNonUniformIndexingNative)), extName));
                properties2.push_back(Property2("shaderSampledImageArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderSampledImageArrayNonUniformIndexingNative)), extName));
                properties2.push_back(Property2("shaderStorageBufferArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderStorageBufferArrayNonUniformIndexingNative)), extName));
                properties2.push_back(Property2("shaderStorageImageArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderStorageImageArrayNonUniformIndexingNative)), extName));
                properties2.push_back(Property2("shaderInputAttachmentArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderInputAttachmentArrayNonUniformIndexingNative)), extName));
                properties2.push_back(Property2("robustBufferAccessUpdateAfterBind", QVariant(bool(extProps.robustBufferAccessUpdateAfterBind)), extName));
                properties2.push_back(Property2("quadDivergentImplicitLod", QVariant(bool(extProps.quadDivergentImplicitLod)), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindSamplers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindSamplers), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindUniformBuffers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindUniformBuffers), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindStorageBuffers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindStorageBuffers), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindSampledImages", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindSampledImages), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindStorageImages", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindStorageImages), extName));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindInputAttachments", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindInputAttachments), extName));
                properties2.push_back(Property2("maxPerStageUpdateAfterBindResources", QVariant(extProps.maxPerStageUpdateAfterBindResources), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindSamplers", QVariant(extProps.maxDescriptorSetUpdateAfterBindSamplers), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindUniformBuffers", QVariant(extProps.maxDescriptorSetUpdateAfterBindUniformBuffers), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", QVariant(extProps.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindStorageBuffers", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageBuffers), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindSampledImages", QVariant(extProps.maxDescriptorSetUpdateAfterBindSampledImages), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindStorageImages", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageImages), extName));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindInputAttachments", QVariant(extProps.maxDescriptorSetUpdateAfterBindInputAttachments), extName));
            }
            // VK_EXT_inline_uniform_block
            if (extensionSupported(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceInlineUniformBlockPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxInlineUniformBlockSize", QVariant(extProps.maxInlineUniformBlockSize), VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
                properties2.push_back(Property2("maxPerStageDescriptorInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorInlineUniformBlocks), VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
                properties2.push_back(Property2("maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks), VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
                properties2.push_back(Property2("maxDescriptorSetInlineUniformBlocks", QVariant(extProps.maxDescriptorSetInlineUniformBlocks), VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
                properties2.push_back(Property2("maxDescriptorSetUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxDescriptorSetUpdateAfterBindInlineUniformBlocks), VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
            }
            // VK_EXT_vertex_attribute_divisor
            if (extensionSupported(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME)) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                properties2.push_back(Property2("maxVertexAttribDivisor", QVariant(extProps.maxVertexAttribDivisor), VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME));
            }
            // VK 1.1 core
            if (vulkan_1_1()) {
                VkPhysicalDeviceProperties2KHR deviceProps2{};
                VkPhysicalDeviceSubgroupProperties extProps{};
                extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
                deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
                deviceProps2.pNext = &extProps;
                pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
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
                    pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
                    properties2.push_back(Property2("maxPerSetDescriptors", QVariant(extProps.maxPerSetDescriptors), extName));
                    properties2.push_back(Property2("maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize), extName));
                }
            }
        }
	}
	
	/// <summary>
	///	Request physical device features
	/// </summary>
	void readPhysicalFeatures()
	{
		assert(device != NULL);
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
        if (pfnGetPhysicalDeviceFeatures2KHR) {
            // VK_KHX_multiview
            if (extensionSupported(VK_KHR_MULTIVIEW_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceMultiviewFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("multiview", extFeatures.multiview, VK_KHR_MULTIVIEW_EXTENSION_NAME));
                features2.push_back(Feature2("multiviewGeometryShader", extFeatures.multiviewGeometryShader, VK_KHR_MULTIVIEW_EXTENSION_NAME));
                features2.push_back(Feature2("multiviewTessellationShader", extFeatures.multiviewTessellationShader, VK_KHR_MULTIVIEW_EXTENSION_NAME));
            }
            // VK_KHR_variable_pointers
            if (extensionSupported(VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceVariablePointerFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("variablePointersStorageBuffer", extFeatures.variablePointersStorageBuffer, VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME));
                features2.push_back(Feature2("variablePointers", extFeatures.variablePointers, VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME));
            }
            // VK_KHR_16bit_storage
            if (extensionSupported(VK_KHR_16BIT_STORAGE_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDevice16BitStorageFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("storageBuffer16BitAccess", extFeatures.storageBuffer16BitAccess, VK_KHR_16BIT_STORAGE_EXTENSION_NAME));
                features2.push_back(Feature2("uniformAndStorageBuffer16BitAccess", extFeatures.uniformAndStorageBuffer16BitAccess, VK_KHR_16BIT_STORAGE_EXTENSION_NAME));
                features2.push_back(Feature2("storagePushConstant16", extFeatures.storagePushConstant16, VK_KHR_16BIT_STORAGE_EXTENSION_NAME));
                features2.push_back(Feature2("storageInputOutput16", extFeatures.storageInputOutput16, VK_KHR_16BIT_STORAGE_EXTENSION_NAME));
            }
            // VK_EXT_blend_operation_advanced
            if (extensionSupported(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("advancedBlendCoherentOperations", extFeatures.advancedBlendCoherentOperations, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME));
            }
            // VK_KHR_sampler_ycbcr_conversion
            if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("samplerYcbcrConversion", extFeatures.samplerYcbcrConversion, VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME));
            }
            // VK_EXT_descriptor_indexing
            if (extensionSupported(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)) {
                const char* extName(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceDescriptorIndexingFeaturesEXT extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("shaderInputAttachmentArrayDynamicIndexing", extFeatures.shaderInputAttachmentArrayDynamicIndexing, extName));
                features2.push_back(Feature2("shaderUniformTexelBufferArrayDynamicIndexing", extFeatures.shaderUniformTexelBufferArrayDynamicIndexing, extName));
                features2.push_back(Feature2("shaderStorageTexelBufferArrayDynamicIndexing", extFeatures.shaderStorageTexelBufferArrayDynamicIndexing, extName));
                features2.push_back(Feature2("shaderUniformBufferArrayNonUniformIndexing", extFeatures.shaderUniformBufferArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderSampledImageArrayNonUniformIndexing", extFeatures.shaderSampledImageArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderStorageBufferArrayNonUniformIndexing", extFeatures.shaderStorageBufferArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderStorageImageArrayNonUniformIndexing", extFeatures.shaderStorageImageArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderInputAttachmentArrayNonUniformIndexing", extFeatures.shaderInputAttachmentArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderUniformTexelBufferArrayNonUniformIndexing", extFeatures.shaderUniformTexelBufferArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("shaderStorageTexelBufferArrayNonUniformIndexing", extFeatures.shaderStorageTexelBufferArrayNonUniformIndexing, extName));
                features2.push_back(Feature2("descriptorBindingUniformBufferUpdateAfterBind", extFeatures.descriptorBindingUniformBufferUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingSampledImageUpdateAfterBind", extFeatures.descriptorBindingSampledImageUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingStorageImageUpdateAfterBind", extFeatures.descriptorBindingStorageImageUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingStorageBufferUpdateAfterBind", extFeatures.descriptorBindingStorageBufferUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingUniformTexelBufferUpdateAfterBind", extFeatures.descriptorBindingUniformTexelBufferUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingStorageTexelBufferUpdateAfterBind", extFeatures.descriptorBindingStorageTexelBufferUpdateAfterBind, extName));
                features2.push_back(Feature2("descriptorBindingUpdateUnusedWhilePending", extFeatures.descriptorBindingUpdateUnusedWhilePending, extName));
                features2.push_back(Feature2("descriptorBindingPartiallyBound", extFeatures.descriptorBindingPartiallyBound, extName));
                features2.push_back(Feature2("descriptorBindingVariableDescriptorCount", extFeatures.descriptorBindingVariableDescriptorCount, extName));
                features2.push_back(Feature2("runtimeDescriptorArray", extFeatures.runtimeDescriptorArray, extName));
            }
            // VK_KHR_8bit_storage
            if (extensionSupported(VK_KHR_8BIT_STORAGE_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDevice8BitStorageFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("storageBuffer8BitAccess", extFeatures.storageBuffer8BitAccess, VK_KHR_8BIT_STORAGE_EXTENSION_NAME));
                features2.push_back(Feature2("uniformAndStorageBuffer8BitAccess", extFeatures.uniformAndStorageBuffer8BitAccess, VK_KHR_8BIT_STORAGE_EXTENSION_NAME));
                features2.push_back(Feature2("storagePushConstant8", extFeatures.storagePushConstant8, VK_KHR_8BIT_STORAGE_EXTENSION_NAME));
            }
            // VK_EXT_conditional_rendering
            if (extensionSupported(VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceConditionalRenderingFeaturesEXT extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("conditionalRendering", extFeatures.conditionalRendering, VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME));
                features2.push_back(Feature2("inheritedConditionalRendering", extFeatures.inheritedConditionalRendering, VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME));
            }
            // VK_EXT_inline_uniform_block
            if (extensionSupported(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceInlineUniformBlockFeaturesEXT extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("inlineUniformBlock", extFeatures.inlineUniformBlock, VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
                features2.push_back(Feature2("descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures.descriptorBindingInlineUniformBlockUpdateAfterBind, VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME));
            }
            // VK_KHR_vulkan_memory_model
            if (extensionSupported(VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceVulkanMemoryModelFeaturesKHR extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("vulkanMemoryModel", extFeatures.vulkanMemoryModel, VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME));
                features2.push_back(Feature2("vulkanMemoryModelDeviceScope", extFeatures.vulkanMemoryModelDeviceScope, VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME));
            }
            // VK_EXT_vertex_attribute_divisor
            if (extensionSupported(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME)) {
                VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT extFeatures{};
                extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
                deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                deviceFeatures2.pNext = &extFeatures;
                pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                features2.push_back(Feature2("vertexAttributeInstanceRateDivisor", extFeatures.vertexAttributeInstanceRateDivisor, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME));
                features2.push_back(Feature2("vertexAttributeInstanceRateZeroDivisor", extFeatures.vertexAttributeInstanceRateZeroDivisor, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME));
            }
            // VK 1.1 Core
            if (vulkan_1_1()) {
                // VK_KHR_shader_draw_parameters
                if (extensionSupported(VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME)) {
                    VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
                    VkPhysicalDeviceShaderDrawParameterFeatures extFeatures{};
                    extFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES;
                    deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
                    deviceFeatures2.pNext = &extFeatures;
                    pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
                    features2.push_back(Feature2("shaderDrawParameters", extFeatures.shaderDrawParameters, VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME));
                }
            }

        }
	}

    QString toHexQString(VkDeviceSize deviceSize)
    {
        return QString::fromStdString(vulkanResources::toHexString(deviceSize));
    }

	/// <summary>
	///	Copy physical device limits into a map
	/// </summary>
	void readPhysicalLimits()
	{
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

	/// <summary>
	///	Request physical memory properties
	/// </summary>
	void readPhysicalMemoryProperties()
	{
		assert(device != NULL);
        vkGetPhysicalDeviceMemoryProperties(device, &memoryProperties);
	}

    /// <summary>
    ///	Read OS dependent surface information
    /// </summary>
    void readSurfaceInfo(VkSurfaceKHR surface, std::string surfaceExtension)
    {
        assert(device != NULL);
        surfaceInfo.validSurface = (surface != VK_NULL_HANDLE);
        surfaceInfo.surfaceExtension = surfaceExtension;
        surfaceInfo.get(device, surface);
    }

#if defined(__ANDROID__)
    std::string getSystemProperty(char* propname)
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

    /// <summary>
    ///	Read platform specific detail info
    /// </summary>
    void readPlatformDetails()
    {
        // Android specific build info
#if defined(__ANDROID__)
        platformdetails["android.ProductModel"] = getSystemProperty("ro.product.model");
        platformdetails["android.ProductManufacturer"] = getSystemProperty("ro.product.manufacturer");
        platformdetails["android.BuildID"] = getSystemProperty("ro.build.id");
        platformdetails["android.BuildVersionIncremental"] = getSystemProperty("ro.build.version.incremental");
#endif
    }

    /// <summary>
    ///	Return device information as a Json object
    /// </summary>
    QJsonObject toJson(std::string fileName, std::string submitter, std::string comment)
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
        root["features"] = QJsonObject::fromVariantMap(features);

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
		jsonEnv["submitter"] = QString::fromStdString(submitter);
		jsonEnv["comment"] = QString::fromStdString(comment);
		jsonEnv["reportversion"] = QString::fromStdString(reportVersion);
		root["environment"] = jsonEnv;

#define EXTENDED_PROPS
#if defined(EXTENDED_PROPS)
        QJsonObject jsonExtended;

        // VK_KHR_get_physical_device_properties2
        // Device properties 2
        QJsonArray jsonProperties2;
        for (auto& property2 : properties2) {
            QJsonObject jsonProperty2;
            jsonProperty2["name"] = QString::fromStdString(property2.name);
            jsonProperty2["extension"] = QString::fromLatin1(property2.extension);
            jsonProperty2["value"] = property2.value.toString();
            jsonProperties2.append(jsonProperty2);
        }
        jsonExtended["deviceproperties2"] = jsonProperties2;

        // Device features 2
        QJsonArray jsonFeatures2;
        for (auto& feature2 : features2) {
            QJsonObject jsonFeature2;
            jsonFeature2["name"] = QString::fromStdString(feature2.name);
            jsonFeature2["extension"] = QString::fromLatin1(feature2.extension);
            jsonFeature2["supported"] = bool(feature2.supported);
            jsonFeatures2.append(jsonFeature2);
        }
        jsonExtended["devicefeatures2"] = jsonFeatures2;

        root["extended"] = jsonExtended;
#endif

        return root;
	}

};
