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
	if (extensionSupported("VK_AMD_shader_core_properties")) {
		const char* extension("VK_AMD_shader_core_properties");
		VkPhysicalDeviceShaderCorePropertiesAMD extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderEngineCount", QVariant(extProps.shaderEngineCount));
		pushProperty2(extension, "shaderArraysPerEngineCount", QVariant(extProps.shaderArraysPerEngineCount));
		pushProperty2(extension, "computeUnitsPerShaderArray", QVariant(extProps.computeUnitsPerShaderArray));
		pushProperty2(extension, "simdPerComputeUnit", QVariant(extProps.simdPerComputeUnit));
		pushProperty2(extension, "wavefrontsPerSimd", QVariant(extProps.wavefrontsPerSimd));
		pushProperty2(extension, "wavefrontSize", QVariant(extProps.wavefrontSize));
		pushProperty2(extension, "sgprsPerSimd", QVariant(extProps.sgprsPerSimd));
		pushProperty2(extension, "minSgprAllocation", QVariant(extProps.minSgprAllocation));
		pushProperty2(extension, "maxSgprAllocation", QVariant(extProps.maxSgprAllocation));
		pushProperty2(extension, "sgprAllocationGranularity", QVariant(extProps.sgprAllocationGranularity));
		pushProperty2(extension, "vgprsPerSimd", QVariant(extProps.vgprsPerSimd));
		pushProperty2(extension, "minVgprAllocation", QVariant(extProps.minVgprAllocation));
		pushProperty2(extension, "maxVgprAllocation", QVariant(extProps.maxVgprAllocation));
		pushProperty2(extension, "vgprAllocationGranularity", QVariant(extProps.vgprAllocationGranularity));
	}
	if (extensionSupported("VK_AMD_shader_core_properties2")) {
		const char* extension("VK_AMD_shader_core_properties2");
		VkPhysicalDeviceShaderCoreProperties2AMD extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderCoreFeatures", QVariant(extProps.shaderCoreFeatures));
		pushProperty2(extension, "activeComputeUnitCount", QVariant(extProps.activeComputeUnitCount));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_ARM() {
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderCoreMask", QVariant::fromValue(extProps.shaderCoreMask));
		pushProperty2(extension, "shaderCoreCount", QVariant(extProps.shaderCoreCount));
		pushProperty2(extension, "shaderWarpsPerCore", QVariant(extProps.shaderWarpsPerCore));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_EXT() {
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
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
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "defaultRobustnessStorageBuffers", QVariant(extProps.defaultRobustnessStorageBuffers));
		pushProperty2(extension, "defaultRobustnessUniformBuffers", QVariant(extProps.defaultRobustnessUniformBuffers));
		pushProperty2(extension, "defaultRobustnessVertexInputs", QVariant(extProps.defaultRobustnessVertexInputs));
		pushProperty2(extension, "defaultRobustnessImages", QVariant(extProps.defaultRobustnessImages));
	}
	if (extensionSupported("VK_EXT_discard_rectangles")) {
		const char* extension("VK_EXT_discard_rectangles");
		VkPhysicalDeviceDiscardRectanglePropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxDiscardRectangles", QVariant(extProps.maxDiscardRectangles));
	}
	if (extensionSupported("VK_EXT_conservative_rasterization")) {
		const char* extension("VK_EXT_conservative_rasterization");
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "primitiveOverestimationSize", QVariant(extProps.primitiveOverestimationSize));
		pushProperty2(extension, "maxExtraPrimitiveOverestimationSize", QVariant(extProps.maxExtraPrimitiveOverestimationSize));
		pushProperty2(extension, "extraPrimitiveOverestimationSizeGranularity", QVariant(extProps.extraPrimitiveOverestimationSizeGranularity));
		pushProperty2(extension, "primitiveUnderestimation", QVariant(bool(extProps.primitiveUnderestimation)));
		pushProperty2(extension, "conservativePointAndLineRasterization", QVariant(bool(extProps.conservativePointAndLineRasterization)));
		pushProperty2(extension, "degenerateTrianglesRasterized", QVariant(bool(extProps.degenerateTrianglesRasterized)));
		pushProperty2(extension, "degenerateLinesRasterized", QVariant(bool(extProps.degenerateLinesRasterized)));
		pushProperty2(extension, "fullyCoveredFragmentShaderInputVariable", QVariant(bool(extProps.fullyCoveredFragmentShaderInputVariable)));
		pushProperty2(extension, "conservativeRasterizationPostDepthCoverage", QVariant(bool(extProps.conservativeRasterizationPostDepthCoverage)));
	}
	if (extensionSupported("VK_EXT_sampler_filter_minmax")) {
		const char* extension("VK_EXT_sampler_filter_minmax");
		VkPhysicalDeviceSamplerFilterMinmaxProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "filterMinmaxSingleComponentFormats", QVariant(bool(extProps.filterMinmaxSingleComponentFormats)));
		pushProperty2(extension, "filterMinmaxImageComponentMapping", QVariant(bool(extProps.filterMinmaxImageComponentMapping)));
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxInlineUniformBlockSize", QVariant(extProps.maxInlineUniformBlockSize));
		pushProperty2(extension, "maxPerStageDescriptorInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorInlineUniformBlocks));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks));
		pushProperty2(extension, "maxDescriptorSetInlineUniformBlocks", QVariant(extProps.maxDescriptorSetInlineUniformBlocks));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", QVariant(extProps.maxDescriptorSetUpdateAfterBindInlineUniformBlocks));
	}
	if (extensionSupported("VK_EXT_sample_locations")) {
		const char* extension("VK_EXT_sample_locations");
		VkPhysicalDeviceSampleLocationsPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "sampleLocationSampleCounts", QVariant(extProps.sampleLocationSampleCounts));
		pushProperty2(extension, "maxSampleLocationGridSize", QVariant::fromValue(QVariantList({ extProps.maxSampleLocationGridSize.width, extProps.maxSampleLocationGridSize.height })));
		pushProperty2(extension, "sampleLocationCoordinateRange", QVariant::fromValue(QVariantList({ extProps.sampleLocationCoordinateRange[0], extProps.sampleLocationCoordinateRange[1] })));
		pushProperty2(extension, "sampleLocationSubPixelBits", QVariant(extProps.sampleLocationSubPixelBits));
		pushProperty2(extension, "variableSampleLocations", QVariant(bool(extProps.variableSampleLocations)));
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "advancedBlendMaxColorAttachments", QVariant(extProps.advancedBlendMaxColorAttachments));
		pushProperty2(extension, "advancedBlendIndependentBlend", QVariant(bool(extProps.advancedBlendIndependentBlend)));
		pushProperty2(extension, "advancedBlendNonPremultipliedSrcColor", QVariant(bool(extProps.advancedBlendNonPremultipliedSrcColor)));
		pushProperty2(extension, "advancedBlendNonPremultipliedDstColor", QVariant(bool(extProps.advancedBlendNonPremultipliedDstColor)));
		pushProperty2(extension, "advancedBlendCorrelatedOverlap", QVariant(bool(extProps.advancedBlendCorrelatedOverlap)));
		pushProperty2(extension, "advancedBlendAllOperations", QVariant(bool(extProps.advancedBlendAllOperations)));
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
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
	if (extensionSupported("VK_EXT_external_memory_host")) {
		const char* extension("VK_EXT_external_memory_host");
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minImportedHostPointerAlignment", QVariant::fromValue(extProps.minImportedHostPointerAlignment));
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxVertexAttribDivisor", QVariant(extProps.maxVertexAttribDivisor));
	}
	if (extensionSupported("VK_EXT_pci_bus_info")) {
		const char* extension("VK_EXT_pci_bus_info");
		VkPhysicalDevicePCIBusInfoPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pciDomain", QVariant(extProps.pciDomain));
		pushProperty2(extension, "pciBus", QVariant(extProps.pciBus));
		pushProperty2(extension, "pciDevice", QVariant(extProps.pciDevice));
		pushProperty2(extension, "pciFunction", QVariant(extProps.pciFunction));
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps.minFragmentDensityTexelSize.width, extProps.minFragmentDensityTexelSize.height })));
		pushProperty2(extension, "maxFragmentDensityTexelSize", QVariant::fromValue(QVariantList({ extProps.maxFragmentDensityTexelSize.width, extProps.maxFragmentDensityTexelSize.height })));
		pushProperty2(extension, "fragmentDensityInvocations", QVariant(bool(extProps.fragmentDensityInvocations)));
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minSubgroupSize", QVariant(extProps.minSubgroupSize));
		pushProperty2(extension, "maxSubgroupSize", QVariant(extProps.maxSubgroupSize));
		pushProperty2(extension, "maxComputeWorkgroupSubgroups", QVariant(extProps.maxComputeWorkgroupSubgroups));
		pushProperty2(extension, "requiredSubgroupSizeStages", QVariant(extProps.requiredSubgroupSizeStages));
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "provokingVertexModePerPipeline", QVariant(bool(extProps.provokingVertexModePerPipeline)));
		pushProperty2(extension, "transformFeedbackPreservesTriangleFanProvokingVertex", QVariant(bool(extProps.transformFeedbackPreservesTriangleFanProvokingVertex)));
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "lineSubPixelPrecisionBits", QVariant(extProps.lineSubPixelPrecisionBits));
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "storageTexelBufferOffsetAlignmentBytes", QVariant::fromValue(extProps.storageTexelBufferOffsetAlignmentBytes));
		pushProperty2(extension, "storageTexelBufferOffsetSingleTexelAlignment", QVariant(bool(extProps.storageTexelBufferOffsetSingleTexelAlignment)));
		pushProperty2(extension, "uniformTexelBufferOffsetAlignmentBytes", QVariant::fromValue(extProps.uniformTexelBufferOffsetAlignmentBytes));
		pushProperty2(extension, "uniformTexelBufferOffsetSingleTexelAlignment", QVariant(bool(extProps.uniformTexelBufferOffsetSingleTexelAlignment)));
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "robustStorageBufferAccessSizeAlignment", QVariant::fromValue(extProps.robustStorageBufferAccessSizeAlignment));
		pushProperty2(extension, "robustUniformBufferAccessSizeAlignment", QVariant::fromValue(extProps.robustUniformBufferAccessSizeAlignment));
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxCustomBorderColorSamplers", QVariant(extProps.maxCustomBorderColorSamplers));
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "combinedImageSamplerDescriptorSingleArray", QVariant(bool(extProps.combinedImageSamplerDescriptorSingleArray)));
		pushProperty2(extension, "bufferlessPushDescriptors", QVariant(bool(extProps.bufferlessPushDescriptors)));
		pushProperty2(extension, "allowSamplerImageViewPostSubmitCreation", QVariant(bool(extProps.allowSamplerImageViewPostSubmitCreation)));
		pushProperty2(extension, "descriptorBufferOffsetAlignment", QVariant::fromValue(extProps.descriptorBufferOffsetAlignment));
		pushProperty2(extension, "maxDescriptorBufferBindings", QVariant(extProps.maxDescriptorBufferBindings));
		pushProperty2(extension, "maxResourceDescriptorBufferBindings", QVariant(extProps.maxResourceDescriptorBufferBindings));
		pushProperty2(extension, "maxSamplerDescriptorBufferBindings", QVariant(extProps.maxSamplerDescriptorBufferBindings));
		pushProperty2(extension, "maxEmbeddedImmutableSamplerBindings", QVariant(extProps.maxEmbeddedImmutableSamplerBindings));
		pushProperty2(extension, "maxEmbeddedImmutableSamplers", QVariant(extProps.maxEmbeddedImmutableSamplers));
		pushProperty2(extension, "bufferCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps.bufferCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "imageCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps.imageCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "imageViewCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps.imageViewCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "samplerCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps.samplerCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "accelerationStructureCaptureReplayDescriptorDataSize", QVariant::fromValue(extProps.accelerationStructureCaptureReplayDescriptorDataSize));
		pushProperty2(extension, "samplerDescriptorSize", QVariant::fromValue(extProps.samplerDescriptorSize));
		pushProperty2(extension, "combinedImageSamplerDescriptorSize", QVariant::fromValue(extProps.combinedImageSamplerDescriptorSize));
		pushProperty2(extension, "sampledImageDescriptorSize", QVariant::fromValue(extProps.sampledImageDescriptorSize));
		pushProperty2(extension, "storageImageDescriptorSize", QVariant::fromValue(extProps.storageImageDescriptorSize));
		pushProperty2(extension, "uniformTexelBufferDescriptorSize", QVariant::fromValue(extProps.uniformTexelBufferDescriptorSize));
		pushProperty2(extension, "robustUniformTexelBufferDescriptorSize", QVariant::fromValue(extProps.robustUniformTexelBufferDescriptorSize));
		pushProperty2(extension, "storageTexelBufferDescriptorSize", QVariant::fromValue(extProps.storageTexelBufferDescriptorSize));
		pushProperty2(extension, "robustStorageTexelBufferDescriptorSize", QVariant::fromValue(extProps.robustStorageTexelBufferDescriptorSize));
		pushProperty2(extension, "uniformBufferDescriptorSize", QVariant::fromValue(extProps.uniformBufferDescriptorSize));
		pushProperty2(extension, "robustUniformBufferDescriptorSize", QVariant::fromValue(extProps.robustUniformBufferDescriptorSize));
		pushProperty2(extension, "storageBufferDescriptorSize", QVariant::fromValue(extProps.storageBufferDescriptorSize));
		pushProperty2(extension, "robustStorageBufferDescriptorSize", QVariant::fromValue(extProps.robustStorageBufferDescriptorSize));
		pushProperty2(extension, "inputAttachmentDescriptorSize", QVariant::fromValue(extProps.inputAttachmentDescriptorSize));
		pushProperty2(extension, "accelerationStructureDescriptorSize", QVariant::fromValue(extProps.accelerationStructureDescriptorSize));
		pushProperty2(extension, "maxSamplerDescriptorBufferRange", QVariant::fromValue(extProps.maxSamplerDescriptorBufferRange));
		pushProperty2(extension, "maxResourceDescriptorBufferRange", QVariant::fromValue(extProps.maxResourceDescriptorBufferRange));
		pushProperty2(extension, "samplerDescriptorBufferAddressSpaceSize", QVariant::fromValue(extProps.samplerDescriptorBufferAddressSpaceSize));
		pushProperty2(extension, "resourceDescriptorBufferAddressSpaceSize", QVariant::fromValue(extProps.resourceDescriptorBufferAddressSpaceSize));
		pushProperty2(extension, "descriptorBufferAddressSpaceSize", QVariant::fromValue(extProps.descriptorBufferAddressSpaceSize));
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "graphicsPipelineLibraryFastLinking", QVariant(bool(extProps.graphicsPipelineLibraryFastLinking)));
		pushProperty2(extension, "graphicsPipelineLibraryIndependentInterpolationDecoration", QVariant(bool(extProps.graphicsPipelineLibraryIndependentInterpolationDecoration)));
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTaskWorkGroupTotalCount", QVariant(extProps.maxTaskWorkGroupTotalCount));
		pushProperty2(extension, "maxTaskWorkGroupCount", QVariant::fromValue(QVariantList({ extProps.maxTaskWorkGroupCount[0], extProps.maxTaskWorkGroupCount[1], extProps.maxTaskWorkGroupCount[2] })));
		pushProperty2(extension, "maxTaskWorkGroupInvocations", QVariant(extProps.maxTaskWorkGroupInvocations));
		pushProperty2(extension, "maxTaskWorkGroupSize", QVariant::fromValue(QVariantList({ extProps.maxTaskWorkGroupSize[0], extProps.maxTaskWorkGroupSize[1], extProps.maxTaskWorkGroupSize[2] })));
		pushProperty2(extension, "maxTaskPayloadSize", QVariant(extProps.maxTaskPayloadSize));
		pushProperty2(extension, "maxTaskSharedMemorySize", QVariant(extProps.maxTaskSharedMemorySize));
		pushProperty2(extension, "maxTaskPayloadAndSharedMemorySize", QVariant(extProps.maxTaskPayloadAndSharedMemorySize));
		pushProperty2(extension, "maxMeshWorkGroupTotalCount", QVariant(extProps.maxMeshWorkGroupTotalCount));
		pushProperty2(extension, "maxMeshWorkGroupCount", QVariant::fromValue(QVariantList({ extProps.maxMeshWorkGroupCount[0], extProps.maxMeshWorkGroupCount[1], extProps.maxMeshWorkGroupCount[2] })));
		pushProperty2(extension, "maxMeshWorkGroupInvocations", QVariant(extProps.maxMeshWorkGroupInvocations));
		pushProperty2(extension, "maxMeshWorkGroupSize", QVariant::fromValue(QVariantList({ extProps.maxMeshWorkGroupSize[0], extProps.maxMeshWorkGroupSize[1], extProps.maxMeshWorkGroupSize[2] })));
		pushProperty2(extension, "maxMeshSharedMemorySize", QVariant(extProps.maxMeshSharedMemorySize));
		pushProperty2(extension, "maxMeshPayloadAndSharedMemorySize", QVariant(extProps.maxMeshPayloadAndSharedMemorySize));
		pushProperty2(extension, "maxMeshOutputMemorySize", QVariant(extProps.maxMeshOutputMemorySize));
		pushProperty2(extension, "maxMeshPayloadAndOutputMemorySize", QVariant(extProps.maxMeshPayloadAndOutputMemorySize));
		pushProperty2(extension, "maxMeshOutputComponents", QVariant(extProps.maxMeshOutputComponents));
		pushProperty2(extension, "maxMeshOutputVertices", QVariant(extProps.maxMeshOutputVertices));
		pushProperty2(extension, "maxMeshOutputPrimitives", QVariant(extProps.maxMeshOutputPrimitives));
		pushProperty2(extension, "maxMeshOutputLayers", QVariant(extProps.maxMeshOutputLayers));
		pushProperty2(extension, "maxMeshMultiviewViewCount", QVariant(extProps.maxMeshMultiviewViewCount));
		pushProperty2(extension, "meshOutputPerVertexGranularity", QVariant(extProps.meshOutputPerVertexGranularity));
		pushProperty2(extension, "meshOutputPerPrimitiveGranularity", QVariant(extProps.meshOutputPerPrimitiveGranularity));
		pushProperty2(extension, "maxPreferredTaskWorkGroupInvocations", QVariant(extProps.maxPreferredTaskWorkGroupInvocations));
		pushProperty2(extension, "maxPreferredMeshWorkGroupInvocations", QVariant(extProps.maxPreferredMeshWorkGroupInvocations));
		pushProperty2(extension, "prefersLocalInvocationVertexOutput", QVariant(bool(extProps.prefersLocalInvocationVertexOutput)));
		pushProperty2(extension, "prefersLocalInvocationPrimitiveOutput", QVariant(bool(extProps.prefersLocalInvocationPrimitiveOutput)));
		pushProperty2(extension, "prefersCompactVertexOutput", QVariant(bool(extProps.prefersCompactVertexOutput)));
		pushProperty2(extension, "prefersCompactPrimitiveOutput", QVariant(bool(extProps.prefersCompactPrimitiveOutput)));
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "subsampledLoads", QVariant(bool(extProps.subsampledLoads)));
		pushProperty2(extension, "subsampledCoarseReconstructionEarlyAccess", QVariant(bool(extProps.subsampledCoarseReconstructionEarlyAccess)));
		pushProperty2(extension, "maxSubsampledArrayLayers", QVariant(extProps.maxSubsampledArrayLayers));
		pushProperty2(extension, "maxDescriptorSetSubsampledSamplers", QVariant(extProps.maxDescriptorSetSubsampledSamplers));
	}
	if (extensionSupported("VK_EXT_physical_device_drm")) {
		const char* extension("VK_EXT_physical_device_drm");
		VkPhysicalDeviceDrmPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "hasPrimary", QVariant(bool(extProps.hasPrimary)));
		pushProperty2(extension, "hasRender", QVariant(bool(extProps.hasRender)));
        pushProperty2(extension, "primaryMajor", QVariant::fromValue(extProps.primaryMajor));
        pushProperty2(extension, "primaryMinor", QVariant::fromValue(extProps.primaryMinor));
        pushProperty2(extension, "renderMajor", QVariant::fromValue(extProps.renderMajor));
        pushProperty2(extension, "renderMinor", QVariant::fromValue(extProps.renderMinor));
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxMultiDrawCount", QVariant(extProps.maxMultiDrawCount));
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxOpacity2StateSubdivisionLevel", QVariant(extProps.maxOpacity2StateSubdivisionLevel));
		pushProperty2(extension, "maxOpacity4StateSubdivisionLevel", QVariant(extProps.maxOpacity4StateSubdivisionLevel));
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "dynamicPrimitiveTopologyUnrestricted", QVariant(bool(extProps.dynamicPrimitiveTopologyUnrestricted)));
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderModuleIdentifierAlgorithmUUID", QVariant::fromValue(arrayToQVariantList(extProps.shaderModuleIdentifierAlgorithmUUID, 16)));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_HUAWEI() {
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxSubpassShadingWorkgroupSizeAspectRatio", QVariant(extProps.maxSubpassShadingWorkgroupSizeAspectRatio));
	}
	if (extensionSupported("VK_HUAWEI_cluster_culling_shader")) {
		const char* extension("VK_HUAWEI_cluster_culling_shader");
		VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxWorkGroupCount", QVariant::fromValue(QVariantList({ extProps.maxWorkGroupCount[0], extProps.maxWorkGroupCount[1], extProps.maxWorkGroupCount[2] })));
		pushProperty2(extension, "maxWorkGroupSize", QVariant::fromValue(QVariantList({ extProps.maxWorkGroupSize[0], extProps.maxWorkGroupSize[1], extProps.maxWorkGroupSize[2] })));
		pushProperty2(extension, "maxOutputClusterCount", QVariant(extProps.maxOutputClusterCount));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_KHR() {
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxMultiviewViewCount", QVariant(extProps.maxMultiviewViewCount));
		pushProperty2(extension, "maxMultiviewInstanceIndex", QVariant(extProps.maxMultiviewInstanceIndex));
	}
	if (extensionSupported("VK_KHR_external_memory_capabilities")) {
		const char* extension("VK_KHR_external_memory_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps.driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps.deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps.deviceLUIDValid)));
	}
	if (extensionSupported("VK_KHR_external_semaphore_capabilities")) {
		const char* extension("VK_KHR_external_semaphore_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps.driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps.deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps.deviceLUIDValid)));
	}
	if (extensionSupported("VK_KHR_push_descriptor")) {
		const char* extension("VK_KHR_push_descriptor");
		VkPhysicalDevicePushDescriptorPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxPushDescriptors", QVariant(extProps.maxPushDescriptors));
	}
	if (extensionSupported("VK_KHR_external_fence_capabilities")) {
		const char* extension("VK_KHR_external_fence_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "deviceUUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceUUID, 16)));
		pushProperty2(extension, "driverUUID", QVariant::fromValue(arrayToQVariantList(extProps.driverUUID, 16)));
		pushProperty2(extension, "deviceLUID", QVariant::fromValue(arrayToQVariantList(extProps.deviceLUID, 8)));
		pushProperty2(extension, "deviceNodeMask", QVariant(extProps.deviceNodeMask));
		pushProperty2(extension, "deviceLUIDValid", QVariant(bool(extProps.deviceLUIDValid)));
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "allowCommandBufferQueryCopies", QVariant(bool(extProps.allowCommandBufferQueryCopies)));
	}
	if (extensionSupported("VK_KHR_maintenance2")) {
		const char* extension("VK_KHR_maintenance2");
		VkPhysicalDevicePointClippingProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "pointClippingBehavior", QVariant(extProps.pointClippingBehavior));
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructurePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxGeometryCount", QVariant::fromValue(extProps.maxGeometryCount));
		pushProperty2(extension, "maxInstanceCount", QVariant::fromValue(extProps.maxInstanceCount));
		pushProperty2(extension, "maxPrimitiveCount", QVariant::fromValue(extProps.maxPrimitiveCount));
		pushProperty2(extension, "maxPerStageDescriptorAccelerationStructures", QVariant(extProps.maxPerStageDescriptorAccelerationStructures));
		pushProperty2(extension, "maxPerStageDescriptorUpdateAfterBindAccelerationStructures", QVariant(extProps.maxPerStageDescriptorUpdateAfterBindAccelerationStructures));
		pushProperty2(extension, "maxDescriptorSetAccelerationStructures", QVariant(extProps.maxDescriptorSetAccelerationStructures));
		pushProperty2(extension, "maxDescriptorSetUpdateAfterBindAccelerationStructures", QVariant(extProps.maxDescriptorSetUpdateAfterBindAccelerationStructures));
		pushProperty2(extension, "minAccelerationStructureScratchOffsetAlignment", QVariant(extProps.minAccelerationStructureScratchOffsetAlignment));
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderGroupHandleSize", QVariant(extProps.shaderGroupHandleSize));
		pushProperty2(extension, "maxRayRecursionDepth", QVariant(extProps.maxRayRecursionDepth));
		pushProperty2(extension, "maxShaderGroupStride", QVariant(extProps.maxShaderGroupStride));
		pushProperty2(extension, "shaderGroupBaseAlignment", QVariant(extProps.shaderGroupBaseAlignment));
		pushProperty2(extension, "shaderGroupHandleCaptureReplaySize", QVariant(extProps.shaderGroupHandleCaptureReplaySize));
		pushProperty2(extension, "maxRayDispatchInvocationCount", QVariant(extProps.maxRayDispatchInvocationCount));
		pushProperty2(extension, "shaderGroupHandleAlignment", QVariant(extProps.shaderGroupHandleAlignment));
		pushProperty2(extension, "maxRayHitAttributeSize", QVariant(extProps.maxRayHitAttributeSize));
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minVertexInputBindingStrideAlignment", QVariant(extProps.minVertexInputBindingStrideAlignment));
	}
	if (extensionSupported("VK_KHR_maintenance3")) {
		const char* extension("VK_KHR_maintenance3");
		VkPhysicalDeviceMaintenance3Properties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxPerSetDescriptors", QVariant(extProps.maxPerSetDescriptors));
		pushProperty2(extension, "maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize));
	}
	if (extensionSupported("VK_KHR_driver_properties")) {
		const char* extension("VK_KHR_driver_properties");
		VkPhysicalDeviceDriverProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "driverID", QVariant(extProps.driverID));
		pushProperty2(extension, "driverName", QVariant(extProps.driverName));
		pushProperty2(extension, "driverInfo", QVariant(extProps.driverInfo));
		pushProperty2(extension, "conformanceVersion", QString::fromStdString(vulkanResources::conformanceVersionKHRString(extProps.conformanceVersion)));
	}
	if (extensionSupported("VK_KHR_shader_float_controls")) {
		const char* extension("VK_KHR_shader_float_controls");
		VkPhysicalDeviceFloatControlsProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "denormBehaviorIndependence", QVariant(extProps.denormBehaviorIndependence));
		pushProperty2(extension, "roundingModeIndependence", QVariant(extProps.roundingModeIndependence));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat16", QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat16)));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat32", QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat32)));
		pushProperty2(extension, "shaderSignedZeroInfNanPreserveFloat64", QVariant(bool(extProps.shaderSignedZeroInfNanPreserveFloat64)));
		pushProperty2(extension, "shaderDenormPreserveFloat16", QVariant(bool(extProps.shaderDenormPreserveFloat16)));
		pushProperty2(extension, "shaderDenormPreserveFloat32", QVariant(bool(extProps.shaderDenormPreserveFloat32)));
		pushProperty2(extension, "shaderDenormPreserveFloat64", QVariant(bool(extProps.shaderDenormPreserveFloat64)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat16", QVariant(bool(extProps.shaderDenormFlushToZeroFloat16)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat32", QVariant(bool(extProps.shaderDenormFlushToZeroFloat32)));
		pushProperty2(extension, "shaderDenormFlushToZeroFloat64", QVariant(bool(extProps.shaderDenormFlushToZeroFloat64)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat16", QVariant(bool(extProps.shaderRoundingModeRTEFloat16)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat32", QVariant(bool(extProps.shaderRoundingModeRTEFloat32)));
		pushProperty2(extension, "shaderRoundingModeRTEFloat64", QVariant(bool(extProps.shaderRoundingModeRTEFloat64)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat16", QVariant(bool(extProps.shaderRoundingModeRTZFloat16)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat32", QVariant(bool(extProps.shaderRoundingModeRTZFloat32)));
		pushProperty2(extension, "shaderRoundingModeRTZFloat64", QVariant(bool(extProps.shaderRoundingModeRTZFloat64)));
	}
	if (extensionSupported("VK_KHR_depth_stencil_resolve")) {
		const char* extension("VK_KHR_depth_stencil_resolve");
		VkPhysicalDeviceDepthStencilResolveProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedDepthResolveModes", QVariant(extProps.supportedDepthResolveModes));
		pushProperty2(extension, "supportedStencilResolveModes", QVariant(extProps.supportedStencilResolveModes));
		pushProperty2(extension, "independentResolveNone", QVariant(bool(extProps.independentResolveNone)));
		pushProperty2(extension, "independentResolve", QVariant(bool(extProps.independentResolve)));
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxTimelineSemaphoreValueDifference", QVariant::fromValue(extProps.maxTimelineSemaphoreValueDifference));
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "minFragmentShadingRateAttachmentTexelSize", QVariant::fromValue(QVariantList({ extProps.minFragmentShadingRateAttachmentTexelSize.width, extProps.minFragmentShadingRateAttachmentTexelSize.height })));
		pushProperty2(extension, "maxFragmentShadingRateAttachmentTexelSize", QVariant::fromValue(QVariantList({ extProps.maxFragmentShadingRateAttachmentTexelSize.width, extProps.maxFragmentShadingRateAttachmentTexelSize.height })));
		pushProperty2(extension, "maxFragmentShadingRateAttachmentTexelSizeAspectRatio", QVariant(extProps.maxFragmentShadingRateAttachmentTexelSizeAspectRatio));
		pushProperty2(extension, "primitiveFragmentShadingRateWithMultipleViewports", QVariant(bool(extProps.primitiveFragmentShadingRateWithMultipleViewports)));
		pushProperty2(extension, "layeredShadingRateAttachments", QVariant(bool(extProps.layeredShadingRateAttachments)));
		pushProperty2(extension, "fragmentShadingRateNonTrivialCombinerOps", QVariant(bool(extProps.fragmentShadingRateNonTrivialCombinerOps)));
		pushProperty2(extension, "maxFragmentSize", QVariant::fromValue(QVariantList({ extProps.maxFragmentSize.width, extProps.maxFragmentSize.height })));
		pushProperty2(extension, "maxFragmentSizeAspectRatio", QVariant(extProps.maxFragmentSizeAspectRatio));
		pushProperty2(extension, "maxFragmentShadingRateCoverageSamples", QVariant(extProps.maxFragmentShadingRateCoverageSamples));
		pushProperty2(extension, "maxFragmentShadingRateRasterizationSamples", QVariant(extProps.maxFragmentShadingRateRasterizationSamples));
		pushProperty2(extension, "fragmentShadingRateWithShaderDepthStencilWrites", QVariant(bool(extProps.fragmentShadingRateWithShaderDepthStencilWrites)));
		pushProperty2(extension, "fragmentShadingRateWithSampleMask", QVariant(bool(extProps.fragmentShadingRateWithSampleMask)));
		pushProperty2(extension, "fragmentShadingRateWithShaderSampleMask", QVariant(bool(extProps.fragmentShadingRateWithShaderSampleMask)));
		pushProperty2(extension, "fragmentShadingRateWithConservativeRasterization", QVariant(bool(extProps.fragmentShadingRateWithConservativeRasterization)));
		pushProperty2(extension, "fragmentShadingRateWithFragmentShaderInterlock", QVariant(bool(extProps.fragmentShadingRateWithFragmentShaderInterlock)));
		pushProperty2(extension, "fragmentShadingRateWithCustomSampleLocations", QVariant(bool(extProps.fragmentShadingRateWithCustomSampleLocations)));
		pushProperty2(extension, "fragmentShadingRateStrictMultiplyCombiner", QVariant(bool(extProps.fragmentShadingRateStrictMultiplyCombiner)));
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "integerDotProduct8BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProduct8BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct8BitSignedAccelerated", QVariant(bool(extProps.integerDotProduct8BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct8BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProduct8BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedUnsignedAccelerated", QVariant(bool(extProps.integerDotProduct4x8BitPackedUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedSignedAccelerated", QVariant(bool(extProps.integerDotProduct4x8BitPackedSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct4x8BitPackedMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProduct4x8BitPackedMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProduct16BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitSignedAccelerated", QVariant(bool(extProps.integerDotProduct16BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct16BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProduct16BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProduct32BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitSignedAccelerated", QVariant(bool(extProps.integerDotProduct32BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct32BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProduct32BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProduct64BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitSignedAccelerated", QVariant(bool(extProps.integerDotProduct64BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProduct64BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProduct64BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitSignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating8BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitSignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating16BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitSignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating32BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitSignedAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating64BitSignedAccelerated)));
		pushProperty2(extension, "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", QVariant(bool(extProps.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated)));
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "triStripVertexOrderIndependentOfProvokingVertex", QVariant(bool(extProps.triStripVertexOrderIndependentOfProvokingVertex)));
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Properties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxBufferSize", QVariant::fromValue(extProps.maxBufferSize));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NV() {
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderSMCount", QVariant(extProps.shaderSMCount));
		pushProperty2(extension, "shaderWarpsPerSM", QVariant(extProps.shaderWarpsPerSM));
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImagePropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shadingRateTexelSize", QVariant::fromValue(QVariantList({ extProps.shadingRateTexelSize.width, extProps.shadingRateTexelSize.height })));
		pushProperty2(extension, "shadingRatePaletteSize", QVariant(extProps.shadingRatePaletteSize));
		pushProperty2(extension, "shadingRateMaxCoarseSamples", QVariant(extProps.shadingRateMaxCoarseSamples));
	}
	if (extensionSupported("VK_NV_ray_tracing")) {
		const char* extension("VK_NV_ray_tracing");
		VkPhysicalDeviceRayTracingPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "shaderGroupHandleSize", QVariant(extProps.shaderGroupHandleSize));
		pushProperty2(extension, "maxRecursionDepth", QVariant(extProps.maxRecursionDepth));
		pushProperty2(extension, "maxShaderGroupStride", QVariant(extProps.maxShaderGroupStride));
		pushProperty2(extension, "shaderGroupBaseAlignment", QVariant(extProps.shaderGroupBaseAlignment));
		pushProperty2(extension, "maxGeometryCount", QVariant::fromValue(extProps.maxGeometryCount));
		pushProperty2(extension, "maxInstanceCount", QVariant::fromValue(extProps.maxInstanceCount));
		pushProperty2(extension, "maxTriangleCount", QVariant::fromValue(extProps.maxTriangleCount));
		pushProperty2(extension, "maxDescriptorSetAccelerationStructures", QVariant(extProps.maxDescriptorSetAccelerationStructures));
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
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
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "cooperativeMatrixSupportedStages", QVariant(extProps.cooperativeMatrixSupportedStages));
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxGraphicsShaderGroupCount", QVariant(extProps.maxGraphicsShaderGroupCount));
		pushProperty2(extension, "maxIndirectSequenceCount", QVariant(extProps.maxIndirectSequenceCount));
		pushProperty2(extension, "maxIndirectCommandsTokenCount", QVariant(extProps.maxIndirectCommandsTokenCount));
		pushProperty2(extension, "maxIndirectCommandsStreamCount", QVariant(extProps.maxIndirectCommandsStreamCount));
		pushProperty2(extension, "maxIndirectCommandsTokenOffset", QVariant(extProps.maxIndirectCommandsTokenOffset));
		pushProperty2(extension, "maxIndirectCommandsStreamStride", QVariant(extProps.maxIndirectCommandsStreamStride));
		pushProperty2(extension, "minSequencesCountBufferOffsetAlignment", QVariant(extProps.minSequencesCountBufferOffsetAlignment));
		pushProperty2(extension, "minSequencesIndexBufferOffsetAlignment", QVariant(extProps.minSequencesIndexBufferOffsetAlignment));
		pushProperty2(extension, "minIndirectCommandsBufferOffsetAlignment", QVariant(extProps.minIndirectCommandsBufferOffsetAlignment));
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxFragmentShadingRateInvocationCount", QVariant(extProps.maxFragmentShadingRateInvocationCount));
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedQueues", QVariant(extProps.supportedQueues));
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "decompressionMethods", QVariant::fromValue(extProps.decompressionMethods));
		pushProperty2(extension, "maxDecompressionIndirectCount", QVariant::fromValue(extProps.maxDecompressionIndirectCount));
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "supportedOutputGridSizes", QVariant(extProps.supportedOutputGridSizes));
		pushProperty2(extension, "supportedHintGridSizes", QVariant(extProps.supportedHintGridSizes));
		pushProperty2(extension, "hintSupported", QVariant(bool(extProps.hintSupported)));
		pushProperty2(extension, "costSupported", QVariant(bool(extProps.costSupported)));
		pushProperty2(extension, "bidirectionalFlowSupported", QVariant(bool(extProps.bidirectionalFlowSupported)));
		pushProperty2(extension, "globalFlowSupported", QVariant(bool(extProps.globalFlowSupported)));
		pushProperty2(extension, "minWidth", QVariant(extProps.minWidth));
		pushProperty2(extension, "minHeight", QVariant(extProps.minHeight));
		pushProperty2(extension, "maxWidth", QVariant(extProps.maxWidth));
		pushProperty2(extension, "maxHeight", QVariant(extProps.maxHeight));
		pushProperty2(extension, "maxNumRegionsOfInterest", QVariant(extProps.maxNumRegionsOfInterest));
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "rayTracingInvocationReorderReorderingHint", QVariant(extProps.rayTracingInvocationReorderReorderingHint));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NVX() {
	if (extensionSupported("VK_NVX_multiview_per_view_attributes")) {
		const char* extension("VK_NVX_multiview_per_view_attributes");
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "perViewPositionAllComponents", QVariant(bool(extProps.perViewPositionAllComponents)));
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_QCOM() {
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "fragmentDensityOffsetGranularity", QVariant::fromValue(QVariantList({ extProps.fragmentDensityOffsetGranularity.width, extProps.fragmentDensityOffsetGranularity.height })));
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingPropertiesQCOM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(device, &deviceProps2);
		pushProperty2(extension, "maxWeightFilterPhases", QVariant(extProps.maxWeightFilterPhases));
		pushProperty2(extension, "maxWeightFilterDimension", QVariant::fromValue(QVariantList({ extProps.maxWeightFilterDimension.width, extProps.maxWeightFilterDimension.height })));
		pushProperty2(extension, "maxBlockMatchRegion", QVariant::fromValue(QVariantList({ extProps.maxBlockMatchRegion.width, extProps.maxBlockMatchRegion.height })));
		pushProperty2(extension, "maxBoxFilterBlockSize", QVariant::fromValue(QVariantList({ extProps.maxBoxFilterBlockSize.width, extProps.maxBoxFilterBlockSize.height })));
	}
}


void VulkanDeviceInfoExtensions::readExtendedProperties() {
    readPhysicalProperties_AMD();
    readPhysicalProperties_ARM();
    readPhysicalProperties_EXT();
    readPhysicalProperties_HUAWEI();
    readPhysicalProperties_KHR();
    readPhysicalProperties_NV();
    readPhysicalProperties_NVX();
    readPhysicalProperties_QCOM();
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
	if (extensionSupported("VK_AMD_device_coherent_memory")) {
		const char* extension("VK_AMD_device_coherent_memory");
		VkPhysicalDeviceCoherentMemoryFeaturesAMD extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceCoherentMemory", extFeatures.deviceCoherentMemory);
	}
	if (extensionSupported("VK_AMD_shader_early_and_late_fragment_tests")) {
		const char* extension("VK_AMD_shader_early_and_late_fragment_tests");
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderEarlyAndLateFragmentTests", extFeatures.shaderEarlyAndLateFragmentTests);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_ARM() {
	if (extensionSupported("VK_ARM_rasterization_order_attachment_access")) {
		const char* extension("VK_ARM_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures.rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures.rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures.rasterizationOrderStencilAttachmentAccess);
	}
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderCoreBuiltins", extFeatures.shaderCoreBuiltins);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_EXT() {
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "transformFeedback", extFeatures.transformFeedback);
		pushFeature2(extension, "geometryStreams", extFeatures.geometryStreams);
	}
	if (extensionSupported("VK_EXT_texture_compression_astc_hdr")) {
		const char* extension("VK_EXT_texture_compression_astc_hdr");
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "textureCompressionASTC_HDR", extFeatures.textureCompressionASTC_HDR);
	}
	if (extensionSupported("VK_EXT_astc_decode_mode")) {
		const char* extension("VK_EXT_astc_decode_mode");
		VkPhysicalDeviceASTCDecodeFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "decodeModeSharedExponent", extFeatures.decodeModeSharedExponent);
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineRobustness", extFeatures.pipelineRobustness);
	}
	if (extensionSupported("VK_EXT_conditional_rendering")) {
		const char* extension("VK_EXT_conditional_rendering");
		VkPhysicalDeviceConditionalRenderingFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "conditionalRendering", extFeatures.conditionalRendering);
		pushFeature2(extension, "inheritedConditionalRendering", extFeatures.inheritedConditionalRendering);
	}
	if (extensionSupported("VK_EXT_depth_clip_enable")) {
		const char* extension("VK_EXT_depth_clip_enable");
		VkPhysicalDeviceDepthClipEnableFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClipEnable", extFeatures.depthClipEnable);
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "inlineUniformBlock", extFeatures.inlineUniformBlock);
		pushFeature2(extension, "descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures.descriptorBindingInlineUniformBlockUpdateAfterBind);
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "advancedBlendCoherentOperations", extFeatures.advancedBlendCoherentOperations);
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
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
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures.vertexAttributeInstanceRateDivisor);
		pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures.vertexAttributeInstanceRateZeroDivisor);
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMap", extFeatures.fragmentDensityMap);
		pushFeature2(extension, "fragmentDensityMapDynamic", extFeatures.fragmentDensityMapDynamic);
		pushFeature2(extension, "fragmentDensityMapNonSubsampledImages", extFeatures.fragmentDensityMapNonSubsampledImages);
	}
	if (extensionSupported("VK_EXT_scalar_block_layout")) {
		const char* extension("VK_EXT_scalar_block_layout");
		VkPhysicalDeviceScalarBlockLayoutFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "scalarBlockLayout", extFeatures.scalarBlockLayout);
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subgroupSizeControl", extFeatures.subgroupSizeControl);
		pushFeature2(extension, "computeFullSubgroups", extFeatures.computeFullSubgroups);
	}
	if (extensionSupported("VK_EXT_shader_image_atomic_int64")) {
		const char* extension("VK_EXT_shader_image_atomic_int64");
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderImageInt64Atomics", extFeatures.shaderImageInt64Atomics);
		pushFeature2(extension, "sparseImageInt64Atomics", extFeatures.sparseImageInt64Atomics);
	}
	if (extensionSupported("VK_EXT_memory_priority")) {
		const char* extension("VK_EXT_memory_priority");
		VkPhysicalDeviceMemoryPriorityFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryPriority", extFeatures.memoryPriority);
	}
	if (extensionSupported("VK_EXT_buffer_device_address")) {
		const char* extension("VK_EXT_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures.bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures.bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures.bufferDeviceAddressMultiDevice);
	}
	if (extensionSupported("VK_EXT_fragment_shader_interlock")) {
		const char* extension("VK_EXT_fragment_shader_interlock");
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderSampleInterlock", extFeatures.fragmentShaderSampleInterlock);
		pushFeature2(extension, "fragmentShaderPixelInterlock", extFeatures.fragmentShaderPixelInterlock);
		pushFeature2(extension, "fragmentShaderShadingRateInterlock", extFeatures.fragmentShaderShadingRateInterlock);
	}
	if (extensionSupported("VK_EXT_ycbcr_image_arrays")) {
		const char* extension("VK_EXT_ycbcr_image_arrays");
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "ycbcrImageArrays", extFeatures.ycbcrImageArrays);
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "provokingVertexLast", extFeatures.provokingVertexLast);
		pushFeature2(extension, "transformFeedbackPreservesProvokingVertex", extFeatures.transformFeedbackPreservesProvokingVertex);
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rectangularLines", extFeatures.rectangularLines);
		pushFeature2(extension, "bresenhamLines", extFeatures.bresenhamLines);
		pushFeature2(extension, "smoothLines", extFeatures.smoothLines);
		pushFeature2(extension, "stippledRectangularLines", extFeatures.stippledRectangularLines);
		pushFeature2(extension, "stippledBresenhamLines", extFeatures.stippledBresenhamLines);
		pushFeature2(extension, "stippledSmoothLines", extFeatures.stippledSmoothLines);
	}
	if (extensionSupported("VK_EXT_shader_atomic_float")) {
		const char* extension("VK_EXT_shader_atomic_float");
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat32Atomics", extFeatures.shaderBufferFloat32Atomics);
		pushFeature2(extension, "shaderBufferFloat32AtomicAdd", extFeatures.shaderBufferFloat32AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat64Atomics", extFeatures.shaderBufferFloat64Atomics);
		pushFeature2(extension, "shaderBufferFloat64AtomicAdd", extFeatures.shaderBufferFloat64AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat32Atomics", extFeatures.shaderSharedFloat32Atomics);
		pushFeature2(extension, "shaderSharedFloat32AtomicAdd", extFeatures.shaderSharedFloat32AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat64Atomics", extFeatures.shaderSharedFloat64Atomics);
		pushFeature2(extension, "shaderSharedFloat64AtomicAdd", extFeatures.shaderSharedFloat64AtomicAdd);
		pushFeature2(extension, "shaderImageFloat32Atomics", extFeatures.shaderImageFloat32Atomics);
		pushFeature2(extension, "shaderImageFloat32AtomicAdd", extFeatures.shaderImageFloat32AtomicAdd);
		pushFeature2(extension, "sparseImageFloat32Atomics", extFeatures.sparseImageFloat32Atomics);
		pushFeature2(extension, "sparseImageFloat32AtomicAdd", extFeatures.sparseImageFloat32AtomicAdd);
	}
	if (extensionSupported("VK_EXT_host_query_reset")) {
		const char* extension("VK_EXT_host_query_reset");
		VkPhysicalDeviceHostQueryResetFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "hostQueryReset", extFeatures.hostQueryReset);
	}
	if (extensionSupported("VK_EXT_index_type_uint8")) {
		const char* extension("VK_EXT_index_type_uint8");
		VkPhysicalDeviceIndexTypeUint8FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indexTypeUint8", extFeatures.indexTypeUint8);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state")) {
		const char* extension("VK_EXT_extended_dynamic_state");
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState", extFeatures.extendedDynamicState);
	}
	if (extensionSupported("VK_EXT_shader_atomic_float2")) {
		const char* extension("VK_EXT_shader_atomic_float2");
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat16Atomics", extFeatures.shaderBufferFloat16Atomics);
		pushFeature2(extension, "shaderBufferFloat16AtomicAdd", extFeatures.shaderBufferFloat16AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat16AtomicMinMax", extFeatures.shaderBufferFloat16AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat32AtomicMinMax", extFeatures.shaderBufferFloat32AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat64AtomicMinMax", extFeatures.shaderBufferFloat64AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat16Atomics", extFeatures.shaderSharedFloat16Atomics);
		pushFeature2(extension, "shaderSharedFloat16AtomicAdd", extFeatures.shaderSharedFloat16AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat16AtomicMinMax", extFeatures.shaderSharedFloat16AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat32AtomicMinMax", extFeatures.shaderSharedFloat32AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat64AtomicMinMax", extFeatures.shaderSharedFloat64AtomicMinMax);
		pushFeature2(extension, "shaderImageFloat32AtomicMinMax", extFeatures.shaderImageFloat32AtomicMinMax);
		pushFeature2(extension, "sparseImageFloat32AtomicMinMax", extFeatures.sparseImageFloat32AtomicMinMax);
	}
	if (extensionSupported("VK_EXT_swapchain_maintenance1")) {
		const char* extension("VK_EXT_swapchain_maintenance1");
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "swapchainMaintenance1", extFeatures.swapchainMaintenance1);
	}
	if (extensionSupported("VK_EXT_shader_demote_to_helper_invocation")) {
		const char* extension("VK_EXT_shader_demote_to_helper_invocation");
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderDemoteToHelperInvocation", extFeatures.shaderDemoteToHelperInvocation);
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "texelBufferAlignment", extFeatures.texelBufferAlignment);
	}
	if (extensionSupported("VK_EXT_device_memory_report")) {
		const char* extension("VK_EXT_device_memory_report");
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceMemoryReport", extFeatures.deviceMemoryReport);
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "robustBufferAccess2", extFeatures.robustBufferAccess2);
		pushFeature2(extension, "robustImageAccess2", extFeatures.robustImageAccess2);
		pushFeature2(extension, "nullDescriptor", extFeatures.nullDescriptor);
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "customBorderColors", extFeatures.customBorderColors);
		pushFeature2(extension, "customBorderColorWithoutFormat", extFeatures.customBorderColorWithoutFormat);
	}
	if (extensionSupported("VK_EXT_private_data")) {
		const char* extension("VK_EXT_private_data");
		VkPhysicalDevicePrivateDataFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "privateData", extFeatures.privateData);
	}
	if (extensionSupported("VK_EXT_pipeline_creation_cache_control")) {
		const char* extension("VK_EXT_pipeline_creation_cache_control");
		VkPhysicalDevicePipelineCreationCacheControlFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineCreationCacheControl", extFeatures.pipelineCreationCacheControl);
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "descriptorBuffer", extFeatures.descriptorBuffer);
		pushFeature2(extension, "descriptorBufferCaptureReplay", extFeatures.descriptorBufferCaptureReplay);
		pushFeature2(extension, "descriptorBufferImageLayoutIgnored", extFeatures.descriptorBufferImageLayoutIgnored);
		pushFeature2(extension, "descriptorBufferPushDescriptors", extFeatures.descriptorBufferPushDescriptors);
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "graphicsPipelineLibrary", extFeatures.graphicsPipelineLibrary);
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures.taskShader);
		pushFeature2(extension, "meshShader", extFeatures.meshShader);
		pushFeature2(extension, "multiviewMeshShader", extFeatures.multiviewMeshShader);
		pushFeature2(extension, "primitiveFragmentShadingRateMeshShader", extFeatures.primitiveFragmentShadingRateMeshShader);
		pushFeature2(extension, "meshShaderQueries", extFeatures.meshShaderQueries);
	}
	if (extensionSupported("VK_EXT_ycbcr_2plane_444_formats")) {
		const char* extension("VK_EXT_ycbcr_2plane_444_formats");
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "ycbcr2plane444Formats", extFeatures.ycbcr2plane444Formats);
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapDeferred", extFeatures.fragmentDensityMapDeferred);
	}
	if (extensionSupported("VK_EXT_image_robustness")) {
		const char* extension("VK_EXT_image_robustness");
		VkPhysicalDeviceImageRobustnessFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "robustImageAccess", extFeatures.robustImageAccess);
	}
	if (extensionSupported("VK_EXT_image_compression_control")) {
		const char* extension("VK_EXT_image_compression_control");
		VkPhysicalDeviceImageCompressionControlFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControl", extFeatures.imageCompressionControl);
	}
	if (extensionSupported("VK_EXT_attachment_feedback_loop_layout")) {
		const char* extension("VK_EXT_attachment_feedback_loop_layout");
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "attachmentFeedbackLoopLayout", extFeatures.attachmentFeedbackLoopLayout);
	}
	if (extensionSupported("VK_EXT_4444_formats")) {
		const char* extension("VK_EXT_4444_formats");
		VkPhysicalDevice4444FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "formatA4R4G4B4", extFeatures.formatA4R4G4B4);
		pushFeature2(extension, "formatA4B4G4R4", extFeatures.formatA4B4G4R4);
	}
	if (extensionSupported("VK_EXT_device_fault")) {
		const char* extension("VK_EXT_device_fault");
		VkPhysicalDeviceFaultFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceFault", extFeatures.deviceFault);
		pushFeature2(extension, "deviceFaultVendorBinary", extFeatures.deviceFaultVendorBinary);
	}
	if (extensionSupported("VK_EXT_rgba10x6_formats")) {
		const char* extension("VK_EXT_rgba10x6_formats");
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "formatRgba10x6WithoutYCbCrSampler", extFeatures.formatRgba10x6WithoutYCbCrSampler);
	}
	if (extensionSupported("VK_EXT_vertex_input_dynamic_state")) {
		const char* extension("VK_EXT_vertex_input_dynamic_state");
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vertexInputDynamicState", extFeatures.vertexInputDynamicState);
	}
	if (extensionSupported("VK_EXT_device_address_binding_report")) {
		const char* extension("VK_EXT_device_address_binding_report");
		VkPhysicalDeviceAddressBindingReportFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "reportAddressBinding", extFeatures.reportAddressBinding);
	}
	if (extensionSupported("VK_EXT_depth_clip_control")) {
		const char* extension("VK_EXT_depth_clip_control");
		VkPhysicalDeviceDepthClipControlFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClipControl", extFeatures.depthClipControl);
	}
	if (extensionSupported("VK_EXT_primitive_topology_list_restart")) {
		const char* extension("VK_EXT_primitive_topology_list_restart");
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "primitiveTopologyListRestart", extFeatures.primitiveTopologyListRestart);
		pushFeature2(extension, "primitiveTopologyPatchListRestart", extFeatures.primitiveTopologyPatchListRestart);
	}
	if (extensionSupported("VK_EXT_pipeline_properties")) {
		const char* extension("VK_EXT_pipeline_properties");
		VkPhysicalDevicePipelinePropertiesFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelinePropertiesIdentifier", extFeatures.pipelinePropertiesIdentifier);
	}
	if (extensionSupported("VK_EXT_multisampled_render_to_single_sampled")) {
		const char* extension("VK_EXT_multisampled_render_to_single_sampled");
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multisampledRenderToSingleSampled", extFeatures.multisampledRenderToSingleSampled);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state2")) {
		const char* extension("VK_EXT_extended_dynamic_state2");
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState2", extFeatures.extendedDynamicState2);
		pushFeature2(extension, "extendedDynamicState2LogicOp", extFeatures.extendedDynamicState2LogicOp);
		pushFeature2(extension, "extendedDynamicState2PatchControlPoints", extFeatures.extendedDynamicState2PatchControlPoints);
	}
	if (extensionSupported("VK_EXT_color_write_enable")) {
		const char* extension("VK_EXT_color_write_enable");
		VkPhysicalDeviceColorWriteEnableFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "colorWriteEnable", extFeatures.colorWriteEnable);
	}
	if (extensionSupported("VK_EXT_primitives_generated_query")) {
		const char* extension("VK_EXT_primitives_generated_query");
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "primitivesGeneratedQuery", extFeatures.primitivesGeneratedQuery);
		pushFeature2(extension, "primitivesGeneratedQueryWithRasterizerDiscard", extFeatures.primitivesGeneratedQueryWithRasterizerDiscard);
		pushFeature2(extension, "primitivesGeneratedQueryWithNonZeroStreams", extFeatures.primitivesGeneratedQueryWithNonZeroStreams);
	}
	if (extensionSupported("VK_EXT_global_priority_query")) {
		const char* extension("VK_EXT_global_priority_query");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures.globalPriorityQuery);
	}
	if (extensionSupported("VK_EXT_image_view_min_lod")) {
		const char* extension("VK_EXT_image_view_min_lod");
		VkPhysicalDeviceImageViewMinLodFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "minLod", extFeatures.minLod);
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiDraw", extFeatures.multiDraw);
	}
	if (extensionSupported("VK_EXT_image_2d_view_of_3d")) {
		const char* extension("VK_EXT_image_2d_view_of_3d");
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "image2DViewOf3D", extFeatures.image2DViewOf3D);
		pushFeature2(extension, "sampler2DViewOf3D", extFeatures.sampler2DViewOf3D);
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "micromap", extFeatures.micromap);
		pushFeature2(extension, "micromapCaptureReplay", extFeatures.micromapCaptureReplay);
		pushFeature2(extension, "micromapHostCommands", extFeatures.micromapHostCommands);
	}
	if (extensionSupported("VK_EXT_border_color_swizzle")) {
		const char* extension("VK_EXT_border_color_swizzle");
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "borderColorSwizzle", extFeatures.borderColorSwizzle);
		pushFeature2(extension, "borderColorSwizzleFromImage", extFeatures.borderColorSwizzleFromImage);
	}
	if (extensionSupported("VK_EXT_pageable_device_local_memory")) {
		const char* extension("VK_EXT_pageable_device_local_memory");
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pageableDeviceLocalMemory", extFeatures.pageableDeviceLocalMemory);
	}
	if (extensionSupported("VK_EXT_depth_clamp_zero_one")) {
		const char* extension("VK_EXT_depth_clamp_zero_one");
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "depthClampZeroOne", extFeatures.depthClampZeroOne);
	}
	if (extensionSupported("VK_EXT_non_seamless_cube_map")) {
		const char* extension("VK_EXT_non_seamless_cube_map");
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "nonSeamlessCubeMap", extFeatures.nonSeamlessCubeMap);
	}
	if (extensionSupported("VK_EXT_image_compression_control_swapchain")) {
		const char* extension("VK_EXT_image_compression_control_swapchain");
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControlSwapchain", extFeatures.imageCompressionControlSwapchain);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState3TessellationDomainOrigin", extFeatures.extendedDynamicState3TessellationDomainOrigin);
		pushFeature2(extension, "extendedDynamicState3DepthClampEnable", extFeatures.extendedDynamicState3DepthClampEnable);
		pushFeature2(extension, "extendedDynamicState3PolygonMode", extFeatures.extendedDynamicState3PolygonMode);
		pushFeature2(extension, "extendedDynamicState3RasterizationSamples", extFeatures.extendedDynamicState3RasterizationSamples);
		pushFeature2(extension, "extendedDynamicState3SampleMask", extFeatures.extendedDynamicState3SampleMask);
		pushFeature2(extension, "extendedDynamicState3AlphaToCoverageEnable", extFeatures.extendedDynamicState3AlphaToCoverageEnable);
		pushFeature2(extension, "extendedDynamicState3AlphaToOneEnable", extFeatures.extendedDynamicState3AlphaToOneEnable);
		pushFeature2(extension, "extendedDynamicState3LogicOpEnable", extFeatures.extendedDynamicState3LogicOpEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEnable", extFeatures.extendedDynamicState3ColorBlendEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEquation", extFeatures.extendedDynamicState3ColorBlendEquation);
		pushFeature2(extension, "extendedDynamicState3ColorWriteMask", extFeatures.extendedDynamicState3ColorWriteMask);
		pushFeature2(extension, "extendedDynamicState3RasterizationStream", extFeatures.extendedDynamicState3RasterizationStream);
		pushFeature2(extension, "extendedDynamicState3ConservativeRasterizationMode", extFeatures.extendedDynamicState3ConservativeRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3ExtraPrimitiveOverestimationSize", extFeatures.extendedDynamicState3ExtraPrimitiveOverestimationSize);
		pushFeature2(extension, "extendedDynamicState3DepthClipEnable", extFeatures.extendedDynamicState3DepthClipEnable);
		pushFeature2(extension, "extendedDynamicState3SampleLocationsEnable", extFeatures.extendedDynamicState3SampleLocationsEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendAdvanced", extFeatures.extendedDynamicState3ColorBlendAdvanced);
		pushFeature2(extension, "extendedDynamicState3ProvokingVertexMode", extFeatures.extendedDynamicState3ProvokingVertexMode);
		pushFeature2(extension, "extendedDynamicState3LineRasterizationMode", extFeatures.extendedDynamicState3LineRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3LineStippleEnable", extFeatures.extendedDynamicState3LineStippleEnable);
		pushFeature2(extension, "extendedDynamicState3DepthClipNegativeOneToOne", extFeatures.extendedDynamicState3DepthClipNegativeOneToOne);
		pushFeature2(extension, "extendedDynamicState3ViewportWScalingEnable", extFeatures.extendedDynamicState3ViewportWScalingEnable);
		pushFeature2(extension, "extendedDynamicState3ViewportSwizzle", extFeatures.extendedDynamicState3ViewportSwizzle);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorEnable", extFeatures.extendedDynamicState3CoverageToColorEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorLocation", extFeatures.extendedDynamicState3CoverageToColorLocation);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationMode", extFeatures.extendedDynamicState3CoverageModulationMode);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTableEnable", extFeatures.extendedDynamicState3CoverageModulationTableEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTable", extFeatures.extendedDynamicState3CoverageModulationTable);
		pushFeature2(extension, "extendedDynamicState3CoverageReductionMode", extFeatures.extendedDynamicState3CoverageReductionMode);
		pushFeature2(extension, "extendedDynamicState3RepresentativeFragmentTestEnable", extFeatures.extendedDynamicState3RepresentativeFragmentTestEnable);
		pushFeature2(extension, "extendedDynamicState3ShadingRateImageEnable", extFeatures.extendedDynamicState3ShadingRateImageEnable);
	}
	if (extensionSupported("VK_EXT_subpass_merge_feedback")) {
		const char* extension("VK_EXT_subpass_merge_feedback");
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subpassMergeFeedback", extFeatures.subpassMergeFeedback);
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderModuleIdentifier", extFeatures.shaderModuleIdentifier);
	}
	if (extensionSupported("VK_EXT_rasterization_order_attachment_access")) {
		const char* extension("VK_EXT_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures.rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures.rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures.rasterizationOrderStencilAttachmentAccess);
	}
	if (extensionSupported("VK_EXT_legacy_dithering")) {
		const char* extension("VK_EXT_legacy_dithering");
		VkPhysicalDeviceLegacyDitheringFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "legacyDithering", extFeatures.legacyDithering);
	}
	if (extensionSupported("VK_EXT_pipeline_protected_access")) {
		const char* extension("VK_EXT_pipeline_protected_access");
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineProtectedAccess", extFeatures.pipelineProtectedAccess);
	}
	if (extensionSupported("VK_EXT_mutable_descriptor_type")) {
		const char* extension("VK_EXT_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures.mutableDescriptorType);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_HUAWEI() {
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "subpassShading", extFeatures.subpassShading);
	}
	if (extensionSupported("VK_HUAWEI_invocation_mask")) {
		const char* extension("VK_HUAWEI_invocation_mask");
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "invocationMask", extFeatures.invocationMask);
	}
	if (extensionSupported("VK_HUAWEI_cluster_culling_shader")) {
		const char* extension("VK_HUAWEI_cluster_culling_shader");
		VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "clustercullingShader", extFeatures.clustercullingShader);
		pushFeature2(extension, "multiviewClusterCullingShader", extFeatures.multiviewClusterCullingShader);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_INTEL() {
	if (extensionSupported("VK_INTEL_shader_integer_functions2")) {
		const char* extension("VK_INTEL_shader_integer_functions2");
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerFunctions2", extFeatures.shaderIntegerFunctions2);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_KHR() {
	if (extensionSupported("VK_KHR_dynamic_rendering")) {
		const char* extension("VK_KHR_dynamic_rendering");
		VkPhysicalDeviceDynamicRenderingFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dynamicRendering", extFeatures.dynamicRendering);
	}
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiview", extFeatures.multiview);
		pushFeature2(extension, "multiviewGeometryShader", extFeatures.multiviewGeometryShader);
		pushFeature2(extension, "multiviewTessellationShader", extFeatures.multiviewTessellationShader);
	}
	if (extensionSupported("VK_KHR_shader_float16_int8")) {
		const char* extension("VK_KHR_shader_float16_int8");
		VkPhysicalDeviceShaderFloat16Int8Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat16", extFeatures.shaderFloat16);
		pushFeature2(extension, "shaderInt8", extFeatures.shaderInt8);
	}
	if (extensionSupported("VK_KHR_16bit_storage")) {
		const char* extension("VK_KHR_16bit_storage");
		VkPhysicalDevice16BitStorageFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer16BitAccess", extFeatures.storageBuffer16BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer16BitAccess", extFeatures.uniformAndStorageBuffer16BitAccess);
		pushFeature2(extension, "storagePushConstant16", extFeatures.storagePushConstant16);
		pushFeature2(extension, "storageInputOutput16", extFeatures.storageInputOutput16);
	}
	if (extensionSupported("VK_KHR_imageless_framebuffer")) {
		const char* extension("VK_KHR_imageless_framebuffer");
		VkPhysicalDeviceImagelessFramebufferFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imagelessFramebuffer", extFeatures.imagelessFramebuffer);
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "performanceCounterQueryPools", extFeatures.performanceCounterQueryPools);
		pushFeature2(extension, "performanceCounterMultipleQueryPools", extFeatures.performanceCounterMultipleQueryPools);
	}
	if (extensionSupported("VK_KHR_variable_pointers")) {
		const char* extension("VK_KHR_variable_pointers");
		VkPhysicalDeviceVariablePointersFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "variablePointersStorageBuffer", extFeatures.variablePointersStorageBuffer);
		pushFeature2(extension, "variablePointers", extFeatures.variablePointers);
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructureFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "accelerationStructure", extFeatures.accelerationStructure);
		pushFeature2(extension, "accelerationStructureCaptureReplay", extFeatures.accelerationStructureCaptureReplay);
		pushFeature2(extension, "accelerationStructureIndirectBuild", extFeatures.accelerationStructureIndirectBuild);
		pushFeature2(extension, "accelerationStructureHostCommands", extFeatures.accelerationStructureHostCommands);
		pushFeature2(extension, "descriptorBindingAccelerationStructureUpdateAfterBind", extFeatures.descriptorBindingAccelerationStructureUpdateAfterBind);
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingPipeline", extFeatures.rayTracingPipeline);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplay", extFeatures.rayTracingPipelineShaderGroupHandleCaptureReplay);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplayMixed", extFeatures.rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect", extFeatures.rayTracingPipelineTraceRaysIndirect);
		pushFeature2(extension, "rayTraversalPrimitiveCulling", extFeatures.rayTraversalPrimitiveCulling);
	}
	if (extensionSupported("VK_KHR_ray_query")) {
		const char* extension("VK_KHR_ray_query");
		VkPhysicalDeviceRayQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayQuery", extFeatures.rayQuery);
	}
	if (extensionSupported("VK_KHR_sampler_ycbcr_conversion")) {
		const char* extension("VK_KHR_sampler_ycbcr_conversion");
		VkPhysicalDeviceSamplerYcbcrConversionFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "samplerYcbcrConversion", extFeatures.samplerYcbcrConversion);
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "constantAlphaColorBlendFactors", extFeatures.constantAlphaColorBlendFactors);
		pushFeature2(extension, "events", extFeatures.events);
		pushFeature2(extension, "imageViewFormatReinterpretation", extFeatures.imageViewFormatReinterpretation);
		pushFeature2(extension, "imageViewFormatSwizzle", extFeatures.imageViewFormatSwizzle);
		pushFeature2(extension, "imageView2DOn3DImage", extFeatures.imageView2DOn3DImage);
		pushFeature2(extension, "multisampleArrayImage", extFeatures.multisampleArrayImage);
		pushFeature2(extension, "mutableComparisonSamplers", extFeatures.mutableComparisonSamplers);
		pushFeature2(extension, "pointPolygons", extFeatures.pointPolygons);
		pushFeature2(extension, "samplerMipLodBias", extFeatures.samplerMipLodBias);
		pushFeature2(extension, "separateStencilMaskRef", extFeatures.separateStencilMaskRef);
		pushFeature2(extension, "shaderSampleRateInterpolationFunctions", extFeatures.shaderSampleRateInterpolationFunctions);
		pushFeature2(extension, "tessellationIsolines", extFeatures.tessellationIsolines);
		pushFeature2(extension, "tessellationPointMode", extFeatures.tessellationPointMode);
		pushFeature2(extension, "triangleFans", extFeatures.triangleFans);
		pushFeature2(extension, "vertexAttributeAccessBeyondStride", extFeatures.vertexAttributeAccessBeyondStride);
	}
	if (extensionSupported("VK_KHR_shader_subgroup_extended_types")) {
		const char* extension("VK_KHR_shader_subgroup_extended_types");
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupExtendedTypes", extFeatures.shaderSubgroupExtendedTypes);
	}
	if (extensionSupported("VK_KHR_8bit_storage")) {
		const char* extension("VK_KHR_8bit_storage");
		VkPhysicalDevice8BitStorageFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer8BitAccess", extFeatures.storageBuffer8BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer8BitAccess", extFeatures.uniformAndStorageBuffer8BitAccess);
		pushFeature2(extension, "storagePushConstant8", extFeatures.storagePushConstant8);
	}
	if (extensionSupported("VK_KHR_shader_atomic_int64")) {
		const char* extension("VK_KHR_shader_atomic_int64");
		VkPhysicalDeviceShaderAtomicInt64Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferInt64Atomics", extFeatures.shaderBufferInt64Atomics);
		pushFeature2(extension, "shaderSharedInt64Atomics", extFeatures.shaderSharedInt64Atomics);
	}
	if (extensionSupported("VK_KHR_shader_clock")) {
		const char* extension("VK_KHR_shader_clock");
		VkPhysicalDeviceShaderClockFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupClock", extFeatures.shaderSubgroupClock);
		pushFeature2(extension, "shaderDeviceClock", extFeatures.shaderDeviceClock);
	}
	if (extensionSupported("VK_KHR_global_priority")) {
		const char* extension("VK_KHR_global_priority");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures.globalPriorityQuery);
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "timelineSemaphore", extFeatures.timelineSemaphore);
	}
	if (extensionSupported("VK_KHR_vulkan_memory_model")) {
		const char* extension("VK_KHR_vulkan_memory_model");
		VkPhysicalDeviceVulkanMemoryModelFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "vulkanMemoryModel", extFeatures.vulkanMemoryModel);
		pushFeature2(extension, "vulkanMemoryModelDeviceScope", extFeatures.vulkanMemoryModelDeviceScope);
		pushFeature2(extension, "vulkanMemoryModelAvailabilityVisibilityChains", extFeatures.vulkanMemoryModelAvailabilityVisibilityChains);
	}
	if (extensionSupported("VK_KHR_shader_terminate_invocation")) {
		const char* extension("VK_KHR_shader_terminate_invocation");
		VkPhysicalDeviceShaderTerminateInvocationFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderTerminateInvocation", extFeatures.shaderTerminateInvocation);
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineFragmentShadingRate", extFeatures.pipelineFragmentShadingRate);
		pushFeature2(extension, "primitiveFragmentShadingRate", extFeatures.primitiveFragmentShadingRate);
		pushFeature2(extension, "attachmentFragmentShadingRate", extFeatures.attachmentFragmentShadingRate);
	}
	if (extensionSupported("VK_KHR_separate_depth_stencil_layouts")) {
		const char* extension("VK_KHR_separate_depth_stencil_layouts");
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "separateDepthStencilLayouts", extFeatures.separateDepthStencilLayouts);
	}
	if (extensionSupported("VK_KHR_present_wait")) {
		const char* extension("VK_KHR_present_wait");
		VkPhysicalDevicePresentWaitFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentWait", extFeatures.presentWait);
	}
	if (extensionSupported("VK_KHR_uniform_buffer_standard_layout")) {
		const char* extension("VK_KHR_uniform_buffer_standard_layout");
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "uniformBufferStandardLayout", extFeatures.uniformBufferStandardLayout);
	}
	if (extensionSupported("VK_KHR_buffer_device_address")) {
		const char* extension("VK_KHR_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures.bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures.bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures.bufferDeviceAddressMultiDevice);
	}
	if (extensionSupported("VK_KHR_pipeline_executable_properties")) {
		const char* extension("VK_KHR_pipeline_executable_properties");
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "pipelineExecutableInfo", extFeatures.pipelineExecutableInfo);
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerDotProduct", extFeatures.shaderIntegerDotProduct);
	}
	if (extensionSupported("VK_KHR_present_id")) {
		const char* extension("VK_KHR_present_id");
		VkPhysicalDevicePresentIdFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentId", extFeatures.presentId);
	}
	if (extensionSupported("VK_KHR_synchronization2")) {
		const char* extension("VK_KHR_synchronization2");
		VkPhysicalDeviceSynchronization2Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "synchronization2", extFeatures.synchronization2);
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures.fragmentShaderBarycentric);
	}
	if (extensionSupported("VK_KHR_shader_subgroup_uniform_control_flow")) {
		const char* extension("VK_KHR_shader_subgroup_uniform_control_flow");
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupUniformControlFlow", extFeatures.shaderSubgroupUniformControlFlow);
	}
	if (extensionSupported("VK_KHR_zero_initialize_workgroup_memory")) {
		const char* extension("VK_KHR_zero_initialize_workgroup_memory");
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderZeroInitializeWorkgroupMemory", extFeatures.shaderZeroInitializeWorkgroupMemory);
	}
	if (extensionSupported("VK_KHR_workgroup_memory_explicit_layout")) {
		const char* extension("VK_KHR_workgroup_memory_explicit_layout");
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "workgroupMemoryExplicitLayout", extFeatures.workgroupMemoryExplicitLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayoutScalarBlockLayout", extFeatures.workgroupMemoryExplicitLayoutScalarBlockLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayout8BitAccess", extFeatures.workgroupMemoryExplicitLayout8BitAccess);
		pushFeature2(extension, "workgroupMemoryExplicitLayout16BitAccess", extFeatures.workgroupMemoryExplicitLayout16BitAccess);
	}
	if (extensionSupported("VK_KHR_ray_tracing_maintenance1")) {
		const char* extension("VK_KHR_ray_tracing_maintenance1");
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMaintenance1", extFeatures.rayTracingMaintenance1);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect2", extFeatures.rayTracingPipelineTraceRaysIndirect2);
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "maintenance4", extFeatures.maintenance4);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_NV() {
	if (extensionSupported("VK_NV_corner_sampled_image")) {
		const char* extension("VK_NV_corner_sampled_image");
		VkPhysicalDeviceCornerSampledImageFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cornerSampledImage", extFeatures.cornerSampledImage);
	}
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shaderSMBuiltins", extFeatures.shaderSMBuiltins);
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImageFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "shadingRateImage", extFeatures.shadingRateImage);
		pushFeature2(extension, "shadingRateCoarseSampleOrder", extFeatures.shadingRateCoarseSampleOrder);
	}
	if (extensionSupported("VK_NV_representative_fragment_test")) {
		const char* extension("VK_NV_representative_fragment_test");
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "representativeFragmentTest", extFeatures.representativeFragmentTest);
	}
	if (extensionSupported("VK_NV_compute_shader_derivatives")) {
		const char* extension("VK_NV_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures.computeDerivativeGroupQuads);
		pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures.computeDerivativeGroupLinear);
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures.taskShader);
		pushFeature2(extension, "meshShader", extFeatures.meshShader);
	}
	if (extensionSupported("VK_NV_fragment_shader_barycentric")) {
		const char* extension("VK_NV_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures.fragmentShaderBarycentric);
	}
	if (extensionSupported("VK_NV_shader_image_footprint")) {
		const char* extension("VK_NV_shader_image_footprint");
		VkPhysicalDeviceShaderImageFootprintFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "imageFootprint", extFeatures.imageFootprint);
	}
	if (extensionSupported("VK_NV_scissor_exclusive")) {
		const char* extension("VK_NV_scissor_exclusive");
		VkPhysicalDeviceExclusiveScissorFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "exclusiveScissor", extFeatures.exclusiveScissor);
	}
	if (extensionSupported("VK_NV_dedicated_allocation_image_aliasing")) {
		const char* extension("VK_NV_dedicated_allocation_image_aliasing");
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "dedicatedAllocationImageAliasing", extFeatures.dedicatedAllocationImageAliasing);
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrix", extFeatures.cooperativeMatrix);
		pushFeature2(extension, "cooperativeMatrixRobustBufferAccess", extFeatures.cooperativeMatrixRobustBufferAccess);
	}
	if (extensionSupported("VK_NV_coverage_reduction_mode")) {
		const char* extension("VK_NV_coverage_reduction_mode");
		VkPhysicalDeviceCoverageReductionModeFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "coverageReductionMode", extFeatures.coverageReductionMode);
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCommands", extFeatures.deviceGeneratedCommands);
	}
	if (extensionSupported("VK_NV_inherited_viewport_scissor")) {
		const char* extension("VK_NV_inherited_viewport_scissor");
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "inheritedViewportScissor2D", extFeatures.inheritedViewportScissor2D);
	}
	if (extensionSupported("VK_NV_present_barrier")) {
		const char* extension("VK_NV_present_barrier");
		VkPhysicalDevicePresentBarrierFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "presentBarrier", extFeatures.presentBarrier);
	}
	if (extensionSupported("VK_NV_device_diagnostics_config")) {
		const char* extension("VK_NV_device_diagnostics_config");
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "diagnosticsConfig", extFeatures.diagnosticsConfig);
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentShadingRateEnums", extFeatures.fragmentShadingRateEnums);
		pushFeature2(extension, "supersampleFragmentShadingRates", extFeatures.supersampleFragmentShadingRates);
		pushFeature2(extension, "noInvocationFragmentShadingRates", extFeatures.noInvocationFragmentShadingRates);
	}
	if (extensionSupported("VK_NV_ray_tracing_motion_blur")) {
		const char* extension("VK_NV_ray_tracing_motion_blur");
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMotionBlur", extFeatures.rayTracingMotionBlur);
		pushFeature2(extension, "rayTracingMotionBlurPipelineTraceRaysIndirect", extFeatures.rayTracingMotionBlurPipelineTraceRaysIndirect);
	}
	if (extensionSupported("VK_NV_external_memory_rdma")) {
		const char* extension("VK_NV_external_memory_rdma");
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "externalMemoryRDMA", extFeatures.externalMemoryRDMA);
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "indirectCopy", extFeatures.indirectCopy);
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "memoryDecompression", extFeatures.memoryDecompression);
	}
	if (extensionSupported("VK_NV_linear_color_attachment")) {
		const char* extension("VK_NV_linear_color_attachment");
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "linearColorAttachment", extFeatures.linearColorAttachment);
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "opticalFlow", extFeatures.opticalFlow);
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "rayTracingInvocationReorder", extFeatures.rayTracingInvocationReorder);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_QCOM() {
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapOffset", extFeatures.fragmentDensityMapOffset);
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "textureSampleWeighted", extFeatures.textureSampleWeighted);
		pushFeature2(extension, "textureBoxFilter", extFeatures.textureBoxFilter);
		pushFeature2(extension, "textureBlockMatch", extFeatures.textureBlockMatch);
	}
	if (extensionSupported("VK_QCOM_tile_properties")) {
		const char* extension("VK_QCOM_tile_properties");
		VkPhysicalDeviceTilePropertiesFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "tileProperties", extFeatures.tileProperties);
	}
	if (extensionSupported("VK_QCOM_multiview_per_view_viewports")) {
		const char* extension("VK_QCOM_multiview_per_view_viewports");
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "multiviewPerViewViewports", extFeatures.multiviewPerViewViewports);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_SEC() {
	if (extensionSupported("VK_SEC_amigo_profiling")) {
		const char* extension("VK_SEC_amigo_profiling");
		VkPhysicalDeviceAmigoProfilingFeaturesSEC extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "amigoProfiling", extFeatures.amigoProfiling);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_VALVE() {
	if (extensionSupported("VK_VALVE_mutable_descriptor_type")) {
		const char* extension("VK_VALVE_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures.mutableDescriptorType);
	}
	if (extensionSupported("VK_VALVE_descriptor_set_host_mapping")) {
		const char* extension("VK_VALVE_descriptor_set_host_mapping");
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(device, &deviceFeatures2);
		pushFeature2(extension, "descriptorSetHostMapping", extFeatures.descriptorSetHostMapping);
	}
}


void VulkanDeviceInfoExtensions::readExtendedFeatures() {
    readPhysicalFeatures_AMD();
    readPhysicalFeatures_ARM();
    readPhysicalFeatures_EXT();
    readPhysicalFeatures_HUAWEI();
    readPhysicalFeatures_INTEL();
    readPhysicalFeatures_KHR();
    readPhysicalFeatures_NV();
    readPhysicalFeatures_QCOM();
    readPhysicalFeatures_SEC();
    readPhysicalFeatures_VALVE();
}
