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

void VulkanDeviceInfoExtensions::readPhysicalProperties_AMD() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_AMD_shader_core_properties")) {
		const char* extension("VK_AMD_shader_core_properties");
		VkPhysicalDeviceShaderCorePropertiesAMD* extProps = new VkPhysicalDeviceShaderCorePropertiesAMD{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderEngineCount", QVariant(extProps->shaderEngineCount));
		pushProperty2(extension, "shaderArraysPerEngineCount", QVariant(extProps->shaderArraysPerEngineCount));
		pushProperty2(extension, "computeUnitsPerShaderArray", QVariant(extProps->computeUnitsPerShaderArray));
		pushProperty2(extension, "simdPerComputeUnit", QVariant(extProps->simdPerComputeUnit));
		pushProperty2(extension, "wavefrontsPerSimd", QVariant(extProps->wavefrontsPerSimd));
		pushProperty2(extension, "wavefrontSize", QVariant(extProps->wavefrontSize));
		pushProperty2(extension, "sgprsPerSimd", QVariant(extProps->sgprsPerSimd));
		pushProperty2(extension, "minSgprAllocation", QVariant(extProps->minSgprAllocation));
		pushProperty2(extension, "maxSgprAllocation", QVariant(extProps->maxSgprAllocation));
		pushProperty2(extension, "sgprAllocationGranularity", QVariant(extProps->sgprAllocationGranularity));
		pushProperty2(extension, "vgprsPerSimd", QVariant(extProps->vgprsPerSimd));
		pushProperty2(extension, "minVgprAllocation", QVariant(extProps->minVgprAllocation));
		pushProperty2(extension, "maxVgprAllocation", QVariant(extProps->maxVgprAllocation));
		pushProperty2(extension, "vgprAllocationGranularity", QVariant(extProps->vgprAllocationGranularity));
		delete extProps;
	}
	if (extensionSupported("VK_AMD_shader_core_properties2")) {
		const char* extension("VK_AMD_shader_core_properties2");
		VkPhysicalDeviceShaderCoreProperties2AMD* extProps = new VkPhysicalDeviceShaderCoreProperties2AMD{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderCoreFeatures", QVariant(extProps->shaderCoreFeatures));
		pushProperty2(extension, "activeComputeUnitCount", QVariant(extProps->activeComputeUnitCount));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_AMDX() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_AMDX_shader_enqueue")) {
		const char* extension("VK_AMDX_shader_enqueue");
		VkPhysicalDeviceShaderEnqueuePropertiesAMDX* extProps = new VkPhysicalDeviceShaderEnqueuePropertiesAMDX{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxExecutionGraphDepth", QVariant(extProps->maxExecutionGraphDepth));
		pushProperty2(extension, "maxExecutionGraphShaderOutputNodes", QVariant(extProps->maxExecutionGraphShaderOutputNodes));
		pushProperty2(extension, "maxExecutionGraphShaderPayloadSize", QVariant(extProps->maxExecutionGraphShaderPayloadSize));
		pushProperty2(extension, "maxExecutionGraphShaderPayloadCount", QVariant(extProps->maxExecutionGraphShaderPayloadCount));
		pushProperty2(extension, "executionGraphDispatchAddressAlignment", QVariant(extProps->executionGraphDispatchAddressAlignment));
		pushProperty2(extension, "maxExecutionGraphWorkgroupCount", QVariant::fromValue(QVariantList({ extProps->maxExecutionGraphWorkgroupCount[0], extProps->maxExecutionGraphWorkgroupCount[1], extProps->maxExecutionGraphWorkgroupCount[2] })));
		pushProperty2(extension, "maxExecutionGraphWorkgroups", QVariant(extProps->maxExecutionGraphWorkgroups));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_ANDROID() {
	VkPhysicalDeviceProperties2 deviceProps2{};
#if defined(VK_USE_PLATFORM_ANDROID)
	if (extensionSupported("VK_ANDROID_native_buffer")) {
		const char* extension("VK_ANDROID_native_buffer");
		VkPhysicalDevicePresentationPropertiesANDROID* extProps = new VkPhysicalDevicePresentationPropertiesANDROID{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "sharedImage", QVariant(bool(extProps->sharedImage)));
		delete extProps;
	}
	if (extensionSupported("VK_ANDROID_external_format_resolve")) {
		const char* extension("VK_ANDROID_external_format_resolve");
		VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* extProps = new VkPhysicalDeviceExternalFormatResolvePropertiesANDROID{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "nullColorAttachmentWithExternalFormatResolve", QVariant(bool(extProps->nullColorAttachmentWithExternalFormatResolve)));
		pushProperty2(extension, "externalFormatResolveChromaOffsetX", QVariant(extProps->externalFormatResolveChromaOffsetX));
		pushProperty2(extension, "externalFormatResolveChromaOffsetY", QVariant(extProps->externalFormatResolveChromaOffsetY));
		delete extProps;
	}
#endif
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_ARM() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_ARM_shader_core_properties")) {
		const char* extension("VK_ARM_shader_core_properties");
		VkPhysicalDeviceShaderCorePropertiesARM* extProps = new VkPhysicalDeviceShaderCorePropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pixelRate", QVariant(extProps->pixelRate));
		pushProperty2(extension, "texelRate", QVariant(extProps->texelRate));
		pushProperty2(extension, "fmaRate", QVariant(extProps->fmaRate));
		delete extProps;
	}
	if (extensionSupported("VK_ARM_scheduling_controls")) {
		const char* extension("VK_ARM_scheduling_controls");
		VkPhysicalDeviceSchedulingControlsPropertiesARM* extProps = new VkPhysicalDeviceSchedulingControlsPropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "schedulingControlsFlags", QVariant::fromValue(extProps->schedulingControlsFlags));
		delete extProps;
	}
	if (extensionSupported("VK_ARM_render_pass_striped")) {
		const char* extension("VK_ARM_render_pass_striped");
		VkPhysicalDeviceRenderPassStripedPropertiesARM* extProps = new VkPhysicalDeviceRenderPassStripedPropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "renderPassStripeGranularity", QVariant::fromValue(QVariantList({ extProps->renderPassStripeGranularity.width, extProps->renderPassStripeGranularity.height })));
		pushProperty2(extension, "maxRenderPassStripes", QVariant(extProps->maxRenderPassStripes));
		delete extProps;
	}
	if (extensionSupported("VK_ARM_tensors")) {
		const char* extension("VK_ARM_tensors");
		VkPhysicalDeviceTensorPropertiesARM* extProps = new VkPhysicalDeviceTensorPropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTensorDimensionCount", QVariant(extProps->maxTensorDimensionCount));
		pushProperty2(extension, "maxTensorElements", QVariant::fromValue(extProps->maxTensorElements));
		pushProperty2(extension, "maxPerDimensionTensorElements", QVariant::fromValue(extProps->maxPerDimensionTensorElements));
		pushProperty2(extension, "maxTensorStride", QVariant::fromValue(extProps->maxTensorStride));
		pushProperty2(extension, "maxTensorSize", QVariant::fromValue(extProps->maxTensorSize));
		pushProperty2(extension, "maxTensorShaderAccessArrayLength", QVariant(extProps->maxTensorShaderAccessArrayLength));
		pushProperty2(extension, "maxTensorShaderAccessSize", QVariant(extProps->maxTensorShaderAccessSize));
		pushProperty2(extension, "maxDescriptorSetStorageTensors", QVariant(extProps->maxDescriptorSetStorageTensors));
		pushProperty2(extension, "maxPerStageDescriptorSetStorageTensors", QVariant(extProps->maxPerStageDescriptorSetStorageTensors));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageTensors", QVariant(extProps->maxDescriptorSetUpdateAfterBindStorageTensors));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindStorageTensors", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindStorageTensors));
		pushProperty2(extension, "shaderStorageTensorArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderStorageTensorArrayNonUniformIndexingNative)));
		pushProperty2(extension, "shaderTensorSupportedStages", QVariant(extProps->shaderTensorSupportedStages));
		delete extProps;
	}
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* extProps = new VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderCoreMask", QVariant::fromValue(extProps->shaderCoreMask));
		pushProperty2(extension, "shaderCoreCount", QVariant(extProps->shaderCoreCount));
		pushProperty2(extension, "shaderWarpsPerCore", QVariant(extProps->shaderWarpsPerCore));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_EXT() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackPropertiesEXT* extProps = new VkPhysicalDeviceTransformFeedbackPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTransformFeedbackStreams", QVariant(extProps->maxTransformFeedbackStreams));
		pushProperty2(extension, "maxTransformFeedbackBuffers", QVariant(extProps->maxTransformFeedbackBuffers));
		pushProperty2(extension, "maxTransformFeedbackBufferSize", QVariant::fromValue(extProps->maxTransformFeedbackBufferSize));
		pushProperty2(extension, "maxTransformFeedbackStreamDataSize", QVariant(extProps->maxTransformFeedbackStreamDataSize));
		pushProperty2(extension, "maxTransformFeedbackBufferDataSize", QVariant(extProps->maxTransformFeedbackBufferDataSize));
		pushProperty2(extension, "maxTransformFeedbackBufferDataStride", QVariant(extProps->maxTransformFeedbackBufferDataStride));
		pushProperty2(extension, "transformFeedbackQueries", QVariant(bool(extProps->transformFeedbackQueries)));
		pushProperty2(extension, "transformFeedbackStreamsLinesTriangles", QVariant(bool(extProps->transformFeedbackStreamsLinesTriangles)));
		pushProperty2(extension, "transformFeedbackRasterizationStreamSelect", QVariant(bool(extProps->transformFeedbackRasterizationStreamSelect)));
		pushProperty2(extension, "transformFeedbackDraw", QVariant(bool(extProps->transformFeedbackDraw)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessPropertiesEXT* extProps = new VkPhysicalDevicePipelineRobustnessPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "defaultRobustnessStorageBuffers", QVariant(extProps->defaultRobustnessStorageBuffers));
		pushProperty2(extension, "defaultRobustnessUniformBuffers", QVariant(extProps->defaultRobustnessUniformBuffers));
		pushProperty2(extension, "defaultRobustnessVertexInputs", QVariant(extProps->defaultRobustnessVertexInputs));
		pushProperty2(extension, "defaultRobustnessImages", QVariant(extProps->defaultRobustnessImages));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_discard_rectangles")) {
		const char* extension("VK_EXT_discard_rectangles");
		VkPhysicalDeviceDiscardRectanglePropertiesEXT* extProps = new VkPhysicalDeviceDiscardRectanglePropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxDiscardRectangles", QVariant(extProps->maxDiscardRectangles));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_conservative_rasterization")) {
		const char* extension("VK_EXT_conservative_rasterization");
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT* extProps = new VkPhysicalDeviceConservativeRasterizationPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "primitiveOverestimationSize", QVariant(extProps->primitiveOverestimationSize));
		pushProperty2(extension, "maxExtraPrimitiveOverestimationSize", QVariant(extProps->maxExtraPrimitiveOverestimationSize));
		pushProperty2(extension, "extraPrimitiveOverestimationSizeGranularity", QVariant(extProps->extraPrimitiveOverestimationSizeGranularity));
		pushProperty2(extension, "primitiveUnderestimation", QVariant(bool(extProps->primitiveUnderestimation)));
		pushProperty2(extension, "conservativePointAndLineRasterization", QVariant(bool(extProps->conservativePointAndLineRasterization)));
		pushProperty2(extension, "degenerateTrianglesRasterized", QVariant(bool(extProps->degenerateTrianglesRasterized)));
		pushProperty2(extension, "degenerateLinesRasterized", QVariant(bool(extProps->degenerateLinesRasterized)));
		pushProperty2(extension, "fullyCoveredFragmentShaderInputVariable", QVariant(bool(extProps->fullyCoveredFragmentShaderInputVariable)));
		pushProperty2(extension, "conservativeRasterizationPostDepthCoverage", QVariant(bool(extProps->conservativeRasterizationPostDepthCoverage)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_sampler_filter_minmax")) {
		const char* extension("VK_EXT_sampler_filter_minmax");
		VkPhysicalDeviceSamplerFilterMinmaxProperties* extProps = new VkPhysicalDeviceSamplerFilterMinmaxProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "filterMinmaxSingleComponentFormats", QVariant(bool(extProps->filterMinmaxSingleComponentFormats)));
		pushProperty2(extension, "filterMinmaxImageComponentMapping", QVariant(bool(extProps->filterMinmaxImageComponentMapping)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockProperties* extProps = new VkPhysicalDeviceInlineUniformBlockProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxInlineUniformBlockSize", QVariant(extProps->maxInlineUniformBlockSize));
		pushProperty2(extension, "maxPerStageDescriptorInlineUniformBlocks", QVariant(extProps->maxPerStageDescriptorInlineUniformBlocks));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks));
		pushProperty2(extension, "maxDescriptorSetInlineUniformBlocks", QVariant(extProps->maxDescriptorSetInlineUniformBlocks));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", QVariant(extProps->maxDescriptorSetUpdateAfterBindInlineUniformBlocks));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_sample_locations")) {
		const char* extension("VK_EXT_sample_locations");
		VkPhysicalDeviceSampleLocationsPropertiesEXT* extProps = new VkPhysicalDeviceSampleLocationsPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "sampleLocationSampleCounts", QVariant(extProps->sampleLocationSampleCounts));
		pushProperty2(extension, "maxSampleLocationGridSize", QVariant::fromValue(QVariantList({ extProps->maxSampleLocationGridSize.width, extProps->maxSampleLocationGridSize.height })));
		pushProperty2(extension, "sampleLocationCoordinateRange", QVariant::fromValue(QVariantList({ extProps->sampleLocationCoordinateRange[0], extProps->sampleLocationCoordinateRange[1] })));
		pushProperty2(extension, "sampleLocationSubPixelBits", QVariant(extProps->sampleLocationSubPixelBits));
		pushProperty2(extension, "variableSampleLocations", QVariant(bool(extProps->variableSampleLocations)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* extProps = new VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "advancedBlendMaxColorAttachments", QVariant(extProps->advancedBlendMaxColorAttachments));
		pushProperty2(extension, "advancedBlendIndependentBlend", QVariant(bool(extProps->advancedBlendIndependentBlend)));
		pushProperty2(extension, "advancedBlendNonPremultipliedSrcColor", QVariant(bool(extProps->advancedBlendNonPremultipliedSrcColor)));
		pushProperty2(extension, "advancedBlendNonPremultipliedDstColor", QVariant(bool(extProps->advancedBlendNonPremultipliedDstColor)));
		pushProperty2(extension, "advancedBlendCorrelatedOverlap", QVariant(bool(extProps->advancedBlendCorrelatedOverlap)));
		pushProperty2(extension, "advancedBlendAllOperations", QVariant(bool(extProps->advancedBlendAllOperations)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingProperties* extProps = new VkPhysicalDeviceDescriptorIndexingProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxUpdateAfterBindDescriptorsInAllPools", QVariant(extProps->maxUpdateAfterBindDescriptorsInAllPools));
		pushProperty2(extension, "shaderUniformBufferArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderUniformBufferArrayNonUniformIndexingNative)));
		pushProperty2(extension, "shaderSampledImageArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderSampledImageArrayNonUniformIndexingNative)));
		pushProperty2(extension, "shaderStorageBufferArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderStorageBufferArrayNonUniformIndexingNative)));
		pushProperty2(extension, "shaderStorageImageArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderStorageImageArrayNonUniformIndexingNative)));
		pushProperty2(extension, "shaderInputAttachmentArrayNonUniformIndexingNative", QVariant(bool(extProps->shaderInputAttachmentArrayNonUniformIndexingNative)));
		pushProperty2(extension, "robustBufferAccessUpdateAfterBind", QVariant(bool(extProps->robustBufferAccessUpdateAfterBind)));
		pushProperty2(extension, "quadDivergentImplicitLod", QVariant(bool(extProps->quadDivergentImplicitLod)));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindSamplers", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindSamplers));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindUniformBuffers));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindStorageBuffers));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindSampledImages", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindSampledImages));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindStorageImages", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindStorageImages));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindInputAttachments", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindInputAttachments));
		pushProperty2(extension, "maxPerStageUpdateAfterBindResources", QVariant(extProps->maxPerStageUpdateAfterBindResources));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindSamplers", QVariant(extProps->maxDescriptorSetUpdateAfterBindSamplers));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindUniformBuffers", QVariant(extProps->maxDescriptorSetUpdateAfterBindUniformBuffers));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", QVariant(extProps->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageBuffers", QVariant(extProps->maxDescriptorSetUpdateAfterBindStorageBuffers));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", QVariant(extProps->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindSampledImages", QVariant(extProps->maxDescriptorSetUpdateAfterBindSampledImages));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindStorageImages", QVariant(extProps->maxDescriptorSetUpdateAfterBindStorageImages));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindInputAttachments", QVariant(extProps->maxDescriptorSetUpdateAfterBindInputAttachments));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_external_memory_host")) {
		const char* extension("VK_EXT_external_memory_host");
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT* extProps = new VkPhysicalDeviceExternalMemoryHostPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minImportedHostPointerAlignment", QVariant::fromValue(extProps->minImportedHostPointerAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* extProps = new VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxVertexAttribDivisor", QVariant(extProps->maxVertexAttribDivisor));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_pci_bus_info")) {
		const char* extension("VK_EXT_pci_bus_info");
		VkPhysicalDevicePCIBusInfoPropertiesEXT* extProps = new VkPhysicalDevicePCIBusInfoPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pciDomain", QVariant(extProps->pciDomain));
		pushProperty2(extension, "pciBus", QVariant(extProps->pciBus));
		pushProperty2(extension, "pciDevice", QVariant(extProps->pciDevice));
		pushProperty2(extension, "pciFunction", QVariant(extProps->pciFunction));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT* extProps = new VkPhysicalDeviceFragmentDensityMapPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps->minFragmentDensityTexelSize.width, extProps->minFragmentDensityTexelSize.height })));
		pushProperty2(extension, "maxFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps->maxFragmentDensityTexelSize.width, extProps->maxFragmentDensityTexelSize.height })));
		pushProperty2(extension, "fragmentDensityInvocations", QVariant(bool(extProps->fragmentDensityInvocations)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlProperties* extProps = new VkPhysicalDeviceSubgroupSizeControlProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minSubgroupSize", QVariant(extProps->minSubgroupSize));
		pushProperty2(extension, "maxSubgroupSize", QVariant(extProps->maxSubgroupSize));
		pushProperty2(extension, "maxComputeWorkgroupSubgroups", QVariant(extProps->maxComputeWorkgroupSubgroups));
		pushProperty2(extension, "requiredSubgroupSizeStages", QVariant(extProps->requiredSubgroupSizeStages));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexPropertiesEXT* extProps = new VkPhysicalDeviceProvokingVertexPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "provokingVertexModePerPipeline", QVariant(bool(extProps->provokingVertexModePerPipeline)));
		pushProperty2(extension, "transformFeedbackPreservesTriangleFanProvokingVertex", QVariant(bool(extProps->transformFeedbackPreservesTriangleFanProvokingVertex)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationPropertiesEXT* extProps = new VkPhysicalDeviceLineRasterizationPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "lineSubPixelPrecisionBits", QVariant(extProps->lineSubPixelPrecisionBits));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_host_image_copy")) {
		// This extension needs some special handling, this code has to be adjusted manually after header generation
		// If changed after header-update, DO NOT COMMIT the changes, but revert them
		const char* extension("VK_EXT_host_image_copy");
		VkPhysicalDeviceHostImageCopyPropertiesEXT* extProps = new VkPhysicalDeviceHostImageCopyPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		// First call will return the sizes of the image format lists
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "copySrcLayoutCount", QVariant(extProps->copySrcLayoutCount));
		pushProperty2(extension, "copyDstLayoutCount", QVariant(extProps->copyDstLayoutCount));
		pushProperty2(extension, "optimalTilingLayoutUUID", QVariant::fromValue(arrayToQVariantList(extProps->optimalTilingLayoutUUID, 16)));
		pushProperty2(extension, "identicalMemoryTypeRequirements", QVariant(bool(extProps->identicalMemoryTypeRequirements)));
		// Second call to get the source and destination format list
		std::vector<VkImageLayout> copySrcLayouts(extProps->copySrcLayoutCount);
		std::vector<VkImageLayout> copyDstLayouts(extProps->copyDstLayoutCount);
		extProps->pCopySrcLayouts = copySrcLayouts.data();
		extProps->pCopyDstLayouts = copyDstLayouts.data();
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		// Store them as serialized values
		pushProperty2(extension, "pCopySrcLayouts", QVariant::fromValue(arrayToQVariantList(copySrcLayouts, copySrcLayouts.size())));
		pushProperty2(extension, "pCopyDstLayouts", QVariant::fromValue(arrayToQVariantList(copySrcLayouts, copyDstLayouts.size())));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_map_memory_placed")) {
		const char* extension("VK_EXT_map_memory_placed");
		VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* extProps = new VkPhysicalDeviceMapMemoryPlacedPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minPlacedMemoryMapAlignment", QVariant::fromValue(extProps->minPlacedMemoryMapAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentProperties* extProps = new VkPhysicalDeviceTexelBufferAlignmentProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "storageTexelBufferOffsetAlignmentBytes", QVariant::fromValue(extProps->storageTexelBufferOffsetAlignmentBytes));
		pushProperty2(extension, "storageTexelBufferOffsetSingleTexelAlignment", QVariant(bool(extProps->storageTexelBufferOffsetSingleTexelAlignment)));
		pushProperty2(extension, "uniformTexelBufferOffsetAlignmentBytes", QVariant::fromValue(extProps->uniformTexelBufferOffsetAlignmentBytes));
		pushProperty2(extension, "uniformTexelBufferOffsetSingleTexelAlignment", QVariant(bool(extProps->uniformTexelBufferOffsetSingleTexelAlignment)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2PropertiesEXT* extProps = new VkPhysicalDeviceRobustness2PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "robustStorageBufferAccessSizeAlignment", QVariant::fromValue(extProps->robustStorageBufferAccessSizeAlignment));
		pushProperty2(extension, "robustUniformBufferAccessSizeAlignment", QVariant::fromValue(extProps->robustUniformBufferAccessSizeAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorPropertiesEXT* extProps = new VkPhysicalDeviceCustomBorderColorPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxCustomBorderColorSamplers", QVariant(extProps->maxCustomBorderColorSamplers));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferPropertiesEXT* extProps = new VkPhysicalDeviceDescriptorBufferPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "combinedImageSamplerDescriptorSingleArray", QVariant(bool(extProps->combinedImageSamplerDescriptorSingleArray)));
		pushProperty2(extension, "bufferlessPushDescriptors", QVariant(bool(extProps->bufferlessPushDescriptors)));
		pushProperty2(extension, "allowSamplerImageViewPostSubmitCreation", QVariant(bool(extProps->allowSamplerImageViewPostSubmitCreation)));
		pushProperty2(extension, "descriptorBufferOffsetAlignment", QVariant::fromValue(extProps->descriptorBufferOffsetAlignment));
		pushProperty2(extension, "maxDescriptorBufferBindings", QVariant(extProps->maxDescriptorBufferBindings));
		pushProperty2(extension, "maxResourceDescriptorBufferBindings", QVariant(extProps->maxResourceDescriptorBufferBindings));
		pushProperty2(extension, "maxSamplerDescriptorBufferBindings", QVariant(extProps->maxSamplerDescriptorBufferBindings));
		pushProperty2(extension, "maxEmbeddedImmutableSamplerBindings", QVariant(extProps->maxEmbeddedImmutableSamplerBindings));
		pushProperty2(extension, "maxEmbeddedImmutableSamplers", QVariant(extProps->maxEmbeddedImmutableSamplers));
		pushProperty2(extension, "bufferCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps->bufferCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "imageCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps->imageCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "imageViewCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps->imageViewCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "samplerCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps->samplerCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "accelerationStructureCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps->accelerationStructureCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "samplerDescriptorSize", QVariant::fromValue(extProps->samplerDescriptorSize));
		pushProperty2(extension, "combinedImageSamplerDescriptorSize", QVariant::fromValue(extProps->combinedImageSamplerDescriptorSize));
		pushProperty2(extension, "sampledImageDescriptorSize", QVariant::fromValue(extProps->sampledImageDescriptorSize));
		pushProperty2(extension, "storageImageDescriptorSize", QVariant::fromValue(extProps->storageImageDescriptorSize));
		pushProperty2(extension, "uniformTexelBufferDescriptorSize", QVariant::fromValue(extProps->uniformTexelBufferDescriptorSize));
		pushProperty2(extension, "robustUniformTexelBufferDescriptorSize", QVariant::fromValue(extProps->robustUniformTexelBufferDescriptorSize));
		pushProperty2(extension, "storageTexelBufferDescriptorSize", QVariant::fromValue(extProps->storageTexelBufferDescriptorSize));
		pushProperty2(extension, "robustStorageTexelBufferDescriptorSize", QVariant::fromValue(extProps->robustStorageTexelBufferDescriptorSize));
		pushProperty2(extension, "uniformBufferDescriptorSize", QVariant::fromValue(extProps->uniformBufferDescriptorSize));
		pushProperty2(extension, "robustUniformBufferDescriptorSize", QVariant::fromValue(extProps->robustUniformBufferDescriptorSize));
		pushProperty2(extension, "storageBufferDescriptorSize", QVariant::fromValue(extProps->storageBufferDescriptorSize));
		pushProperty2(extension, "robustStorageBufferDescriptorSize", QVariant::fromValue(extProps->robustStorageBufferDescriptorSize));
		pushProperty2(extension, "inputAttachmentDescriptorSize", QVariant::fromValue(extProps->inputAttachmentDescriptorSize));
		pushProperty2(extension, "accelerationStructureDescriptorSize", QVariant::fromValue(extProps->accelerationStructureDescriptorSize));
		pushProperty2(extension, "maxSamplerDescriptorBufferRange", QVariant::fromValue(extProps->maxSamplerDescriptorBufferRange));
		pushProperty2(extension, "maxResourceDescriptorBufferRange", QVariant::fromValue(extProps->maxResourceDescriptorBufferRange));
		pushProperty2(extension, "samplerDescriptorBufferAddressSpaceSize", QVariant::fromValue(extProps->samplerDescriptorBufferAddressSpaceSize));
		pushProperty2(extension, "resourceDescriptorBufferAddressSpaceSize", QVariant::fromValue(extProps->resourceDescriptorBufferAddressSpaceSize));
		pushProperty2(extension, "descriptorBufferAddressSpaceSize", QVariant::fromValue(extProps->descriptorBufferAddressSpaceSize));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* extProps = new VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "graphicsPipelineLibraryFastLinking", QVariant(bool(extProps->graphicsPipelineLibraryFastLinking)));
		pushProperty2(extension, "graphicsPipelineLibraryIndependentInterpolationDecoration", QVariant(bool(extProps->graphicsPipelineLibraryIndependentInterpolationDecoration)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesEXT* extProps = new VkPhysicalDeviceMeshShaderPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTaskWorkGroupTotalCount", QVariant(extProps->maxTaskWorkGroupTotalCount));
		pushProperty2(extension, "maxTaskWorkGroupCount", QVariant::fromValue(QVariantList({ extProps->maxTaskWorkGroupCount[0], extProps->maxTaskWorkGroupCount[1], extProps->maxTaskWorkGroupCount[2] })));
		pushProperty2(extension, "maxTaskWorkGroupInvocations", QVariant(extProps->maxTaskWorkGroupInvocations));
		pushProperty2(extension, "maxTaskWorkGroupSize", QVariant::fromValue(QVariantList({ extProps->maxTaskWorkGroupSize[0], extProps->maxTaskWorkGroupSize[1], extProps->maxTaskWorkGroupSize[2] })));
		pushProperty2(extension, "maxTaskPayloadSize", QVariant(extProps->maxTaskPayloadSize));
		pushProperty2(extension, "maxTaskSharedMemorySize", QVariant(extProps->maxTaskSharedMemorySize));
		pushProperty2(extension, "maxTaskPayloadAndSharedMemorySize", QVariant(extProps->maxTaskPayloadAndSharedMemorySize));
		pushProperty2(extension, "maxMeshWorkGroupTotalCount", QVariant(extProps->maxMeshWorkGroupTotalCount));
		pushProperty2(extension, "maxMeshWorkGroupCount", QVariant::fromValue(QVariantList({ extProps->maxMeshWorkGroupCount[0], extProps->maxMeshWorkGroupCount[1], extProps->maxMeshWorkGroupCount[2] })));
		pushProperty2(extension, "maxMeshWorkGroupInvocations", QVariant(extProps->maxMeshWorkGroupInvocations));
		pushProperty2(extension, "maxMeshWorkGroupSize", QVariant::fromValue(QVariantList({ extProps->maxMeshWorkGroupSize[0], extProps->maxMeshWorkGroupSize[1], extProps->maxMeshWorkGroupSize[2] })));
		pushProperty2(extension, "maxMeshSharedMemorySize", QVariant(extProps->maxMeshSharedMemorySize));
		pushProperty2(extension, "maxMeshPayloadAndSharedMemorySize", QVariant(extProps->maxMeshPayloadAndSharedMemorySize));
		pushProperty2(extension, "maxMeshOutputMemorySize", QVariant(extProps->maxMeshOutputMemorySize));
		pushProperty2(extension, "maxMeshPayloadAndOutputMemorySize", QVariant(extProps->maxMeshPayloadAndOutputMemorySize));
		pushProperty2(extension, "maxMeshOutputComponents", QVariant(extProps->maxMeshOutputComponents));
		pushProperty2(extension, "maxMeshOutputVertices", QVariant(extProps->maxMeshOutputVertices));
		pushProperty2(extension, "maxMeshOutputPrimitives", QVariant(extProps->maxMeshOutputPrimitives));
		pushProperty2(extension, "maxMeshOutputLayers", QVariant(extProps->maxMeshOutputLayers));
		pushProperty2(extension, "maxMeshMultiviewViewCount", QVariant(extProps->maxMeshMultiviewViewCount));
		pushProperty2(extension, "meshOutputPerVertexGranularity", QVariant(extProps->meshOutputPerVertexGranularity));
		pushProperty2(extension, "meshOutputPerPrimitiveGranularity", QVariant(extProps->meshOutputPerPrimitiveGranularity));
		pushProperty2(extension, "maxPreferredTaskWorkGroupInvocations", QVariant(extProps->maxPreferredTaskWorkGroupInvocations));
		pushProperty2(extension, "maxPreferredMeshWorkGroupInvocations", QVariant(extProps->maxPreferredMeshWorkGroupInvocations));
		pushProperty2(extension, "prefersLocalInvocationVertexOutput", QVariant(bool(extProps->prefersLocalInvocationVertexOutput)));
		pushProperty2(extension, "prefersLocalInvocationPrimitiveOutput", QVariant(bool(extProps->prefersLocalInvocationPrimitiveOutput)));
		pushProperty2(extension, "prefersCompactVertexOutput", QVariant(bool(extProps->prefersCompactVertexOutput)));
		pushProperty2(extension, "prefersCompactPrimitiveOutput", QVariant(bool(extProps->prefersCompactPrimitiveOutput)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* extProps = new VkPhysicalDeviceFragmentDensityMap2PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "subsampledLoads", QVariant(bool(extProps->subsampledLoads)));
		pushProperty2(extension, "subsampledCoarseReconstructionEarlyAccess", QVariant(bool(extProps->subsampledCoarseReconstructionEarlyAccess)));
		pushProperty2(extension, "maxSubsampledArrayLayers", QVariant(extProps->maxSubsampledArrayLayers));
		pushProperty2(extension, "maxDescriptorSetSubsampledSamplers", QVariant(extProps->maxDescriptorSetSubsampledSamplers));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_physical_device_drm")) {
		const char* extension("VK_EXT_physical_device_drm");
		VkPhysicalDeviceDrmPropertiesEXT* extProps = new VkPhysicalDeviceDrmPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "hasPrimary", QVariant(bool(extProps->hasPrimary)));
		pushProperty2(extension, "hasRender", QVariant(bool(extProps->hasRender)));
		pushProperty2(extension, "primaryMajor", QVariant::fromValue(extProps->primaryMajor));
		pushProperty2(extension, "primaryMinor", QVariant::fromValue(extProps->primaryMinor));
		pushProperty2(extension, "renderMajor", QVariant::fromValue(extProps->renderMajor));
		pushProperty2(extension, "renderMinor", QVariant::fromValue(extProps->renderMinor));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawPropertiesEXT* extProps = new VkPhysicalDeviceMultiDrawPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxMultiDrawCount", QVariant(extProps->maxMultiDrawCount));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_shader_tile_image")) {
		const char* extension("VK_EXT_shader_tile_image");
		VkPhysicalDeviceShaderTileImagePropertiesEXT* extProps = new VkPhysicalDeviceShaderTileImagePropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderTileImageCoherentReadAccelerated", QVariant(bool(extProps->shaderTileImageCoherentReadAccelerated)));
		pushProperty2(extension, "shaderTileImageReadSampleFromPixelRateInvocation", QVariant(bool(extProps->shaderTileImageReadSampleFromPixelRateInvocation)));
		pushProperty2(extension, "shaderTileImageReadFromHelperInvocation", QVariant(bool(extProps->shaderTileImageReadFromHelperInvocation)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapPropertiesEXT* extProps = new VkPhysicalDeviceOpacityMicromapPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxOpacity2StateSubdivisionLevel", QVariant(extProps->maxOpacity2StateSubdivisionLevel));
		pushProperty2(extension, "maxOpacity4StateSubdivisionLevel", QVariant(extProps->maxOpacity4StateSubdivisionLevel));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_nested_command_buffer")) {
		const char* extension("VK_EXT_nested_command_buffer");
		VkPhysicalDeviceNestedCommandBufferPropertiesEXT* extProps = new VkPhysicalDeviceNestedCommandBufferPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxCommandBufferNestingLevel", QVariant(extProps->maxCommandBufferNestingLevel));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* extProps = new VkPhysicalDeviceExtendedDynamicState3PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "dynamicPrimitiveTopologyUnrestricted", QVariant(bool(extProps->dynamicPrimitiveTopologyUnrestricted)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* extProps = new VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderModuleIdentifierAlgorithmUUID", QVariant::fromValue(arrayToQVariantList(extProps->shaderModuleIdentifierAlgorithmUUID, 16)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_shader_object")) {
		const char* extension("VK_EXT_shader_object");
		VkPhysicalDeviceShaderObjectPropertiesEXT* extProps = new VkPhysicalDeviceShaderObjectPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderBinaryUUID", QVariant::fromValue(arrayToQVariantList(extProps->shaderBinaryUUID, 16)));
		pushProperty2(extension, "shaderBinaryVersion", QVariant(extProps->shaderBinaryVersion));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_legacy_vertex_attributes")) {
		const char* extension("VK_EXT_legacy_vertex_attributes");
		VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* extProps = new VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "nativeUnalignedPerformance", QVariant(bool(extProps->nativeUnalignedPerformance)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_memory_decompression")) {
		const char* extension("VK_EXT_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionPropertiesEXT* extProps = new VkPhysicalDeviceMemoryDecompressionPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "decompressionMethods", QVariant::fromValue(extProps->decompressionMethods));
		pushProperty2(extension, "maxDecompressionIndirectCount", QVariant::fromValue(extProps->maxDecompressionIndirectCount));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_device_generated_commands")) {
		const char* extension("VK_EXT_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* extProps = new VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxIndirectPipelineCount", QVariant(extProps->maxIndirectPipelineCount));
		pushProperty2(extension, "maxIndirectShaderObjectCount", QVariant(extProps->maxIndirectShaderObjectCount));
		pushProperty2(extension, "maxIndirectSequenceCount", QVariant(extProps->maxIndirectSequenceCount));
		pushProperty2(extension, "maxIndirectCommandsTokenCount", QVariant(extProps->maxIndirectCommandsTokenCount));
		pushProperty2(extension, "maxIndirectCommandsTokenOffset", QVariant(extProps->maxIndirectCommandsTokenOffset));
		pushProperty2(extension, "maxIndirectCommandsIndirectStride", QVariant(extProps->maxIndirectCommandsIndirectStride));
		pushProperty2(extension, "supportedIndirectCommandsInputModes", QVariant(extProps->supportedIndirectCommandsInputModes));
		pushProperty2(extension, "supportedIndirectCommandsShaderStages", QVariant(extProps->supportedIndirectCommandsShaderStages));
		pushProperty2(extension, "supportedIndirectCommandsShaderStagesPipelineBinding", QVariant(extProps->supportedIndirectCommandsShaderStagesPipelineBinding));
		pushProperty2(extension, "supportedIndirectCommandsShaderStagesShaderBinding", QVariant(extProps->supportedIndirectCommandsShaderStagesShaderBinding));
		pushProperty2(extension, "deviceGeneratedCommandsTransformFeedback", QVariant(bool(extProps->deviceGeneratedCommandsTransformFeedback)));
		pushProperty2(extension, "deviceGeneratedCommandsMultiDrawIndirectCount", QVariant(bool(extProps->deviceGeneratedCommandsMultiDrawIndirectCount)));
		delete extProps;
	}
	if (extensionSupported("VK_EXT_fragment_density_map_offset")) {
		const char* extension("VK_EXT_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* extProps = new VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "fragmentDensityOffsetGranularity", QVariant::fromValue(QVariantList({ extProps->fragmentDensityOffsetGranularity.width, extProps->fragmentDensityOffsetGranularity.height })));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_HUAWEI() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI* extProps = new VkPhysicalDeviceSubpassShadingPropertiesHUAWEI{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxSubpassShadingWorkgroupSizeAspectRatio", QVariant(extProps->maxSubpassShadingWorkgroupSizeAspectRatio));
		delete extProps;
	}
	if (extensionSupported("VK_HUAWEI_cluster_culling_shader")) {
		const char* extension("VK_HUAWEI_cluster_culling_shader");
		VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* extProps = new VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxWorkGroupCount", QVariant::fromValue(QVariantList({ extProps->maxWorkGroupCount[0], extProps->maxWorkGroupCount[1], extProps->maxWorkGroupCount[2] })));
		pushProperty2(extension, "maxWorkGroupSize", QVariant::fromValue(QVariantList({ extProps->maxWorkGroupSize[0], extProps->maxWorkGroupSize[1], extProps->maxWorkGroupSize[2] })));
		pushProperty2(extension, "maxOutputClusterCount", QVariant(extProps->maxOutputClusterCount));
		pushProperty2(extension, "indirectBufferOffsetAlignment", QVariant::fromValue(extProps->indirectBufferOffsetAlignment));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_KHR() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewProperties* extProps = new VkPhysicalDeviceMultiviewProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxMultiviewViewCount", QVariant(extProps->maxMultiviewViewCount));
		pushProperty2(extension, "maxMultiviewInstanceIndex", QVariant(extProps->maxMultiviewInstanceIndex));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_memory_capabilities")) {
		const char* extension("VK_KHR_external_memory_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps->driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps->deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps->deviceLUIDValid)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_semaphore_capabilities")) {
		const char* extension("VK_KHR_external_semaphore_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps->driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps->deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps->deviceLUIDValid)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_push_descriptor")) {
		const char* extension("VK_KHR_push_descriptor");
		VkPhysicalDevicePushDescriptorPropertiesKHR* extProps = new VkPhysicalDevicePushDescriptorPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxPushDescriptors", QVariant(extProps->maxPushDescriptors));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_fence_capabilities")) {
		const char* extension("VK_KHR_external_fence_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps->driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps->deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps->deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps->deviceLUIDValid)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryPropertiesKHR* extProps = new VkPhysicalDevicePerformanceQueryPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "allowCommandBufferQueryCopies", QVariant(bool(extProps->allowCommandBufferQueryCopies)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance2")) {
		const char* extension("VK_KHR_maintenance2");
		VkPhysicalDevicePointClippingProperties* extProps = new VkPhysicalDevicePointClippingProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pointClippingBehavior", QVariant(extProps->pointClippingBehavior));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructurePropertiesKHR* extProps = new VkPhysicalDeviceAccelerationStructurePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxGeometryCount", QVariant::fromValue(extProps->maxGeometryCount));
		pushProperty2(extension, "maxInstanceCount", QVariant::fromValue(extProps->maxInstanceCount));
		pushProperty2(extension, "maxPrimitiveCount", QVariant::fromValue(extProps->maxPrimitiveCount));
		pushProperty2(extension, "maxPerStageDescriptorAccelerationStructures", QVariant(extProps->maxPerStageDescriptorAccelerationStructures));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindAccelerationStructures", QVariant(extProps->maxPerStageDescriptorUpdateAfterBindAccelerationStructures));
		pushProperty2(extension, "maxDescriptorSetAccelerationStructures", QVariant(extProps->maxDescriptorSetAccelerationStructures));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindAccelerationStructures", QVariant(extProps->maxDescriptorSetUpdateAfterBindAccelerationStructures));
		pushProperty2(extension, "minAccelerationStructureScratchOffsetAlignment", QVariant(extProps->minAccelerationStructureScratchOffsetAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR* extProps = new VkPhysicalDeviceRayTracingPipelinePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderGroupHandleSize", QVariant(extProps->shaderGroupHandleSize));
		pushProperty2(extension, "maxRayRecursionDepth", QVariant(extProps->maxRayRecursionDepth));
		pushProperty2(extension, "maxShaderGroupStride", QVariant(extProps->maxShaderGroupStride));
		pushProperty2(extension, "shaderGroupBaseAlignment", QVariant(extProps->shaderGroupBaseAlignment));
		pushProperty2(extension, "shaderGroupHandleCaptureReplaySize", QVariant(extProps->shaderGroupHandleCaptureReplaySize));
		pushProperty2(extension, "maxRayDispatchInvocationCount", QVariant(extProps->maxRayDispatchInvocationCount));
		pushProperty2(extension, "shaderGroupHandleAlignment", QVariant(extProps->shaderGroupHandleAlignment));
		pushProperty2(extension, "maxRayHitAttributeSize", QVariant(extProps->maxRayHitAttributeSize));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetPropertiesKHR* extProps = new VkPhysicalDevicePortabilitySubsetPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minVertexInputBindingStrideAlignment", QVariant(extProps->minVertexInputBindingStrideAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance3")) {
		const char* extension("VK_KHR_maintenance3");
		VkPhysicalDeviceMaintenance3Properties* extProps = new VkPhysicalDeviceMaintenance3Properties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxPerSetDescriptors", QVariant(extProps->maxPerSetDescriptors));
		pushProperty2(extension, "maxMemoryAllocationSize", QVariant::fromValue(extProps->maxMemoryAllocationSize));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_driver_properties")) {
		const char* extension("VK_KHR_driver_properties");
		VkPhysicalDeviceDriverProperties* extProps = new VkPhysicalDeviceDriverProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "driverID", QVariant(extProps->driverID));
		pushProperty2(extension, "driverName", QVariant(extProps->driverName));
		pushProperty2(extension, "driverInfo", QVariant(extProps->driverInfo));
		pushProperty2(extension, "conformanceVersion", QString::fromStdString(vulkanResources::conformanceVersionKHRString(extProps->conformanceVersion)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_shader_float_controls")) {
		const char* extension("VK_KHR_shader_float_controls");
		VkPhysicalDeviceFloatControlsProperties* extProps = new VkPhysicalDeviceFloatControlsProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "denormBehaviorIndependence", QVariant(extProps->denormBehaviorIndependence));
		pushProperty2(extension, "roundingModeIndependence", QVariant(extProps->roundingModeIndependence));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat16", QVariant(bool(extProps->shaderSignedZeroInfNanPreserveFloat16)));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat32", QVariant(bool(extProps->shaderSignedZeroInfNanPreserveFloat32)));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat64", QVariant(bool(extProps->shaderSignedZeroInfNanPreserveFloat64)));
		pushProperty2(extension, "shaderDenormPreserveFloat16", QVariant(bool(extProps->shaderDenormPreserveFloat16)));
		pushProperty2(extension, "shaderDenormPreserveFloat32", QVariant(bool(extProps->shaderDenormPreserveFloat32)));
		pushProperty2(extension, "shaderDenormPreserveFloat64", QVariant(bool(extProps->shaderDenormPreserveFloat64)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat16", QVariant(bool(extProps->shaderDenormFlushToZeroFloat16)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat32", QVariant(bool(extProps->shaderDenormFlushToZeroFloat32)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat64", QVariant(bool(extProps->shaderDenormFlushToZeroFloat64)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat16", QVariant(bool(extProps->shaderRoundingModeRTEFloat16)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat32", QVariant(bool(extProps->shaderRoundingModeRTEFloat32)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat64", QVariant(bool(extProps->shaderRoundingModeRTEFloat64)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat16", QVariant(bool(extProps->shaderRoundingModeRTZFloat16)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat32", QVariant(bool(extProps->shaderRoundingModeRTZFloat32)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat64", QVariant(bool(extProps->shaderRoundingModeRTZFloat64)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_depth_stencil_resolve")) {
		const char* extension("VK_KHR_depth_stencil_resolve");
		VkPhysicalDeviceDepthStencilResolveProperties* extProps = new VkPhysicalDeviceDepthStencilResolveProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedDepthResolveModes", QVariant(extProps->supportedDepthResolveModes));
		pushProperty2(extension, "supportedStencilResolveModes", QVariant(extProps->supportedStencilResolveModes));
		pushProperty2(extension, "independentResolveNone", QVariant(bool(extProps->independentResolveNone)));
		pushProperty2(extension, "independentResolve", QVariant(bool(extProps->independentResolve)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreProperties* extProps = new VkPhysicalDeviceTimelineSemaphoreProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTimelineSemaphoreValueDifference", QVariant::fromValue(extProps->maxTimelineSemaphoreValueDifference));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR* extProps = new VkPhysicalDeviceFragmentShadingRatePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minFragmentShadingRateAttachmentTexelSize", QVariant::fromValue(QVariantList({ extProps->minFragmentShadingRateAttachmentTexelSize.width, extProps->minFragmentShadingRateAttachmentTexelSize.height })));
		pushProperty2(extension, "maxFragmentShadingRateAttachmentTexelSize", QVariant::fromValue(QVariantList({ extProps->maxFragmentShadingRateAttachmentTexelSize.width, extProps->maxFragmentShadingRateAttachmentTexelSize.height })));
		pushProperty2(extension, "maxFragmentShadingRateAttachmentTexelSizeAspectRatio", QVariant(extProps->maxFragmentShadingRateAttachmentTexelSizeAspectRatio));
		pushProperty2(extension, "primitiveFragmentShadingRateWithMultipleViewports", QVariant(bool(extProps->primitiveFragmentShadingRateWithMultipleViewports)));
		pushProperty2(extension, "layeredShadingRateAttachments", QVariant(bool(extProps->layeredShadingRateAttachments)));
		pushProperty2(extension, "fragmentShadingRateNonTrivialCombinerOps", QVariant(bool(extProps->fragmentShadingRateNonTrivialCombinerOps)));
		pushProperty2(extension, "maxFragmentSize", QVariant::fromValue(QVariantList({ extProps->maxFragmentSize.width, extProps->maxFragmentSize.height })));
		pushProperty2(extension, "maxFragmentSizeAspectRatio", QVariant(extProps->maxFragmentSizeAspectRatio));
		pushProperty2(extension, "maxFragmentShadingRateCoverageSamples", QVariant(extProps->maxFragmentShadingRateCoverageSamples));
		pushProperty2(extension, "maxFragmentShadingRateRasterizationSamples", QVariant(extProps->maxFragmentShadingRateRasterizationSamples));
		pushProperty2(extension, "fragmentShadingRateWithShaderDepthStencilWrites", QVariant(bool(extProps->fragmentShadingRateWithShaderDepthStencilWrites)));
		pushProperty2(extension, "fragmentShadingRateWithSampleMask", QVariant(bool(extProps->fragmentShadingRateWithSampleMask)));
		pushProperty2(extension, "fragmentShadingRateWithShaderSampleMask", QVariant(bool(extProps->fragmentShadingRateWithShaderSampleMask)));
		pushProperty2(extension, "fragmentShadingRateWithConservativeRasterization", QVariant(bool(extProps->fragmentShadingRateWithConservativeRasterization)));
		pushProperty2(extension, "fragmentShadingRateWithFragmentShaderInterlock", QVariant(bool(extProps->fragmentShadingRateWithFragmentShaderInterlock)));
		pushProperty2(extension, "fragmentShadingRateWithCustomSampleLocations", QVariant(bool(extProps->fragmentShadingRateWithCustomSampleLocations)));
		pushProperty2(extension, "fragmentShadingRateStrictMultiplyCombiner", QVariant(bool(extProps->fragmentShadingRateStrictMultiplyCombiner)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductProperties* extProps = new VkPhysicalDeviceShaderIntegerDotProductProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "integerDotProduct8BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProduct8BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct8BitSignedAccelerated", QVariant(bool(extProps->integerDotProduct8BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct8BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProduct8BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedUnsignedAccelerated", QVariant(bool(extProps->integerDotProduct4x8BitPackedUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedSignedAccelerated", QVariant(bool(extProps->integerDotProduct4x8BitPackedSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProduct4x8BitPackedMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProduct16BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitSignedAccelerated", QVariant(bool(extProps->integerDotProduct16BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProduct16BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProduct32BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitSignedAccelerated", QVariant(bool(extProps->integerDotProduct32BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProduct32BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProduct64BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitSignedAccelerated", QVariant(bool(extProps->integerDotProduct64BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProduct64BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating8BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitSignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating8BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating16BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitSignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating16BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating32BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitSignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating32BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating64BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitSignedAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating64BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", QVariant(bool(extProps->integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* extProps = new VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "triStripVertexOrderIndependentOfProvokingVertex", QVariant(bool(extProps->triStripVertexOrderIndependentOfProvokingVertex)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Properties* extProps = new VkPhysicalDeviceMaintenance4Properties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxBufferSize", QVariant::fromValue(extProps->maxBufferSize));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance5")) {
		const char* extension("VK_KHR_maintenance5");
		VkPhysicalDeviceMaintenance5PropertiesKHR* extProps = new VkPhysicalDeviceMaintenance5PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "earlyFragmentMultisampleCoverageAfterSampleCounting", QVariant(bool(extProps->earlyFragmentMultisampleCoverageAfterSampleCounting)));
		pushProperty2(extension, "earlyFragmentSampleMaskTestBeforeSampleCounting", QVariant(bool(extProps->earlyFragmentSampleMaskTestBeforeSampleCounting)));
		pushProperty2(extension, "depthStencilSwizzleOneSupport", QVariant(bool(extProps->depthStencilSwizzleOneSupport)));
		pushProperty2(extension, "polygonModePointSize", QVariant(bool(extProps->polygonModePointSize)));
		pushProperty2(extension, "nonStrictSinglePixelWideLinesUseParallelogram", QVariant(bool(extProps->nonStrictSinglePixelWideLinesUseParallelogram)));
		pushProperty2(extension, "nonStrictWideLinesUseParallelogram", QVariant(bool(extProps->nonStrictWideLinesUseParallelogram)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_pipeline_binary")) {
		const char* extension("VK_KHR_pipeline_binary");
		VkPhysicalDevicePipelineBinaryPropertiesKHR* extProps = new VkPhysicalDevicePipelineBinaryPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pipelineBinaryInternalCache", QVariant(bool(extProps->pipelineBinaryInternalCache)));
		pushProperty2(extension, "pipelineBinaryInternalCacheControl", QVariant(bool(extProps->pipelineBinaryInternalCacheControl)));
		pushProperty2(extension, "pipelineBinaryPrefersInternalCache", QVariant(bool(extProps->pipelineBinaryPrefersInternalCache)));
		pushProperty2(extension, "pipelineBinaryPrecompiledInternalCache", QVariant(bool(extProps->pipelineBinaryPrecompiledInternalCache)));
		pushProperty2(extension, "pipelineBinaryCompressedData", QVariant(bool(extProps->pipelineBinaryCompressedData)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_cooperative_matrix")) {
		const char* extension("VK_KHR_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixPropertiesKHR* extProps = new VkPhysicalDeviceCooperativeMatrixPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "cooperativeMatrixSupportedStages", QVariant(extProps->cooperativeMatrixSupportedStages));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_compute_shader_derivatives")) {
		const char* extension("VK_KHR_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* extProps = new VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "meshAndTaskShaderDerivatives", QVariant(bool(extProps->meshAndTaskShaderDerivatives)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_vertex_attribute_divisor")) {
		const char* extension("VK_KHR_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* extProps = new VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxVertexAttribDivisor", QVariant(extProps->maxVertexAttribDivisor));
		pushProperty2(extension, "supportsNonZeroFirstInstance", QVariant(bool(extProps->supportsNonZeroFirstInstance)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_line_rasterization")) {
		const char* extension("VK_KHR_line_rasterization");
		VkPhysicalDeviceLineRasterizationPropertiesKHR* extProps = new VkPhysicalDeviceLineRasterizationPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "lineSubPixelPrecisionBits", QVariant(extProps->lineSubPixelPrecisionBits));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance6")) {
		const char* extension("VK_KHR_maintenance6");
		VkPhysicalDeviceMaintenance6PropertiesKHR* extProps = new VkPhysicalDeviceMaintenance6PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "blockTexelViewCompatibleMultipleLayers", QVariant(bool(extProps->blockTexelViewCompatibleMultipleLayers)));
		pushProperty2(extension, "maxCombinedImageSamplerDescriptorCount", QVariant(extProps->maxCombinedImageSamplerDescriptorCount));
		pushProperty2(extension, "fragmentShadingRateClampCombinerInputs", QVariant(bool(extProps->fragmentShadingRateClampCombinerInputs)));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_copy_memory_indirect")) {
		const char* extension("VK_KHR_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* extProps = new VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedQueues", QVariant(extProps->supportedQueues));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance7")) {
		const char* extension("VK_KHR_maintenance7");
		VkPhysicalDeviceMaintenance7PropertiesKHR* extProps = new VkPhysicalDeviceMaintenance7PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "robustFragmentShadingRateAttachmentAccess", QVariant(bool(extProps->robustFragmentShadingRateAttachmentAccess)));
		pushProperty2(extension, "separateDepthStencilAttachmentAccess", QVariant(bool(extProps->separateDepthStencilAttachmentAccess)));
		pushProperty2(extension, "maxDescriptorSetTotalUniformBuffersDynamic", QVariant(extProps->maxDescriptorSetTotalUniformBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetTotalStorageBuffersDynamic", QVariant(extProps->maxDescriptorSetTotalStorageBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetTotalBuffersDynamic", QVariant(extProps->maxDescriptorSetTotalBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic", QVariant(extProps->maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic", QVariant(extProps->maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindTotalBuffersDynamic", QVariant(extProps->maxDescriptorSetUpdateAfterBindTotalBuffersDynamic));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance9")) {
		const char* extension("VK_KHR_maintenance9");
		VkPhysicalDeviceMaintenance9PropertiesKHR* extProps = new VkPhysicalDeviceMaintenance9PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "image2DViewOf3DSparse", QVariant(bool(extProps->image2DViewOf3DSparse)));
		pushProperty2(extension, "defaultVertexAttributeValue", QVariant(extProps->defaultVertexAttributeValue));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_robustness2")) {
		const char* extension("VK_KHR_robustness2");
		VkPhysicalDeviceRobustness2PropertiesKHR* extProps = new VkPhysicalDeviceRobustness2PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "robustStorageBufferAccessSizeAlignment", QVariant::fromValue(extProps->robustStorageBufferAccessSizeAlignment));
		pushProperty2(extension, "robustUniformBufferAccessSizeAlignment", QVariant::fromValue(extProps->robustUniformBufferAccessSizeAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance10")) {
		const char* extension("VK_KHR_maintenance10");
		VkPhysicalDeviceMaintenance10PropertiesKHR* extProps = new VkPhysicalDeviceMaintenance10PropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "rgba4OpaqueBlackSwizzled", QVariant(bool(extProps->rgba4OpaqueBlackSwizzled)));
		pushProperty2(extension, "resolveSrgbFormatAppliesTransferFunction", QVariant(bool(extProps->resolveSrgbFormatAppliesTransferFunction)));
		pushProperty2(extension, "resolveSrgbFormatSupportsTransferFunctionControl", QVariant(bool(extProps->resolveSrgbFormatSupportsTransferFunctionControl)));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_MESA() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_MESA_image_alignment_control")) {
		const char* extension("VK_MESA_image_alignment_control");
		VkPhysicalDeviceImageAlignmentControlPropertiesMESA* extProps = new VkPhysicalDeviceImageAlignmentControlPropertiesMESA{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedImageAlignmentMask", QVariant(extProps->supportedImageAlignmentMask));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_MSFT() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_MSFT_layered_driver")) {
		const char* extension("VK_MSFT_layered_driver");
		VkPhysicalDeviceLayeredDriverPropertiesMSFT* extProps = new VkPhysicalDeviceLayeredDriverPropertiesMSFT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "underlyingAPI", QVariant(extProps->underlyingAPI));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NV() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* extProps = new VkPhysicalDeviceShaderSMBuiltinsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderSMCount", QVariant(extProps->shaderSMCount));
		pushProperty2(extension, "shaderWarpsPerSM", QVariant(extProps->shaderWarpsPerSM));
		delete extProps;
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImagePropertiesNV* extProps = new VkPhysicalDeviceShadingRateImagePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shadingRateTexelSize", QVariant::fromValue(QVariantList({ extProps->shadingRateTexelSize.width, extProps->shadingRateTexelSize.height })));
		pushProperty2(extension, "shadingRatePaletteSize", QVariant(extProps->shadingRatePaletteSize));
		pushProperty2(extension, "shadingRateMaxCoarseSamples", QVariant(extProps->shadingRateMaxCoarseSamples));
		delete extProps;
	}
	if (extensionSupported("VK_NV_ray_tracing")) {
		const char* extension("VK_NV_ray_tracing");
		VkPhysicalDeviceRayTracingPropertiesNV* extProps = new VkPhysicalDeviceRayTracingPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderGroupHandleSize", QVariant(extProps->shaderGroupHandleSize));
		pushProperty2(extension, "maxRecursionDepth", QVariant(extProps->maxRecursionDepth));
		pushProperty2(extension, "maxShaderGroupStride", QVariant(extProps->maxShaderGroupStride));
		pushProperty2(extension, "shaderGroupBaseAlignment", QVariant(extProps->shaderGroupBaseAlignment));
		pushProperty2(extension, "maxGeometryCount", QVariant::fromValue(extProps->maxGeometryCount));
		pushProperty2(extension, "maxInstanceCount", QVariant::fromValue(extProps->maxInstanceCount));
		pushProperty2(extension, "maxTriangleCount", QVariant::fromValue(extProps->maxTriangleCount));
		pushProperty2(extension, "maxDescriptorSetAccelerationStructures", QVariant(extProps->maxDescriptorSetAccelerationStructures));
		delete extProps;
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesNV* extProps = new VkPhysicalDeviceMeshShaderPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxDrawMeshTasksCount", QVariant(extProps->maxDrawMeshTasksCount));
		pushProperty2(extension, "maxTaskWorkGroupInvocations", QVariant(extProps->maxTaskWorkGroupInvocations));
		pushProperty2(extension, "maxTaskWorkGroupSize", QVariant::fromValue(QVariantList({ extProps->maxTaskWorkGroupSize[0], extProps->maxTaskWorkGroupSize[1], extProps->maxTaskWorkGroupSize[2] })));
		pushProperty2(extension, "maxTaskTotalMemorySize", QVariant(extProps->maxTaskTotalMemorySize));
		pushProperty2(extension, "maxTaskOutputCount", QVariant(extProps->maxTaskOutputCount));
		pushProperty2(extension, "maxMeshWorkGroupInvocations", QVariant(extProps->maxMeshWorkGroupInvocations));
		pushProperty2(extension, "maxMeshWorkGroupSize", QVariant::fromValue(QVariantList({ extProps->maxMeshWorkGroupSize[0], extProps->maxMeshWorkGroupSize[1], extProps->maxMeshWorkGroupSize[2] })));
		pushProperty2(extension, "maxMeshTotalMemorySize", QVariant(extProps->maxMeshTotalMemorySize));
		pushProperty2(extension, "maxMeshOutputVertices", QVariant(extProps->maxMeshOutputVertices));
		pushProperty2(extension, "maxMeshOutputPrimitives", QVariant(extProps->maxMeshOutputPrimitives));
		pushProperty2(extension, "maxMeshMultiviewViewCount", QVariant(extProps->maxMeshMultiviewViewCount));
		pushProperty2(extension, "meshOutputPerVertexGranularity", QVariant(extProps->meshOutputPerVertexGranularity));
		pushProperty2(extension, "meshOutputPerPrimitiveGranularity", QVariant(extProps->meshOutputPerPrimitiveGranularity));
		delete extProps;
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixPropertiesNV* extProps = new VkPhysicalDeviceCooperativeMatrixPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "cooperativeMatrixSupportedStages", QVariant(extProps->cooperativeMatrixSupportedStages));
		delete extProps;
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* extProps = new VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxGraphicsShaderGroupCount", QVariant(extProps->maxGraphicsShaderGroupCount));
		pushProperty2(extension, "maxIndirectSequenceCount", QVariant(extProps->maxIndirectSequenceCount));
		pushProperty2(extension, "maxIndirectCommandsTokenCount", QVariant(extProps->maxIndirectCommandsTokenCount));
		pushProperty2(extension, "maxIndirectCommandsStreamCount", QVariant(extProps->maxIndirectCommandsStreamCount));
		pushProperty2(extension, "maxIndirectCommandsTokenOffset", QVariant(extProps->maxIndirectCommandsTokenOffset));
		pushProperty2(extension, "maxIndirectCommandsStreamStride", QVariant(extProps->maxIndirectCommandsStreamStride));
		pushProperty2(extension, "minSequencesCountBufferOffsetAlignment", QVariant(extProps->minSequencesCountBufferOffsetAlignment));
		pushProperty2(extension, "minSequencesIndexBufferOffsetAlignment", QVariant(extProps->minSequencesIndexBufferOffsetAlignment));
		pushProperty2(extension, "minIndirectCommandsBufferOffsetAlignment", QVariant(extProps->minIndirectCommandsBufferOffsetAlignment));
		delete extProps;
	}
	if (extensionSupported("VK_NV_cuda_kernel_launch")) {
		const char* extension("VK_NV_cuda_kernel_launch");
		VkPhysicalDeviceCudaKernelLaunchPropertiesNV* extProps = new VkPhysicalDeviceCudaKernelLaunchPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "computeCapabilityMinor", QVariant(extProps->computeCapabilityMinor));
		pushProperty2(extension, "computeCapabilityMajor", QVariant(extProps->computeCapabilityMajor));
		delete extProps;
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* extProps = new VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxFragmentShadingRateInvocationCount", QVariant(extProps->maxFragmentShadingRateInvocationCount));
		delete extProps;
	}
	if (extensionSupported("VK_NV_displacement_micromap")) {
		const char* extension("VK_NV_displacement_micromap");
		VkPhysicalDeviceDisplacementMicromapPropertiesNV* extProps = new VkPhysicalDeviceDisplacementMicromapPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxDisplacementMicromapSubdivisionLevel", QVariant(extProps->maxDisplacementMicromapSubdivisionLevel));
		delete extProps;
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV* extProps = new VkPhysicalDeviceCopyMemoryIndirectPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedQueues", QVariant(extProps->supportedQueues));
		delete extProps;
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionPropertiesNV* extProps = new VkPhysicalDeviceMemoryDecompressionPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "decompressionMethods", QVariant::fromValue(extProps->decompressionMethods));
		pushProperty2(extension, "maxDecompressionIndirectCount", QVariant::fromValue(extProps->maxDecompressionIndirectCount));
		delete extProps;
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowPropertiesNV* extProps = new VkPhysicalDeviceOpticalFlowPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedOutputGridSizes", QVariant(extProps->supportedOutputGridSizes));
		pushProperty2(extension, "supportedHintGridSizes", QVariant(extProps->supportedHintGridSizes));
		pushProperty2(extension, "hintSupported", QVariant(bool(extProps->hintSupported)));
		pushProperty2(extension, "costSupported", QVariant(bool(extProps->costSupported)));
		pushProperty2(extension, "bidirectionalFlowSupported", QVariant(bool(extProps->bidirectionalFlowSupported)));
		pushProperty2(extension, "globalFlowSupported", QVariant(bool(extProps->globalFlowSupported)));
		pushProperty2(extension, "minWidth", QVariant(extProps->minWidth));
		pushProperty2(extension, "minHeight", QVariant(extProps->minHeight));
		pushProperty2(extension, "maxWidth", QVariant(extProps->maxWidth));
		pushProperty2(extension, "maxHeight", QVariant(extProps->maxHeight));
		pushProperty2(extension, "maxNumRegionsOfInterest", QVariant(extProps->maxNumRegionsOfInterest));
		delete extProps;
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* extProps = new VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "rayTracingInvocationReorderReorderingHint", QVariant(extProps->rayTracingInvocationReorderReorderingHint));
		delete extProps;
	}
	if (extensionSupported("VK_NV_cooperative_vector")) {
		const char* extension("VK_NV_cooperative_vector");
		VkPhysicalDeviceCooperativeVectorPropertiesNV* extProps = new VkPhysicalDeviceCooperativeVectorPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "cooperativeVectorSupportedStages", QVariant(extProps->cooperativeVectorSupportedStages));
		pushProperty2(extension, "cooperativeVectorTrainingFloat16Accumulation", QVariant(bool(extProps->cooperativeVectorTrainingFloat16Accumulation)));
		pushProperty2(extension, "cooperativeVectorTrainingFloat32Accumulation", QVariant(bool(extProps->cooperativeVectorTrainingFloat32Accumulation)));
		pushProperty2(extension, "maxCooperativeVectorComponents", QVariant(extProps->maxCooperativeVectorComponents));
		delete extProps;
	}
	if (extensionSupported("VK_NV_extended_sparse_address_space")) {
		const char* extension("VK_NV_extended_sparse_address_space");
		VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* extProps = new VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "extendedSparseAddressSpaceSize", QVariant::fromValue(extProps->extendedSparseAddressSpaceSize));
		pushProperty2(extension, "extendedSparseImageUsageFlags", QVariant(extProps->extendedSparseImageUsageFlags));
		pushProperty2(extension, "extendedSparseBufferUsageFlags", QVariant(extProps->extendedSparseBufferUsageFlags));
		delete extProps;
	}
	if (extensionSupported("VK_NV_external_compute_queue")) {
		const char* extension("VK_NV_external_compute_queue");
		VkPhysicalDeviceExternalComputeQueuePropertiesNV* extProps = new VkPhysicalDeviceExternalComputeQueuePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_COMPUTE_QUEUE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "externalDataSize", QVariant(extProps->externalDataSize));
		pushProperty2(extension, "maxExternalQueues", QVariant(extProps->maxExternalQueues));
		delete extProps;
	}
	if (extensionSupported("VK_NV_cluster_acceleration_structure")) {
		const char* extension("VK_NV_cluster_acceleration_structure");
		VkPhysicalDeviceClusterAccelerationStructurePropertiesNV* extProps = new VkPhysicalDeviceClusterAccelerationStructurePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxVerticesPerCluster", QVariant(extProps->maxVerticesPerCluster));
		pushProperty2(extension, "maxTrianglesPerCluster", QVariant(extProps->maxTrianglesPerCluster));
		pushProperty2(extension, "clusterScratchByteAlignment", QVariant(extProps->clusterScratchByteAlignment));
		pushProperty2(extension, "clusterByteAlignment", QVariant(extProps->clusterByteAlignment));
		pushProperty2(extension, "clusterTemplateByteAlignment", QVariant(extProps->clusterTemplateByteAlignment));
		pushProperty2(extension, "clusterBottomLevelByteAlignment", QVariant(extProps->clusterBottomLevelByteAlignment));
		pushProperty2(extension, "clusterTemplateBoundsByteAlignment", QVariant(extProps->clusterTemplateBoundsByteAlignment));
		pushProperty2(extension, "maxClusterGeometryIndex", QVariant(extProps->maxClusterGeometryIndex));
		delete extProps;
	}
	if (extensionSupported("VK_NV_partitioned_acceleration_structure")) {
		const char* extension("VK_NV_partitioned_acceleration_structure");
		VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* extProps = new VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxPartitionCount", QVariant(extProps->maxPartitionCount));
		delete extProps;
	}
	if (extensionSupported("VK_NV_cooperative_matrix2")) {
		const char* extension("VK_NV_cooperative_matrix2");
		VkPhysicalDeviceCooperativeMatrix2PropertiesNV* extProps = new VkPhysicalDeviceCooperativeMatrix2PropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "cooperativeMatrixWorkgroupScopeMaxWorkgroupSize", QVariant(extProps->cooperativeMatrixWorkgroupScopeMaxWorkgroupSize));
		pushProperty2(extension, "cooperativeMatrixFlexibleDimensionsMaxDimension", QVariant(extProps->cooperativeMatrixFlexibleDimensionsMaxDimension));
		pushProperty2(extension, "cooperativeMatrixWorkgroupScopeReservedSharedMemory", QVariant(extProps->cooperativeMatrixWorkgroupScopeReservedSharedMemory));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NVX() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_NVX_multiview_per_view_attributes")) {
		const char* extension("VK_NVX_multiview_per_view_attributes");
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* extProps = new VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "perViewPositionAllComponents", QVariant(bool(extProps->perViewPositionAllComponents)));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_OHOS() {
	VkPhysicalDeviceProperties2 deviceProps2{};
#if defined(VK_USE_PLATFORM_OHOS)
	if (extensionSupported("VK_OHOS_native_buffer")) {
		const char* extension("VK_OHOS_native_buffer");
		VkPhysicalDevicePresentationPropertiesOHOS* extProps = new VkPhysicalDevicePresentationPropertiesOHOS{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_OHOS;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "sharedImage", QVariant(bool(extProps->sharedImage)));
		delete extProps;
	}
#endif
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_QCOM() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_QCOM_tile_shading")) {
		const char* extension("VK_QCOM_tile_shading");
		VkPhysicalDeviceTileShadingPropertiesQCOM* extProps = new VkPhysicalDeviceTileShadingPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxApronSize", QVariant(extProps->maxApronSize));
		pushProperty2(extension, "preferNonCoherent", QVariant(bool(extProps->preferNonCoherent)));
		pushProperty2(extension, "tileGranularity", QVariant::fromValue(QVariantList({ extProps->tileGranularity.width, extProps->tileGranularity.height })));
		pushProperty2(extension, "maxTileShadingRate", QVariant::fromValue(QVariantList({ extProps->maxTileShadingRate.width, extProps->maxTileShadingRate.height })));
		delete extProps;
	}
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* extProps = new VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "fragmentDensityOffsetGranularity", QVariant::fromValue(QVariantList({ extProps->fragmentDensityOffsetGranularity.width, extProps->fragmentDensityOffsetGranularity.height })));
		delete extProps;
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingPropertiesQCOM* extProps = new VkPhysicalDeviceImageProcessingPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxWeightFilterPhases", QVariant(extProps->maxWeightFilterPhases));
		pushProperty2(extension, "maxWeightFilterDimension", QVariant::fromValue(QVariantList({ extProps->maxWeightFilterDimension.width, extProps->maxWeightFilterDimension.height })));
		pushProperty2(extension, "maxBlockMatchRegion", QVariant::fromValue(QVariantList({ extProps->maxBlockMatchRegion.width, extProps->maxBlockMatchRegion.height })));
		pushProperty2(extension, "maxBoxFilterBlockSize", QVariant::fromValue(QVariantList({ extProps->maxBoxFilterBlockSize.width, extProps->maxBoxFilterBlockSize.height })));
		delete extProps;
	}
	if (extensionSupported("VK_QCOM_image_processing2")) {
		const char* extension("VK_QCOM_image_processing2");
		VkPhysicalDeviceImageProcessing2PropertiesQCOM* extProps = new VkPhysicalDeviceImageProcessing2PropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxBlockMatchWindow", QVariant::fromValue(QVariantList({ extProps->maxBlockMatchWindow.width, extProps->maxBlockMatchWindow.height })));
		delete extProps;
	}
	if (extensionSupported("VK_QCOM_tile_memory_heap")) {
		const char* extension("VK_QCOM_tile_memory_heap");
		VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* extProps = new VkPhysicalDeviceTileMemoryHeapPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "queueSubmitBoundary", QVariant(bool(extProps->queueSubmitBoundary)));
		pushProperty2(extension, "tileBufferTransfers", QVariant(bool(extProps->tileBufferTransfers)));
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_VALVE() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_VALVE_fragment_density_map_layered")) {
		const char* extension("VK_VALVE_fragment_density_map_layered");
		VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* extProps = new VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxFragmentDensityMapLayers", QVariant(extProps->maxFragmentDensityMapLayers));
		delete extProps;
	}
}


void VulkanDeviceInfoExtensions::readExtendedProperties() {
    readPhysicalProperties_AMD();
    readPhysicalProperties_AMDX();
    readPhysicalProperties_ANDROID();
    readPhysicalProperties_ARM();
    readPhysicalProperties_EXT();
    readPhysicalProperties_HUAWEI();
    readPhysicalProperties_KHR();
    readPhysicalProperties_MESA();
    readPhysicalProperties_MSFT();
    readPhysicalProperties_NV();
    readPhysicalProperties_NVX();
    readPhysicalProperties_OHOS();
    readPhysicalProperties_QCOM();
    readPhysicalProperties_VALVE();
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

void VulkanDeviceInfoExtensions::readPhysicalFeatures_AMD() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_AMD_device_coherent_memory")) {
		const char* extension("VK_AMD_device_coherent_memory");
		VkPhysicalDeviceCoherentMemoryFeaturesAMD* extFeatures = new VkPhysicalDeviceCoherentMemoryFeaturesAMD{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceCoherentMemory", extFeatures->deviceCoherentMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_AMD_shader_early_and_late_fragment_tests")) {
		const char* extension("VK_AMD_shader_early_and_late_fragment_tests");
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* extFeatures = new VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderEarlyAndLateFragmentTests", extFeatures->shaderEarlyAndLateFragmentTests);
		delete extFeatures;
	}
	if (extensionSupported("VK_AMD_anti_lag")) {
		const char* extension("VK_AMD_anti_lag");
		VkPhysicalDeviceAntiLagFeaturesAMD* extFeatures = new VkPhysicalDeviceAntiLagFeaturesAMD{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "antiLag", extFeatures->antiLag);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_AMDX() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_AMDX_shader_enqueue")) {
		const char* extension("VK_AMDX_shader_enqueue");
		VkPhysicalDeviceShaderEnqueueFeaturesAMDX* extFeatures = new VkPhysicalDeviceShaderEnqueueFeaturesAMDX{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderEnqueue", extFeatures->shaderEnqueue);
		pushFeature2(extension, "shaderMeshEnqueue", extFeatures->shaderMeshEnqueue);
		delete extFeatures;
	}
	if (extensionSupported("VK_AMDX_dense_geometry_format")) {
		const char* extension("VK_AMDX_dense_geometry_format");
		VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX* extFeatures = new VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "denseGeometryFormat", extFeatures->denseGeometryFormat);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_ANDROID() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
#if defined(VK_USE_PLATFORM_ANDROID)
	if (extensionSupported("VK_ANDROID_external_format_resolve")) {
		const char* extension("VK_ANDROID_external_format_resolve");
		VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* extFeatures = new VkPhysicalDeviceExternalFormatResolveFeaturesANDROID{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "externalFormatResolve", extFeatures->externalFormatResolve);
		delete extFeatures;
	}
#endif
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_ARM() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_ARM_rasterization_order_attachment_access")) {
		const char* extension("VK_ARM_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* extFeatures = new VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures->rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures->rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures->rasterizationOrderStencilAttachmentAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_scheduling_controls")) {
		const char* extension("VK_ARM_scheduling_controls");
		VkPhysicalDeviceSchedulingControlsFeaturesARM* extFeatures = new VkPhysicalDeviceSchedulingControlsFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "schedulingControls", extFeatures->schedulingControls);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_render_pass_striped")) {
		const char* extension("VK_ARM_render_pass_striped");
		VkPhysicalDeviceRenderPassStripedFeaturesARM* extFeatures = new VkPhysicalDeviceRenderPassStripedFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "renderPassStriped", extFeatures->renderPassStriped);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_tensors")) {
		const char* extension("VK_ARM_tensors");
		VkPhysicalDeviceTensorFeaturesARM* extFeatures = new VkPhysicalDeviceTensorFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "tensorNonPacked", extFeatures->tensorNonPacked);
		pushFeature2(extension, "shaderTensorAccess", extFeatures->shaderTensorAccess);
		pushFeature2(extension, "shaderStorageTensorArrayDynamicIndexing", extFeatures->shaderStorageTensorArrayDynamicIndexing);
		pushFeature2(extension, "shaderStorageTensorArrayNonUniformIndexing", extFeatures->shaderStorageTensorArrayNonUniformIndexing);
		pushFeature2(extension, "descriptorBindingStorageTensorUpdateAfterBind", extFeatures->descriptorBindingStorageTensorUpdateAfterBind);
		pushFeature2(extension, "tensors", extFeatures->tensors);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* extFeatures = new VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderCoreBuiltins", extFeatures->shaderCoreBuiltins);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_data_graph")) {
		const char* extension("VK_ARM_data_graph");
		VkPhysicalDeviceDataGraphFeaturesARM* extFeatures = new VkPhysicalDeviceDataGraphFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dataGraph", extFeatures->dataGraph);
		pushFeature2(extension, "dataGraphUpdateAfterBind", extFeatures->dataGraphUpdateAfterBind);
		pushFeature2(extension, "dataGraphSpecializationConstants", extFeatures->dataGraphSpecializationConstants);
		pushFeature2(extension, "dataGraphDescriptorBuffer", extFeatures->dataGraphDescriptorBuffer);
		pushFeature2(extension, "dataGraphShaderModule", extFeatures->dataGraphShaderModule);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_pipeline_opacity_micromap")) {
		const char* extension("VK_ARM_pipeline_opacity_micromap");
		VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* extFeatures = new VkPhysicalDevicePipelineOpacityMicromapFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineOpacityMicromap", extFeatures->pipelineOpacityMicromap);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_format_pack")) {
		const char* extension("VK_ARM_format_pack");
		VkPhysicalDeviceFormatPackFeaturesARM* extFeatures = new VkPhysicalDeviceFormatPackFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "formatPack", extFeatures->formatPack);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_EXT() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackFeaturesEXT* extFeatures = new VkPhysicalDeviceTransformFeedbackFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "transformFeedback", extFeatures->transformFeedback);
		pushFeature2(extension, "geometryStreams", extFeatures->geometryStreams);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_texture_compression_astc_hdr")) {
		const char* extension("VK_EXT_texture_compression_astc_hdr");
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures* extFeatures = new VkPhysicalDeviceTextureCompressionASTCHDRFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "textureCompressionASTC_HDR", extFeatures->textureCompressionASTC_HDR);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_astc_decode_mode")) {
		const char* extension("VK_EXT_astc_decode_mode");
		VkPhysicalDeviceASTCDecodeFeaturesEXT* extFeatures = new VkPhysicalDeviceASTCDecodeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "decodeModeSharedExponent", extFeatures->decodeModeSharedExponent);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessFeaturesEXT* extFeatures = new VkPhysicalDevicePipelineRobustnessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineRobustness", extFeatures->pipelineRobustness);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_conditional_rendering")) {
		const char* extension("VK_EXT_conditional_rendering");
		VkPhysicalDeviceConditionalRenderingFeaturesEXT* extFeatures = new VkPhysicalDeviceConditionalRenderingFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "conditionalRendering", extFeatures->conditionalRendering);
		pushFeature2(extension, "inheritedConditionalRendering", extFeatures->inheritedConditionalRendering);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clip_enable")) {
		const char* extension("VK_EXT_depth_clip_enable");
		VkPhysicalDeviceDepthClipEnableFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClipEnableFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClipEnable", extFeatures->depthClipEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockFeatures* extFeatures = new VkPhysicalDeviceInlineUniformBlockFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "inlineUniformBlock", extFeatures->inlineUniformBlock);
		pushFeature2(extension, "descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures->descriptorBindingInlineUniformBlockUpdateAfterBind);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* extFeatures = new VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "advancedBlendCoherentOperations", extFeatures->advancedBlendCoherentOperations);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingFeatures* extFeatures = new VkPhysicalDeviceDescriptorIndexingFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderInputAttachmentArrayDynamicIndexing", extFeatures->shaderInputAttachmentArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayDynamicIndexing", extFeatures->shaderUniformTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayDynamicIndexing", extFeatures->shaderStorageTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformBufferArrayNonUniformIndexing", extFeatures->shaderUniformBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderSampledImageArrayNonUniformIndexing", extFeatures->shaderSampledImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageBufferArrayNonUniformIndexing", extFeatures->shaderStorageBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageImageArrayNonUniformIndexing", extFeatures->shaderStorageImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderInputAttachmentArrayNonUniformIndexing", extFeatures->shaderInputAttachmentArrayNonUniformIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayNonUniformIndexing", extFeatures->shaderUniformTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayNonUniformIndexing", extFeatures->shaderStorageTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "descriptorBindingUniformBufferUpdateAfterBind", extFeatures->descriptorBindingUniformBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingSampledImageUpdateAfterBind", extFeatures->descriptorBindingSampledImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageImageUpdateAfterBind", extFeatures->descriptorBindingStorageImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageBufferUpdateAfterBind", extFeatures->descriptorBindingStorageBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUniformTexelBufferUpdateAfterBind", extFeatures->descriptorBindingUniformTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageTexelBufferUpdateAfterBind", extFeatures->descriptorBindingStorageTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUpdateUnusedWhilePending", extFeatures->descriptorBindingUpdateUnusedWhilePending);
		pushFeature2(extension, "descriptorBindingPartiallyBound", extFeatures->descriptorBindingPartiallyBound);
		pushFeature2(extension, "descriptorBindingVariableDescriptorCount", extFeatures->descriptorBindingVariableDescriptorCount);
		pushFeature2(extension, "runtimeDescriptorArray", extFeatures->runtimeDescriptorArray);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* extFeatures = new VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures->vertexAttributeInstanceRateDivisor);
		pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures->vertexAttributeInstanceRateZeroDivisor);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentDensityMapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMap", extFeatures->fragmentDensityMap);
		pushFeature2(extension, "fragmentDensityMapDynamic", extFeatures->fragmentDensityMapDynamic);
		pushFeature2(extension, "fragmentDensityMapNonSubsampledImages", extFeatures->fragmentDensityMapNonSubsampledImages);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_scalar_block_layout")) {
		const char* extension("VK_EXT_scalar_block_layout");
		VkPhysicalDeviceScalarBlockLayoutFeatures* extFeatures = new VkPhysicalDeviceScalarBlockLayoutFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "scalarBlockLayout", extFeatures->scalarBlockLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlFeatures* extFeatures = new VkPhysicalDeviceSubgroupSizeControlFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subgroupSizeControl", extFeatures->subgroupSizeControl);
		pushFeature2(extension, "computeFullSubgroups", extFeatures->computeFullSubgroups);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_image_atomic_int64")) {
		const char* extension("VK_EXT_shader_image_atomic_int64");
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* extFeatures = new VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderImageInt64Atomics", extFeatures->shaderImageInt64Atomics);
		pushFeature2(extension, "sparseImageInt64Atomics", extFeatures->sparseImageInt64Atomics);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_memory_priority")) {
		const char* extension("VK_EXT_memory_priority");
		VkPhysicalDeviceMemoryPriorityFeaturesEXT* extFeatures = new VkPhysicalDeviceMemoryPriorityFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryPriority", extFeatures->memoryPriority);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_buffer_device_address")) {
		const char* extension("VK_EXT_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* extFeatures = new VkPhysicalDeviceBufferDeviceAddressFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures->bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures->bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures->bufferDeviceAddressMultiDevice);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_shader_interlock")) {
		const char* extension("VK_EXT_fragment_shader_interlock");
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderSampleInterlock", extFeatures->fragmentShaderSampleInterlock);
		pushFeature2(extension, "fragmentShaderPixelInterlock", extFeatures->fragmentShaderPixelInterlock);
		pushFeature2(extension, "fragmentShaderShadingRateInterlock", extFeatures->fragmentShaderShadingRateInterlock);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_ycbcr_image_arrays")) {
		const char* extension("VK_EXT_ycbcr_image_arrays");
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* extFeatures = new VkPhysicalDeviceYcbcrImageArraysFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "ycbcrImageArrays", extFeatures->ycbcrImageArrays);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexFeaturesEXT* extFeatures = new VkPhysicalDeviceProvokingVertexFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "provokingVertexLast", extFeatures->provokingVertexLast);
		pushFeature2(extension, "transformFeedbackPreservesProvokingVertex", extFeatures->transformFeedbackPreservesProvokingVertex);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationFeaturesEXT* extFeatures = new VkPhysicalDeviceLineRasterizationFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rectangularLines", extFeatures->rectangularLines);
		pushFeature2(extension, "bresenhamLines", extFeatures->bresenhamLines);
		pushFeature2(extension, "smoothLines", extFeatures->smoothLines);
		pushFeature2(extension, "stippledRectangularLines", extFeatures->stippledRectangularLines);
		pushFeature2(extension, "stippledBresenhamLines", extFeatures->stippledBresenhamLines);
		pushFeature2(extension, "stippledSmoothLines", extFeatures->stippledSmoothLines);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_atomic_float")) {
		const char* extension("VK_EXT_shader_atomic_float");
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderAtomicFloatFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat32Atomics", extFeatures->shaderBufferFloat32Atomics);
		pushFeature2(extension, "shaderBufferFloat32AtomicAdd", extFeatures->shaderBufferFloat32AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat64Atomics", extFeatures->shaderBufferFloat64Atomics);
		pushFeature2(extension, "shaderBufferFloat64AtomicAdd", extFeatures->shaderBufferFloat64AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat32Atomics", extFeatures->shaderSharedFloat32Atomics);
		pushFeature2(extension, "shaderSharedFloat32AtomicAdd", extFeatures->shaderSharedFloat32AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat64Atomics", extFeatures->shaderSharedFloat64Atomics);
		pushFeature2(extension, "shaderSharedFloat64AtomicAdd", extFeatures->shaderSharedFloat64AtomicAdd);
		pushFeature2(extension, "shaderImageFloat32Atomics", extFeatures->shaderImageFloat32Atomics);
		pushFeature2(extension, "shaderImageFloat32AtomicAdd", extFeatures->shaderImageFloat32AtomicAdd);
		pushFeature2(extension, "sparseImageFloat32Atomics", extFeatures->sparseImageFloat32Atomics);
		pushFeature2(extension, "sparseImageFloat32AtomicAdd", extFeatures->sparseImageFloat32AtomicAdd);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_host_query_reset")) {
		const char* extension("VK_EXT_host_query_reset");
		VkPhysicalDeviceHostQueryResetFeatures* extFeatures = new VkPhysicalDeviceHostQueryResetFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "hostQueryReset", extFeatures->hostQueryReset);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_index_type_uint8")) {
		const char* extension("VK_EXT_index_type_uint8");
		VkPhysicalDeviceIndexTypeUint8FeaturesEXT* extFeatures = new VkPhysicalDeviceIndexTypeUint8FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indexTypeUint8", extFeatures->indexTypeUint8);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state")) {
		const char* extension("VK_EXT_extended_dynamic_state");
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicStateFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState", extFeatures->extendedDynamicState);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_host_image_copy")) {
		const char* extension("VK_EXT_host_image_copy");
		VkPhysicalDeviceHostImageCopyFeaturesEXT* extFeatures = new VkPhysicalDeviceHostImageCopyFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "hostImageCopy", extFeatures->hostImageCopy);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_map_memory_placed")) {
		const char* extension("VK_EXT_map_memory_placed");
		VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* extFeatures = new VkPhysicalDeviceMapMemoryPlacedFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryMapPlaced", extFeatures->memoryMapPlaced);
		pushFeature2(extension, "memoryMapRangePlaced", extFeatures->memoryMapRangePlaced);
		pushFeature2(extension, "memoryUnmapReserve", extFeatures->memoryUnmapReserve);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_atomic_float2")) {
		const char* extension("VK_EXT_shader_atomic_float2");
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* extFeatures = new VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat16Atomics", extFeatures->shaderBufferFloat16Atomics);
		pushFeature2(extension, "shaderBufferFloat16AtomicAdd", extFeatures->shaderBufferFloat16AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat16AtomicMinMax", extFeatures->shaderBufferFloat16AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat32AtomicMinMax", extFeatures->shaderBufferFloat32AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat64AtomicMinMax", extFeatures->shaderBufferFloat64AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat16Atomics", extFeatures->shaderSharedFloat16Atomics);
		pushFeature2(extension, "shaderSharedFloat16AtomicAdd", extFeatures->shaderSharedFloat16AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat16AtomicMinMax", extFeatures->shaderSharedFloat16AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat32AtomicMinMax", extFeatures->shaderSharedFloat32AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat64AtomicMinMax", extFeatures->shaderSharedFloat64AtomicMinMax);
		pushFeature2(extension, "shaderImageFloat32AtomicMinMax", extFeatures->shaderImageFloat32AtomicMinMax);
		pushFeature2(extension, "sparseImageFloat32AtomicMinMax", extFeatures->sparseImageFloat32AtomicMinMax);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_swapchain_maintenance1")) {
		const char* extension("VK_EXT_swapchain_maintenance1");
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* extFeatures = new VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "swapchainMaintenance1", extFeatures->swapchainMaintenance1);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_demote_to_helper_invocation")) {
		const char* extension("VK_EXT_shader_demote_to_helper_invocation");
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* extFeatures = new VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderDemoteToHelperInvocation", extFeatures->shaderDemoteToHelperInvocation);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* extFeatures = new VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "texelBufferAlignment", extFeatures->texelBufferAlignment);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_bias_control")) {
		const char* extension("VK_EXT_depth_bias_control");
		VkPhysicalDeviceDepthBiasControlFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthBiasControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthBiasControl", extFeatures->depthBiasControl);
		pushFeature2(extension, "leastRepresentableValueForceUnormRepresentation", extFeatures->leastRepresentableValueForceUnormRepresentation);
		pushFeature2(extension, "floatRepresentation", extFeatures->floatRepresentation);
		pushFeature2(extension, "depthBiasExact", extFeatures->depthBiasExact);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_memory_report")) {
		const char* extension("VK_EXT_device_memory_report");
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* extFeatures = new VkPhysicalDeviceDeviceMemoryReportFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceMemoryReport", extFeatures->deviceMemoryReport);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2FeaturesEXT* extFeatures = new VkPhysicalDeviceRobustness2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "robustBufferAccess2", extFeatures->robustBufferAccess2);
		pushFeature2(extension, "robustImageAccess2", extFeatures->robustImageAccess2);
		pushFeature2(extension, "nullDescriptor", extFeatures->nullDescriptor);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorFeaturesEXT* extFeatures = new VkPhysicalDeviceCustomBorderColorFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "customBorderColors", extFeatures->customBorderColors);
		pushFeature2(extension, "customBorderColorWithoutFormat", extFeatures->customBorderColorWithoutFormat);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_private_data")) {
		const char* extension("VK_EXT_private_data");
		VkPhysicalDevicePrivateDataFeatures* extFeatures = new VkPhysicalDevicePrivateDataFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "privateData", extFeatures->privateData);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_creation_cache_control")) {
		const char* extension("VK_EXT_pipeline_creation_cache_control");
		VkPhysicalDevicePipelineCreationCacheControlFeatures* extFeatures = new VkPhysicalDevicePipelineCreationCacheControlFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineCreationCacheControl", extFeatures->pipelineCreationCacheControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferFeaturesEXT* extFeatures = new VkPhysicalDeviceDescriptorBufferFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "descriptorBuffer", extFeatures->descriptorBuffer);
		pushFeature2(extension, "descriptorBufferCaptureReplay", extFeatures->descriptorBufferCaptureReplay);
		pushFeature2(extension, "descriptorBufferImageLayoutIgnored", extFeatures->descriptorBufferImageLayoutIgnored);
		pushFeature2(extension, "descriptorBufferPushDescriptors", extFeatures->descriptorBufferPushDescriptors);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* extFeatures = new VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "graphicsPipelineLibrary", extFeatures->graphicsPipelineLibrary);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesEXT* extFeatures = new VkPhysicalDeviceMeshShaderFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures->taskShader);
		pushFeature2(extension, "meshShader", extFeatures->meshShader);
		pushFeature2(extension, "multiviewMeshShader", extFeatures->multiviewMeshShader);
		pushFeature2(extension, "primitiveFragmentShadingRateMeshShader", extFeatures->primitiveFragmentShadingRateMeshShader);
		pushFeature2(extension, "meshShaderQueries", extFeatures->meshShaderQueries);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_ycbcr_2plane_444_formats")) {
		const char* extension("VK_EXT_ycbcr_2plane_444_formats");
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* extFeatures = new VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "ycbcr2plane444Formats", extFeatures->ycbcr2plane444Formats);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentDensityMap2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapDeferred", extFeatures->fragmentDensityMapDeferred);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_robustness")) {
		const char* extension("VK_EXT_image_robustness");
		VkPhysicalDeviceImageRobustnessFeatures* extFeatures = new VkPhysicalDeviceImageRobustnessFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "robustImageAccess", extFeatures->robustImageAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_compression_control")) {
		const char* extension("VK_EXT_image_compression_control");
		VkPhysicalDeviceImageCompressionControlFeaturesEXT* extFeatures = new VkPhysicalDeviceImageCompressionControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControl", extFeatures->imageCompressionControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_attachment_feedback_loop_layout")) {
		const char* extension("VK_EXT_attachment_feedback_loop_layout");
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* extFeatures = new VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "attachmentFeedbackLoopLayout", extFeatures->attachmentFeedbackLoopLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_4444_formats")) {
		const char* extension("VK_EXT_4444_formats");
		VkPhysicalDevice4444FormatsFeaturesEXT* extFeatures = new VkPhysicalDevice4444FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "formatA4R4G4B4", extFeatures->formatA4R4G4B4);
		pushFeature2(extension, "formatA4B4G4R4", extFeatures->formatA4B4G4R4);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_fault")) {
		const char* extension("VK_EXT_device_fault");
		VkPhysicalDeviceFaultFeaturesEXT* extFeatures = new VkPhysicalDeviceFaultFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceFault", extFeatures->deviceFault);
		pushFeature2(extension, "deviceFaultVendorBinary", extFeatures->deviceFaultVendorBinary);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_rgba10x6_formats")) {
		const char* extension("VK_EXT_rgba10x6_formats");
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* extFeatures = new VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "formatRgba10x6WithoutYCbCrSampler", extFeatures->formatRgba10x6WithoutYCbCrSampler);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_vertex_input_dynamic_state")) {
		const char* extension("VK_EXT_vertex_input_dynamic_state");
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* extFeatures = new VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexInputDynamicState", extFeatures->vertexInputDynamicState);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_address_binding_report")) {
		const char* extension("VK_EXT_device_address_binding_report");
		VkPhysicalDeviceAddressBindingReportFeaturesEXT* extFeatures = new VkPhysicalDeviceAddressBindingReportFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "reportAddressBinding", extFeatures->reportAddressBinding);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clip_control")) {
		const char* extension("VK_EXT_depth_clip_control");
		VkPhysicalDeviceDepthClipControlFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClipControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClipControl", extFeatures->depthClipControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_primitive_topology_list_restart")) {
		const char* extension("VK_EXT_primitive_topology_list_restart");
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* extFeatures = new VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "primitiveTopologyListRestart", extFeatures->primitiveTopologyListRestart);
		pushFeature2(extension, "primitiveTopologyPatchListRestart", extFeatures->primitiveTopologyPatchListRestart);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_present_mode_fifo_latest_ready")) {
		const char* extension("VK_EXT_present_mode_fifo_latest_ready");
		VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT* extFeatures = new VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentModeFifoLatestReady", extFeatures->presentModeFifoLatestReady);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_properties")) {
		const char* extension("VK_EXT_pipeline_properties");
		VkPhysicalDevicePipelinePropertiesFeaturesEXT* extFeatures = new VkPhysicalDevicePipelinePropertiesFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelinePropertiesIdentifier", extFeatures->pipelinePropertiesIdentifier);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_frame_boundary")) {
		const char* extension("VK_EXT_frame_boundary");
		VkPhysicalDeviceFrameBoundaryFeaturesEXT* extFeatures = new VkPhysicalDeviceFrameBoundaryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "frameBoundary", extFeatures->frameBoundary);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_multisampled_render_to_single_sampled")) {
		const char* extension("VK_EXT_multisampled_render_to_single_sampled");
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* extFeatures = new VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multisampledRenderToSingleSampled", extFeatures->multisampledRenderToSingleSampled);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state2")) {
		const char* extension("VK_EXT_extended_dynamic_state2");
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicState2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState2", extFeatures->extendedDynamicState2);
		pushFeature2(extension, "extendedDynamicState2LogicOp", extFeatures->extendedDynamicState2LogicOp);
		pushFeature2(extension, "extendedDynamicState2PatchControlPoints", extFeatures->extendedDynamicState2PatchControlPoints);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_color_write_enable")) {
		const char* extension("VK_EXT_color_write_enable");
		VkPhysicalDeviceColorWriteEnableFeaturesEXT* extFeatures = new VkPhysicalDeviceColorWriteEnableFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "colorWriteEnable", extFeatures->colorWriteEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_primitives_generated_query")) {
		const char* extension("VK_EXT_primitives_generated_query");
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* extFeatures = new VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "primitivesGeneratedQuery", extFeatures->primitivesGeneratedQuery);
		pushFeature2(extension, "primitivesGeneratedQueryWithRasterizerDiscard", extFeatures->primitivesGeneratedQueryWithRasterizerDiscard);
		pushFeature2(extension, "primitivesGeneratedQueryWithNonZeroStreams", extFeatures->primitivesGeneratedQueryWithNonZeroStreams);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_global_priority_query")) {
		const char* extension("VK_EXT_global_priority_query");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures->globalPriorityQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_view_min_lod")) {
		const char* extension("VK_EXT_image_view_min_lod");
		VkPhysicalDeviceImageViewMinLodFeaturesEXT* extFeatures = new VkPhysicalDeviceImageViewMinLodFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "minLod", extFeatures->minLod);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawFeaturesEXT* extFeatures = new VkPhysicalDeviceMultiDrawFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiDraw", extFeatures->multiDraw);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_2d_view_of_3d")) {
		const char* extension("VK_EXT_image_2d_view_of_3d");
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* extFeatures = new VkPhysicalDeviceImage2DViewOf3DFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "image2DViewOf3D", extFeatures->image2DViewOf3D);
		pushFeature2(extension, "sampler2DViewOf3D", extFeatures->sampler2DViewOf3D);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_tile_image")) {
		const char* extension("VK_EXT_shader_tile_image");
		VkPhysicalDeviceShaderTileImageFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderTileImageFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderTileImageColorReadAccess", extFeatures->shaderTileImageColorReadAccess);
		pushFeature2(extension, "shaderTileImageDepthReadAccess", extFeatures->shaderTileImageDepthReadAccess);
		pushFeature2(extension, "shaderTileImageStencilReadAccess", extFeatures->shaderTileImageStencilReadAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapFeaturesEXT* extFeatures = new VkPhysicalDeviceOpacityMicromapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "micromap", extFeatures->micromap);
		pushFeature2(extension, "micromapCaptureReplay", extFeatures->micromapCaptureReplay);
		pushFeature2(extension, "micromapHostCommands", extFeatures->micromapHostCommands);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_border_color_swizzle")) {
		const char* extension("VK_EXT_border_color_swizzle");
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* extFeatures = new VkPhysicalDeviceBorderColorSwizzleFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "borderColorSwizzle", extFeatures->borderColorSwizzle);
		pushFeature2(extension, "borderColorSwizzleFromImage", extFeatures->borderColorSwizzleFromImage);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pageable_device_local_memory")) {
		const char* extension("VK_EXT_pageable_device_local_memory");
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* extFeatures = new VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pageableDeviceLocalMemory", extFeatures->pageableDeviceLocalMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_sliced_view_of_3d")) {
		const char* extension("VK_EXT_image_sliced_view_of_3d");
		VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* extFeatures = new VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageSlicedViewOf3D", extFeatures->imageSlicedViewOf3D);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clamp_zero_one")) {
		const char* extension("VK_EXT_depth_clamp_zero_one");
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClampZeroOneFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClampZeroOne", extFeatures->depthClampZeroOne);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_non_seamless_cube_map")) {
		const char* extension("VK_EXT_non_seamless_cube_map");
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* extFeatures = new VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "nonSeamlessCubeMap", extFeatures->nonSeamlessCubeMap);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_compression_control_swapchain")) {
		const char* extension("VK_EXT_image_compression_control_swapchain");
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* extFeatures = new VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControlSwapchain", extFeatures->imageCompressionControlSwapchain);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_nested_command_buffer")) {
		const char* extension("VK_EXT_nested_command_buffer");
		VkPhysicalDeviceNestedCommandBufferFeaturesEXT* extFeatures = new VkPhysicalDeviceNestedCommandBufferFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "nestedCommandBuffer", extFeatures->nestedCommandBuffer);
		pushFeature2(extension, "nestedCommandBufferRendering", extFeatures->nestedCommandBufferRendering);
		pushFeature2(extension, "nestedCommandBufferSimultaneousUse", extFeatures->nestedCommandBufferSimultaneousUse);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicState3FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState3TessellationDomainOrigin", extFeatures->extendedDynamicState3TessellationDomainOrigin);
		pushFeature2(extension, "extendedDynamicState3DepthClampEnable", extFeatures->extendedDynamicState3DepthClampEnable);
		pushFeature2(extension, "extendedDynamicState3PolygonMode", extFeatures->extendedDynamicState3PolygonMode);
		pushFeature2(extension, "extendedDynamicState3RasterizationSamples", extFeatures->extendedDynamicState3RasterizationSamples);
		pushFeature2(extension, "extendedDynamicState3SampleMask", extFeatures->extendedDynamicState3SampleMask);
		pushFeature2(extension, "extendedDynamicState3AlphaToCoverageEnable", extFeatures->extendedDynamicState3AlphaToCoverageEnable);
		pushFeature2(extension, "extendedDynamicState3AlphaToOneEnable", extFeatures->extendedDynamicState3AlphaToOneEnable);
		pushFeature2(extension, "extendedDynamicState3LogicOpEnable", extFeatures->extendedDynamicState3LogicOpEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEnable", extFeatures->extendedDynamicState3ColorBlendEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEquation", extFeatures->extendedDynamicState3ColorBlendEquation);
		pushFeature2(extension, "extendedDynamicState3ColorWriteMask", extFeatures->extendedDynamicState3ColorWriteMask);
		pushFeature2(extension, "extendedDynamicState3RasterizationStream", extFeatures->extendedDynamicState3RasterizationStream);
		pushFeature2(extension, "extendedDynamicState3ConservativeRasterizationMode", extFeatures->extendedDynamicState3ConservativeRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3ExtraPrimitiveOverestimationSize", extFeatures->extendedDynamicState3ExtraPrimitiveOverestimationSize);
		pushFeature2(extension, "extendedDynamicState3DepthClipEnable", extFeatures->extendedDynamicState3DepthClipEnable);
		pushFeature2(extension, "extendedDynamicState3SampleLocationsEnable", extFeatures->extendedDynamicState3SampleLocationsEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendAdvanced", extFeatures->extendedDynamicState3ColorBlendAdvanced);
		pushFeature2(extension, "extendedDynamicState3ProvokingVertexMode", extFeatures->extendedDynamicState3ProvokingVertexMode);
		pushFeature2(extension, "extendedDynamicState3LineRasterizationMode", extFeatures->extendedDynamicState3LineRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3LineStippleEnable", extFeatures->extendedDynamicState3LineStippleEnable);
		pushFeature2(extension, "extendedDynamicState3DepthClipNegativeOneToOne", extFeatures->extendedDynamicState3DepthClipNegativeOneToOne);
		pushFeature2(extension, "extendedDynamicState3ViewportWScalingEnable", extFeatures->extendedDynamicState3ViewportWScalingEnable);
		pushFeature2(extension, "extendedDynamicState3ViewportSwizzle", extFeatures->extendedDynamicState3ViewportSwizzle);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorEnable", extFeatures->extendedDynamicState3CoverageToColorEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorLocation", extFeatures->extendedDynamicState3CoverageToColorLocation);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationMode", extFeatures->extendedDynamicState3CoverageModulationMode);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTableEnable", extFeatures->extendedDynamicState3CoverageModulationTableEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTable", extFeatures->extendedDynamicState3CoverageModulationTable);
		pushFeature2(extension, "extendedDynamicState3CoverageReductionMode", extFeatures->extendedDynamicState3CoverageReductionMode);
		pushFeature2(extension, "extendedDynamicState3RepresentativeFragmentTestEnable", extFeatures->extendedDynamicState3RepresentativeFragmentTestEnable);
		pushFeature2(extension, "extendedDynamicState3ShadingRateImageEnable", extFeatures->extendedDynamicState3ShadingRateImageEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_subpass_merge_feedback")) {
		const char* extension("VK_EXT_subpass_merge_feedback");
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* extFeatures = new VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subpassMergeFeedback", extFeatures->subpassMergeFeedback);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderModuleIdentifier", extFeatures->shaderModuleIdentifier);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_rasterization_order_attachment_access")) {
		const char* extension("VK_EXT_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* extFeatures = new VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures->rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures->rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures->rasterizationOrderStencilAttachmentAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_legacy_dithering")) {
		const char* extension("VK_EXT_legacy_dithering");
		VkPhysicalDeviceLegacyDitheringFeaturesEXT* extFeatures = new VkPhysicalDeviceLegacyDitheringFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "legacyDithering", extFeatures->legacyDithering);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_protected_access")) {
		const char* extension("VK_EXT_pipeline_protected_access");
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* extFeatures = new VkPhysicalDevicePipelineProtectedAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineProtectedAccess", extFeatures->pipelineProtectedAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_object")) {
		const char* extension("VK_EXT_shader_object");
		VkPhysicalDeviceShaderObjectFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderObjectFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderObject", extFeatures->shaderObject);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_mutable_descriptor_type")) {
		const char* extension("VK_EXT_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* extFeatures = new VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures->mutableDescriptorType);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_legacy_vertex_attributes")) {
		const char* extension("VK_EXT_legacy_vertex_attributes");
		VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* extFeatures = new VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "legacyVertexAttributes", extFeatures->legacyVertexAttributes);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_library_group_handles")) {
		const char* extension("VK_EXT_pipeline_library_group_handles");
		VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* extFeatures = new VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineLibraryGroupHandles", extFeatures->pipelineLibraryGroupHandles);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_dynamic_rendering_unused_attachments")) {
		const char* extension("VK_EXT_dynamic_rendering_unused_attachments");
		VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* extFeatures = new VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dynamicRenderingUnusedAttachments", extFeatures->dynamicRenderingUnusedAttachments);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_attachment_feedback_loop_dynamic_state")) {
		const char* extension("VK_EXT_attachment_feedback_loop_dynamic_state");
		VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* extFeatures = new VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "attachmentFeedbackLoopDynamicState", extFeatures->attachmentFeedbackLoopDynamicState);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_memory_decompression")) {
		const char* extension("VK_EXT_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionFeaturesEXT* extFeatures = new VkPhysicalDeviceMemoryDecompressionFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryDecompression", extFeatures->memoryDecompression);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_replicated_composites")) {
		const char* extension("VK_EXT_shader_replicated_composites");
		VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderReplicatedComposites", extFeatures->shaderReplicatedComposites);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_float8")) {
		const char* extension("VK_EXT_shader_float8");
		VkPhysicalDeviceShaderFloat8FeaturesEXT* extFeatures = new VkPhysicalDeviceShaderFloat8FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat8", extFeatures->shaderFloat8);
		pushFeature2(extension, "shaderFloat8CooperativeMatrix", extFeatures->shaderFloat8CooperativeMatrix);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_generated_commands")) {
		const char* extension("VK_EXT_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* extFeatures = new VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCommands", extFeatures->deviceGeneratedCommands);
		pushFeature2(extension, "dynamicGeneratedPipelineLayout", extFeatures->dynamicGeneratedPipelineLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clamp_control")) {
		const char* extension("VK_EXT_depth_clamp_control");
		VkPhysicalDeviceDepthClampControlFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClampControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClampControl", extFeatures->depthClampControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_vertex_attribute_robustness")) {
		const char* extension("VK_EXT_vertex_attribute_robustness");
		VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* extFeatures = new VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeRobustness", extFeatures->vertexAttributeRobustness);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_density_map_offset")) {
		const char* extension("VK_EXT_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapOffset", extFeatures->fragmentDensityMapOffset);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_zero_initialize_device_memory")) {
		const char* extension("VK_EXT_zero_initialize_device_memory");
		VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* extFeatures = new VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "zeroInitializeDeviceMemory", extFeatures->zeroInitializeDeviceMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_64bit_indexing")) {
		const char* extension("VK_EXT_shader_64bit_indexing");
		VkPhysicalDeviceShader64BitIndexingFeaturesEXT* extFeatures = new VkPhysicalDeviceShader64BitIndexingFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shader64BitIndexing", extFeatures->shader64BitIndexing);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_uniform_buffer_unsized_array")) {
		const char* extension("VK_EXT_shader_uniform_buffer_unsized_array");
		VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderUniformBufferUnsizedArray", extFeatures->shaderUniformBufferUnsizedArray);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_HUAWEI() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceSubpassShadingFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subpassShading", extFeatures->subpassShading);
		delete extFeatures;
	}
	if (extensionSupported("VK_HUAWEI_invocation_mask")) {
		const char* extension("VK_HUAWEI_invocation_mask");
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceInvocationMaskFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "invocationMask", extFeatures->invocationMask);
		delete extFeatures;
	}
	if (extensionSupported("VK_HUAWEI_cluster_culling_shader")) {
		const char* extension("VK_HUAWEI_cluster_culling_shader");
		VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "clustercullingShader", extFeatures->clustercullingShader);
		pushFeature2(extension, "multiviewClusterCullingShader", extFeatures->multiviewClusterCullingShader);
		delete extFeatures;
	}
	if (extensionSupported("VK_HUAWEI_hdr_vivid")) {
		const char* extension("VK_HUAWEI_hdr_vivid");
		VkPhysicalDeviceHdrVividFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceHdrVividFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "hdrVivid", extFeatures->hdrVivid);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_IMG() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_IMG_relaxed_line_rasterization")) {
		const char* extension("VK_IMG_relaxed_line_rasterization");
		VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* extFeatures = new VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "relaxedLineRasterization", extFeatures->relaxedLineRasterization);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_INTEL() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_INTEL_shader_integer_functions2")) {
		const char* extension("VK_INTEL_shader_integer_functions2");
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* extFeatures = new VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerFunctions2", extFeatures->shaderIntegerFunctions2);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_KHR() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_KHR_dynamic_rendering")) {
		const char* extension("VK_KHR_dynamic_rendering");
		VkPhysicalDeviceDynamicRenderingFeatures* extFeatures = new VkPhysicalDeviceDynamicRenderingFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dynamicRendering", extFeatures->dynamicRendering);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewFeatures* extFeatures = new VkPhysicalDeviceMultiviewFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiview", extFeatures->multiview);
		pushFeature2(extension, "multiviewGeometryShader", extFeatures->multiviewGeometryShader);
		pushFeature2(extension, "multiviewTessellationShader", extFeatures->multiviewTessellationShader);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_float16_int8")) {
		const char* extension("VK_KHR_shader_float16_int8");
		VkPhysicalDeviceShaderFloat16Int8Features* extFeatures = new VkPhysicalDeviceShaderFloat16Int8Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat16", extFeatures->shaderFloat16);
		pushFeature2(extension, "shaderInt8", extFeatures->shaderInt8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_16bit_storage")) {
		const char* extension("VK_KHR_16bit_storage");
		VkPhysicalDevice16BitStorageFeatures* extFeatures = new VkPhysicalDevice16BitStorageFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer16BitAccess", extFeatures->storageBuffer16BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer16BitAccess", extFeatures->uniformAndStorageBuffer16BitAccess);
		pushFeature2(extension, "storagePushConstant16", extFeatures->storagePushConstant16);
		pushFeature2(extension, "storageInputOutput16", extFeatures->storageInputOutput16);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_imageless_framebuffer")) {
		const char* extension("VK_KHR_imageless_framebuffer");
		VkPhysicalDeviceImagelessFramebufferFeatures* extFeatures = new VkPhysicalDeviceImagelessFramebufferFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imagelessFramebuffer", extFeatures->imagelessFramebuffer);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryFeaturesKHR* extFeatures = new VkPhysicalDevicePerformanceQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "performanceCounterQueryPools", extFeatures->performanceCounterQueryPools);
		pushFeature2(extension, "performanceCounterMultipleQueryPools", extFeatures->performanceCounterMultipleQueryPools);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_variable_pointers")) {
		const char* extension("VK_KHR_variable_pointers");
		VkPhysicalDeviceVariablePointersFeatures* extFeatures = new VkPhysicalDeviceVariablePointersFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "variablePointersStorageBuffer", extFeatures->variablePointersStorageBuffer);
		pushFeature2(extension, "variablePointers", extFeatures->variablePointers);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_bfloat16")) {
		const char* extension("VK_KHR_shader_bfloat16");
		VkPhysicalDeviceShaderBfloat16FeaturesKHR* extFeatures = new VkPhysicalDeviceShaderBfloat16FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBFloat16Type", extFeatures->shaderBFloat16Type);
		pushFeature2(extension, "shaderBFloat16DotProduct", extFeatures->shaderBFloat16DotProduct);
		pushFeature2(extension, "shaderBFloat16CooperativeMatrix", extFeatures->shaderBFloat16CooperativeMatrix);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructureFeaturesKHR* extFeatures = new VkPhysicalDeviceAccelerationStructureFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "accelerationStructure", extFeatures->accelerationStructure);
		pushFeature2(extension, "accelerationStructureCaptureReplay", extFeatures->accelerationStructureCaptureReplay);
		pushFeature2(extension, "accelerationStructureIndirectBuild", extFeatures->accelerationStructureIndirectBuild);
		pushFeature2(extension, "accelerationStructureHostCommands", extFeatures->accelerationStructureHostCommands);
		pushFeature2(extension, "descriptorBindingAccelerationStructureUpdateAfterBind", extFeatures->descriptorBindingAccelerationStructureUpdateAfterBind);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR* extFeatures = new VkPhysicalDeviceRayTracingPipelineFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingPipeline", extFeatures->rayTracingPipeline);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplay", extFeatures->rayTracingPipelineShaderGroupHandleCaptureReplay);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplayMixed", extFeatures->rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect", extFeatures->rayTracingPipelineTraceRaysIndirect);
		pushFeature2(extension, "rayTraversalPrimitiveCulling", extFeatures->rayTraversalPrimitiveCulling);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_query")) {
		const char* extension("VK_KHR_ray_query");
		VkPhysicalDeviceRayQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceRayQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayQuery", extFeatures->rayQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_sampler_ycbcr_conversion")) {
		const char* extension("VK_KHR_sampler_ycbcr_conversion");
		VkPhysicalDeviceSamplerYcbcrConversionFeatures* extFeatures = new VkPhysicalDeviceSamplerYcbcrConversionFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "samplerYcbcrConversion", extFeatures->samplerYcbcrConversion);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetFeaturesKHR* extFeatures = new VkPhysicalDevicePortabilitySubsetFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "constantAlphaColorBlendFactors", extFeatures->constantAlphaColorBlendFactors);
		pushFeature2(extension, "events", extFeatures->events);
		pushFeature2(extension, "imageViewFormatReinterpretation", extFeatures->imageViewFormatReinterpretation);
		pushFeature2(extension, "imageViewFormatSwizzle", extFeatures->imageViewFormatSwizzle);
		pushFeature2(extension, "imageView2DOn3DImage", extFeatures->imageView2DOn3DImage);
		pushFeature2(extension, "multisampleArrayImage", extFeatures->multisampleArrayImage);
		pushFeature2(extension, "mutableComparisonSamplers", extFeatures->mutableComparisonSamplers);
		pushFeature2(extension, "pointPolygons", extFeatures->pointPolygons);
		pushFeature2(extension, "samplerMipLodBias", extFeatures->samplerMipLodBias);
		pushFeature2(extension, "separateStencilMaskRef", extFeatures->separateStencilMaskRef);
		pushFeature2(extension, "shaderSampleRateInterpolationFunctions", extFeatures->shaderSampleRateInterpolationFunctions);
		pushFeature2(extension, "tessellationIsolines", extFeatures->tessellationIsolines);
		pushFeature2(extension, "tessellationPointMode", extFeatures->tessellationPointMode);
		pushFeature2(extension, "triangleFans", extFeatures->triangleFans);
		pushFeature2(extension, "vertexAttributeAccessBeyondStride", extFeatures->vertexAttributeAccessBeyondStride);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_subgroup_extended_types")) {
		const char* extension("VK_KHR_shader_subgroup_extended_types");
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* extFeatures = new VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupExtendedTypes", extFeatures->shaderSubgroupExtendedTypes);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_8bit_storage")) {
		const char* extension("VK_KHR_8bit_storage");
		VkPhysicalDevice8BitStorageFeatures* extFeatures = new VkPhysicalDevice8BitStorageFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer8BitAccess", extFeatures->storageBuffer8BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer8BitAccess", extFeatures->uniformAndStorageBuffer8BitAccess);
		pushFeature2(extension, "storagePushConstant8", extFeatures->storagePushConstant8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_atomic_int64")) {
		const char* extension("VK_KHR_shader_atomic_int64");
		VkPhysicalDeviceShaderAtomicInt64Features* extFeatures = new VkPhysicalDeviceShaderAtomicInt64Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferInt64Atomics", extFeatures->shaderBufferInt64Atomics);
		pushFeature2(extension, "shaderSharedInt64Atomics", extFeatures->shaderSharedInt64Atomics);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_clock")) {
		const char* extension("VK_KHR_shader_clock");
		VkPhysicalDeviceShaderClockFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderClockFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupClock", extFeatures->shaderSubgroupClock);
		pushFeature2(extension, "shaderDeviceClock", extFeatures->shaderDeviceClock);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_global_priority")) {
		const char* extension("VK_KHR_global_priority");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures->globalPriorityQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreFeatures* extFeatures = new VkPhysicalDeviceTimelineSemaphoreFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "timelineSemaphore", extFeatures->timelineSemaphore);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_vulkan_memory_model")) {
		const char* extension("VK_KHR_vulkan_memory_model");
		VkPhysicalDeviceVulkanMemoryModelFeatures* extFeatures = new VkPhysicalDeviceVulkanMemoryModelFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vulkanMemoryModel", extFeatures->vulkanMemoryModel);
		pushFeature2(extension, "vulkanMemoryModelDeviceScope", extFeatures->vulkanMemoryModelDeviceScope);
		pushFeature2(extension, "vulkanMemoryModelAvailabilityVisibilityChains", extFeatures->vulkanMemoryModelAvailabilityVisibilityChains);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_terminate_invocation")) {
		const char* extension("VK_KHR_shader_terminate_invocation");
		VkPhysicalDeviceShaderTerminateInvocationFeatures* extFeatures = new VkPhysicalDeviceShaderTerminateInvocationFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderTerminateInvocation", extFeatures->shaderTerminateInvocation);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShadingRateFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineFragmentShadingRate", extFeatures->pipelineFragmentShadingRate);
		pushFeature2(extension, "primitiveFragmentShadingRate", extFeatures->primitiveFragmentShadingRate);
		pushFeature2(extension, "attachmentFragmentShadingRate", extFeatures->attachmentFragmentShadingRate);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_dynamic_rendering_local_read")) {
		const char* extension("VK_KHR_dynamic_rendering_local_read");
		VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* extFeatures = new VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dynamicRenderingLocalRead", extFeatures->dynamicRenderingLocalRead);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_quad_control")) {
		const char* extension("VK_KHR_shader_quad_control");
		VkPhysicalDeviceShaderQuadControlFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderQuadControlFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderQuadControl", extFeatures->shaderQuadControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_separate_depth_stencil_layouts")) {
		const char* extension("VK_KHR_separate_depth_stencil_layouts");
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* extFeatures = new VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "separateDepthStencilLayouts", extFeatures->separateDepthStencilLayouts);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_wait")) {
		const char* extension("VK_KHR_present_wait");
		VkPhysicalDevicePresentWaitFeaturesKHR* extFeatures = new VkPhysicalDevicePresentWaitFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentWait", extFeatures->presentWait);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_uniform_buffer_standard_layout")) {
		const char* extension("VK_KHR_uniform_buffer_standard_layout");
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures* extFeatures = new VkPhysicalDeviceUniformBufferStandardLayoutFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "uniformBufferStandardLayout", extFeatures->uniformBufferStandardLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_buffer_device_address")) {
		const char* extension("VK_KHR_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeatures* extFeatures = new VkPhysicalDeviceBufferDeviceAddressFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures->bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures->bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures->bufferDeviceAddressMultiDevice);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_pipeline_executable_properties")) {
		const char* extension("VK_KHR_pipeline_executable_properties");
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* extFeatures = new VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineExecutableInfo", extFeatures->pipelineExecutableInfo);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductFeatures* extFeatures = new VkPhysicalDeviceShaderIntegerDotProductFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerDotProduct", extFeatures->shaderIntegerDotProduct);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_id")) {
		const char* extension("VK_KHR_present_id");
		VkPhysicalDevicePresentIdFeaturesKHR* extFeatures = new VkPhysicalDevicePresentIdFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentId", extFeatures->presentId);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_synchronization2")) {
		const char* extension("VK_KHR_synchronization2");
		VkPhysicalDeviceSynchronization2Features* extFeatures = new VkPhysicalDeviceSynchronization2Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "synchronization2", extFeatures->synchronization2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures->fragmentShaderBarycentric);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_subgroup_uniform_control_flow")) {
		const char* extension("VK_KHR_shader_subgroup_uniform_control_flow");
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupUniformControlFlow", extFeatures->shaderSubgroupUniformControlFlow);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_zero_initialize_workgroup_memory")) {
		const char* extension("VK_KHR_zero_initialize_workgroup_memory");
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* extFeatures = new VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderZeroInitializeWorkgroupMemory", extFeatures->shaderZeroInitializeWorkgroupMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_workgroup_memory_explicit_layout")) {
		const char* extension("VK_KHR_workgroup_memory_explicit_layout");
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* extFeatures = new VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "workgroupMemoryExplicitLayout", extFeatures->workgroupMemoryExplicitLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayoutScalarBlockLayout", extFeatures->workgroupMemoryExplicitLayoutScalarBlockLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayout8BitAccess", extFeatures->workgroupMemoryExplicitLayout8BitAccess);
		pushFeature2(extension, "workgroupMemoryExplicitLayout16BitAccess", extFeatures->workgroupMemoryExplicitLayout16BitAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_tracing_maintenance1")) {
		const char* extension("VK_KHR_ray_tracing_maintenance1");
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* extFeatures = new VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMaintenance1", extFeatures->rayTracingMaintenance1);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect2", extFeatures->rayTracingPipelineTraceRaysIndirect2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_untyped_pointers")) {
		const char* extension("VK_KHR_shader_untyped_pointers");
		VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderUntypedPointersFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderUntypedPointers", extFeatures->shaderUntypedPointers);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Features* extFeatures = new VkPhysicalDeviceMaintenance4Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance4", extFeatures->maintenance4);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_subgroup_rotate")) {
		const char* extension("VK_KHR_shader_subgroup_rotate");
		VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupRotate", extFeatures->shaderSubgroupRotate);
		pushFeature2(extension, "shaderSubgroupRotateClustered", extFeatures->shaderSubgroupRotateClustered);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_maximal_reconvergence")) {
		const char* extension("VK_KHR_shader_maximal_reconvergence");
		VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderMaximalReconvergence", extFeatures->shaderMaximalReconvergence);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance5")) {
		const char* extension("VK_KHR_maintenance5");
		VkPhysicalDeviceMaintenance5FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance5FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance5", extFeatures->maintenance5);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_id2")) {
		const char* extension("VK_KHR_present_id2");
		VkPhysicalDevicePresentId2FeaturesKHR* extFeatures = new VkPhysicalDevicePresentId2FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentId2", extFeatures->presentId2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_wait2")) {
		const char* extension("VK_KHR_present_wait2");
		VkPhysicalDevicePresentWait2FeaturesKHR* extFeatures = new VkPhysicalDevicePresentWait2FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentWait2", extFeatures->presentWait2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_tracing_position_fetch")) {
		const char* extension("VK_KHR_ray_tracing_position_fetch");
		VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* extFeatures = new VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingPositionFetch", extFeatures->rayTracingPositionFetch);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_pipeline_binary")) {
		const char* extension("VK_KHR_pipeline_binary");
		VkPhysicalDevicePipelineBinaryFeaturesKHR* extFeatures = new VkPhysicalDevicePipelineBinaryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineBinaries", extFeatures->pipelineBinaries);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_swapchain_maintenance1")) {
		const char* extension("VK_KHR_swapchain_maintenance1");
		VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* extFeatures = new VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "swapchainMaintenance1", extFeatures->swapchainMaintenance1);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_cooperative_matrix")) {
		const char* extension("VK_KHR_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixFeaturesKHR* extFeatures = new VkPhysicalDeviceCooperativeMatrixFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrix", extFeatures->cooperativeMatrix);
		pushFeature2(extension, "cooperativeMatrixRobustBufferAccess", extFeatures->cooperativeMatrixRobustBufferAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_compute_shader_derivatives")) {
		const char* extension("VK_KHR_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* extFeatures = new VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures->computeDerivativeGroupQuads);
		pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures->computeDerivativeGroupLinear);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_encode_av1")) {
		const char* extension("VK_KHR_video_encode_av1");
		VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* extFeatures = new VkPhysicalDeviceVideoEncodeAV1FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoEncodeAV1", extFeatures->videoEncodeAV1);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_decode_vp9")) {
		const char* extension("VK_KHR_video_decode_vp9");
		VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* extFeatures = new VkPhysicalDeviceVideoDecodeVP9FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoDecodeVP9", extFeatures->videoDecodeVP9);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_maintenance1")) {
		const char* extension("VK_KHR_video_maintenance1");
		VkPhysicalDeviceVideoMaintenance1FeaturesKHR* extFeatures = new VkPhysicalDeviceVideoMaintenance1FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoMaintenance1", extFeatures->videoMaintenance1);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_vertex_attribute_divisor")) {
		const char* extension("VK_KHR_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* extFeatures = new VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures->vertexAttributeInstanceRateDivisor);
		pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures->vertexAttributeInstanceRateZeroDivisor);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_unified_image_layouts")) {
		const char* extension("VK_KHR_unified_image_layouts");
		VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* extFeatures = new VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "unifiedImageLayouts", extFeatures->unifiedImageLayouts);
		pushFeature2(extension, "unifiedImageLayoutsVideo", extFeatures->unifiedImageLayoutsVideo);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_float_controls2")) {
		const char* extension("VK_KHR_shader_float_controls2");
		VkPhysicalDeviceShaderFloatControls2FeaturesKHR* extFeatures = new VkPhysicalDeviceShaderFloatControls2FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFloatControls2", extFeatures->shaderFloatControls2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_index_type_uint8")) {
		const char* extension("VK_KHR_index_type_uint8");
		VkPhysicalDeviceIndexTypeUint8FeaturesKHR* extFeatures = new VkPhysicalDeviceIndexTypeUint8FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indexTypeUint8", extFeatures->indexTypeUint8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_line_rasterization")) {
		const char* extension("VK_KHR_line_rasterization");
		VkPhysicalDeviceLineRasterizationFeaturesKHR* extFeatures = new VkPhysicalDeviceLineRasterizationFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rectangularLines", extFeatures->rectangularLines);
		pushFeature2(extension, "bresenhamLines", extFeatures->bresenhamLines);
		pushFeature2(extension, "smoothLines", extFeatures->smoothLines);
		pushFeature2(extension, "stippledRectangularLines", extFeatures->stippledRectangularLines);
		pushFeature2(extension, "stippledBresenhamLines", extFeatures->stippledBresenhamLines);
		pushFeature2(extension, "stippledSmoothLines", extFeatures->stippledSmoothLines);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_expect_assume")) {
		const char* extension("VK_KHR_shader_expect_assume");
		VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderExpectAssumeFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderExpectAssume", extFeatures->shaderExpectAssume);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance6")) {
		const char* extension("VK_KHR_maintenance6");
		VkPhysicalDeviceMaintenance6FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance6FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance6", extFeatures->maintenance6);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_copy_memory_indirect")) {
		const char* extension("VK_KHR_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* extFeatures = new VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indirectMemoryCopy", extFeatures->indirectMemoryCopy);
		pushFeature2(extension, "indirectMemoryToImageCopy", extFeatures->indirectMemoryToImageCopy);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_encode_intra_refresh")) {
		const char* extension("VK_KHR_video_encode_intra_refresh");
		VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* extFeatures = new VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoEncodeIntraRefresh", extFeatures->videoEncodeIntraRefresh);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_encode_quantization_map")) {
		const char* extension("VK_KHR_video_encode_quantization_map");
		VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* extFeatures = new VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoEncodeQuantizationMap", extFeatures->videoEncodeQuantizationMap);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_relaxed_extended_instruction")) {
		const char* extension("VK_KHR_shader_relaxed_extended_instruction");
		VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderRelaxedExtendedInstruction", extFeatures->shaderRelaxedExtendedInstruction);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance7")) {
		const char* extension("VK_KHR_maintenance7");
		VkPhysicalDeviceMaintenance7FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance7FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance7", extFeatures->maintenance7);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance8")) {
		const char* extension("VK_KHR_maintenance8");
		VkPhysicalDeviceMaintenance8FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance8FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance8", extFeatures->maintenance8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_fma")) {
		const char* extension("VK_KHR_shader_fma");
		VkPhysicalDeviceShaderFmaFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderFmaFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFmaFloat16", extFeatures->shaderFmaFloat16);
		pushFeature2(extension, "shaderFmaFloat32", extFeatures->shaderFmaFloat32);
		pushFeature2(extension, "shaderFmaFloat64", extFeatures->shaderFmaFloat64);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance9")) {
		const char* extension("VK_KHR_maintenance9");
		VkPhysicalDeviceMaintenance9FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance9FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance9", extFeatures->maintenance9);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_video_maintenance2")) {
		const char* extension("VK_KHR_video_maintenance2");
		VkPhysicalDeviceVideoMaintenance2FeaturesKHR* extFeatures = new VkPhysicalDeviceVideoMaintenance2FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoMaintenance2", extFeatures->videoMaintenance2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_depth_clamp_zero_one")) {
		const char* extension("VK_KHR_depth_clamp_zero_one");
		VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* extFeatures = new VkPhysicalDeviceDepthClampZeroOneFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClampZeroOne", extFeatures->depthClampZeroOne);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_robustness2")) {
		const char* extension("VK_KHR_robustness2");
		VkPhysicalDeviceRobustness2FeaturesKHR* extFeatures = new VkPhysicalDeviceRobustness2FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "robustBufferAccess2", extFeatures->robustBufferAccess2);
		pushFeature2(extension, "robustImageAccess2", extFeatures->robustImageAccess2);
		pushFeature2(extension, "nullDescriptor", extFeatures->nullDescriptor);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_mode_fifo_latest_ready")) {
		const char* extension("VK_KHR_present_mode_fifo_latest_ready");
		VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* extFeatures = new VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentModeFifoLatestReady", extFeatures->presentModeFifoLatestReady);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance10")) {
		const char* extension("VK_KHR_maintenance10");
		VkPhysicalDeviceMaintenance10FeaturesKHR* extFeatures = new VkPhysicalDeviceMaintenance10FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance10", extFeatures->maintenance10);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_MESA() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_MESA_image_alignment_control")) {
		const char* extension("VK_MESA_image_alignment_control");
		VkPhysicalDeviceImageAlignmentControlFeaturesMESA* extFeatures = new VkPhysicalDeviceImageAlignmentControlFeaturesMESA{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageAlignmentControl", extFeatures->imageAlignmentControl);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_NV() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_NV_corner_sampled_image")) {
		const char* extension("VK_NV_corner_sampled_image");
		VkPhysicalDeviceCornerSampledImageFeaturesNV* extFeatures = new VkPhysicalDeviceCornerSampledImageFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cornerSampledImage", extFeatures->cornerSampledImage);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* extFeatures = new VkPhysicalDeviceShaderSMBuiltinsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSMBuiltins", extFeatures->shaderSMBuiltins);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImageFeaturesNV* extFeatures = new VkPhysicalDeviceShadingRateImageFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shadingRateImage", extFeatures->shadingRateImage);
		pushFeature2(extension, "shadingRateCoarseSampleOrder", extFeatures->shadingRateCoarseSampleOrder);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_representative_fragment_test")) {
		const char* extension("VK_NV_representative_fragment_test");
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* extFeatures = new VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "representativeFragmentTest", extFeatures->representativeFragmentTest);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_compute_shader_derivatives")) {
		const char* extension("VK_NV_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* extFeatures = new VkPhysicalDeviceComputeShaderDerivativesFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures->computeDerivativeGroupQuads);
		pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures->computeDerivativeGroupLinear);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesNV* extFeatures = new VkPhysicalDeviceMeshShaderFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures->taskShader);
		pushFeature2(extension, "meshShader", extFeatures->meshShader);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_fragment_shader_barycentric")) {
		const char* extension("VK_NV_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures->fragmentShaderBarycentric);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shader_image_footprint")) {
		const char* extension("VK_NV_shader_image_footprint");
		VkPhysicalDeviceShaderImageFootprintFeaturesNV* extFeatures = new VkPhysicalDeviceShaderImageFootprintFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageFootprint", extFeatures->imageFootprint);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_scissor_exclusive")) {
		const char* extension("VK_NV_scissor_exclusive");
		VkPhysicalDeviceExclusiveScissorFeaturesNV* extFeatures = new VkPhysicalDeviceExclusiveScissorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "exclusiveScissor", extFeatures->exclusiveScissor);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_dedicated_allocation_image_aliasing")) {
		const char* extension("VK_NV_dedicated_allocation_image_aliasing");
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* extFeatures = new VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dedicatedAllocationImageAliasing", extFeatures->dedicatedAllocationImageAliasing);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixFeaturesNV* extFeatures = new VkPhysicalDeviceCooperativeMatrixFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrix", extFeatures->cooperativeMatrix);
		pushFeature2(extension, "cooperativeMatrixRobustBufferAccess", extFeatures->cooperativeMatrixRobustBufferAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_coverage_reduction_mode")) {
		const char* extension("VK_NV_coverage_reduction_mode");
		VkPhysicalDeviceCoverageReductionModeFeaturesNV* extFeatures = new VkPhysicalDeviceCoverageReductionModeFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "coverageReductionMode", extFeatures->coverageReductionMode);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* extFeatures = new VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCommands", extFeatures->deviceGeneratedCommands);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_inherited_viewport_scissor")) {
		const char* extension("VK_NV_inherited_viewport_scissor");
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV* extFeatures = new VkPhysicalDeviceInheritedViewportScissorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "inheritedViewportScissor2D", extFeatures->inheritedViewportScissor2D);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_present_barrier")) {
		const char* extension("VK_NV_present_barrier");
		VkPhysicalDevicePresentBarrierFeaturesNV* extFeatures = new VkPhysicalDevicePresentBarrierFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentBarrier", extFeatures->presentBarrier);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_device_diagnostics_config")) {
		const char* extension("VK_NV_device_diagnostics_config");
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV* extFeatures = new VkPhysicalDeviceDiagnosticsConfigFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "diagnosticsConfig", extFeatures->diagnosticsConfig);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cuda_kernel_launch")) {
		const char* extension("VK_NV_cuda_kernel_launch");
		VkPhysicalDeviceCudaKernelLaunchFeaturesNV* extFeatures = new VkPhysicalDeviceCudaKernelLaunchFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cudaKernelLaunchFeatures", extFeatures->cudaKernelLaunchFeatures);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* extFeatures = new VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShadingRateEnums", extFeatures->fragmentShadingRateEnums);
		pushFeature2(extension, "supersampleFragmentShadingRates", extFeatures->supersampleFragmentShadingRates);
		pushFeature2(extension, "noInvocationFragmentShadingRates", extFeatures->noInvocationFragmentShadingRates);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_motion_blur")) {
		const char* extension("VK_NV_ray_tracing_motion_blur");
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingMotionBlurFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMotionBlur", extFeatures->rayTracingMotionBlur);
		pushFeature2(extension, "rayTracingMotionBlurPipelineTraceRaysIndirect", extFeatures->rayTracingMotionBlurPipelineTraceRaysIndirect);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_external_memory_rdma")) {
		const char* extension("VK_NV_external_memory_rdma");
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* extFeatures = new VkPhysicalDeviceExternalMemoryRDMAFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "externalMemoryRDMA", extFeatures->externalMemoryRDMA);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_displacement_micromap")) {
		const char* extension("VK_NV_displacement_micromap");
		VkPhysicalDeviceDisplacementMicromapFeaturesNV* extFeatures = new VkPhysicalDeviceDisplacementMicromapFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "displacementMicromap", extFeatures->displacementMicromap);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV* extFeatures = new VkPhysicalDeviceCopyMemoryIndirectFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indirectCopy", extFeatures->indirectCopy);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionFeaturesNV* extFeatures = new VkPhysicalDeviceMemoryDecompressionFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryDecompression", extFeatures->memoryDecompression);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_device_generated_commands_compute")) {
		const char* extension("VK_NV_device_generated_commands_compute");
		VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* extFeatures = new VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCompute", extFeatures->deviceGeneratedCompute);
		pushFeature2(extension, "deviceGeneratedComputePipelines", extFeatures->deviceGeneratedComputePipelines);
		pushFeature2(extension, "deviceGeneratedComputeCaptureReplay", extFeatures->deviceGeneratedComputeCaptureReplay);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_linear_swept_spheres")) {
		const char* extension("VK_NV_ray_tracing_linear_swept_spheres");
		VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "spheres", extFeatures->spheres);
		pushFeature2(extension, "linearSweptSpheres", extFeatures->linearSweptSpheres);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_linear_color_attachment")) {
		const char* extension("VK_NV_linear_color_attachment");
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV* extFeatures = new VkPhysicalDeviceLinearColorAttachmentFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "linearColorAttachment", extFeatures->linearColorAttachment);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowFeaturesNV* extFeatures = new VkPhysicalDeviceOpticalFlowFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "opticalFlow", extFeatures->opticalFlow);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingInvocationReorder", extFeatures->rayTracingInvocationReorder);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cooperative_vector")) {
		const char* extension("VK_NV_cooperative_vector");
		VkPhysicalDeviceCooperativeVectorFeaturesNV* extFeatures = new VkPhysicalDeviceCooperativeVectorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cooperativeVector", extFeatures->cooperativeVector);
		pushFeature2(extension, "cooperativeVectorTraining", extFeatures->cooperativeVectorTraining);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_extended_sparse_address_space")) {
		const char* extension("VK_NV_extended_sparse_address_space");
		VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* extFeatures = new VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedSparseAddressSpace", extFeatures->extendedSparseAddressSpace);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_per_stage_descriptor_set")) {
		const char* extension("VK_NV_per_stage_descriptor_set");
		VkPhysicalDevicePerStageDescriptorSetFeaturesNV* extFeatures = new VkPhysicalDevicePerStageDescriptorSetFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "perStageDescriptorSet", extFeatures->perStageDescriptorSet);
		pushFeature2(extension, "dynamicPipelineLayout", extFeatures->dynamicPipelineLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_descriptor_pool_overallocation")) {
		const char* extension("VK_NV_descriptor_pool_overallocation");
		VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* extFeatures = new VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "descriptorPoolOverallocation", extFeatures->descriptorPoolOverallocation);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_raw_access_chains")) {
		const char* extension("VK_NV_raw_access_chains");
		VkPhysicalDeviceRawAccessChainsFeaturesNV* extFeatures = new VkPhysicalDeviceRawAccessChainsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderRawAccessChains", extFeatures->shaderRawAccessChains);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_command_buffer_inheritance")) {
		const char* extension("VK_NV_command_buffer_inheritance");
		VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* extFeatures = new VkPhysicalDeviceCommandBufferInheritanceFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "commandBufferInheritance", extFeatures->commandBufferInheritance);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shader_atomic_float16_vector")) {
		const char* extension("VK_NV_shader_atomic_float16_vector");
		VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* extFeatures = new VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat16VectorAtomics", extFeatures->shaderFloat16VectorAtomics);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_validation")) {
		const char* extension("VK_NV_ray_tracing_validation");
		VkPhysicalDeviceRayTracingValidationFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingValidationFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingValidation", extFeatures->rayTracingValidation);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cluster_acceleration_structure")) {
		const char* extension("VK_NV_cluster_acceleration_structure");
		VkPhysicalDeviceClusterAccelerationStructureFeaturesNV* extFeatures = new VkPhysicalDeviceClusterAccelerationStructureFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "clusterAccelerationStructure", extFeatures->clusterAccelerationStructure);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_partitioned_acceleration_structure")) {
		const char* extension("VK_NV_partitioned_acceleration_structure");
		VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* extFeatures = new VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "partitionedAccelerationStructure", extFeatures->partitionedAccelerationStructure);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cooperative_matrix2")) {
		const char* extension("VK_NV_cooperative_matrix2");
		VkPhysicalDeviceCooperativeMatrix2FeaturesNV* extFeatures = new VkPhysicalDeviceCooperativeMatrix2FeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrixWorkgroupScope", extFeatures->cooperativeMatrixWorkgroupScope);
		pushFeature2(extension, "cooperativeMatrixFlexibleDimensions", extFeatures->cooperativeMatrixFlexibleDimensions);
		pushFeature2(extension, "cooperativeMatrixReductions", extFeatures->cooperativeMatrixReductions);
		pushFeature2(extension, "cooperativeMatrixConversions", extFeatures->cooperativeMatrixConversions);
		pushFeature2(extension, "cooperativeMatrixPerElementOperations", extFeatures->cooperativeMatrixPerElementOperations);
		pushFeature2(extension, "cooperativeMatrixTensorAddressing", extFeatures->cooperativeMatrixTensorAddressing);
		pushFeature2(extension, "cooperativeMatrixBlockLoads", extFeatures->cooperativeMatrixBlockLoads);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_present_metering")) {
		const char* extension("VK_NV_present_metering");
		VkPhysicalDevicePresentMeteringFeaturesNV* extFeatures = new VkPhysicalDevicePresentMeteringFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentMetering", extFeatures->presentMetering);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_QCOM() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_QCOM_tile_shading")) {
		const char* extension("VK_QCOM_tile_shading");
		VkPhysicalDeviceTileShadingFeaturesQCOM* extFeatures = new VkPhysicalDeviceTileShadingFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "tileShading", extFeatures->tileShading);
		pushFeature2(extension, "tileShadingFragmentStage", extFeatures->tileShadingFragmentStage);
		pushFeature2(extension, "tileShadingColorAttachments", extFeatures->tileShadingColorAttachments);
		pushFeature2(extension, "tileShadingDepthAttachments", extFeatures->tileShadingDepthAttachments);
		pushFeature2(extension, "tileShadingStencilAttachments", extFeatures->tileShadingStencilAttachments);
		pushFeature2(extension, "tileShadingInputAttachments", extFeatures->tileShadingInputAttachments);
		pushFeature2(extension, "tileShadingSampledAttachments", extFeatures->tileShadingSampledAttachments);
		pushFeature2(extension, "tileShadingPerTileDraw", extFeatures->tileShadingPerTileDraw);
		pushFeature2(extension, "tileShadingPerTileDispatch", extFeatures->tileShadingPerTileDispatch);
		pushFeature2(extension, "tileShadingDispatchTile", extFeatures->tileShadingDispatchTile);
		pushFeature2(extension, "tileShadingApron", extFeatures->tileShadingApron);
		pushFeature2(extension, "tileShadingAnisotropicApron", extFeatures->tileShadingAnisotropicApron);
		pushFeature2(extension, "tileShadingAtomicOps", extFeatures->tileShadingAtomicOps);
		pushFeature2(extension, "tileShadingImageProcessing", extFeatures->tileShadingImageProcessing);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* extFeatures = new VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapOffset", extFeatures->fragmentDensityMapOffset);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingFeaturesQCOM* extFeatures = new VkPhysicalDeviceImageProcessingFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "textureSampleWeighted", extFeatures->textureSampleWeighted);
		pushFeature2(extension, "textureBoxFilter", extFeatures->textureBoxFilter);
		pushFeature2(extension, "textureBlockMatch", extFeatures->textureBlockMatch);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_tile_properties")) {
		const char* extension("VK_QCOM_tile_properties");
		VkPhysicalDeviceTilePropertiesFeaturesQCOM* extFeatures = new VkPhysicalDeviceTilePropertiesFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "tileProperties", extFeatures->tileProperties);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_multiview_per_view_viewports")) {
		const char* extension("VK_QCOM_multiview_per_view_viewports");
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* extFeatures = new VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiviewPerViewViewports", extFeatures->multiviewPerViewViewports);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_multiview_per_view_render_areas")) {
		const char* extension("VK_QCOM_multiview_per_view_render_areas");
		VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* extFeatures = new VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiviewPerViewRenderAreas", extFeatures->multiviewPerViewRenderAreas);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_image_processing2")) {
		const char* extension("VK_QCOM_image_processing2");
		VkPhysicalDeviceImageProcessing2FeaturesQCOM* extFeatures = new VkPhysicalDeviceImageProcessing2FeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "textureBlockMatch2", extFeatures->textureBlockMatch2);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_filter_cubic_weights")) {
		const char* extension("VK_QCOM_filter_cubic_weights");
		VkPhysicalDeviceCubicWeightsFeaturesQCOM* extFeatures = new VkPhysicalDeviceCubicWeightsFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "selectableCubicWeights", extFeatures->selectableCubicWeights);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_ycbcr_degamma")) {
		const char* extension("VK_QCOM_ycbcr_degamma");
		VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* extFeatures = new VkPhysicalDeviceYcbcrDegammaFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "ycbcrDegamma", extFeatures->ycbcrDegamma);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_filter_cubic_clamp")) {
		const char* extension("VK_QCOM_filter_cubic_clamp");
		VkPhysicalDeviceCubicClampFeaturesQCOM* extFeatures = new VkPhysicalDeviceCubicClampFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cubicRangeClamp", extFeatures->cubicRangeClamp);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_tile_memory_heap")) {
		const char* extension("VK_QCOM_tile_memory_heap");
		VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* extFeatures = new VkPhysicalDeviceTileMemoryHeapFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "tileMemoryHeap", extFeatures->tileMemoryHeap);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_QNX() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
	if (extensionSupported("VK_QNX_external_memory_screen_buffer")) {
		const char* extension("VK_QNX_external_memory_screen_buffer");
		VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX* extFeatures = new VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "screenBufferImport", extFeatures->screenBufferImport);
		delete extFeatures;
	}
