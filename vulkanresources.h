/*
*
* Vulkan hardware capability viewer
*
* Helpers converting Vulkan entities to strings
*
* Copyright (C) 2015-2021 by Sascha Willems (www.saschawillems.de)
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

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include <QString>
#include <QSet>
#include "vulkan/vulkan.h"

namespace vulkanResources {
	template<typename Number>
	inline std::string toHexString(const Number number)
	{
		std::stringstream ss;
		ss << std::hex << std::showbase << number;
		return ss.str();
	}

	inline std::string toHexString(const uint8_t number)
	{
		return toHexString(static_cast<unsigned>(number));
	}

	inline std::string toHexString(const int8_t number)
	{
		return toHexString(static_cast<int>(number));
	}

	template<typename Number>
	inline QString toHexQString(const Number number)
	{
		return QString::fromStdString(toHexString(number));
	}

	inline std::string toStringList(const VkSampleCountFlags samples)
	{
		assert(samples <= 0x7F);

		if (samples == 0) return "none";

		std::string sampleList = "[";
		bool first = true;
		for (uint32_t sample = 1; sample != 0; sample <<= 1) {
			if (samples & sample) {
				if (first) first = false; else sampleList += ", ";
				sampleList += std::to_string(sample);
			}
		}
		sampleList += "]";

		return sampleList;
	}

	inline QString toQStringList(const VkSampleCountFlags samples)
	{
		return QString::fromStdString(toStringList(samples));
	}

	inline const std::string versionToString(const uint32_t version)
	{
		std::stringstream ss;
		ss << VK_VERSION_MAJOR(version) << "." << VK_VERSION_MINOR(version) << "." << VK_VERSION_PATCH(version);
		return ss.str();
	}

	inline const std::string revisionToString(const uint32_t revision)
	{
		return "r. " + std::to_string(revision);
	}

	template<typename Size>
	inline const std::string arraySizeToString(const Size size)
	{
		return "[" + std::to_string(size) + "]";
	}

	template<typename Index>
	inline const std::string arrayIndexToString(const Index i)
	{
		return "[" + std::to_string(i) + "]";
	}

	inline std::string physicalDeviceTypeString(const VkPhysicalDeviceType type)
	{
		switch (type)
		{
#define STR(r) case VK_PHYSICAL_DEVICE_TYPE_##r: return #r
			STR(OTHER);
			STR(INTEGRATED_GPU);
			STR(DISCRETE_GPU);
			STR(VIRTUAL_GPU);
			STR(CPU);
#undef STR
		default: return "UNKNOWN_DEVICE_TYPE (" + toHexString(type) + ")";
		}
	}

	inline std::string resultString(const VkResult result)
	{
		switch (result)
		{
#define STR(r) case VK_##r: return #r
			STR(SUCCESS);
			STR(NOT_READY);
			STR(TIMEOUT);
			STR(EVENT_SET);
			STR(EVENT_RESET);
			STR(INCOMPLETE);
			STR(ERROR_OUT_OF_HOST_MEMORY);
			STR(ERROR_OUT_OF_DEVICE_MEMORY);
			STR(ERROR_INITIALIZATION_FAILED);
			STR(ERROR_DEVICE_LOST);
			STR(ERROR_MEMORY_MAP_FAILED);
			STR(ERROR_LAYER_NOT_PRESENT);
			STR(ERROR_EXTENSION_NOT_PRESENT);
			STR(ERROR_FEATURE_NOT_PRESENT);
			STR(ERROR_INCOMPATIBLE_DRIVER);
			STR(ERROR_TOO_MANY_OBJECTS);
			STR(ERROR_FORMAT_NOT_SUPPORTED);
			STR(ERROR_FRAGMENTED_POOL);
			STR(ERROR_OUT_OF_POOL_MEMORY);
			STR(ERROR_INVALID_EXTERNAL_HANDLE);
			STR(ERROR_SURFACE_LOST_KHR);
			STR(ERROR_NATIVE_WINDOW_IN_USE_KHR);
			STR(SUBOPTIMAL_KHR);
			STR(ERROR_OUT_OF_DATE_KHR);
			STR(ERROR_INCOMPATIBLE_DISPLAY_KHR);
			STR(ERROR_VALIDATION_FAILED_EXT);
			STR(ERROR_INVALID_SHADER_NV);
			STR(ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT);
			STR(ERROR_FRAGMENTATION_EXT);
			STR(ERROR_NOT_PERMITTED_EXT);
			STR(ERROR_INVALID_DEVICE_ADDRESS_EXT);
			STR(ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT);
#undef STR
		default: return "UNKNOWN_RESULT (" + toHexString(result) + ")";
		}
	}

	inline std::string formatString(const VkFormat format)
	{
		switch (format)
		{
#define STR(r) case VK_FORMAT_##r: return #r
			STR(UNDEFINED);
			STR(R4G4_UNORM_PACK8);
			STR(R4G4B4A4_UNORM_PACK16);
			STR(B4G4R4A4_UNORM_PACK16);
			STR(R5G6B5_UNORM_PACK16);
			STR(B5G6R5_UNORM_PACK16);
			STR(R5G5B5A1_UNORM_PACK16);
			STR(B5G5R5A1_UNORM_PACK16);
			STR(A1R5G5B5_UNORM_PACK16);
			STR(R8_UNORM);
			STR(R8_SNORM);
			STR(R8_USCALED);
			STR(R8_SSCALED);
			STR(R8_UINT);
			STR(R8_SINT);
			STR(R8_SRGB);
			STR(R8G8_UNORM);
			STR(R8G8_SNORM);
			STR(R8G8_USCALED);
			STR(R8G8_SSCALED);
			STR(R8G8_UINT);
			STR(R8G8_SINT);
			STR(R8G8_SRGB);
			STR(R8G8B8_UNORM);
			STR(R8G8B8_SNORM);
			STR(R8G8B8_USCALED);
			STR(R8G8B8_SSCALED);
			STR(R8G8B8_UINT);
			STR(R8G8B8_SINT);
			STR(R8G8B8_SRGB);
			STR(B8G8R8_UNORM);
			STR(B8G8R8_SNORM);
			STR(B8G8R8_USCALED);
			STR(B8G8R8_SSCALED);
			STR(B8G8R8_UINT);
			STR(B8G8R8_SINT);
			STR(B8G8R8_SRGB);
			STR(R8G8B8A8_UNORM);
			STR(R8G8B8A8_SNORM);
			STR(R8G8B8A8_USCALED);
			STR(R8G8B8A8_SSCALED);
			STR(R8G8B8A8_UINT);
			STR(R8G8B8A8_SINT);
			STR(R8G8B8A8_SRGB);
			STR(B8G8R8A8_UNORM);
			STR(B8G8R8A8_SNORM);
			STR(B8G8R8A8_USCALED);
			STR(B8G8R8A8_SSCALED);
			STR(B8G8R8A8_UINT);
			STR(B8G8R8A8_SINT);
			STR(B8G8R8A8_SRGB);
			STR(A8B8G8R8_UNORM_PACK32);
			STR(A8B8G8R8_SNORM_PACK32);
			STR(A8B8G8R8_USCALED_PACK32);
			STR(A8B8G8R8_SSCALED_PACK32);
			STR(A8B8G8R8_UINT_PACK32);
			STR(A8B8G8R8_SINT_PACK32);
			STR(A8B8G8R8_SRGB_PACK32);
			STR(A2R10G10B10_UNORM_PACK32);
			STR(A2R10G10B10_SNORM_PACK32);
			STR(A2R10G10B10_USCALED_PACK32);
			STR(A2R10G10B10_SSCALED_PACK32);
			STR(A2R10G10B10_UINT_PACK32);
			STR(A2R10G10B10_SINT_PACK32);
			STR(A2B10G10R10_UNORM_PACK32);
			STR(A2B10G10R10_SNORM_PACK32);
			STR(A2B10G10R10_USCALED_PACK32);
			STR(A2B10G10R10_SSCALED_PACK32);
			STR(A2B10G10R10_UINT_PACK32);
			STR(A2B10G10R10_SINT_PACK32);
			STR(R16_UNORM);
			STR(R16_SNORM);
			STR(R16_USCALED);
			STR(R16_SSCALED);
			STR(R16_UINT);
			STR(R16_SINT);
			STR(R16_SFLOAT);
			STR(R16G16_UNORM);
			STR(R16G16_SNORM);
			STR(R16G16_USCALED);
			STR(R16G16_SSCALED);
			STR(R16G16_UINT);
			STR(R16G16_SINT);
			STR(R16G16_SFLOAT);
			STR(R16G16B16_UNORM);
			STR(R16G16B16_SNORM);
			STR(R16G16B16_USCALED);
			STR(R16G16B16_SSCALED);
			STR(R16G16B16_UINT);
			STR(R16G16B16_SINT);
			STR(R16G16B16_SFLOAT);
			STR(R16G16B16A16_UNORM);
			STR(R16G16B16A16_SNORM);
			STR(R16G16B16A16_USCALED);
			STR(R16G16B16A16_SSCALED);
			STR(R16G16B16A16_UINT);
			STR(R16G16B16A16_SINT);
			STR(R16G16B16A16_SFLOAT);
			STR(R32_UINT);
			STR(R32_SINT);
			STR(R32_SFLOAT);
			STR(R32G32_UINT);
			STR(R32G32_SINT);
			STR(R32G32_SFLOAT);
			STR(R32G32B32_UINT);
			STR(R32G32B32_SINT);
			STR(R32G32B32_SFLOAT);
			STR(R32G32B32A32_UINT);
			STR(R32G32B32A32_SINT);
			STR(R32G32B32A32_SFLOAT);
			STR(R64_UINT);
			STR(R64_SINT);
			STR(R64_SFLOAT);
			STR(R64G64_UINT);
			STR(R64G64_SINT);
			STR(R64G64_SFLOAT);
			STR(R64G64B64_UINT);
			STR(R64G64B64_SINT);
			STR(R64G64B64_SFLOAT);
			STR(R64G64B64A64_UINT);
			STR(R64G64B64A64_SINT);
			STR(R64G64B64A64_SFLOAT);
			STR(B10G11R11_UFLOAT_PACK32);
			STR(E5B9G9R9_UFLOAT_PACK32);
			STR(D16_UNORM);
			STR(X8_D24_UNORM_PACK32);
			STR(D32_SFLOAT);
			STR(S8_UINT);
			STR(D16_UNORM_S8_UINT);
			STR(D24_UNORM_S8_UINT);
			STR(D32_SFLOAT_S8_UINT);
			STR(BC1_RGB_UNORM_BLOCK);
			STR(BC1_RGB_SRGB_BLOCK);
			STR(BC1_RGBA_UNORM_BLOCK);
			STR(BC1_RGBA_SRGB_BLOCK);
			STR(BC2_UNORM_BLOCK);
			STR(BC2_SRGB_BLOCK);
			STR(BC3_UNORM_BLOCK);
			STR(BC3_SRGB_BLOCK);
			STR(BC4_UNORM_BLOCK);
			STR(BC4_SNORM_BLOCK);
			STR(BC5_UNORM_BLOCK);
			STR(BC5_SNORM_BLOCK);
			STR(BC6H_UFLOAT_BLOCK);
			STR(BC6H_SFLOAT_BLOCK);
			STR(BC7_UNORM_BLOCK);
			STR(BC7_SRGB_BLOCK);
			STR(ETC2_R8G8B8_UNORM_BLOCK);
			STR(ETC2_R8G8B8_SRGB_BLOCK);
			STR(ETC2_R8G8B8A1_UNORM_BLOCK);
			STR(ETC2_R8G8B8A1_SRGB_BLOCK);
			STR(ETC2_R8G8B8A8_UNORM_BLOCK);
			STR(ETC2_R8G8B8A8_SRGB_BLOCK);
			STR(EAC_R11_UNORM_BLOCK);
			STR(EAC_R11_SNORM_BLOCK);
			STR(EAC_R11G11_UNORM_BLOCK);
			STR(EAC_R11G11_SNORM_BLOCK);
			STR(ASTC_4x4_UNORM_BLOCK);
			STR(ASTC_4x4_SRGB_BLOCK);
			STR(ASTC_5x4_UNORM_BLOCK);
			STR(ASTC_5x4_SRGB_BLOCK);
			STR(ASTC_5x5_UNORM_BLOCK);
			STR(ASTC_5x5_SRGB_BLOCK);
			STR(ASTC_6x5_UNORM_BLOCK);
			STR(ASTC_6x5_SRGB_BLOCK);
			STR(ASTC_6x6_UNORM_BLOCK);
			STR(ASTC_6x6_SRGB_BLOCK);
			STR(ASTC_8x5_UNORM_BLOCK);
			STR(ASTC_8x5_SRGB_BLOCK);
			STR(ASTC_8x6_UNORM_BLOCK);
			STR(ASTC_8x6_SRGB_BLOCK);
			STR(ASTC_8x8_UNORM_BLOCK);
			STR(ASTC_8x8_SRGB_BLOCK);
			STR(ASTC_10x5_UNORM_BLOCK);
			STR(ASTC_10x5_SRGB_BLOCK);
			STR(ASTC_10x6_UNORM_BLOCK);
			STR(ASTC_10x6_SRGB_BLOCK);
			STR(ASTC_10x8_UNORM_BLOCK);
			STR(ASTC_10x8_SRGB_BLOCK);
			STR(ASTC_10x10_UNORM_BLOCK);
			STR(ASTC_10x10_SRGB_BLOCK);
			STR(ASTC_12x10_UNORM_BLOCK);
			STR(ASTC_12x10_SRGB_BLOCK);
			STR(ASTC_12x12_UNORM_BLOCK);
			STR(ASTC_12x12_SRGB_BLOCK);
			STR(G8B8G8R8_422_UNORM);
			STR(B8G8R8G8_422_UNORM);
			STR(G8_B8_R8_3PLANE_420_UNORM);
			STR(G8_B8R8_2PLANE_420_UNORM);
			STR(G8_B8_R8_3PLANE_422_UNORM);
			STR(G8_B8R8_2PLANE_422_UNORM);
			STR(G8_B8_R8_3PLANE_444_UNORM);
			STR(R10X6_UNORM_PACK16);
			STR(R10X6G10X6_UNORM_2PACK16);
			STR(R10X6G10X6B10X6A10X6_UNORM_4PACK16);
			STR(G10X6B10X6G10X6R10X6_422_UNORM_4PACK16);
			STR(B10X6G10X6R10X6G10X6_422_UNORM_4PACK16);
			STR(G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16);
			STR(G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16);
			STR(G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16);
			STR(G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16);
			STR(G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16);
			STR(R12X4_UNORM_PACK16);
			STR(R12X4G12X4_UNORM_2PACK16);
			STR(R12X4G12X4B12X4A12X4_UNORM_4PACK16);
			STR(G12X4B12X4G12X4R12X4_422_UNORM_4PACK16);
			STR(B12X4G12X4R12X4G12X4_422_UNORM_4PACK16);
			STR(G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16);
			STR(G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16);
			STR(G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16);
			STR(G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16);
			STR(G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16);
			STR(G16B16G16R16_422_UNORM);
			STR(B16G16R16G16_422_UNORM);
			STR(G16_B16_R16_3PLANE_420_UNORM);
			STR(G16_B16R16_2PLANE_420_UNORM);
			STR(G16_B16_R16_3PLANE_422_UNORM);
			STR(G16_B16R16_2PLANE_422_UNORM);
			STR(G16_B16_R16_3PLANE_444_UNORM);
			STR(PVRTC1_2BPP_UNORM_BLOCK_IMG);
			STR(PVRTC1_4BPP_UNORM_BLOCK_IMG);
			STR(PVRTC2_2BPP_UNORM_BLOCK_IMG);
			STR(PVRTC2_4BPP_UNORM_BLOCK_IMG);
			STR(PVRTC1_2BPP_SRGB_BLOCK_IMG);
			STR(PVRTC1_4BPP_SRGB_BLOCK_IMG);
			STR(PVRTC2_2BPP_SRGB_BLOCK_IMG);
			STR(PVRTC2_4BPP_SRGB_BLOCK_IMG);
#undef STR
		default: return "UNKNOWN_ENUM (" + toHexString(format) + ")";
		}
	}

	inline std::string presentModeKHRString(const VkPresentModeKHR presentMode)
	{
		switch (presentMode)
		{
#define STR(r) case VK_PRESENT_MODE_##r##_KHR: return #r
			STR(IMMEDIATE);
			STR(MAILBOX);
			STR(FIFO);
			STR(FIFO_RELAXED);
			STR(SHARED_DEMAND_REFRESH);
			STR(SHARED_CONTINUOUS_REFRESH);
#undef STR
		default: return "UNKNOWN_ENUM (" + toHexString(presentMode) + ")";
		}
	}

	inline std::string colorSpaceKHRString(const VkColorSpaceKHR colorSpace)
	{
		switch (colorSpace)
		{
#define STR(r) case VK_COLOR_SPACE_##r: return #r
			STR(SRGB_NONLINEAR_KHR);
			STR(DISPLAY_P3_NONLINEAR_EXT);
			STR(EXTENDED_SRGB_LINEAR_EXT);
			STR(DISPLAY_P3_LINEAR_EXT);
			STR(DCI_P3_NONLINEAR_EXT);
			STR(BT709_LINEAR_EXT);
			STR(BT709_NONLINEAR_EXT);
			STR(BT2020_LINEAR_EXT);
			STR(HDR10_ST2084_EXT);
			STR(DOLBYVISION_EXT);
			STR(HDR10_HLG_EXT);
			STR(ADOBERGB_LINEAR_EXT);
			STR(ADOBERGB_NONLINEAR_EXT);
			STR(PASS_THROUGH_EXT);
			STR(EXTENDED_SRGB_NONLINEAR_EXT);
			STR(DISPLAY_NATIVE_AMD);
#undef STR
		default: return "UNKNOWN_ENUM (" + toHexString(colorSpace) + ")";
		}
	}

	inline std::string driverIdKHRString(const VkDriverIdKHR driverId)
	{
		switch (driverId) {
#define STR(r) case VK_DRIVER_ID_##r##_KHR: return #r
			STR(AMD_PROPRIETARY);
			STR(AMD_OPEN_SOURCE);
			STR(MESA_RADV);
			STR(NVIDIA_PROPRIETARY);
			STR(INTEL_PROPRIETARY_WINDOWS);
			STR(INTEL_OPEN_SOURCE_MESA);
			STR(IMAGINATION_PROPRIETARY);
			STR(QUALCOMM_PROPRIETARY);
			STR(ARM_PROPRIETARY);
			STR(GOOGLE_SWIFTSHADER);
			STR(GGP_PROPRIETARY);
			STR(BROADCOM_PROPRIETARY);
#undef STR
		default: return "UNKNOWN_ENUM (" + toHexString(driverId) + ")";
		};
	}

	inline std::string imageUsageBitString(const VkImageUsageFlagBits usageBit)
	{
		switch (usageBit) {
#define STR(r) case VK_IMAGE_USAGE_##r: return #r
			STR(TRANSFER_SRC_BIT);
			STR(TRANSFER_DST_BIT);
			STR(SAMPLED_BIT);
			STR(STORAGE_BIT);
			STR(COLOR_ATTACHMENT_BIT);
			STR(DEPTH_STENCIL_ATTACHMENT_BIT);
			STR(TRANSIENT_ATTACHMENT_BIT);
			STR(INPUT_ATTACHMENT_BIT);
			STR(SHADING_RATE_IMAGE_BIT_NV);
			STR(FRAGMENT_DENSITY_MAP_BIT_EXT);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(usageBit) + ")";
		};
	}

	inline std::string surfaceTransformBitString(const VkSurfaceTransformFlagBitsKHR transformBit)
	{
		switch (transformBit) {
#define STR(r) case VK_SURFACE_TRANSFORM_##r##_KHR: return #r
			STR(IDENTITY_BIT);
			STR(ROTATE_90_BIT);
			STR(ROTATE_180_BIT);
			STR(ROTATE_270_BIT);
			STR(HORIZONTAL_MIRROR_BIT);
			STR(HORIZONTAL_MIRROR_ROTATE_90_BIT);
			STR(HORIZONTAL_MIRROR_ROTATE_180_BIT);
			STR(HORIZONTAL_MIRROR_ROTATE_270_BIT);
			STR(INHERIT_BIT);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(transformBit) + ")";
		};
	}

	inline std::string compositeAlphaBitString(const VkCompositeAlphaFlagBitsKHR alphaBit)
	{
		switch (alphaBit) {
#define STR(r) case VK_COMPOSITE_ALPHA_##r##_KHR: return #r
			STR(OPAQUE_BIT);
			STR(PRE_MULTIPLIED_BIT);
			STR(POST_MULTIPLIED_BIT);
			STR(INHERIT_BIT);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(alphaBit) + ")";
		};
	}

	inline std::string memoryPropBitString(const VkMemoryPropertyFlagBits memoryPropBit)
	{
		switch (memoryPropBit) {
#define STR(r) case VK_MEMORY_PROPERTY_##r: return #r
			STR(DEVICE_LOCAL_BIT);
			STR(HOST_VISIBLE_BIT);
			STR(HOST_COHERENT_BIT);
			STR(HOST_CACHED_BIT);
			STR(LAZILY_ALLOCATED_BIT);
			STR(PROTECTED_BIT);
			STR(DEVICE_COHERENT_BIT_AMD);
			STR(DEVICE_UNCACHED_BIT_AMD);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(memoryPropBit) + ")";
		};
	}

	inline std::string memoryHeapBitString(const VkMemoryHeapFlagBits heapBit)
	{
		switch (heapBit) {
#define STR(r) case VK_MEMORY_HEAP_##r: return #r
			STR(DEVICE_LOCAL_BIT);
			STR(MULTI_INSTANCE_BIT);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(heapBit) + ")";
		};
	}

	inline std::string queueBitString(const VkQueueFlagBits queueBit)
	{
		switch (queueBit) {
#define STR(r) case VK_QUEUE_##r: return #r
			STR(GRAPHICS_BIT);
			STR(COMPUTE_BIT);
			STR(TRANSFER_BIT);
			STR(SPARSE_BINDING_BIT);
			STR(PROTECTED_BIT);
			STR(VIDEO_DECODE_BIT_KHR);
			STR(VIDEO_ENCODE_BIT_KHR);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(queueBit) + ")";
		};
	}

	inline std::string subgroupFeatureBitString(const VkSubgroupFeatureFlagBits subgroupBit)
	{
		switch (subgroupBit) {
#define STR(r) case VK_SUBGROUP_FEATURE_##r: return #r
			STR(BASIC_BIT);
			STR(VOTE_BIT);
			STR(ARITHMETIC_BIT);
			STR(BALLOT_BIT);
			STR(SHUFFLE_BIT);
			STR(SHUFFLE_RELATIVE_BIT);
			STR(CLUSTERED_BIT);
			STR(QUAD_BIT);
			STR(PARTITIONED_BIT_NV);
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(subgroupBit) + ")";
		};
	}

	inline std::string shaderStagesBitString(const VkShaderStageFlagBits stageBit)
	{
		switch (stageBit) {
#define STR(r) case VK_SHADER_STAGE_##r: return #r
			STR(VERTEX_BIT);
			STR(TESSELLATION_CONTROL_BIT);
			STR(TESSELLATION_EVALUATION_BIT);
			STR(GEOMETRY_BIT);
			STR(FRAGMENT_BIT);
			STR(ALL_GRAPHICS); // technically not a single bit, but it should work here
			STR(COMPUTE_BIT);
			STR(RAYGEN_BIT_NV);
			STR(ANY_HIT_BIT_NV);
			STR(CLOSEST_HIT_BIT_NV);
			STR(MISS_BIT_NV);
			STR(INTERSECTION_BIT_NV);
			STR(CALLABLE_BIT_NV);
			STR(TASK_BIT_NV);
			STR(MESH_BIT_NV);
			STR(ALL); // technically not a single bit, but it should work here
#undef STR
		default: return "UNKNOWN_FLAG (" + toHexString(stageBit) + ")";
		};
	}

	inline std::string joinString(const char separator, const std::vector<std::string>& stringList)
	{
		std::stringstream ss;
		bool first = true;
		for (const auto& s : stringList) {
			if (!first) ss << separator;
			first = false;
			ss << s;
		}

		return ss.str();
	}

	inline std::string conformanceVersionKHRString(const VkConformanceVersionKHR& conformanceVersion)
	{
		const std::vector<uint8_t> versionAsList = { conformanceVersion.major, conformanceVersion.minor, conformanceVersion.subminor, conformanceVersion.patch };
		std::vector<std::string> versionAsStringList;
		const auto u8ToString = [](const uint8_t num) {
			return std::to_string(static_cast<unsigned>(num));
		};
		std::transform(versionAsList.begin(), versionAsList.end(), std::back_inserter(versionAsStringList), u8ToString);

		return joinString('.', versionAsStringList);
	}

	// Values to be displayed as sample counts
	const QSet<QString> sampleFlagsValueNames = {
		"framebufferColorSampleCounts",
		"framebufferDepthSampleCounts",
		"framebufferStencilSampleCounts",
		"framebufferNoAttachmentsSampleCounts",
		"sampledImageColorSampleCounts",
		"sampledImageIntegerSampleCounts",
		"sampledImageDepthSampleCounts",
		"sampledImageStencilSampleCounts",
		"storageImageSampleCounts",
		// Core 1.2
		"framebufferIntegerColorSampleCounts"
	};

	// Values to be displayed as booleans
	const QSet<QString> boolValueNames = {
		"timestampComputeAndGraphics",
		"strictLines",
		"standardSampleLocations",
		// Core 1.1
		"deviceLUIDValid",
		"subgroupQuadOperationsInAllStages",
		"protectedNoFault",
		// Core 1.2
		"shaderSignedZeroInfNanPreserveFloat16",
		"shaderSignedZeroInfNanPreserveFloat32",
		"shaderSignedZeroInfNanPreserveFloat64",
		"shaderDenormPreserveFloat16",
		"shaderDenormPreserveFloat32",
		"shaderDenormPreserveFloat64",
		"shaderDenormFlushToZeroFloat16",
		"shaderDenormFlushToZeroFloat32",
		"shaderDenormFlushToZeroFloat64",
		"shaderRoundingModeRTEFloat16",
		"shaderRoundingModeRTEFloat32",
		"shaderRoundingModeRTEFloat64",
		"shaderRoundingModeRTZFloat16",
		"shaderRoundingModeRTZFloat32",
		"shaderRoundingModeRTZFloat64",
		"shaderUniformBufferArrayNonUniformIndexingNative",
		"shaderSampledImageArrayNonUniformIndexingNative",
		"shaderStorageBufferArrayNonUniformIndexingNative",
		"shaderStorageImageArrayNonUniformIndexingNative",
		"shaderInputAttachmentArrayNonUniformIndexingNative",
		"robustBufferAccessUpdateAfterBind",
		"quadDivergentImplicitLod",
		"independentResolveNone",
		"independentResolve",
		"filterMinmaxSingleComponentFormats",
		"filterMinmaxImageComponentMapping",
		// Core 1.3
		"integerDotProduct16BitMixedSignednessAccelerated",
		"integerDotProduct16BitSignedAccelerated",
		"integerDotProduct16BitUnsignedAccelerated",
		"integerDotProduct32BitMixedSignednessAccelerated",
		"integerDotProduct32BitSignedAccelerated",
		"integerDotProduct32BitUnsignedAccelerated",
		"integerDotProduct4x8BitPackedMixedSignednessAccelerated",
		"integerDotProduct4x8BitPackedSignedAccelerated",
		"integerDotProduct4x8BitPackedUnsignedAccelerated",
		"integerDotProduct64BitMixedSignednessAccelerated",
		"integerDotProduct64BitSignedAccelerated",
		"integerDotProduct64BitUnsignedAccelerated",
		"integerDotProduct8BitMixedSignednessAccelerated",
		"integerDotProduct8BitSignedAccelerated",
		"integerDotProduct8BitUnsignedAccelerated",
		"integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated",
		"integerDotProductAccumulatingSaturating16BitSignedAccelerated",
		"integerDotProductAccumulatingSaturating16BitUnsignedAccelerated",
		"integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated",
		"integerDotProductAccumulatingSaturating32BitSignedAccelerated",
		"integerDotProductAccumulatingSaturating32BitUnsignedAccelerated",
		"integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated",
		"integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated",
		"integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated",
		"integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated",
		"integerDotProductAccumulatingSaturating64BitSignedAccelerated",
		"integerDotProductAccumulatingSaturating64BitUnsignedAccelerated",
		"integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated",
		"integerDotProductAccumulatingSaturating8BitSignedAccelerated",
		"integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"
	};

	// Values to be displayed as UUIDs
	const QSet<QString> uuidValueNames = {
		"deviceUUID",
		// Core 1.1
		"driverUUID",
	};

	//Values to be displayed as LUIDs
	const QSet<QString> luidValueNames = {
			// Core 1.1
			"deviceLUID"
	};

	// Values to be displayed as hex
	const QSet<QString> hexValueNames = {
		"vendorID",
		"deviceID"
	};

	// Values not to be displayd
	const QSet<QString> skipValueNames = {
		"apiVersion",
		"deviceType",
		"driverVersion",
		"headerversion"
	};

	// Key replacement for display
	const QMap<QString, QString> replaceKeyNames = {
		{ "apiVersionText", "apiVersion" },
		{ "deviceTypeText", "deviceType" },
		{ "driverVersionText", "driverVersion" },
	};

};
