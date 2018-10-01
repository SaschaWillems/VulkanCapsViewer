/*
*
* Vulkan hardware capability viewer
*
* Class with static translations to vulkan enums as strings 
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

#include "stdlib.h"
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <vector>
#include "vulkan/vulkan.h"

class vulkanResources {
public:

	static const std::string versionToString(uint32_t version)
	{
		std::stringstream ss;
		ss << (version >> 22) << "." << ((version >> 12) & 0x3ff) << "." << (version & 0xfff);
		return ss.str();
	}

	static const char *physicalDeviceTypeString(VkPhysicalDeviceType type)
	{
            switch (type)
		{
#define STR(r) case VK_PHYSICAL_DEVICE_TYPE_ ##r: return #r
                STR(OTHER);
                STR(INTEGRATED_GPU);
                STR(DISCRETE_GPU);
                STR(VIRTUAL_GPU);
#undef STR
default: return "UNKNOWN_DEVICE";
		}
	}

	static const char *resultString(VkResult result)
	{
            switch (result)
            {
#define STR(r) case VK_ ##r: return #r
                STR(SUCCESS);
                STR(NOT_READY);
                STR(TIMEOUT);
                STR(EVENT_SET);
                STR(EVENT_RESET);
                STR(ERROR_INITIALIZATION_FAILED);
                STR(ERROR_OUT_OF_HOST_MEMORY);
                STR(ERROR_OUT_OF_DEVICE_MEMORY);
                STR(ERROR_DEVICE_LOST);
                STR(ERROR_LAYER_NOT_PRESENT);
                STR(ERROR_EXTENSION_NOT_PRESENT);
                STR(ERROR_MEMORY_MAP_FAILED);
                STR(ERROR_INCOMPATIBLE_DRIVER);
#undef STR
		default: return "UNKNOWN_RESULT";
            }
	}

	static std::string formatString(VkFormat format)
	{
            switch (format)
            {
#define STR(r) case VK_FORMAT_ ##r: return #r
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
#undef STR
                default:
                        std::stringstream ss;
                        ss << "UNKNOWN_FORMAT (0x" << std::setfill('0') << std::setw(8) << std::hex << format << ")";
                        std::string s = ss.str();
                        return s;
            }
        }

        static std::string presentModeKHRString(VkPresentModeKHR presentMode)
        {
            switch (presentMode)
            {
#define STR(r) case VK_PRESENT_MODE_ ##r: return #r
                STR(IMMEDIATE_KHR);
                STR(MAILBOX_KHR);
                STR(FIFO_KHR);
                STR(FIFO_RELAXED_KHR);
#undef STR
                default:
                    std::stringstream ss;
                    ss << "UNKNOWN_PRESENT_MODE (0x" << std::setfill('0') << std::setw(8) << std::hex << presentMode << ")";
                    std::string s = ss.str();
                    return s;
            }
        }

        static std::string colorSpaceKHRString(VkColorSpaceKHR colorSpace)
        {
            switch (colorSpace)
            {
#define STR(r) case VK_COLOR_SPACE_ ##r: return #r
                STR(SRGB_NONLINEAR_KHR);                
#undef STR
                default:
                    std::stringstream ss;
                    ss << "UNKNOWN_COLOR_SPACE (0x" << std::setfill('0') << std::setw(8) << std::hex << colorSpace << ")";
                    std::string s = ss.str();
                    return s;
            }
        }

    template<typename Number>
    static std::string toHexString(const Number number)
    {
        std::stringstream ss;
        ss << std::hex << std::showbase << number;
        return ss.str();
    }

    template<>
    static std::string toHexString(const uint8_t number)
    {
        return toHexString(static_cast<unsigned>(number));
    }

    template<>
    static std::string toHexString(const int8_t number)
    {
        return toHexString(static_cast<int>(number));
    }

    static std::string driverIdKHRString(const VkDriverIdKHR driverId)
    {
        switch(driverId){
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
#undef STR
            default: return toHexString(driverId);
        };
    }

    static std::string joinString(const char separator, const std::vector<std::string>& stringList)
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

    static std::string conformanceVersionKHRString(const VkConformanceVersionKHR& conformanceVersion)
    {
        const std::vector<uint8_t> versionAsList = {conformanceVersion.major, conformanceVersion.minor, conformanceVersion.subminor, conformanceVersion.patch};
        std::vector<std::string> versionAsStringList;
        const auto u8ToString = [](const uint8_t num) {
            return std::to_string(static_cast<uint>(num));
        };
        std::transform(versionAsList.begin(), versionAsList.end(), std::back_inserter(versionAsStringList), u8ToString);
    
        return joinString('.', versionAsStringList);
    }
};
