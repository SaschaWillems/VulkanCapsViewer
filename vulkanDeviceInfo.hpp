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
#include <map>
#include <list>
#include <iostream>
#include <fstream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include "vulkan/vulkan.h"
#include "vulkanresources.h"
#include "vulkanLayerInfo.hpp"
#include "vulkanFormatInfo.hpp"

#include "vulkanandroid.h"

struct OSInfo
{
	std::string name;
	std::string version;
	std::string architecture;
};

// std::string is missing from MinGW
template <typename T>
std::string to_string(T value)
{
    std::ostringstream os;
    os << value ;
    return os.str();
}


class VulkanDeviceInfo
{
private:
	std::vector<VulkanLayerInfo> layers;
public:
	uint32_t id;

	std::map<std::string, std::string> properties;
	std::map<std::string, std::string> limits;
	std::map<std::string, VkBool32> features;

	VkPhysicalDevice device;
	VkDevice dev;

	VkPhysicalDeviceProperties props;
	VkPhysicalDeviceMemoryProperties memoryProperties;
	VkPhysicalDeviceFeatures deviceFeatures;

	std::vector<VkExtensionProperties> extensions;
	std::vector<VkQueueFamilyProperties> queues;

	int32_t supportedFormatCount;
	std::vector<VulkanFormatInfo> formats;

	OSInfo os;

	std::string reportVersion;