#endif
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_SEC() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_SEC_amigo_profiling")) {
		const char* extension("VK_SEC_amigo_profiling");
		VkPhysicalDeviceAmigoProfilingFeaturesSEC* extFeatures = new VkPhysicalDeviceAmigoProfilingFeaturesSEC{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "amigoProfiling", extFeatures->amigoProfiling);
		delete extFeatures;
	}
	if (extensionSupported("VK_SEC_pipeline_cache_incremental_mode")) {
		const char* extension("VK_SEC_pipeline_cache_incremental_mode");
		VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* extFeatures = new VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineCacheIncrementalMode", extFeatures->pipelineCacheIncrementalMode);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_VALVE() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_VALVE_mutable_descriptor_type")) {
		const char* extension("VK_VALVE_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* extFeatures = new VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures->mutableDescriptorType);
		delete extFeatures;
	}
	if (extensionSupported("VK_VALVE_video_encode_rgb_conversion")) {
		const char* extension("VK_VALVE_video_encode_rgb_conversion");
		VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* extFeatures = new VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "videoEncodeRgbConversion", extFeatures->videoEncodeRgbConversion);
		delete extFeatures;
	}
	if (extensionSupported("VK_VALVE_descriptor_set_host_mapping")) {
		const char* extension("VK_VALVE_descriptor_set_host_mapping");
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* extFeatures = new VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "descriptorSetHostMapping", extFeatures->descriptorSetHostMapping);
		delete extFeatures;
	}
	if (extensionSupported("VK_VALVE_fragment_density_map_layered")) {
		const char* extension("VK_VALVE_fragment_density_map_layered");
		VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* extFeatures = new VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapLayered", extFeatures->fragmentDensityMapLayered);
		delete extFeatures;
	}
}


void VulkanDeviceInfoExtensions::readExtendedFeatures() {
    readPhysicalFeatures_AMD();
    readPhysicalFeatures_AMDX();
    readPhysicalFeatures_ANDROID();
    readPhysicalFeatures_ARM();
    readPhysicalFeatures_EXT();
    readPhysicalFeatures_HUAWEI();
    readPhysicalFeatures_IMG();
    readPhysicalFeatures_INTEL();
    readPhysicalFeatures_KHR();
    readPhysicalFeatures_MESA();
    readPhysicalFeatures_NV();
    readPhysicalFeatures_QCOM();
    readPhysicalFeatures_QNX();
    readPhysicalFeatures_SEC();
    readPhysicalFeatures_VALVE();
}
