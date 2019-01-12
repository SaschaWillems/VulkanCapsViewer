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

    /*
        Physical device properties
    */

    VkPhysicalDeviceProperties2 initDeviceProperties2(void * pNext) {
        VkPhysicalDeviceProperties2 props2{};
        props2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
        props2.pNext = pNext;
        return props2;
    }

    template<typename T>
    void pushProperty2(const char* extension, std::string name, T value) {
        properties2.push_back(Property2(name, QVariant(value), extension));
    }

    // Read physical device properties (2) for extensions from the KHR namespace
    void readPhysicalProperties_KHR() {
        // VK_KHR_multiview
        if (extensionSupported(VK_KHR_MULTIVIEW_EXTENSION_NAME)) {
            const char* extension(VK_KHR_MULTIVIEW_EXTENSION_NAME);
            VkPhysicalDeviceMultiviewPropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxMultiviewViewCount", QString::number(extProps.maxMultiviewViewCount));
            pushProperty2(extension, "maxMultiviewInstanceIndex", QString::number(extProps.maxMultiviewInstanceIndex));
        }
        // VK_KHR_push_descriptor
        if (extensionSupported(VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME)) {
            const char* extension(VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME);
            VkPhysicalDevicePushDescriptorPropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxPushDescriptors", QString::number(extProps.maxPushDescriptors));
        }
        // VK_KHR_sampler_ycbcr_conversion
        if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
            const char* extension(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME);
            VkSamplerYcbcrConversionImageFormatPropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "combinedImageSamplerDescriptorCount", QVariant(extProps.combinedImageSamplerDescriptorCount));
        }
        // VK_KHR_driver_properties
        if (extensionSupported(VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME)) {
            const char* extension(VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME);
            VkPhysicalDeviceDriverPropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "driverID", QString::fromStdString(vulkanResources::driverIdKHRString(static_cast<VkDriverIdKHR>(extProps.driverID))));
            pushProperty2(extension, "driverName", QString::fromStdString(extProps.driverName));
            pushProperty2(extension, "driverInfo", QString::fromStdString(extProps.driverInfo));
            pushProperty2(extension, "conformanceVersion", QString::fromStdString(vulkanResources::conformanceVersionKHRString(extProps.conformanceVersion)));
        }
        // VK_KHR_shader_float_controls
        if (extensionSupported(VK_KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME)) {
            const char* extension(VK_KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME);
            VkPhysicalDeviceFloatControlsPropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "separateDenormSettings",  QVariant(bool(extProps.separateDenormSettings)));
            pushProperty2(extension, "separateRoundingModeSettings",  QVariant(bool(extProps.separateRoundingModeSettings)));
            pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat16",  QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat16)));
            pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat32",  QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat32)));
            pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat64",  QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat64)));
            pushProperty2(extension, "shaderDenormPreserveFloat16",  QVariant(bool(extProps.shaderDenormPreserveFloat16)));
            pushProperty2(extension, "shaderDenormPreserveFloat32",  QVariant(bool(extProps.shaderDenormPreserveFloat32)));
            pushProperty2(extension, "shaderDenormPreserveFloat64",  QVariant(bool(extProps.shaderDenormPreserveFloat64)));
            pushProperty2(extension, "shaderDenormFlushToZeroFloat16",  QVariant(bool(extProps.shaderDenormFlushToZeroFloat16)));
            pushProperty2(extension, "shaderDenormFlushToZeroFloat32",  QVariant(bool(extProps.shaderDenormFlushToZeroFloat32)));
            pushProperty2(extension, "shaderDenormFlushToZeroFloat64",  QVariant(bool(extProps.shaderDenormFlushToZeroFloat64)));
            pushProperty2(extension, "shaderRoundingModeRTEFloat16",  QVariant(bool(extProps.shaderRoundingModeRTEFloat16)));
            pushProperty2(extension, "shaderRoundingModeRTEFloat32",  QVariant(bool(extProps.shaderRoundingModeRTEFloat32)));
            pushProperty2(extension, "shaderRoundingModeRTEFloat64",  QVariant(bool(extProps.shaderRoundingModeRTEFloat64)));
            pushProperty2(extension, "shaderRoundingModeRTZFloat16",  QVariant(bool(extProps.shaderRoundingModeRTZFloat16)));
            pushProperty2(extension, "shaderRoundingModeRTZFloat32",  QVariant(bool(extProps.shaderRoundingModeRTZFloat32)));
            pushProperty2(extension, "shaderRoundingModeRTZFloat64",  QVariant(bool(extProps.shaderRoundingModeRTZFloat64)));
        }
        // VK_KHR_depth_stencil_resolve
        if (extensionSupported(VK_KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME )) {
            const char* extension(VK_KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME );
            VkPhysicalDeviceDepthStencilResolvePropertiesKHR extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "supportedDepthResolveModes",  QVariant(uint64_t(extProps.supportedDepthResolveModes)));
            pushProperty2(extension, "supportedStencilResolveModes",  QVariant(uint64_t(extProps.supportedStencilResolveModes)));
            pushProperty2(extension, "independentResolveNone",  QVariant(bool(extProps.independentResolveNone)));
            pushProperty2(extension, "independentResolve",  QVariant(bool(extProps.independentResolve)));
        }
    }

    // Read physical device properties (2) for extensions from the EXT namespace
    void readPhysicalProperties_EXT() {
        // VK_EXT_discard_rectangles
        if (extensionSupported(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME)) {
            const char* extension(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME);
            VkPhysicalDeviceDiscardRectanglePropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxDiscardRectangles", QString::number(extProps.maxDiscardRectangles));
        }
        // VK_EXT_conservative_rasterization
        if (extensionSupported(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME)) {
            const char* extension(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME);
            VkPhysicalDeviceConservativeRasterizationPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "primitiveOverestimationSize", QString::number(extProps.primitiveOverestimationSize));
            pushProperty2(extension, "maxExtraPrimitiveOverestimationSize", QString::number(extProps.maxExtraPrimitiveOverestimationSize));
            pushProperty2(extension, "extraPrimitiveOverestimationSizeGranularity", QString::number(extProps.extraPrimitiveOverestimationSizeGranularity));
            pushProperty2(extension, "primitiveUnderestimation", QVariant(bool(extProps.primitiveUnderestimation)));
            pushProperty2(extension, "conservativePointAndLineRasterization", QVariant(bool(extProps.conservativePointAndLineRasterization)));
            pushProperty2(extension, "degenerateTrianglesRasterized", QVariant(bool(extProps.degenerateTrianglesRasterized)));
            pushProperty2(extension, "degenerateLinesRasterized", QVariant(bool(extProps.degenerateLinesRasterized)));
            pushProperty2(extension, "fullyCoveredFragmentShaderInputVariable", QVariant(bool(extProps.fullyCoveredFragmentShaderInputVariable)));
            pushProperty2(extension, "conservativeRasterizationPostDepthCoverage", QVariant(bool(extProps.conservativeRasterizationPostDepthCoverage)));
        }
        // VK_EXT_sampler_filter_minmax
        if (extensionSupported(VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME)) {
            const char* extension(VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME);
            VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "filterMinmaxSingleComponentFormats", QVariant(bool(extProps.filterMinmaxSingleComponentFormats)));
            pushProperty2(extension, "filterMinmaxImageComponentMapping", QVariant(bool(extProps.filterMinmaxImageComponentMapping)));
        }
        // VK_EXT_sample_locations
        if (extensionSupported(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME)) {
            const char* extension(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME);
            VkPhysicalDeviceSampleLocationsPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "sampleLocationSampleCounts", QString::number(extProps.sampleLocationSampleCounts));
            pushProperty2(extension, "maxSampleLocationGridSize.width", QString::number(extProps.maxSampleLocationGridSize.width));
            pushProperty2(extension, "maxSampleLocationGridSize.height", QString::number(extProps.maxSampleLocationGridSize.height));
            pushProperty2(extension, "sampleLocationCoordinateRange[0]", QString::number(extProps.sampleLocationCoordinateRange[0]));
            pushProperty2(extension, "sampleLocationCoordinateRange[1]", QString::number(extProps.sampleLocationCoordinateRange[1]));
            pushProperty2(extension, "sampleLocationSubPixelBits", QString::number(extProps.sampleLocationSubPixelBits));
            pushProperty2(extension, "variableSampleLocations", QVariant(bool(extProps.variableSampleLocations)));
        }
        // VK_EXT_blend_operation_advanced
        if (extensionSupported(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME)) {
            const char* extension(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME);
            VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "advancedBlendMaxColorAttachments", QVariant(extProps.advancedBlendMaxColorAttachments));
            pushProperty2(extension, "advancedBlendIndependentBlend", QVariant(bool(extProps.advancedBlendIndependentBlend)));
            pushProperty2(extension, "advancedBlendNonPremultipliedSrcColor", QVariant(bool(extProps.advancedBlendNonPremultipliedSrcColor)));
            pushProperty2(extension, "advancedBlendNonPremultipliedDstColor", QVariant(bool(extProps.advancedBlendNonPremultipliedDstColor)));
            pushProperty2(extension, "advancedBlendCorrelatedOverlap", QVariant(bool(extProps.advancedBlendCorrelatedOverlap)));
            pushProperty2(extension, "advancedBlendAllOperations", QVariant(bool(extProps.advancedBlendAllOperations)));
        }
        // VK_EXT_descriptor_indexing
        if (extensionSupported(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)) {
            const char* extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
            VkPhysicalDeviceDescriptorIndexingPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxUpdateAfterBindDescriptorsInAllPools", QVariant(extProps.maxUpdateAfterBindDescriptorsInAllPools));
            pushProperty2(extension, "shaderUniformBufferArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderUniformBufferArrayNonUniformIndexingNative)));
            pushProperty2(extension, "shaderSampledImageArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderSampledImageArrayNonUniformIndexingNative)));
            pushProperty2(extension, "shaderStorageBufferArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderStorageBufferArrayNonUniformIndexingNative)));
            pushProperty2(extension, "shaderStorageImageArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderStorageImageArrayNonUniformIndexingNative)));
            pushProperty2(extension, "shaderInputAttachmentArrayNonUniformIndexingNative", QVariant(bool(extProps.shaderInputAttachmentArrayNonUniformIndexingNative)));
            pushProperty2(extension, "robustBufferAccessUpdateAfterBind", QVariant(bool(extProps.robustBufferAccessUpdateAfterBind)));
            pushProperty2(extension, "quadDivergentImplicitLod", QVariant(bool(extProps.quadDivergentImplicitLod)));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindSamplers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindSamplers));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindUniformBuffers));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindStorageBuffers));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindSampledImages", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindSampledImages));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindStorageImages", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindStorageImages));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindInputAttachments", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindInputAttachments));
            pushProperty2(extension, "maxPerStageUpdateAfterBindResources", QVariant(extProps.maxPerStageUpdateAfterBindResources));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindSamplers", QVariant(extProps.maxDescriptorSetUpdateAfterBindSamplers));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindUniformBuffers", QVariant(extProps.maxDescriptorSetUpdateAfterBindUniformBuffers));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", QVariant(extProps.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageBuffers", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageBuffers));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindSampledImages", QVariant(extProps.maxDescriptorSetUpdateAfterBindSampledImages));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageImages", QVariant(extProps.maxDescriptorSetUpdateAfterBindStorageImages));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindInputAttachments", QVariant(extProps.maxDescriptorSetUpdateAfterBindInputAttachments));
        }
        // VK_EXT_inline_uniform_block
        if (extensionSupported(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME)) {
            const char* extension(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME);
            VkPhysicalDeviceInlineUniformBlockPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxInlineUniformBlockSize", QVariant(extProps.maxInlineUniformBlockSize));
            pushProperty2(extension, "maxPerStageDescriptorInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorInlineUniformBlocks));
            pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks));
            pushProperty2(extension, "maxDescriptorSetInlineUniformBlocks", QVariant(extProps.maxDescriptorSetInlineUniformBlocks));
            pushProperty2(extension, "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxDescriptorSetUpdateAfterBindInlineUniformBlocks));
        }
        // VK_EXT_vertex_attribute_divisor
        if (extensionSupported(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME)) {
            const char* extension(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME);
            VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxVertexAttribDivisor", QVariant(extProps.maxVertexAttribDivisor));
        }
        // VK_EXT_transform_feedback
        if (extensionSupported(VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME)) {
            const char* extension(VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME);
            VkPhysicalDeviceTransformFeedbackPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxTransformFeedbackStreams", QVariant(extProps.maxTransformFeedbackStreams));
            pushProperty2(extension, "maxTransformFeedbackBuffers", QVariant(extProps.maxTransformFeedbackBuffers));
            pushProperty2(extension, "maxTransformFeedbackBufferSize", QVariant::fromValue(extProps.maxTransformFeedbackBufferSize));
            pushProperty2(extension, "maxTransformFeedbackStreamDataSize", QVariant(extProps.maxTransformFeedbackStreamDataSize));
            pushProperty2(extension, "maxTransformFeedbackBufferDataSize", QVariant(extProps.maxTransformFeedbackBufferDataSize));
            pushProperty2(extension, "maxTransformFeedbackBufferDataStride", QVariant(extProps.maxTransformFeedbackBufferDataStride));
            pushProperty2(extension, "transformFeedbackQueries", QVariant(bool(extProps.transformFeedbackQueries)));
            pushProperty2(extension, "transformFeedbackStreamsLinesTriangles", QVariant(bool(extProps.transformFeedbackStreamsLinesTriangles)));
            pushProperty2(extension, "transformFeedbackRasterizationStreamSelect", QVariant(bool(extProps.transformFeedbackRasterizationStreamSelect)));
            pushProperty2(extension, "transformFeedbackDraw", QVariant(bool(extProps.transformFeedbackDraw)));
        }
        // VK_EXT_fragment_density_map
        if (extensionSupported(VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME)) {
            const char* extension(VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME);
            VkPhysicalDeviceFragmentDensityMapPropertiesEXT extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "fragmentDensityInvocations", QVariant(bool(extProps.fragmentDensityInvocations)));
            pushProperty2(extension, "minFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps.minFragmentDensityTexelSize.width, extProps.minFragmentDensityTexelSize.height })));
            pushProperty2(extension, "maxFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps.maxFragmentDensityTexelSize.width, extProps.maxFragmentDensityTexelSize.height })));
        }
        // VK_EXT_pci_bus_info
        if (extensionSupported(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME )) {
            const char* extension(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME );
            VkPhysicalDevicePCIBusInfoPropertiesEXT  extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "pciDomain", QVariant(extProps.pciDomain));
            pushProperty2(extension, "pciBus", QVariant(extProps.pciBus));
            pushProperty2(extension, "pciDevice", QVariant(extProps.pciDevice));
            pushProperty2(extension, "pciFunction", QVariant(extProps.pciFunction));
        }
    }

    // Read physical device properties (2) for extensions from the AMD namespace
    void readPhysicalProperties_AMD() {
        // VK_AMD_shader_core_properties
        if (extensionSupported(VK_AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME)) {
            const char* extension(VK_AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME);
            VkPhysicalDeviceShaderCorePropertiesAMD extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "shaderEngineCount", extProps.shaderEngineCount);
            pushProperty2(extension, "shaderArraysPerEngineCount", extProps.shaderArraysPerEngineCount);
            pushProperty2(extension, "computeUnitsPerShaderArray", extProps.computeUnitsPerShaderArray);
            pushProperty2(extension, "simdPerComputeUnit", extProps.simdPerComputeUnit);
            pushProperty2(extension, "wavefrontsPerSimd", extProps.wavefrontsPerSimd);
            pushProperty2(extension, "wavefrontSize", extProps.wavefrontSize);
            pushProperty2(extension, "sgprsPerSimd", extProps.sgprsPerSimd);
            pushProperty2(extension, "minSgprAllocation", extProps.minSgprAllocation);
            pushProperty2(extension, "maxSgprAllocation", extProps.maxSgprAllocation);
            pushProperty2(extension, "sgprAllocationGranularity", extProps.sgprAllocationGranularity);
            pushProperty2(extension, "vgprsPerSimd", extProps.vgprsPerSimd);
            pushProperty2(extension, "minVgprAllocation", extProps.minVgprAllocation);
            pushProperty2(extension, "maxVgprAllocation", extProps.maxVgprAllocation);
            pushProperty2(extension, "vgprAllocationGranularity", extProps.vgprAllocationGranularity);
        }
    }

    // Read physical device properties (2) for extensions from the NV namespace
    void readPhysicalProperties_NV() {
        // VK_NVX_multiview_per_view_attributes
        if (extensionSupported(VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME)) {
            const char* extension(VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME);
            VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "perViewPositionAllComponents", QVariant(bool(extProps.perViewPositionAllComponents)));
        }
        // VK_NV_raytracing
        if (extensionSupported(VK_NV_RAY_TRACING_EXTENSION_NAME)) {
            const char* extension(VK_NV_RAY_TRACING_EXTENSION_NAME);
            VkPhysicalDeviceRayTracingPropertiesNV extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "shaderGroupHandleSize", QVariant(extProps.shaderGroupHandleSize));
            pushProperty2(extension, "maxRecursionDepth", QVariant(extProps.maxRecursionDepth));
            pushProperty2(extension, "maxShaderGroupStride", QVariant(extProps.maxShaderGroupStride));
            pushProperty2(extension, "shaderGroupBaseAlignment", QVariant(extProps.shaderGroupBaseAlignment));
            pushProperty2(extension, "maxGeometryCount", QVariant::fromValue(extProps.maxGeometryCount));
            pushProperty2(extension, "maxInstanceCount", QVariant::fromValue(extProps.maxInstanceCount));
            pushProperty2(extension, "maxTriangleCount", QVariant::fromValue(extProps.maxTriangleCount));
            pushProperty2(extension, "maxDescriptorSetAccelerationStructures", QVariant(extProps.maxDescriptorSetAccelerationStructures));
        }
        // VK_NV_mesh_shader
        if (extensionSupported(VK_NV_MESH_SHADER_EXTENSION_NAME)) {
            const char* extension(VK_NV_MESH_SHADER_EXTENSION_NAME);
            VkPhysicalDeviceMeshShaderPropertiesNV extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "maxDrawMeshTasksCount", QVariant(extProps.maxDrawMeshTasksCount));
            pushProperty2(extension, "maxTaskWorkGroupInvocations", QVariant(extProps.maxTaskWorkGroupInvocations));
            pushProperty2(extension, "maxTaskWorkGroupSize", QVariant::fromValue(QVariantList({ extProps.maxTaskWorkGroupSize[0], extProps.maxTaskWorkGroupSize[1], extProps.maxTaskWorkGroupSize[2] })));
            pushProperty2(extension, "maxTaskTotalMemorySize", QVariant(extProps.maxTaskTotalMemorySize));
            pushProperty2(extension, "maxTaskOutputCount", QVariant(extProps.maxTaskOutputCount));
            pushProperty2(extension, "maxMeshWorkGroupInvocations", QVariant(extProps.maxMeshWorkGroupInvocations));
            pushProperty2(extension, "maxMeshWorkGroupSize", QVariant::fromValue(QVariantList({ extProps.maxMeshWorkGroupSize[0], extProps.maxMeshWorkGroupSize[1], extProps.maxMeshWorkGroupSize[2] })));
            pushProperty2(extension, "maxMeshTotalMemorySize", QVariant(extProps.maxMeshTotalMemorySize));
            pushProperty2(extension, "maxMeshOutputVertices", QVariant(extProps.maxMeshOutputVertices));
            pushProperty2(extension, "maxMeshOutputPrimitives", QVariant(extProps.maxMeshOutputPrimitives));
            pushProperty2(extension, "maxMeshMultiviewViewCount", QVariant(extProps.maxMeshMultiviewViewCount));
            pushProperty2(extension, "meshOutputPerVertexGranularity", QVariant(extProps.meshOutputPerVertexGranularity));
            pushProperty2(extension, "meshOutputPerPrimitiveGranularity", QVariant(extProps.meshOutputPerPrimitiveGranularity));
        }
        // VK_NV_shading_rate_image
        if (extensionSupported(VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME)) {
            const char* extension(VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME);
            VkPhysicalDeviceShadingRateImagePropertiesNV extProps{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV };
            VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
            pfnGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
            pushProperty2(extension, "shadingRateTexelSize", QVariant::fromValue(QVariantList({ extProps.shadingRateTexelSize.width, extProps.shadingRateTexelSize.height })));
            pushProperty2(extension, "shadingRatePaletteSize", QVariant(extProps.shadingRatePaletteSize));
            pushProperty2(extension, "shadingRateMaxCoarseSamples", QVariant(extProps.shadingRateMaxCoarseSamples));
        }
    }

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

            readPhysicalProperties_EXT();
            readPhysicalProperties_KHR();
            readPhysicalProperties_AMD();
            readPhysicalProperties_NV();

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
                    properties2.push_back(Property2("maxPerSetDescriptors", QVariant::fromValue(extProps.maxPerSetDescriptors), extName));
                    properties2.push_back(Property2("maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize), extName));
                }
            }
        }
	}

    /*
        Physical device features
    */

    VkPhysicalDeviceFeatures2 initDeviceFeatures2(void *pNext) {
        VkPhysicalDeviceFeatures2 features2{};
        features2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
        features2.pNext = pNext;
        return features2;
    }

    void pushFeature2(const char* extension, std::string name, bool supported) {
        features2.push_back(Feature2(name, supported, extension));
    }

    // Read physical device features (2) for extensions from the KHR namespace
    void readPhysicalFeatures_KHR() {
        // VK_KHR_multiview
        if (extensionSupported(VK_KHR_MULTIVIEW_EXTENSION_NAME)) {
            const char* extension(VK_KHR_MULTIVIEW_EXTENSION_NAME);
            VkPhysicalDeviceMultiviewFeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "multiview", extFeatures.multiview);
            pushFeature2(extension, "multiviewGeometryShader", extFeatures.multiviewGeometryShader);
            pushFeature2(extension, "multiviewTessellationShader", extFeatures.multiviewTessellationShader);
        }
        // VK_KHR_variable_pointers
        if (extensionSupported(VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME)) {
            const char* extension(VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME);
            VkPhysicalDeviceVariablePointerFeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "variablePointersStorageBuffer", extFeatures.variablePointersStorageBuffer);
            pushFeature2(extension, "variablePointers", extFeatures.variablePointers);
        }
        // VK_KHR_16bit_storage
        if (extensionSupported(VK_KHR_16BIT_STORAGE_EXTENSION_NAME)) {
            const char* extension(VK_KHR_16BIT_STORAGE_EXTENSION_NAME);
            VkPhysicalDevice16BitStorageFeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "storageBuffer16BitAccess", extFeatures.storageBuffer16BitAccess);
            pushFeature2(extension, "uniformAndStorageBuffer16BitAccess", extFeatures.uniformAndStorageBuffer16BitAccess);
            pushFeature2(extension, "storagePushConstant16", extFeatures.storagePushConstant16);
            pushFeature2(extension, "storageInputOutput16", extFeatures.storageInputOutput16);
        }
        // VK_KHR_sampler_ycbcr_conversion
        if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
            const char* extension(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME);
            VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "samplerYcbcrConversion", extFeatures.samplerYcbcrConversion);
        }
        // VK_KHR_8bit_storage
        if (extensionSupported(VK_KHR_8BIT_STORAGE_EXTENSION_NAME)) {
            const char* extension(VK_KHR_8BIT_STORAGE_EXTENSION_NAME);
            VkPhysicalDevice8BitStorageFeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "storageBuffer8BitAccess", extFeatures.storageBuffer8BitAccess);
            pushFeature2(extension, "uniformAndStorageBuffer8BitAccess", extFeatures.uniformAndStorageBuffer8BitAccess);
            pushFeature2(extension, "storagePushConstant8", extFeatures.storagePushConstant8);
        }
        // VK_KHR_vulkan_memory_model
        if (extensionSupported(VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME)) {
            const char* extension(VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME);
            VkPhysicalDeviceVulkanMemoryModelFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "vulkanMemoryModel", extFeatures.vulkanMemoryModel);
            pushFeature2(extension, "vulkanMemoryModelDeviceScope", extFeatures.vulkanMemoryModelDeviceScope);
        }
        // VK_KHR_shader_atomic_int64
        if (extensionSupported(VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME)) {
            const char* extension(VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME);
            VkPhysicalDeviceShaderAtomicInt64FeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "shaderBufferInt64Atomics", extFeatures.shaderBufferInt64Atomics);
            pushFeature2(extension, "shaderSharedInt64Atomics", extFeatures.shaderSharedInt64Atomics);
        }
        // VK_KHR_shader_float16_int8
        if (extensionSupported(VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME)) {
            const char* extension(VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME);
            VkPhysicalDeviceFloat16Int8FeaturesKHR extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "shaderFloat16", extFeatures.shaderFloat16);
            pushFeature2(extension, "shaderInt8", extFeatures.shaderInt8);
        }
    }

    // Read physical device features (2) for extensions from the EXT namespace
    void readPhysicalFeatures_EXT() {
        // VK_EXT_blend_operation_advanced
        if (extensionSupported(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME)) {
            const char* extension(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME);
            VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "advancedBlendCoherentOperations", extFeatures.advancedBlendCoherentOperations);
        }
        // VK_EXT_descriptor_indexing
        if (extensionSupported(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)) {
            const char* extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "shaderInputAttachmentArrayDynamicIndexing", extFeatures.shaderInputAttachmentArrayDynamicIndexing);
            pushFeature2(extension, "shaderUniformTexelBufferArrayDynamicIndexing", extFeatures.shaderUniformTexelBufferArrayDynamicIndexing);
            pushFeature2(extension, "shaderStorageTexelBufferArrayDynamicIndexing", extFeatures.shaderStorageTexelBufferArrayDynamicIndexing);
            pushFeature2(extension, "shaderUniformBufferArrayNonUniformIndexing", extFeatures.shaderUniformBufferArrayNonUniformIndexing);
            pushFeature2(extension, "shaderSampledImageArrayNonUniformIndexing", extFeatures.shaderSampledImageArrayNonUniformIndexing);
            pushFeature2(extension, "shaderStorageBufferArrayNonUniformIndexing", extFeatures.shaderStorageBufferArrayNonUniformIndexing);
            pushFeature2(extension, "shaderStorageImageArrayNonUniformIndexing", extFeatures.shaderStorageImageArrayNonUniformIndexing);
            pushFeature2(extension, "shaderInputAttachmentArrayNonUniformIndexing", extFeatures.shaderInputAttachmentArrayNonUniformIndexing);
            pushFeature2(extension, "shaderUniformTexelBufferArrayNonUniformIndexing", extFeatures.shaderUniformTexelBufferArrayNonUniformIndexing);
            pushFeature2(extension, "shaderStorageTexelBufferArrayNonUniformIndexing", extFeatures.shaderStorageTexelBufferArrayNonUniformIndexing);
            pushFeature2(extension, "descriptorBindingUniformBufferUpdateAfterBind", extFeatures.descriptorBindingUniformBufferUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingSampledImageUpdateAfterBind", extFeatures.descriptorBindingSampledImageUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingStorageImageUpdateAfterBind", extFeatures.descriptorBindingStorageImageUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingStorageBufferUpdateAfterBind", extFeatures.descriptorBindingStorageBufferUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingUniformTexelBufferUpdateAfterBind", extFeatures.descriptorBindingUniformTexelBufferUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingStorageTexelBufferUpdateAfterBind", extFeatures.descriptorBindingStorageTexelBufferUpdateAfterBind);
            pushFeature2(extension, "descriptorBindingUpdateUnusedWhilePending", extFeatures.descriptorBindingUpdateUnusedWhilePending);
            pushFeature2(extension, "descriptorBindingPartiallyBound", extFeatures.descriptorBindingPartiallyBound);
            pushFeature2(extension, "descriptorBindingVariableDescriptorCount", extFeatures.descriptorBindingVariableDescriptorCount);
            pushFeature2(extension, "runtimeDescriptorArray", extFeatures.runtimeDescriptorArray);
        }
        // VK_EXT_conditional_rendering
        if (extensionSupported(VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME)) {
            const char* extension(VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME);
            VkPhysicalDeviceConditionalRenderingFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "conditionalRendering", extFeatures.conditionalRendering);
            pushFeature2(extension, "inheritedConditionalRendering", extFeatures.inheritedConditionalRendering);
        }
        // VK_EXT_inline_uniform_block
        if (extensionSupported(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME)) {
            const char* extension(VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME);
            VkPhysicalDeviceInlineUniformBlockFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "inlineUniformBlock", extFeatures.inlineUniformBlock);
            pushFeature2(extension, "descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures.descriptorBindingInlineUniformBlockUpdateAfterBind);
        }
        // VK_EXT_vertex_attribute_divisor
        if (extensionSupported(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME)) {
            const char* extension(VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME);
            VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures.vertexAttributeInstanceRateDivisor);
            pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures.vertexAttributeInstanceRateZeroDivisor);
        }
        // VK_EXT_transform_feedback
        if (extensionSupported(VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME)) {
            const char* extension(VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME);
            VkPhysicalDeviceTransformFeedbackFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "transformFeedback", extFeatures.transformFeedback);
            pushFeature2(extension, "geometryStreams", extFeatures.geometryStreams);
        }
        // VK_EXT_fragment_density_map
        if (extensionSupported(VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME)) {
            const char* extension(VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME);
            VkPhysicalDeviceFragmentDensityMapFeaturesEXT extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "fragmentDensityMap", extFeatures.fragmentDensityMap);
            pushFeature2(extension, "fragmentDensityMapDynamic", extFeatures.fragmentDensityMapDynamic);
            pushFeature2(extension, "fragmentDensityMapNonSubsampledImages", extFeatures.fragmentDensityMapNonSubsampledImages);
        }
        // VK_EXT_buffer_device_address
        if (extensionSupported(VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME )) {
            const char* extension(VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME );
            VkPhysicalDeviceBufferAddressFeaturesEXT  extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "bufferDeviceAddress", extFeatures.bufferDeviceAddress);
            pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures.bufferDeviceAddressCaptureReplay);
            pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures.bufferDeviceAddressMultiDevice);
        }
    }
	
    // Read physical device features (2) for extensions from the NV namespace
    void readPhysicalFeatures_NV() {
        // VK_NV_mesh_shader
        if (extensionSupported(VK_NV_MESH_SHADER_EXTENSION_NAME)) {
            const char* extension(VK_NV_MESH_SHADER_EXTENSION_NAME);
            VkPhysicalDeviceMeshShaderFeaturesNV extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "taskShader", extFeatures.taskShader);
            pushFeature2(extension, "meshShader", extFeatures.meshShader);
        }
        // VK_NV_compute_shader_derivatives
        if (extensionSupported(VK_NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME)) {
            const char* extension(VK_NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME);
            VkPhysicalDeviceComputeShaderDerivativesFeaturesNV extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures.computeDerivativeGroupQuads);
            pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures.computeDerivativeGroupLinear);
        }
        // VK_NV_shading_rate_image
        if (extensionSupported(VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME)) {
            const char* extension(VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME);
            VkPhysicalDeviceShadingRateImageFeaturesNV extFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV };
            VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
            pfnGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
            pushFeature2(extension, "shadingRateImage", extFeatures.shadingRateImage);
            pushFeature2(extension, "shadingRateCoarseSampleOrder", extFeatures.shadingRateCoarseSampleOrder);
        }
    }

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

            readPhysicalFeatures_KHR();
            readPhysicalFeatures_EXT();
            readPhysicalFeatures_NV();

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
    std::string getSystemProperty(const char* propname)
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