	std::vector<VulkanLayerInfo> getLayers()
	{
		return layers;
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
        for (int32_t format = VK_FORMAT_BEGIN_RANGE+1; format < VK_FORMAT_END_RANGE+1; format++)
		{
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

	/// <summary>
    ///	Get list of available device queues
	/// </summary>
	void readQueues()
	{
		assert(device != NULL);
		uint32_t queueCount;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, NULL);
		assert(queueCount > 0);
		std::vector<VkQueueFamilyProperties> qs(queueCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, &qs.front());
		for (auto& q : qs)
        {
			queues.push_back(q);
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
	void readPhyiscalProperties()
	{
		assert(device != NULL);
		vkGetPhysicalDeviceProperties(device, &props);
		properties.clear();

		properties["devicename"] = props.deviceName;
        properties["driverversionraw"] = to_string(props.driverVersion);
        properties["driverversion"] = getDriverVersion();

		properties["apiversion"] = vulkanResources::versionToString(props.apiVersion);
        properties["vendorid"] = to_string(props.vendorID);
        properties["deviceid"] = to_string(props.deviceID);
		properties["devicetype"] = vulkanResources::physicalDeviceTypeString(props.deviceType);

        // Sparse residency
        properties["residencyStandard2DBlockShape"] = to_string(props.sparseProperties.residencyStandard2DBlockShape);
        properties["residencyStandard2DMSBlockShape"] = to_string(props.sparseProperties.residencyStandard2DMultisampleBlockShape);
        properties["residencyStandard3DBlockShape"] = to_string(props.sparseProperties.residencyStandard3DBlockShape);
        properties["residencyAlignedMipSize"] = to_string(props.sparseProperties.residencyAlignedMipSize);
        properties["residencyNonResidentStrict"] = to_string(props.sparseProperties.residencyNonResidentStrict);
	}
	

	/// <summary>
	///	Request physical device features
	/// </summary>
	void readPhyiscalFeatures()
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
	}

	/// <summary>
	///	Copy physical device limits into a map
	/// </summary>
	void readPhyiscalLimits()
	{
		limits.clear();
        limits["maxImageDimension1D"] = to_string(props.limits.maxImageDimension1D);
        limits["maxImageDimension2D"] = to_string(props.limits.maxImageDimension2D);
        limits["maxImageDimension3D"] = to_string(props.limits.maxImageDimension3D);
        limits["maxImageDimensionCube"] = to_string(props.limits.maxImageDimensionCube);
        limits["maxImageArrayLayers"] = to_string(props.limits.maxImageArrayLayers);
        limits["maxTexelBufferElements"] = to_string(props.limits.maxTexelBufferElements);
        limits["maxUniformBufferRange"] = to_string(props.limits.maxUniformBufferRange);
        limits["maxStorageBufferRange"] = to_string(props.limits.maxStorageBufferRange);
        limits["maxPushConstantsSize"] = to_string(props.limits.maxPushConstantsSize);
        limits["maxMemoryAllocationCount"] = to_string(props.limits.maxMemoryAllocationCount);
        limits["maxSamplerAllocationCount"] = to_string(props.limits.maxSamplerAllocationCount);
        limits["bufferImageGranularity"] = to_string(props.limits.bufferImageGranularity);
        limits["sparseAddressSpaceSize"] = to_string(props.limits.sparseAddressSpaceSize);
        limits["maxBoundDescriptorSets"] = to_string(props.limits.maxBoundDescriptorSets);
        limits["maxPerStageDescriptorSamplers"] = to_string(props.limits.maxPerStageDescriptorSamplers);
        limits["maxPerStageDescriptorUniformBuffers"] = to_string(props.limits.maxPerStageDescriptorUniformBuffers);
        limits["maxPerStageDescriptorStorageBuffers"] = to_string(props.limits.maxPerStageDescriptorStorageBuffers);
        limits["maxPerStageDescriptorSampledImages"] = to_string(props.limits.maxPerStageDescriptorSampledImages);
        limits["maxPerStageDescriptorStorageImages"] = to_string(props.limits.maxPerStageDescriptorStorageImages);
        limits["maxPerStageDescriptorInputAttachments"] = to_string(props.limits.maxPerStageDescriptorInputAttachments);
        limits["maxPerStageResources"] = to_string(props.limits.maxPerStageResources);
        limits["maxDescriptorSetSamplers"] = to_string(props.limits.maxDescriptorSetSamplers);
        limits["maxDescriptorSetUniformBuffers"] = to_string(props.limits.maxDescriptorSetUniformBuffers);
        limits["maxDescriptorSetUniformBuffersDynamic"] = to_string(props.limits.maxDescriptorSetUniformBuffersDynamic);
        limits["maxDescriptorSetStorageBuffers"] = to_string(props.limits.maxDescriptorSetStorageBuffers);
        limits["maxDescriptorSetStorageBuffersDynamic"] = to_string(props.limits.maxDescriptorSetStorageBuffersDynamic);
        limits["maxDescriptorSetSampledImages"] = to_string(props.limits.maxDescriptorSetSampledImages);
        limits["maxDescriptorSetStorageImages"] = to_string(props.limits.maxDescriptorSetStorageImages);
        limits["maxDescriptorSetInputAttachments"] = to_string(props.limits.maxDescriptorSetInputAttachments);
        limits["maxVertexInputAttributes"] = to_string(props.limits.maxVertexInputAttributes);
        limits["maxVertexInputBindings"] = to_string(props.limits.maxVertexInputBindings);
        limits["maxVertexInputAttributeOffset"] = to_string(props.limits.maxVertexInputAttributeOffset);
        limits["maxVertexInputBindingStride"] = to_string(props.limits.maxVertexInputBindingStride);
        limits["maxVertexOutputComponents"] = to_string(props.limits.maxVertexOutputComponents);
        limits["maxTessellationGenerationLevel"] = to_string(props.limits.maxTessellationGenerationLevel);
        limits["maxTessellationPatchSize"] = to_string(props.limits.maxTessellationPatchSize);
        limits["maxTessellationControlPerVertexInputComponents"] = to_string(props.limits.maxTessellationControlPerVertexInputComponents);
        limits["maxTessellationControlPerVertexOutputComponents"] = to_string(props.limits.maxTessellationControlPerVertexOutputComponents);
        limits["maxTessellationControlPerPatchOutputComponents"] = to_string(props.limits.maxTessellationControlPerPatchOutputComponents);
        limits["maxTessellationControlTotalOutputComponents"] = to_string(props.limits.maxTessellationControlTotalOutputComponents);
        limits["maxTessellationEvaluationInputComponents"] = to_string(props.limits.maxTessellationEvaluationInputComponents);
        limits["maxTessellationEvaluationOutputComponents"] = to_string(props.limits.maxTessellationEvaluationOutputComponents);
        limits["maxGeometryShaderInvocations"] = to_string(props.limits.maxGeometryShaderInvocations);
        limits["maxGeometryInputComponents"] = to_string(props.limits.maxGeometryInputComponents);
        limits["maxGeometryOutputComponents"] = to_string(props.limits.maxGeometryOutputComponents);
        limits["maxGeometryOutputVertices"] = to_string(props.limits.maxGeometryOutputVertices);
        limits["maxGeometryTotalOutputComponents"] = to_string(props.limits.maxGeometryTotalOutputComponents);
        limits["maxFragmentInputComponents"] = to_string(props.limits.maxFragmentInputComponents);
        limits["maxFragmentOutputAttachments"] = to_string(props.limits.maxFragmentOutputAttachments);
        limits["maxFragmentDualSrcAttachments"] = to_string(props.limits.maxFragmentDualSrcAttachments);
        limits["maxFragmentCombinedOutputResources"] = to_string(props.limits.maxFragmentCombinedOutputResources);
        limits["maxComputeSharedMemorySize"] = to_string(props.limits.maxComputeSharedMemorySize);
        limits["maxComputeWorkGroupCount[0]"] = to_string(props.limits.maxComputeWorkGroupCount[0]);
        limits["maxComputeWorkGroupCount[1]"] = to_string(props.limits.maxComputeWorkGroupCount[1]);
        limits["maxComputeWorkGroupCount[2]"] = to_string(props.limits.maxComputeWorkGroupCount[2]);
        limits["maxComputeWorkGroupInvocations"] = to_string(props.limits.maxComputeWorkGroupInvocations);
        limits["maxComputeWorkGroupSize[0]"] = to_string(props.limits.maxComputeWorkGroupSize[0]);
        limits["maxComputeWorkGroupSize[1]"] = to_string(props.limits.maxComputeWorkGroupSize[1]);
        limits["maxComputeWorkGroupSize[2]"] = to_string(props.limits.maxComputeWorkGroupSize[2]);
        limits["subPixelPrecisionBits"] = to_string(props.limits.subPixelPrecisionBits);
        limits["subTexelPrecisionBits"] = to_string(props.limits.subTexelPrecisionBits);
        limits["mipmapPrecisionBits"] = to_string(props.limits.mipmapPrecisionBits);
        limits["maxDrawIndexedIndexValue"] = to_string(props.limits.maxDrawIndexedIndexValue);
        limits["maxDrawIndirectCount"] = to_string(props.limits.maxDrawIndirectCount);
        limits["maxSamplerLodBias"] = to_string(props.limits.maxSamplerLodBias);
        limits["maxSamplerAnisotropy"] = to_string(props.limits.maxSamplerAnisotropy);
        limits["maxViewports"] = to_string(props.limits.maxViewports);
        limits["maxViewportDimensions[0]"] = to_string(props.limits.maxViewportDimensions[0]);
        limits["maxViewportDimensions[1]"] = to_string(props.limits.maxViewportDimensions[1]);
        limits["viewportBoundsRange[0]"] = to_string(props.limits.viewportBoundsRange[0]);
        limits["viewportBoundsRange[1]"] = to_string(props.limits.viewportBoundsRange[1]);
        limits["viewportSubPixelBits"] = to_string(props.limits.viewportSubPixelBits);
        limits["minMemoryMapAlignment"] = to_string(props.limits.minMemoryMapAlignment);
        limits["minTexelBufferOffsetAlignment"] = to_string(props.limits.minTexelBufferOffsetAlignment);
        limits["minUniformBufferOffsetAlignment"] = to_string(props.limits.minUniformBufferOffsetAlignment);
        limits["minStorageBufferOffsetAlignment"] = to_string(props.limits.minStorageBufferOffsetAlignment);
        limits["minTexelOffset"] = to_string(props.limits.minTexelOffset);
        limits["maxTexelOffset"] = to_string(props.limits.maxTexelOffset);
        limits["minTexelGatherOffset"] = to_string(props.limits.minTexelGatherOffset);
        limits["maxTexelGatherOffset"] = to_string(props.limits.maxTexelGatherOffset);
        limits["minInterpolationOffset"] = to_string(props.limits.minInterpolationOffset);
        limits["maxInterpolationOffset"] = to_string(props.limits.maxInterpolationOffset);
        limits["subPixelInterpolationOffsetBits"] = to_string(props.limits.subPixelInterpolationOffsetBits);
        limits["maxFramebufferWidth"] = to_string(props.limits.maxFramebufferWidth);
        limits["maxFramebufferHeight"] = to_string(props.limits.maxFramebufferHeight);
        limits["maxFramebufferLayers"] = to_string(props.limits.maxFramebufferLayers);
        limits["framebufferColorSampleCounts"] = to_string(props.limits.framebufferColorSampleCounts);
        limits["framebufferDepthSampleCounts"] = to_string(props.limits.framebufferDepthSampleCounts);
        limits["framebufferStencilSampleCounts"] = to_string(props.limits.framebufferStencilSampleCounts);
        limits["framebufferNoAttachmentsSampleCounts"] = to_string(props.limits.framebufferNoAttachmentsSampleCounts);
        limits["maxColorAttachments"] = to_string(props.limits.maxColorAttachments);
        limits["sampledImageColorSampleCounts"] = to_string(props.limits.sampledImageColorSampleCounts);
        limits["sampledImageIntegerSampleCounts"] = to_string(props.limits.sampledImageIntegerSampleCounts);
        limits["sampledImageDepthSampleCounts"] = to_string(props.limits.sampledImageDepthSampleCounts);
        limits["sampledImageStencilSampleCounts"] = to_string(props.limits.sampledImageStencilSampleCounts);
        limits["storageImageSampleCounts"] = to_string(props.limits.storageImageSampleCounts);
        limits["maxSampleMaskWords"] = to_string(props.limits.maxSampleMaskWords);
        limits["timestampComputeAndGraphics"] = to_string(props.limits.timestampComputeAndGraphics);
        limits["timestampPeriod"] = to_string(props.limits.timestampPeriod);
        limits["maxClipDistances"] = to_string(props.limits.maxClipDistances);
        limits["maxCullDistances"] = to_string(props.limits.maxCullDistances);
        limits["maxCombinedClipAndCullDistances"] = to_string(props.limits.maxCombinedClipAndCullDistances);
        limits["discreteQueuePriorities"] = to_string(props.limits.discreteQueuePriorities);
        limits["pointSizeRange[0]"] = to_string(props.limits.pointSizeRange[0]);
        limits["pointSizeRange[1]"] = to_string(props.limits.pointSizeRange[1]);
        limits["lineWidthRange[0]"] = to_string(props.limits.lineWidthRange[0]);
        limits["lineWidthRange[1]"] = to_string(props.limits.lineWidthRange[1]);
        limits["pointSizeGranularity"] = to_string(props.limits.pointSizeGranularity);
        limits["lineWidthGranularity"] = to_string(props.limits.lineWidthGranularity);
        limits["strictLines"] = to_string(props.limits.strictLines);
        limits["standardSampleLocations"] = to_string(props.limits.standardSampleLocations);
        limits["optimalBufferCopyOffsetAlignment"] = to_string(props.limits.optimalBufferCopyOffsetAlignment);
        limits["optimalBufferCopyRowPitchAlignment"] = to_string(props.limits.optimalBufferCopyRowPitchAlignment);
        limits["nonCoherentAtomSize"] = to_string(props.limits.nonCoherentAtomSize);
	}

	/// <summary>
	///	Request physical memory properties
	/// </summary>
	void readPhyiscalMemoryProperties()
	{
		assert(device != NULL);
        vkGetPhysicalDeviceMemoryProperties(device, &memoryProperties);
	}

    /// <summary>
    ///	Save report to JSON file
    /// </summary>
    void saveToJSON(std::string fileName, std::string submitter, std::string comment)
	{
		QJsonObject root;

		// Device properties
		QJsonObject jsonProperties;
		for (auto& prop : properties)
		{
			jsonProperties[QString::fromStdString(prop.first)] = QString::fromStdString(prop.second);
		}
		root["deviceproperties"] = jsonProperties;

		// Device features
		QJsonObject jsonFeatures;
		for (auto& feature : features)
		{
			jsonFeatures[QString::fromStdString(feature.first)] = QString::number(feature.second);
		}
		root["devicefeatures"] = jsonFeatures;

		// Device limits
		QJsonObject jsonLimits;
		for (auto& limit : limits)
		{
			jsonLimits[QString::fromStdString(limit.first)] = QString::fromStdString(limit.second);
		}
		root["devicelimits"] = jsonLimits;

		// Extensions
		QJsonArray jsonExtensions;
		for (auto& ext : extensions)
		{
			QJsonObject jsonExt;
			jsonExt["extname"] = ext.extensionName;
			jsonExt["specversion"] = QString::number(ext.specVersion);
			jsonExtensions.append(jsonExt);
		}
		root["extensions"] = jsonExtensions;

		// Formats
		QJsonArray jsonFormats;
		for (auto& format : formats)
		{
			QJsonObject jsonFormat;
			jsonFormat["format"] = QString::number(format.format);
			jsonFormat["supported"] = QString::number(format.supported);
			jsonFormat["lineartilingfeatures"] = QString::number(format.properties.linearTilingFeatures);
			jsonFormat["optimaltilingfeatures"] = QString::number(format.properties.optimalTilingFeatures);
			jsonFormat["bufferfeatures"] = QString::number(format.properties.bufferFeatures);
			jsonFormats.append(jsonFormat);
		}
		root["formats"] = jsonFormats;

		// Layers
		QJsonArray jsonLayers;
		for (auto& layer : layers)
		{
			QJsonObject jsonLayer;
			jsonLayer["layername"] = layer.properties.layerName;
			jsonLayer["description"] = layer.properties.description;
			jsonLayer["specversion"] = QString::number(layer.properties.specVersion);
			jsonLayer["implversion"] = QString::number(layer.properties.implementationVersion);
			QJsonArray jsonLayerExtensions;
			for (auto& ext : layer.extensions)
			{
				QJsonObject jsonExt;
				jsonExt["extname"] = ext.extensionName;
				jsonExt["specversion"] = QString::number(ext.specVersion);
				jsonLayerExtensions.append(jsonExt);
			}
			jsonLayer["extensions"] = jsonLayerExtensions;
			jsonLayers.append(jsonLayer);
		}
		root["layers"] = jsonLayers;

		// Queues
		QJsonArray jsonQueues;
		for (auto& queue : queues)
		{
			QJsonObject jsonQueue;
			jsonQueue["flags"] = QString::number(queue.queueFlags);
			jsonQueue["count"] = QString::number(queue.queueCount);
			jsonQueue["timestampValidBits"] = QString::number(queue.timestampValidBits);
			jsonQueue["minImageTransferGranularity.width"] = QString::number(queue.minImageTransferGranularity.width);
			jsonQueue["minImageTransferGranularity.height"] = QString::number(queue.minImageTransferGranularity.height);
			jsonQueue["minImageTransferGranularity.depth"] = QString::number(queue.minImageTransferGranularity.depth);
			jsonQueues.append(jsonQueue);
		}
		root["queues"] = jsonQueues;

		// Memory properties
		QJsonObject jsonMemoryProperties;
		// Available memory types
		jsonMemoryProperties["memorytypecount"] = QString::number(memoryProperties.memoryTypeCount);
		QJsonArray memtypes;
		for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++)
		{
			QJsonObject memtype;
			memtype["propertyflags"] = QString::number(memoryProperties.memoryTypes[i].propertyFlags);
			memtype["heapindex"] = QString::number(memoryProperties.memoryTypes[i].heapIndex);
			memtypes.append(memtype);
		}
		jsonMemoryProperties["memorytypes"] = memtypes;
		// Memory heaps
		jsonMemoryProperties["memoryheapcount"] = QString::number(memoryProperties.memoryHeapCount);
		QJsonArray heaps;
		for (uint32_t i = 0; i < memoryProperties.memoryHeapCount; i++)
		{
			QJsonObject memheap;
			memheap["flags"] = QString::number(memoryProperties.memoryHeaps[i].flags);
			memheap["size"] = QString::number(memoryProperties.memoryHeaps[i].size);
			heaps.append(memheap);
		}
		jsonMemoryProperties["heaps"] = heaps;
		root["memoryproperties"] = jsonMemoryProperties;

		// Environment
		QJsonObject jsonEnv;
		jsonEnv["name"] = QString::fromStdString(os.name);
		jsonEnv["version"] = QString::fromStdString(os.version);
		jsonEnv["architecture"] = QString::fromStdString(os.architecture);
		jsonEnv["submitter"] = QString::fromStdString(submitter);
		jsonEnv["comment"] = QString::fromStdString(comment);
		jsonEnv["reportversion"] = QString::fromStdString(reportVersion);
		root["environment"] = jsonEnv;

		QJsonDocument doc(root);
		QFile jsonFile(QString::fromStdString(fileName));
		jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson(QJsonDocument::Compact));
	}

};
