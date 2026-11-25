
/*
 * Copyright (C) 2021-2026 Valve Corporation
 * Copyright (C) 2021-2026 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file is ***GENERATED***.  Do Not Edit.
 * See scripts/source/generate_api_library.py for modifications.
 */

#pragma once

#define VPAPI_ATTR inline

#include <vulkan/vulkan.h>

#include <cstddef>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

#if defined(VK_VERSION_1_3) && \
    defined(VK_KHR_global_priority)
#define VP_KHR_roadmap_2022 1
#define VP_KHR_ROADMAP_2022_NAME "VP_KHR_roadmap_2022"
#define VP_KHR_ROADMAP_2022_SPEC_VERSION 2
#define VP_KHR_ROADMAP_2022_MIN_API_VERSION VK_MAKE_VERSION(1, 3, 204)
#endif

#if defined(VK_VERSION_1_3) && \
    defined(VP_KHR_roadmap_2022) && \
    defined(VK_KHR_dynamic_rendering) && \
    defined(VK_KHR_dynamic_rendering_local_read) && \
    defined(VK_KHR_index_type_uint8) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_load_store_op_none) && \
    defined(VK_KHR_maintenance5) && \
    defined(VK_KHR_map_memory2) && \
    defined(VK_KHR_push_descriptor) && \
    defined(VK_KHR_shader_expect_assume) && \
    defined(VK_KHR_shader_float_controls2) && \
    defined(VK_KHR_shader_maximal_reconvergence) && \
    defined(VK_KHR_shader_quad_control) && \
    defined(VK_KHR_shader_subgroup_rotate) && \
    defined(VK_KHR_shader_subgroup_uniform_control_flow) && \
    defined(VK_KHR_vertex_attribute_divisor)
#define VP_KHR_roadmap_2024 1
#define VP_KHR_ROADMAP_2024_NAME "VP_KHR_roadmap_2024"
#define VP_KHR_ROADMAP_2024_SPEC_VERSION 2
#define VP_KHR_ROADMAP_2024_MIN_API_VERSION VK_MAKE_VERSION(1, 3, 276)
#endif

#if defined(VK_VERSION_1_4) && \
    defined(VK_KHR_compute_shader_derivatives) && \
    defined(VK_KHR_cooperative_matrix) && \
    defined(VK_KHR_copy_memory_indirect) && \
    defined(VK_KHR_depth_clamp_zero_one) && \
    defined(VK_KHR_dynamic_rendering) && \
    defined(VK_KHR_dynamic_rendering_local_read) && \
    defined(VK_KHR_fragment_shading_rate) && \
    defined(VK_KHR_get_surface_capabilities2) && \
    defined(VK_KHR_index_type_uint8) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_line_rasterization) && \
    defined(VK_KHR_load_store_op_none) && \
    defined(VK_KHR_maintenance5) && \
    defined(VK_KHR_maintenance7) && \
    defined(VK_KHR_maintenance8) && \
    defined(VK_KHR_maintenance9) && \
    defined(VK_KHR_map_memory2) && \
    defined(VK_KHR_pipeline_binary) && \
    defined(VK_KHR_present_id2) && \
    defined(VK_KHR_present_mode_fifo_latest_ready) && \
    defined(VK_KHR_present_wait2) && \
    defined(VK_KHR_push_descriptor) && \
    defined(VK_KHR_robustness2) && \
    defined(VK_KHR_shader_clock) && \
    defined(VK_KHR_shader_expect_assume) && \
    defined(VK_KHR_shader_float_controls2) && \
    defined(VK_KHR_shader_maximal_reconvergence) && \
    defined(VK_KHR_shader_quad_control) && \
    defined(VK_KHR_shader_subgroup_rotate) && \
    defined(VK_KHR_shader_subgroup_uniform_control_flow) && \
    defined(VK_KHR_shader_untyped_pointers) && \
    defined(VK_KHR_surface) && \
    defined(VK_KHR_surface_maintenance1) && \
    defined(VK_KHR_swapchain) && \
    defined(VK_KHR_swapchain_maintenance1) && \
    defined(VK_KHR_vertex_attribute_divisor) && \
    defined(VK_KHR_workgroup_memory_explicit_layout)
#define VP_KHR_roadmap_2026 1
#define VP_KHR_ROADMAP_2026_NAME "VP_KHR_roadmap_2026"
#define VP_KHR_ROADMAP_2026_SPEC_VERSION 2
#define VP_KHR_ROADMAP_2026_MIN_API_VERSION VK_MAKE_VERSION(1, 4, 328)
#endif

#define VP_HEADER_VERSION_COMPLETE VK_MAKE_API_VERSION(0, 2, 0, VK_HEADER_VERSION)

#define VP_MAX_PROFILE_NAME_SIZE 256U

typedef struct VpProfileProperties {
    char        profileName[VP_MAX_PROFILE_NAME_SIZE];
    uint32_t    specVersion;
} VpProfileProperties;

typedef struct VpBlockProperties {
    VpProfileProperties profiles;
    uint32_t apiVersion;
    char blockName[VP_MAX_PROFILE_NAME_SIZE];
} VpBlockProperties;

typedef struct VpVideoProfileProperties {
    char name[VP_MAX_PROFILE_NAME_SIZE];
} VpVideoProfileProperties;

typedef enum VpInstanceCreateFlagBits {
    VP_INSTANCE_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VpInstanceCreateFlagBits;
typedef VkFlags VpInstanceCreateFlags;

typedef struct VpInstanceCreateInfo {
    const VkInstanceCreateInfo* pCreateInfo;
    VpInstanceCreateFlags       flags;
    uint32_t                    enabledFullProfileCount;
    const VpProfileProperties*  pEnabledFullProfiles;
    uint32_t                    enabledProfileBlockCount;
    const VpBlockProperties*    pEnabledProfileBlocks;
} VpInstanceCreateInfo;

typedef enum VpDeviceCreateFlagBits {
    VP_DEVICE_CREATE_DISABLE_ROBUST_BUFFER_ACCESS_BIT = 0x0000001,
    VP_DEVICE_CREATE_DISABLE_ROBUST_IMAGE_ACCESS_BIT = 0x0000002,
    VP_DEVICE_CREATE_DISABLE_ROBUST_ACCESS =
        VP_DEVICE_CREATE_DISABLE_ROBUST_BUFFER_ACCESS_BIT | VP_DEVICE_CREATE_DISABLE_ROBUST_IMAGE_ACCESS_BIT,

    VP_DEVICE_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VpDeviceCreateFlagBits;
typedef VkFlags VpDeviceCreateFlags;

typedef struct VpDeviceCreateInfo {
    const VkDeviceCreateInfo*   pCreateInfo;
    VpDeviceCreateFlags         flags;
    uint32_t                    enabledFullProfileCount;
    const VpProfileProperties*  pEnabledFullProfiles;
    uint32_t                    enabledProfileBlockCount;
    const VpBlockProperties*    pEnabledProfileBlocks;
} VpDeviceCreateInfo;

VK_DEFINE_HANDLE(VpFunctions)

typedef VpFunctions VpCapabilities;

typedef enum VpFunctionsCreateFlagBits {
    VP_FUNCTIONS_CREATE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VpFunctionsCreateFlagBits;

typedef VkFlags VpFunctionsCreateFlags;

typedef enum VpInstanceFunctionsLoadFlagBits {
    VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT = (1 << 0),
    VP_INSTANCE_FUNCTIONS_LOAD_MISSING_ONLY_BIT = (1 << 1),
    VP_INSTANCE_FUNCTIONS_LOAD_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VpInstanceFunctionsLoadFlagBits;

typedef VkFlags VpInstanceFunctionsLoadFlags;

struct VpFunctions_T {
    static VpFunctions_T& Get() {
        static VpFunctions_T instance;
        return instance;
    }

    VpFunctions_T() {
#ifndef VK_NO_PROTOTYPES
        ImportVulkanFunctions_Static();
#endif//VK_NO_PROTOTYPES
    }

    VkResult validate(bool full_init = false) const {
        // Validate global vulkan function initialization
        // vkEnumerateInstanceVersion is omitted from validation on purpose.
        // It is not available in Vulkan 1.0, and nullptr is a valid state indicating Vulkan 1.0.

        if (this->EnumerateInstanceExtensionProperties == nullptr ||
            this->CreateInstance == nullptr ||
            this->GetInstanceProcAddr == nullptr) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        if (full_init) {
            if (this->GetPhysicalDeviceFeatures2 == nullptr ||
                this->GetPhysicalDeviceProperties2 == nullptr ||
                this->GetPhysicalDeviceFormatProperties2 == nullptr ||
                this->GetPhysicalDeviceQueueFamilyProperties2 == nullptr) {
                return VK_ERROR_INITIALIZATION_FAILED;
            }
        }

        return VK_SUCCESS;
    }

    PFN_vkGetInstanceProcAddr GetInstanceProcAddr = nullptr;
    PFN_vkEnumerateInstanceVersion EnumerateInstanceVersion;
    PFN_vkEnumerateInstanceExtensionProperties EnumerateInstanceExtensionProperties = nullptr;
    PFN_vkEnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties = nullptr;
    PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2 = nullptr;
    PFN_vkGetPhysicalDeviceProperties2 GetPhysicalDeviceProperties2 = nullptr;
    PFN_vkGetPhysicalDeviceFormatProperties2 GetPhysicalDeviceFormatProperties2 = nullptr;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 GetPhysicalDeviceQueueFamilyProperties2 = nullptr;
    PFN_vkCreateInstance CreateInstance = nullptr;
    PFN_vkCreateDevice CreateDevice = nullptr;

private:
#ifndef VK_NO_PROTOTYPES
    void ImportVulkanFunctions_Static() {
        #define VP_SET_STATIC(memberName, staticFuncName) this->memberName = (PFN_vk##memberName)staticFuncName

        VP_SET_STATIC(GetInstanceProcAddr, vkGetInstanceProcAddr);

        VP_SET_STATIC(EnumerateInstanceVersion, vkEnumerateInstanceVersion);
        VP_SET_STATIC(EnumerateInstanceExtensionProperties, vkEnumerateInstanceExtensionProperties);
        VP_SET_STATIC(EnumerateDeviceExtensionProperties, vkEnumerateDeviceExtensionProperties);

        VP_SET_STATIC(GetPhysicalDeviceFeatures2, vkGetPhysicalDeviceFeatures2);
        VP_SET_STATIC(GetPhysicalDeviceProperties2, vkGetPhysicalDeviceProperties2);
        VP_SET_STATIC(GetPhysicalDeviceFormatProperties2, vkGetPhysicalDeviceFormatProperties2);
        VP_SET_STATIC(GetPhysicalDeviceQueueFamilyProperties2, vkGetPhysicalDeviceQueueFamilyProperties2);

        VP_SET_STATIC(CreateInstance, vkCreateInstance);
        VP_SET_STATIC(CreateDevice, vkCreateDevice);

        #undef VP_SET_STATIC
    }
#endif//VK_NO_PROTOTYPES
};

/// Description of a Allocator to be created.
typedef struct VpFunctionsCreateInfo
{
    /// Flags for created allocator. Use #VpInstanceCreateFlagBits enum.
    VpFunctionsCreateFlags          flags;

    PFN_vkGetInstanceProcAddr GetInstanceProcAddr = nullptr;
    PFN_vkEnumerateInstanceVersion EnumerateInstanceVersion;
    PFN_vkEnumerateInstanceExtensionProperties EnumerateInstanceExtensionProperties = nullptr;
    PFN_vkEnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties = nullptr;
    PFN_vkCreateInstance CreateInstance = nullptr;
    PFN_vkCreateDevice CreateDevice = nullptr;
    PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2 = nullptr;
    PFN_vkGetPhysicalDeviceProperties2 GetPhysicalDeviceProperties2 = nullptr;
    PFN_vkGetPhysicalDeviceFormatProperties2 GetPhysicalDeviceFormatProperties2 = nullptr;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 GetPhysicalDeviceQueueFamilyProperties2 = nullptr;
} VpFunctionsCreateInfo;

#ifdef VP_USE_OBJECT

VPAPI_ATTR VkResult vpCreateFunctions(
    const VpFunctionsCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VpFunctions*                                pFunctions
);

/// Destroys allocator object.
VPAPI_ATTR void vpDestroyFunctions(
    VpFunctions                                 functions,
    const VkAllocationCallbacks*                pAllocator);

#endif//VP_USE_OBJECT

/// Helper function to initialize a VpFunctions instance with global Vulkan functions loaded with GetInstanceProcAddr
VPAPI_ATTR VkResult vpInitializeGlobalFunctions(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    PFN_vkGetInstanceProcAddr                   GetInstanceProcAddr);

/// Initializes capabilities with instance functions
VPAPI_ATTR VkResult vpInitializeInstanceFunctions(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VpInstanceFunctionsLoadFlags                flags);

// Query the list of available profiles in the library
VPAPI_ATTR VkResult vpGetProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties);

// List the required profiles of a profile
VPAPI_ATTR VkResult vpGetProfileRequiredProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties);

// Query the profile required Vulkan API version, returns 0 on failure
VPAPI_ATTR uint32_t vpGetProfileAPIVersion(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile);

// List the recommended fallback profiles of a profile
VPAPI_ATTR VkResult vpGetProfileFallbacks(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties);

// Query whether the profile has multiple variants. Profiles with multiple variants can only use vpGetInstanceProfileSupport and vpGetPhysicalDeviceProfileSupport capabilities of the library. Other function will return a VK_ERROR_UNKNOWN error
VPAPI_ATTR VkResult vpHasMultipleVariantsProfile(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pHasMultipleVariants);

// Check whether a profile is supported at the instance level
VPAPI_ATTR VkResult vpGetInstanceProfileSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const char*                                 pLayerName,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported);

// Check whether a variant of a profile is supported at the instance level and report this list of blocks used to validate the profiles
VPAPI_ATTR VkResult vpGetInstanceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const char*                                 pLayerName,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported,
    uint32_t*                                   pPropertyCount,
    VpBlockProperties*                          pProperties);

// Create a VkInstance with the profile instance extensions enabled
VPAPI_ATTR VkResult vpCreateInstance(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance);

// Check whether a profile is supported by the physical device
VPAPI_ATTR VkResult vpGetPhysicalDeviceProfileSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VkPhysicalDevice                            physicalDevice,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported);

// Check whether a variant of a profile is supported by the physical device and report this list of blocks used to validate the profiles
VPAPI_ATTR VkResult vpGetPhysicalDeviceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VkPhysicalDevice                            physicalDevice,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported,
    uint32_t*                                   pPropertyCount,
    VpBlockProperties*                          pProperties);

// Create a VkDevice with the profile features and device extensions enabled
VPAPI_ATTR VkResult vpCreateDevice(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkPhysicalDevice                            physicalDevice,
    const VpDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice);

// Query the list of instance extensions of a profile
VPAPI_ATTR VkResult vpGetProfileInstanceExtensionProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties);

// Query the list of device extensions of a profile
VPAPI_ATTR VkResult vpGetProfileDeviceExtensionProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties);

// Fill the feature structures with the requirements of a profile
VPAPI_ATTR VkResult vpGetProfileFeatures(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    void*                                       pNext);

// Query the list of feature structure types specified by the profile
VPAPI_ATTR VkResult vpGetProfileFeatureStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

// Fill the property structures with the requirements of a profile
VPAPI_ATTR VkResult vpGetProfileProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    void*                                       pNext);

// Query the list of property structure types specified by the profile
VPAPI_ATTR VkResult vpGetProfilePropertyStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

// Fill the queue family property structures with the requirements of a profile
VPAPI_ATTR VkResult vpGetProfileQueueFamilyProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkQueueFamilyProperties2KHR*                pProperties);

// Query the list of queue family property structure types specified by the profile
VPAPI_ATTR VkResult vpGetProfileQueueFamilyStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

// Query the list of formats with specified requirements by a profile
VPAPI_ATTR VkResult vpGetProfileFormats(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pFormatCount,
    VkFormat*                                   pFormats);

// Query the requirements of a format for a profile
VPAPI_ATTR VkResult vpGetProfileFormatProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    VkFormat                                    format,
    void*                                       pNext);

// Query the list of format structure types specified by the profile
VPAPI_ATTR VkResult vpGetProfileFormatStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

#ifdef VK_KHR_video_queue
// Query the list of video profiles specified by the profile
VPAPI_ATTR VkResult vpGetProfileVideoProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pVideoProfileCount,
    VpVideoProfileProperties*                   pVideoProfiles);

// Query the video profile info structures for a video profile defined by a profile
VPAPI_ATTR VkResult vpGetProfileVideoProfileInfo(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    VkVideoProfileInfoKHR*                      pVideoProfileInfo);

// Query the list of video profile info structure types specified by the profile for a video profile
VPAPI_ATTR VkResult vpGetProfileVideoProfileInfoStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

// Query the video capabilities requirements for a video profile defined by a profile
VPAPI_ATTR VkResult vpGetProfileVideoCapabilities(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    void*                                       pNext);

// Query the list of video capability structure types specified by the profile for a video profile
VPAPI_ATTR VkResult vpGetProfileVideoCapabilityStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);

// Query the video format property requirements for a video profile defined by a profile
VPAPI_ATTR VkResult vpGetProfileVideoFormatProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pPropertyCount,
    VkVideoFormatPropertiesKHR*                 pProperties);

// Query the list of video format property structure types specified by the profile for a video profile
VPAPI_ATTR VkResult vpGetProfileVideoFormatStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes);
#endif  // VK_KHR_video_queue

#include <cstdio>

#ifndef VP_DEBUG_MESSAGE_CALLBACK
#if defined(ANDROID) || defined(__ANDROID__)
#include <android/log.h>
#define VP_DEBUG_MESSAGE_CALLBACK(MSG) \
    __android_log_print(ANDROID_LOG_ERROR, "Profiles ERROR", "%s", MSG)
#else
#define VP_DEBUG_MESSAGE_CALLBACK(MSG) fprintf(stderr, "%s\n", MSG)
#endif
#else
void VP_DEBUG_MESSAGE_CALLBACK(const char*);
#endif

#define VP_DEBUG_MSG(MSG) VP_DEBUG_MESSAGE_CALLBACK((MSG))
#define VP_DEBUG_MSGF(MSGFMT, ...) { char msg[1024]; snprintf(msg, sizeof(msg) - 1, (MSGFMT), __VA_ARGS__); VP_DEBUG_MESSAGE_CALLBACK(msg); }
#define VP_DEBUG_COND_MSG(COND, MSG) if ((COND)) { VP_DEBUG_MSG((MSG)); }
#define VP_DEBUG_COND_MSGF(COND, MSGFMT, ...) if ((COND)) { VP_DEBUG_MSGF((MSGFMT), __VA_ARGS__); }

namespace detail {


VPAPI_ATTR std::string FormatString(const char* message, ...) {
    std::size_t const STRING_BUFFER(4096);

    assert(message != nullptr);
    assert(strlen(message) >= 1 && strlen(message) < STRING_BUFFER);

    char buffer[STRING_BUFFER];
    va_list list;

    va_start(list, message);
    vsnprintf(buffer, STRING_BUFFER, message, list);
    va_end(list);

    return buffer;
}

VPAPI_ATTR const void* vpGetStructure(const void* pNext, VkStructureType type) {
    const VkBaseOutStructure* p = static_cast<const VkBaseOutStructure*>(pNext);
    while (p != nullptr) {
        if (p->sType == type) return p;
        p = p->pNext;
    }
    return nullptr;
}

VPAPI_ATTR void* vpGetStructure(void* pNext, VkStructureType type) {
    VkBaseOutStructure* p = static_cast<VkBaseOutStructure*>(pNext);
    while (p != nullptr) {
        if (p->sType == type) return p;
        p = p->pNext;
    }
    return nullptr;
}

VPAPI_ATTR VkBaseOutStructure* vpExtractStructure(VkPhysicalDeviceFeatures2KHR* pFeatures, VkStructureType structureType) {
    if (structureType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR) {
        return nullptr;
    }

    VkBaseOutStructure* current = reinterpret_cast<VkBaseOutStructure*>(pFeatures);
    VkBaseOutStructure* previous = nullptr;
    VkBaseOutStructure* found = nullptr;

    while (current != nullptr) {
        if (structureType == current->sType) {
            found = current;
            if (previous != nullptr) {
                previous->pNext = current->pNext;
            }
            current = nullptr;
        } else {
            previous = current;
            current = current->pNext;
        }
    }

    if (found != nullptr) {
        found->pNext = nullptr;
        return found;
    } else {
        return nullptr;
    }
}

VPAPI_ATTR void GatherStructureTypes(std::vector<VkStructureType>& structureTypes, VkBaseOutStructure* pNext) {
    while (pNext) {
        if (std::find(structureTypes.begin(), structureTypes.end(), pNext->sType) == structureTypes.end()) {
            structureTypes.push_back(pNext->sType);
        }

        pNext = pNext->pNext;
    }
}

VPAPI_ATTR bool isMultiple(double source, double multiple) {
    double mod = std::fmod(source, multiple);
    return std::abs(mod) < 0.0001;
}

VPAPI_ATTR bool isPowerOfTwo(double source) {
    double mod = std::fmod(source, 1.0);
    if (std::abs(mod) >= 0.0001) return false;

    std::uint64_t value = static_cast<std::uint64_t>(std::abs(source));
    return !(value & (value - static_cast<std::uint64_t>(1)));
}

using PFN_vpStructFiller = void(*)(VkBaseOutStructure* p);
using PFN_vpStructComparator = bool(*)(VkBaseOutStructure* p);
using PFN_vpPropertyComparator = bool(*)(VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features);
using PFN_vpStructChainerCb = void(*)(VkBaseOutStructure* p, void* pUser);
using PFN_vpStructChainer = void(*)(VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb);
using PFN_vpStructArrayChainerCb = void(*)(uint32_t count, VkBaseOutStructure* p, void* pUser);
using PFN_vpStructArrayChainer = void(*)(uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb);

struct VpFeatureDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpPropertyDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpPropertyComparator        pfnComparator;
};

struct VpQueueFamilyDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpFormatDesc {
    VkFormat                        format;
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpStructChainerDesc {
    PFN_vpStructChainer             pfnFeature;
    PFN_vpStructChainer             pfnProperty;
    PFN_vpStructArrayChainer        pfnQueueFamily;
    PFN_vpStructChainer             pfnFormat;
};

struct VpVideoProfileInfoDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpVideoCapabilityDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpVideoFormatDesc {
    PFN_vpStructFiller              pfnFiller;
    PFN_vpStructComparator          pfnComparator;
};

struct VpVideoProfileStructChainerDesc {
    PFN_vpStructChainer             pfnInfo;
    PFN_vpStructChainer             pfnCapability;
    PFN_vpStructArrayChainer        pfnFormat;
};

struct VpVideoProfileDesc {
    VpVideoProfileProperties properties;

    uint32_t infoStructTypeCount;
    const VkStructureType* pInfoStructTypes;
    VpVideoProfileInfoDesc info;

    uint32_t capabilityStructTypeCount;
    const VkStructureType* pCapabilityStructTypes;
    VpVideoCapabilityDesc capability;

    uint32_t formatStructTypeCount;
    const VkStructureType* pFormatStructTypes;
    uint32_t formatCount;
    const VpVideoFormatDesc* pFormats;

    VpVideoProfileStructChainerDesc chainers;
};

// The physical device information to evaluate the 'depends' condition of a capability block
struct VpDependsContext {
    VkPhysicalDevice                    physicalDevice;
    PFN_vkGetPhysicalDeviceFeatures2KHR pfnGetPhysicalDeviceFeatures2;
    uint32_t                            apiVersion;
    uint32_t                            extensionCount;
    const VkExtensionProperties*        pExtensions;

    bool HasVersion(uint32_t major, uint32_t minor) const {
        const uint32_t actualMajor = VK_API_VERSION_MAJOR(this->apiVersion);
        const uint32_t actualMinor = VK_API_VERSION_MINOR(this->apiVersion);
        return actualMajor > major || (actualMajor == major && actualMinor >= minor);
    }

    bool HasExtension(const char* extensionName) const {
        for (uint32_t i = 0; i < this->extensionCount; ++i) {
            if (strcmp(this->pExtensions[i].extensionName, extensionName) == 0) {
                return true;
            }
        }
        return false;
    }
};

// Returns whether the physical device satisfies the 'depends' condition of a capability block
typedef bool(*PFN_vpDependsCb)(const VpDependsContext& context);

struct VpVariantDesc {
    char blockName[VP_MAX_PROFILE_NAME_SIZE];

    // nullptr when the capability block requirements are unconditional
    PFN_vpDependsCb pfnDepends;

    uint32_t instanceExtensionCount;
    const VkExtensionProperties* pInstanceExtensions;

    uint32_t deviceExtensionCount;
    const VkExtensionProperties* pDeviceExtensions;

    uint32_t featureStructTypeCount;
    const VkStructureType* pFeatureStructTypes;
    VpFeatureDesc feature;

    uint32_t propertyStructTypeCount;
    const VkStructureType* pPropertyStructTypes;
    VpPropertyDesc property;

    uint32_t queueFamilyStructTypeCount;
    const VkStructureType* pQueueFamilyStructTypes;
    uint32_t queueFamilyCount;
    const VpQueueFamilyDesc* pQueueFamilies;

    uint32_t formatStructTypeCount;
    const VkStructureType* pFormatStructTypes;
    uint32_t formatCount;
    const VpFormatDesc* pFormats;

    VpStructChainerDesc chainers;

    uint32_t videoProfileCount;
    const VpVideoProfileDesc* pVideoProfiles;
};

struct VpCapabilitiesDesc {
    uint32_t variantCount;
    const VpVariantDesc* pVariants;
};

struct VpProfileDesc {
    VpProfileProperties             props;
    uint32_t                        minApiVersion;

    const detail::VpVariantDesc*    pMergedCapabilities;

    uint32_t                        requiredProfileCount;
    const VpProfileProperties*      pRequiredProfiles;

    uint32_t                        requiredCapabilityCount;
    const VpCapabilitiesDesc*       pRequiredCapabilities;

    uint32_t                        fallbackCount;
    const VpProfileProperties*      pFallbacks;
};

template <typename T>
VPAPI_ATTR bool vpCheckFlags(const T& actual, const uint64_t expected) {
    return (actual & expected) == expected;
}

// Checks that a returned array (e.g. VkDrmFormatModifierPropertiesListEXT::pDrmFormatModifierProperties) contains an element
// matching the profile element requirements
template <typename T, typename Pred>
VPAPI_ATTR bool vpCheckArrayElement(const T* pArray, uint32_t count, Pred pred) {
    if (pArray == nullptr) return false;
    for (uint32_t i = 0; i < count; ++i) {
        if (pred(pArray[i])) return true;
    }
    return false;
}

// Fills a returned array (e.g. VkDrmFormatModifierPropertiesListEXT::pDrmFormatModifierProperties) with the profile elements,
// following the Vulkan two-call idiom: when the array is null, only the number of profile elements is returned
template <typename T, typename Fill>
VPAPI_ATTR void vpFillArray(T* pArray, uint32_t* pCount, uint32_t profileCount, Fill fill) {
    if (pArray == nullptr) {
        *pCount = profileCount;
        return;
    }
    const uint32_t count = std::min(*pCount, profileCount);
    for (uint32_t i = 0; i < count; ++i) {
        pArray[i] = T{};
        fill(i, pArray[i]);
    }
    *pCount = count;
}

VPAPI_ATTR bool vpAllocateFormatPropertiesArrays(VkBaseOutStructure* p, std::vector<std::vector<uint64_t>>& storage) {
    (void)storage;
    bool allocated = false;
    for (; p != nullptr; p = p->pNext) {
        switch (p->sType) {
#if defined(VK_EXT_image_drm_format_modifier)
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: {
                VkDrmFormatModifierPropertiesList2EXT* s = static_cast<VkDrmFormatModifierPropertiesList2EXT*>(static_cast<void*>(p));
                if (s->drmFormatModifierCount > 0 && s->pDrmFormatModifierProperties == nullptr) {
                    storage.emplace_back((sizeof(VkDrmFormatModifierProperties2EXT) * s->drmFormatModifierCount + sizeof(uint64_t) - 1) / sizeof(uint64_t));
                    s->pDrmFormatModifierProperties = static_cast<VkDrmFormatModifierProperties2EXT*>(static_cast<void*>(storage.back().data()));
                    allocated = true;
                }
            } break;
#endif
#if defined(VK_EXT_image_drm_format_modifier)
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: {
                VkDrmFormatModifierPropertiesListEXT* s = static_cast<VkDrmFormatModifierPropertiesListEXT*>(static_cast<void*>(p));
                if (s->drmFormatModifierCount > 0 && s->pDrmFormatModifierProperties == nullptr) {
                    storage.emplace_back((sizeof(VkDrmFormatModifierPropertiesEXT) * s->drmFormatModifierCount + sizeof(uint64_t) - 1) / sizeof(uint64_t));
                    s->pDrmFormatModifierProperties = static_cast<VkDrmFormatModifierPropertiesEXT*>(static_cast<void*>(storage.back().data()));
                    allocated = true;
                }
            } break;
#endif
            default: break;
        }
    }
    return allocated;
}


#ifdef VK_KHR_video_queue
VPAPI_ATTR void vpForEachMatchingVideoProfiles(
    VkVideoProfileInfoKHR*                      pVideoProfileInfo,
    void*                                       pUser,
    PFN_vpStructChainerCb                       pfnCb) {
    const VkVideoChromaSubsamplingFlagsKHR chroma_subsampling_list[] = {
        VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR,
        VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR,
        VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR,
        VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR
    };
    const VkVideoComponentBitDepthFlagsKHR bit_depth_list[] = {
        VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR,
        VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR,
        VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR
    };
    for (size_t chromaSubsampling_idx = 0; chromaSubsampling_idx < std::size(chroma_subsampling_list); ++chromaSubsampling_idx) {
        pVideoProfileInfo->chromaSubsampling = chroma_subsampling_list[chromaSubsampling_idx];
        for (size_t lumaBitDepth_idx = 0; lumaBitDepth_idx < std::size(bit_depth_list); ++lumaBitDepth_idx) {
            pVideoProfileInfo->lumaBitDepth = bit_depth_list[lumaBitDepth_idx];
            for (size_t chromaBitDepth_idx = 0; chromaBitDepth_idx < std::size(bit_depth_list); ++chromaBitDepth_idx) {
                pVideoProfileInfo->chromaBitDepth = bit_depth_list[chromaBitDepth_idx];
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR;
                    VkVideoDecodeH264ProfileInfoKHR var_VideoDecodeH264ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR };
                    var_VideoDecodeH264ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoDecodeH264ProfileInfoKHR;
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_BASELINE;
                    var_VideoDecodeH264ProfileInfoKHR.pictureLayout = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_422;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_BASELINE;
                    var_VideoDecodeH264ProfileInfoKHR.pictureLayout = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_422;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_BASELINE;
                    var_VideoDecodeH264ProfileInfoKHR.pictureLayout = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_422;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR;
                    VkVideoDecodeH265ProfileInfoKHR var_VideoDecodeH265ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR };
                    var_VideoDecodeH265ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoDecodeH265ProfileInfoKHR;
                    var_VideoDecodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_DECODE_VP9_BIT_KHR;
                    VkVideoDecodeVP9ProfileInfoKHR var_VideoDecodeVP9ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR };
                    var_VideoDecodeVP9ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoDecodeVP9ProfileInfoKHR;
                    var_VideoDecodeVP9ProfileInfoKHR.stdProfile = STD_VIDEO_VP9_PROFILE_0;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeVP9ProfileInfoKHR.stdProfile = STD_VIDEO_VP9_PROFILE_1;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeVP9ProfileInfoKHR.stdProfile = STD_VIDEO_VP9_PROFILE_2;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeVP9ProfileInfoKHR.stdProfile = STD_VIDEO_VP9_PROFILE_3;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR;
                    VkVideoDecodeAV1ProfileInfoKHR var_VideoDecodeAV1ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR };
                    var_VideoDecodeAV1ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoDecodeAV1ProfileInfoKHR;
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_MAIN;
                    var_VideoDecodeAV1ProfileInfoKHR.filmGrainSupport = VK_TRUE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_PROFESSIONAL;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_MAIN;
                    var_VideoDecodeAV1ProfileInfoKHR.filmGrainSupport = VK_FALSE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoDecodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_PROFESSIONAL;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR;
                    VkVideoEncodeH264ProfileInfoKHR var_VideoEncodeH264ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR };
                    var_VideoEncodeH264ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoEncodeH264ProfileInfoKHR;
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_BASELINE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_422;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH264ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR;
                    VkVideoEncodeH265ProfileInfoKHR var_VideoEncodeH265ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR };
                    var_VideoEncodeH265ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoEncodeH265ProfileInfoKHR;
                    var_VideoEncodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN_10;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeH265ProfileInfoKHR.stdProfileIdc = STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
                {
                    pVideoProfileInfo->pNext = nullptr;
                    pVideoProfileInfo->videoCodecOperation = VK_VIDEO_CODEC_OPERATION_ENCODE_AV1_BIT_KHR;
                    VkVideoEncodeAV1ProfileInfoKHR var_VideoEncodeAV1ProfileInfoKHR = { VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR };
                    var_VideoEncodeAV1ProfileInfoKHR.pNext = pVideoProfileInfo->pNext;
                    pVideoProfileInfo->pNext = &var_VideoEncodeAV1ProfileInfoKHR;
                    var_VideoEncodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_MAIN;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_HIGH;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                    var_VideoEncodeAV1ProfileInfoKHR.stdProfile = STD_VIDEO_AV1_PROFILE_PROFESSIONAL;
                    pfnCb(reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo), pUser);
                }
            }
        }
    }
}
#endif  // VK_KHR_video_queue
#ifdef VP_KHR_roadmap_2022
namespace VP_KHR_ROADMAP_2022 {

static const VkStructureType featureStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR,
};

static const VkStructureType propertyStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR,
};

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.depthBiasClamp = VK_TRUE;
                    s->features.depthClamp = VK_TRUE;
                    s->features.drawIndirectFirstInstance = VK_TRUE;
                    s->features.fragmentStoresAndAtomics = VK_TRUE;
                    s->features.fullDrawIndexUint32 = VK_TRUE;
                    s->features.imageCubeArray = VK_TRUE;
                    s->features.independentBlend = VK_TRUE;
                    s->features.occlusionQueryPrecise = VK_TRUE;
                    s->features.robustBufferAccess = VK_TRUE;
                    s->features.sampleRateShading = VK_TRUE;
                    s->features.samplerAnisotropy = VK_TRUE;
                    s->features.shaderSampledImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageBufferArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageExtendedFormats = VK_TRUE;
                    s->features.shaderUniformBufferArrayDynamicIndexing = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->multiview = VK_TRUE;
                    s->samplerYcbcrConversion = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->bufferDeviceAddress = VK_TRUE;
                    s->descriptorBindingPartiallyBound = VK_TRUE;
                    s->descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUniformTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUpdateUnusedWhilePending = VK_TRUE;
                    s->descriptorBindingVariableDescriptorCount = VK_TRUE;
                    s->descriptorIndexing = VK_TRUE;
                    s->hostQueryReset = VK_TRUE;
                    s->imagelessFramebuffer = VK_TRUE;
                    s->runtimeDescriptorArray = VK_TRUE;
                    s->scalarBlockLayout = VK_TRUE;
                    s->separateDepthStencilLayouts = VK_TRUE;
                    s->shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderSubgroupExtendedTypes = VK_TRUE;
                    s->shaderUniformBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayNonUniformIndexing = VK_TRUE;
                    s->subgroupBroadcastDynamicId = VK_TRUE;
                    s->timelineSemaphore = VK_TRUE;
                    s->uniformBufferStandardLayout = VK_TRUE;
                    s->vulkanMemoryModel = VK_TRUE;
                    s->vulkanMemoryModelDeviceScope = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* s = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    s->computeFullSubgroups = VK_TRUE;
                    s->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_TRUE;
                    s->dynamicRendering = VK_TRUE;
                    s->inlineUniformBlock = VK_TRUE;
                    s->maintenance4 = VK_TRUE;
                    s->pipelineCreationCacheControl = VK_TRUE;
                    s->privateData = VK_TRUE;
                    s->robustImageAccess = VK_TRUE;
                    s->shaderDemoteToHelperInvocation = VK_TRUE;
                    s->shaderIntegerDotProduct = VK_TRUE;
                    s->shaderTerminateInvocation = VK_TRUE;
                    s->shaderZeroInitializeWorkgroupMemory = VK_TRUE;
                    s->subgroupSizeControl = VK_TRUE;
                    s->synchronization2 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: {
                    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* s = static_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(static_cast<void*>(p));
                    s->globalPriorityQuery = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthBiasClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.drawIndirectFirstInstance == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fragmentStoresAndAtomics == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fullDrawIndexUint32 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.imageCubeArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.independentBlend == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.occlusionQueryPrecise == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.robustBufferAccess == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.sampleRateShading == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.samplerAnisotropy == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderSampledImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageExtendedFormats == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::multiview == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::samplerYcbcrConversion == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::bufferDeviceAddress == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingPartiallyBound == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingSampledImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUpdateUnusedWhilePending == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingVariableDescriptorCount == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::hostQueryReset == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::imagelessFramebuffer == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::runtimeDescriptorArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::scalarBlockLayout == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::separateDepthStencilLayouts == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSampledImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSubgroupExtendedTypes == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::subgroupBroadcastDynamicId == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::timelineSemaphore == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::uniformBufferStandardLayout == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModel == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModelDeviceScope == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* prettify_VkPhysicalDeviceVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::computeFullSubgroups == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::dynamicRendering == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::inlineUniformBlock == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::maintenance4 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::pipelineCreationCacheControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::privateData == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::robustImageAccess == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderDemoteToHelperInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderIntegerDotProduct == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderTerminateInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderZeroInitializeWorkgroupMemory == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::subgroupSizeControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::synchronization2 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: {
                    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR = static_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR->globalPriorityQuery == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR->globalPriorityQuery == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR::globalPriorityQuery == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, &physicalDeviceVulkan11Features };
        VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, &physicalDeviceVulkan12Features };
        VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR physicalDeviceGlobalPriorityQueryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR, &physicalDeviceVulkan13Features };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceGlobalPriorityQueryFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};

namespace blocks {
namespace vulkan10requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.robustBufferAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.robustBufferAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements
namespace vulkan11requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->multiview = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::multiview == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* s = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    s->maxMultiviewInstanceIndex = 134217727;
                    s->maxMultiviewViewCount = 6;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* prettify_VkPhysicalDeviceVulkan11Properties = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewInstanceIndex >= 134217727); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewInstanceIndex >= 134217727), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::maxMultiviewInstanceIndex >= 134217727");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewViewCount >= 6); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewViewCount >= 6), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::maxMultiviewViewCount >= 6");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements
namespace vulkan12requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->hostQueryReset = VK_TRUE;
                    s->imagelessFramebuffer = VK_TRUE;
                    s->separateDepthStencilLayouts = VK_TRUE;
                    s->shaderSubgroupExtendedTypes = VK_TRUE;
                    s->subgroupBroadcastDynamicId = VK_TRUE;
                    s->timelineSemaphore = VK_TRUE;
                    s->uniformBufferStandardLayout = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::hostQueryReset == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::imagelessFramebuffer == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::separateDepthStencilLayouts == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSubgroupExtendedTypes == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::subgroupBroadcastDynamicId == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::timelineSemaphore == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::uniformBufferStandardLayout == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->maxTimelineSemaphoreValueDifference = 2147483647;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxTimelineSemaphoreValueDifference >= 2147483647); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxTimelineSemaphoreValueDifference >= 2147483647), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxTimelineSemaphoreValueDifference >= 2147483647");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements
namespace vulkan13requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->bufferDeviceAddress = VK_TRUE;
                    s->vulkanMemoryModel = VK_TRUE;
                    s->vulkanMemoryModelDeviceScope = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* s = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    s->computeFullSubgroups = VK_TRUE;
                    s->dynamicRendering = VK_TRUE;
                    s->inlineUniformBlock = VK_TRUE;
                    s->maintenance4 = VK_TRUE;
                    s->pipelineCreationCacheControl = VK_TRUE;
                    s->privateData = VK_TRUE;
                    s->robustImageAccess = VK_TRUE;
                    s->shaderDemoteToHelperInvocation = VK_TRUE;
                    s->shaderIntegerDotProduct = VK_TRUE;
                    s->shaderTerminateInvocation = VK_TRUE;
                    s->shaderZeroInitializeWorkgroupMemory = VK_TRUE;
                    s->subgroupSizeControl = VK_TRUE;
                    s->synchronization2 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::bufferDeviceAddress == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModel == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModelDeviceScope == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* prettify_VkPhysicalDeviceVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::computeFullSubgroups == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::dynamicRendering == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::inlineUniformBlock == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::maintenance4 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::pipelineCreationCacheControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::privateData == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::robustImageAccess == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderDemoteToHelperInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderIntegerDotProduct == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderTerminateInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderZeroInitializeWorkgroupMemory == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::subgroupSizeControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::synchronization2 == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                    VkPhysicalDeviceVulkan13Properties* s = static_cast<VkPhysicalDeviceVulkan13Properties*>(static_cast<void*>(p));
                    s->maxBufferSize = 1073741824;
                    s->maxDescriptorSetInlineUniformBlocks = 4;
                    s->maxDescriptorSetUpdateAfterBindInlineUniformBlocks = 4;
                    s->maxInlineUniformBlockSize = 256;
                    s->maxInlineUniformTotalSize = 256;
                    s->maxPerStageDescriptorInlineUniformBlocks = 4;
                    s->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = 4;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                    VkPhysicalDeviceVulkan13Properties* prettify_VkPhysicalDeviceVulkan13Properties = static_cast<VkPhysicalDeviceVulkan13Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxBufferSize >= 1073741824); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxBufferSize >= 1073741824), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxBufferSize >= 1073741824");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxDescriptorSetInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformBlockSize >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformBlockSize >= 256), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxInlineUniformBlockSize >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformTotalSize >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformTotalSize >= 256), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxInlineUniformTotalSize >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxPerStageDescriptorInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, &physicalDeviceVulkan12Features };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan13requirements
namespace vulkan10requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.depthBiasClamp = VK_TRUE;
                    s->features.depthClamp = VK_TRUE;
                    s->features.drawIndirectFirstInstance = VK_TRUE;
                    s->features.fragmentStoresAndAtomics = VK_TRUE;
                    s->features.fullDrawIndexUint32 = VK_TRUE;
                    s->features.imageCubeArray = VK_TRUE;
                    s->features.independentBlend = VK_TRUE;
                    s->features.occlusionQueryPrecise = VK_TRUE;
                    s->features.sampleRateShading = VK_TRUE;
                    s->features.samplerAnisotropy = VK_TRUE;
                    s->features.shaderSampledImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageBufferArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageExtendedFormats = VK_TRUE;
                    s->features.shaderUniformBufferArrayDynamicIndexing = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthBiasClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.drawIndirectFirstInstance == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fragmentStoresAndAtomics == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fullDrawIndexUint32 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.imageCubeArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.independentBlend == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.occlusionQueryPrecise == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.sampleRateShading == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.samplerAnisotropy == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderSampledImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageExtendedFormats == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* s = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    s->properties.limits.bufferImageGranularity = 4096;
                    s->properties.limits.maxColorAttachments = 7;
                    s->properties.limits.maxComputeWorkGroupInvocations = 256;
                    s->properties.limits.maxComputeWorkGroupSize[0] = 256;
                    s->properties.limits.maxComputeWorkGroupSize[1] = 256;
                    s->properties.limits.maxComputeWorkGroupSize[2] = 64;
                    s->properties.limits.maxDescriptorSetSampledImages = 1800;
                    s->properties.limits.maxDescriptorSetSamplers = 576;
                    s->properties.limits.maxDescriptorSetStorageBuffers = 96;
                    s->properties.limits.maxDescriptorSetStorageImages = 144;
                    s->properties.limits.maxDescriptorSetUniformBuffers = 90;
                    s->properties.limits.maxFragmentCombinedOutputResources = 16;
                    s->properties.limits.maxImageArrayLayers = 2048;
                    s->properties.limits.maxImageDimension1D = 8192;
                    s->properties.limits.maxImageDimension2D = 8192;
                    s->properties.limits.maxImageDimensionCube = 8192;
                    s->properties.limits.maxPerStageDescriptorSampledImages = 200;
                    s->properties.limits.maxPerStageDescriptorSamplers = 64;
                    s->properties.limits.maxPerStageDescriptorStorageBuffers = 30;
                    s->properties.limits.maxPerStageDescriptorStorageImages = 16;
                    s->properties.limits.maxPerStageDescriptorUniformBuffers = 15;
                    s->properties.limits.maxPerStageResources = 200;
                    s->properties.limits.maxSamplerLodBias = 14;
                    s->properties.limits.maxUniformBufferRange = 65536;
                    s->properties.limits.mipmapPrecisionBits = 6;
                    s->properties.limits.standardSampleLocations = VK_TRUE;
                    s->properties.limits.subTexelPrecisionBits = 8;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* prettify_VkPhysicalDeviceProperties2KHR = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity <= 4096); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity <= 4096), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.bufferImageGranularity <= 4096");
                    ret = ret && ((4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0); VP_DEBUG_COND_MSG(!((4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0), "Unsupported properties condition: (4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxColorAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupInvocations >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupInvocations >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupInvocations >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[0] >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[0] >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[0] >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[1] >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[1] >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[1] >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[2] >= 64); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[2] >= 64), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[2] >= 64");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSampledImages >= 1800); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSampledImages >= 1800), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetSampledImages >= 1800");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSamplers >= 576); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSamplers >= 576), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetSamplers >= 576");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 96); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 96), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetStorageBuffers >= 96");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageImages >= 144); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageImages >= 144), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetStorageImages >= 144");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 90); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 90), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetUniformBuffers >= 90");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentCombinedOutputResources >= 16); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentCombinedOutputResources >= 16), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFragmentCombinedOutputResources >= 16");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageArrayLayers >= 2048); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageArrayLayers >= 2048), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageArrayLayers >= 2048");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension1D >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension1D >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimension1D >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension2D >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension2D >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimension2D >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimensionCube >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimensionCube >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimensionCube >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSampledImages >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSampledImages >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorSampledImages >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSamplers >= 64); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSamplers >= 64), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorSamplers >= 64");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 30); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 30), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorStorageBuffers >= 30");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageImages >= 16); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageImages >= 16), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorStorageImages >= 16");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 15); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 15), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorUniformBuffers >= 15");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageResources >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageResources >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageResources >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxSamplerLodBias >= 14); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxSamplerLodBias >= 14), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxSamplerLodBias >= 14");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxUniformBufferRange >= 65536); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxUniformBufferRange >= 65536), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxUniformBufferRange >= 65536");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.mipmapPrecisionBits >= 6); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.mipmapPrecisionBits >= 6), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.mipmapPrecisionBits >= 6");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.standardSampleLocations >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.standardSampleLocations >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.standardSampleLocations >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subTexelPrecisionBits >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subTexelPrecisionBits >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.subTexelPrecisionBits >= 8");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements_roadmap2022
namespace vulkan11requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->samplerYcbcrConversion = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::samplerYcbcrConversion == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* s = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    s->subgroupSize = 4;
                    s->subgroupSupportedOperations |= (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT);
                    s->subgroupSupportedStages |= (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT);
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* prettify_VkPhysicalDeviceVulkan11Properties = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSize >= 4");
                    ret = ret && ((prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0); VP_DEBUG_COND_MSG(!((prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0), "Unsupported properties condition: (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0");
                    ret = ret && (vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedOperations, (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT))); VP_DEBUG_COND_MSG(!(vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedOperations, (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT))), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations contains (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT)");
                    ret = ret && (vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedStages, (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT))); VP_DEBUG_COND_MSG(!(vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedStages, (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT))), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSupportedStages contains (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT)");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements_roadmap2022
namespace vulkan12requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->descriptorBindingPartiallyBound = VK_TRUE;
                    s->descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUniformTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUpdateUnusedWhilePending = VK_TRUE;
                    s->descriptorBindingVariableDescriptorCount = VK_TRUE;
                    s->descriptorIndexing = VK_TRUE;
                    s->runtimeDescriptorArray = VK_TRUE;
                    s->scalarBlockLayout = VK_TRUE;
                    s->shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderUniformBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayNonUniformIndexing = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingPartiallyBound == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingSampledImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUpdateUnusedWhilePending == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingVariableDescriptorCount == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::runtimeDescriptorArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::scalarBlockLayout == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSampledImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->maxDescriptorSetUpdateAfterBindInputAttachments = 7;
                    s->maxDescriptorSetUpdateAfterBindSampledImages = 500000;
                    s->maxDescriptorSetUpdateAfterBindSamplers = 500000;
                    s->maxDescriptorSetUpdateAfterBindStorageBuffers = 500000;
                    s->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 4;
                    s->maxDescriptorSetUpdateAfterBindStorageImages = 500000;
                    s->maxDescriptorSetUpdateAfterBindUniformBuffers = 72;
                    s->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 8;
                    s->maxPerStageDescriptorUpdateAfterBindInputAttachments = 7;
                    s->maxPerStageDescriptorUpdateAfterBindSampledImages = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindSamplers = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindStorageBuffers = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindStorageImages = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindUniformBuffers = 12;
                    s->maxPerStageUpdateAfterBindResources = 500000;
                    s->shaderSignedZeroInfNanPreserveFloat16 = VK_TRUE;
                    s->shaderSignedZeroInfNanPreserveFloat32 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindInputAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindInputAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindInputAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSampledImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSampledImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindSampledImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSamplers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSamplers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindSamplers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffers >= 72); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffers >= 72), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindUniformBuffers >= 72");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSamplers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSamplers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindSamplers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageUpdateAfterBindResources >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageUpdateAfterBindResources >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageUpdateAfterBindResources >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements_roadmap2022
namespace vulkan13requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* s = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    s->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* prettify_VkPhysicalDeviceVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan13requirements_roadmap2022
namespace vulkanextensionrequirements_roadmap2022_promoted_vulkan14 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: {
                    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* s = static_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(static_cast<void*>(p));
                    s->globalPriorityQuery = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: {
                    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR = static_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR->globalPriorityQuery == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR->globalPriorityQuery == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR::globalPriorityQuery == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR physicalDeviceGlobalPriorityQueryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceGlobalPriorityQueryFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2022_promoted_vulkan14
} // namespace blocks
} // namespace VP_KHR_ROADMAP_2022
#endif // VP_KHR_roadmap_2022

#ifdef VP_KHR_roadmap_2024
namespace VP_KHR_ROADMAP_2024 {

static const VkStructureType featureStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR,
};

static const VkStructureType propertyStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES,
};

namespace blocks {
namespace vulkan10requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.multiDrawIndirect = VK_TRUE;
                    s->features.shaderImageGatherExtended = VK_TRUE;
                    s->features.shaderInt16 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.multiDrawIndirect == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.multiDrawIndirect == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.multiDrawIndirect == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderImageGatherExtended == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderImageGatherExtended == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderImageGatherExtended == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderInt16 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderInt16 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderInt16 == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* s = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    s->properties.limits.maxBoundDescriptorSets = 7;
                    s->properties.limits.maxColorAttachments = 8;
                    s->properties.limits.timestampComputeAndGraphics = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* prettify_VkPhysicalDeviceProperties2KHR = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxBoundDescriptorSets >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxBoundDescriptorSets >= 7), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxBoundDescriptorSets >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxColorAttachments >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.timestampComputeAndGraphics >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.timestampComputeAndGraphics >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.timestampComputeAndGraphics >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements_roadmap2024
namespace vulkan11requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->shaderDrawParameters = VK_TRUE;
                    s->storageBuffer16BitAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->shaderDrawParameters == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->shaderDrawParameters == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::shaderDrawParameters == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->storageBuffer16BitAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->storageBuffer16BitAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::storageBuffer16BitAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements_roadmap2024
namespace vulkan12requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->shaderFloat16 = VK_TRUE;
                    s->shaderInt8 = VK_TRUE;
                    s->storageBuffer8BitAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderFloat16 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderFloat16 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderFloat16 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderInt8 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderInt8 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderInt8 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->storageBuffer8BitAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->storageBuffer8BitAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::storageBuffer8BitAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->shaderRoundingModeRTEFloat16 = VK_TRUE;
                    s->shaderRoundingModeRTEFloat32 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat16 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat16 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat16 >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat32 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat32 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat32 >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements_roadmap2024
namespace vulkanextensionrequirements_roadmap2024 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LOAD_STORE_OP_NONE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAP_MEMORY_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_MAXIMAL_RECONVERGENCE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_QUAD_CONTROL_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                    VkPhysicalDeviceShaderQuadControlFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderQuadControl = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderMaximalReconvergence = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderSubgroupUniformControlFlow = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                    VkPhysicalDeviceShaderQuadControlFeaturesKHR* prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR = static_cast<VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR->shaderQuadControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR->shaderQuadControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderQuadControlFeaturesKHR::shaderQuadControl == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR = static_cast<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR->shaderMaximalReconvergence == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR->shaderMaximalReconvergence == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR::shaderMaximalReconvergence == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = static_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR->shaderSubgroupUniformControlFlow == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR->shaderSubgroupUniformControlFlow == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR::shaderSubgroupUniformControlFlow == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceShaderQuadControlFeaturesKHR physicalDeviceShaderQuadControlFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR, nullptr };
        VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR physicalDeviceShaderMaximalReconvergenceFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR, &physicalDeviceShaderQuadControlFeaturesKHR };
        VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR, &physicalDeviceShaderMaximalReconvergenceFeaturesKHR };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024
namespace vulkanextensionrequirements_roadmap2024_promoted_vulkan14 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_DYNAMIC_RENDERING_LOCAL_READ_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAINTENANCE_5_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_EXPECT_ASSUME_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_FLOAT_CONTROLS_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_SUBGROUP_ROTATE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderSubgroupRotate = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR: {
                    VkPhysicalDeviceShaderFloatControls2FeaturesKHR* s = static_cast<VkPhysicalDeviceShaderFloatControls2FeaturesKHR*>(static_cast<void*>(p));
                    s->shaderFloatControls2 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR: {
                    VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderExpectAssumeFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderExpectAssume = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR: {
                    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* s = static_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(static_cast<void*>(p));
                    s->vertexAttributeInstanceRateDivisor = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR: {
                    VkPhysicalDeviceIndexTypeUint8FeaturesKHR* s = static_cast<VkPhysicalDeviceIndexTypeUint8FeaturesKHR*>(static_cast<void*>(p));
                    s->indexTypeUint8 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR: {
                    VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* s = static_cast<VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR*>(static_cast<void*>(p));
                    s->dynamicRenderingLocalRead = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance5FeaturesKHR* s = static_cast<VkPhysicalDeviceMaintenance5FeaturesKHR*>(static_cast<void*>(p));
                    s->maintenance5 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* prettify_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR = static_cast<VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR->shaderSubgroupRotate == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR->shaderSubgroupRotate == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR::shaderSubgroupRotate == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR: {
                    VkPhysicalDeviceShaderFloatControls2FeaturesKHR* prettify_VkPhysicalDeviceShaderFloatControls2FeaturesKHR = static_cast<VkPhysicalDeviceShaderFloatControls2FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderFloatControls2FeaturesKHR->shaderFloatControls2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderFloatControls2FeaturesKHR->shaderFloatControls2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderFloatControls2FeaturesKHR::shaderFloatControls2 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR: {
                    VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* prettify_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR = static_cast<VkPhysicalDeviceShaderExpectAssumeFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR->shaderExpectAssume == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR->shaderExpectAssume == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderExpectAssumeFeaturesKHR::shaderExpectAssume == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR: {
                    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* prettify_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR = static_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR->vertexAttributeInstanceRateDivisor == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR->vertexAttributeInstanceRateDivisor == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR::vertexAttributeInstanceRateDivisor == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR: {
                    VkPhysicalDeviceIndexTypeUint8FeaturesKHR* prettify_VkPhysicalDeviceIndexTypeUint8FeaturesKHR = static_cast<VkPhysicalDeviceIndexTypeUint8FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceIndexTypeUint8FeaturesKHR->indexTypeUint8 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceIndexTypeUint8FeaturesKHR->indexTypeUint8 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceIndexTypeUint8FeaturesKHR::indexTypeUint8 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR: {
                    VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* prettify_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR = static_cast<VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR->dynamicRenderingLocalRead == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR->dynamicRenderingLocalRead == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR::dynamicRenderingLocalRead == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance5FeaturesKHR* prettify_VkPhysicalDeviceMaintenance5FeaturesKHR = static_cast<VkPhysicalDeviceMaintenance5FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance5FeaturesKHR->maintenance5 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance5FeaturesKHR->maintenance5 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceMaintenance5FeaturesKHR::maintenance5 == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR physicalDeviceShaderSubgroupRotateFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR, nullptr };
        VkPhysicalDeviceShaderFloatControls2FeaturesKHR physicalDeviceShaderFloatControls2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR, &physicalDeviceShaderSubgroupRotateFeaturesKHR };
        VkPhysicalDeviceShaderExpectAssumeFeaturesKHR physicalDeviceShaderExpectAssumeFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR, &physicalDeviceShaderFloatControls2FeaturesKHR };
        VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR physicalDeviceVertexAttributeDivisorFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR, &physicalDeviceShaderExpectAssumeFeaturesKHR };
        VkPhysicalDeviceIndexTypeUint8FeaturesKHR physicalDeviceIndexTypeUint8FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR, &physicalDeviceVertexAttributeDivisorFeaturesKHR };
        VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR physicalDeviceDynamicRenderingLocalReadFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR, &physicalDeviceIndexTypeUint8FeaturesKHR };
        VkPhysicalDeviceMaintenance5FeaturesKHR physicalDeviceMaintenance5FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR, &physicalDeviceDynamicRenderingLocalReadFeaturesKHR };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance5FeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_promoted_vulkan14
namespace vulkanextensionrequirements_roadmap2024_line0 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->rectangularLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->rectangularLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->rectangularLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::rectangularLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line0
namespace vulkanextensionrequirements_roadmap2024_line1 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->bresenhamLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->bresenhamLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->bresenhamLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::bresenhamLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line1
namespace vulkanextensionrequirements_roadmap2024_line2 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->smoothLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->smoothLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->smoothLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::smoothLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line2
namespace vulkanextensionrequirements_roadmap2024_line3 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->stippledRectangularLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledRectangularLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledRectangularLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::stippledRectangularLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line3
namespace vulkanextensionrequirements_roadmap2024_line4 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->stippledBresenhamLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledBresenhamLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledBresenhamLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::stippledBresenhamLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line4
namespace vulkanextensionrequirements_roadmap2024_line5 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* s = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    s->stippledSmoothLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: {
                    VkPhysicalDeviceLineRasterizationFeaturesKHR* prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR = static_cast<VkPhysicalDeviceLineRasterizationFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledSmoothLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceLineRasterizationFeaturesKHR->stippledSmoothLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceLineRasterizationFeaturesKHR::stippledSmoothLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceLineRasterizationFeaturesKHR physicalDeviceLineRasterizationFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceLineRasterizationFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Properties));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024_line5
} // namespace blocks
} // namespace VP_KHR_ROADMAP_2024
#endif // VP_KHR_roadmap_2024

#ifdef VP_KHR_roadmap_2026
namespace VP_KHR_ROADMAP_2026 {

static const VkStructureType featureStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR,
};

static const VkStructureType propertyStructTypes[] = {
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR,
};

namespace blocks {
namespace vulkan10requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.robustBufferAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.robustBufferAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.robustBufferAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements
namespace vulkan11requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->multiview = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->multiview == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::multiview == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* s = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    s->maxMultiviewInstanceIndex = 134217727;
                    s->maxMultiviewViewCount = 6;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* prettify_VkPhysicalDeviceVulkan11Properties = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewInstanceIndex >= 134217727); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewInstanceIndex >= 134217727), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::maxMultiviewInstanceIndex >= 134217727");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewViewCount >= 6); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->maxMultiviewViewCount >= 6), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::maxMultiviewViewCount >= 6");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements
namespace vulkan12requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->hostQueryReset = VK_TRUE;
                    s->imagelessFramebuffer = VK_TRUE;
                    s->separateDepthStencilLayouts = VK_TRUE;
                    s->shaderSubgroupExtendedTypes = VK_TRUE;
                    s->subgroupBroadcastDynamicId = VK_TRUE;
                    s->timelineSemaphore = VK_TRUE;
                    s->uniformBufferStandardLayout = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->hostQueryReset == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::hostQueryReset == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->imagelessFramebuffer == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::imagelessFramebuffer == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->separateDepthStencilLayouts == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::separateDepthStencilLayouts == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSubgroupExtendedTypes == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSubgroupExtendedTypes == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->subgroupBroadcastDynamicId == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::subgroupBroadcastDynamicId == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->timelineSemaphore == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::timelineSemaphore == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->uniformBufferStandardLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::uniformBufferStandardLayout == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->maxTimelineSemaphoreValueDifference = 2147483647;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxTimelineSemaphoreValueDifference >= 2147483647); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxTimelineSemaphoreValueDifference >= 2147483647), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxTimelineSemaphoreValueDifference >= 2147483647");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements
namespace vulkan13requirements {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->bufferDeviceAddress = VK_TRUE;
                    s->vulkanMemoryModel = VK_TRUE;
                    s->vulkanMemoryModelDeviceScope = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* s = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    s->computeFullSubgroups = VK_TRUE;
                    s->dynamicRendering = VK_TRUE;
                    s->inlineUniformBlock = VK_TRUE;
                    s->maintenance4 = VK_TRUE;
                    s->pipelineCreationCacheControl = VK_TRUE;
                    s->privateData = VK_TRUE;
                    s->robustImageAccess = VK_TRUE;
                    s->shaderDemoteToHelperInvocation = VK_TRUE;
                    s->shaderIntegerDotProduct = VK_TRUE;
                    s->shaderTerminateInvocation = VK_TRUE;
                    s->shaderZeroInitializeWorkgroupMemory = VK_TRUE;
                    s->subgroupSizeControl = VK_TRUE;
                    s->synchronization2 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->bufferDeviceAddress == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::bufferDeviceAddress == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModel == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModel == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->vulkanMemoryModelDeviceScope == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::vulkanMemoryModelDeviceScope == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* prettify_VkPhysicalDeviceVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->computeFullSubgroups == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::computeFullSubgroups == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->dynamicRendering == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::dynamicRendering == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->inlineUniformBlock == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::inlineUniformBlock == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->maintenance4 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::maintenance4 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->pipelineCreationCacheControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::pipelineCreationCacheControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->privateData == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::privateData == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->robustImageAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::robustImageAccess == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderDemoteToHelperInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderDemoteToHelperInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderIntegerDotProduct == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderIntegerDotProduct == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderTerminateInvocation == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderTerminateInvocation == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->shaderZeroInitializeWorkgroupMemory == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::shaderZeroInitializeWorkgroupMemory == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->subgroupSizeControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::subgroupSizeControl == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->synchronization2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::synchronization2 == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                    VkPhysicalDeviceVulkan13Properties* s = static_cast<VkPhysicalDeviceVulkan13Properties*>(static_cast<void*>(p));
                    s->maxBufferSize = 1073741824;
                    s->maxDescriptorSetInlineUniformBlocks = 4;
                    s->maxDescriptorSetUpdateAfterBindInlineUniformBlocks = 4;
                    s->maxInlineUniformBlockSize = 256;
                    s->maxInlineUniformTotalSize = 256;
                    s->maxPerStageDescriptorInlineUniformBlocks = 4;
                    s->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = 4;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                    VkPhysicalDeviceVulkan13Properties* prettify_VkPhysicalDeviceVulkan13Properties = static_cast<VkPhysicalDeviceVulkan13Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxBufferSize >= 1073741824); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxBufferSize >= 1073741824), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxBufferSize >= 1073741824");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxDescriptorSetInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxDescriptorSetUpdateAfterBindInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformBlockSize >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformBlockSize >= 256), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxInlineUniformBlockSize >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformTotalSize >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxInlineUniformTotalSize >= 256), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxInlineUniformTotalSize >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxPerStageDescriptorInlineUniformBlocks >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Properties->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan13Properties::maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks >= 4");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, &physicalDeviceVulkan12Features };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan13requirements
namespace vulkan10requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.depthBiasClamp = VK_TRUE;
                    s->features.depthClamp = VK_TRUE;
                    s->features.drawIndirectFirstInstance = VK_TRUE;
                    s->features.fragmentStoresAndAtomics = VK_TRUE;
                    s->features.fullDrawIndexUint32 = VK_TRUE;
                    s->features.imageCubeArray = VK_TRUE;
                    s->features.independentBlend = VK_TRUE;
                    s->features.occlusionQueryPrecise = VK_TRUE;
                    s->features.sampleRateShading = VK_TRUE;
                    s->features.samplerAnisotropy = VK_TRUE;
                    s->features.shaderSampledImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageBufferArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageArrayDynamicIndexing = VK_TRUE;
                    s->features.shaderStorageImageExtendedFormats = VK_TRUE;
                    s->features.shaderUniformBufferArrayDynamicIndexing = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthBiasClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthBiasClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.depthClamp == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.depthClamp == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.drawIndirectFirstInstance == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.drawIndirectFirstInstance == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fragmentStoresAndAtomics == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fragmentStoresAndAtomics == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.fullDrawIndexUint32 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.fullDrawIndexUint32 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.imageCubeArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.imageCubeArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.independentBlend == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.independentBlend == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.occlusionQueryPrecise == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.occlusionQueryPrecise == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.sampleRateShading == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.sampleRateShading == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.samplerAnisotropy == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.samplerAnisotropy == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderSampledImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderSampledImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderStorageImageExtendedFormats == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderStorageImageExtendedFormats == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderUniformBufferArrayDynamicIndexing == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* s = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    s->properties.limits.bufferImageGranularity = 4096;
                    s->properties.limits.maxColorAttachments = 7;
                    s->properties.limits.maxComputeWorkGroupInvocations = 256;
                    s->properties.limits.maxComputeWorkGroupSize[0] = 256;
                    s->properties.limits.maxComputeWorkGroupSize[1] = 256;
                    s->properties.limits.maxComputeWorkGroupSize[2] = 64;
                    s->properties.limits.maxDescriptorSetSampledImages = 1800;
                    s->properties.limits.maxDescriptorSetSamplers = 576;
                    s->properties.limits.maxDescriptorSetStorageBuffers = 96;
                    s->properties.limits.maxDescriptorSetStorageImages = 144;
                    s->properties.limits.maxDescriptorSetUniformBuffers = 90;
                    s->properties.limits.maxFragmentCombinedOutputResources = 16;
                    s->properties.limits.maxImageArrayLayers = 2048;
                    s->properties.limits.maxImageDimension1D = 8192;
                    s->properties.limits.maxImageDimension2D = 8192;
                    s->properties.limits.maxImageDimensionCube = 8192;
                    s->properties.limits.maxPerStageDescriptorSampledImages = 200;
                    s->properties.limits.maxPerStageDescriptorSamplers = 64;
                    s->properties.limits.maxPerStageDescriptorStorageBuffers = 30;
                    s->properties.limits.maxPerStageDescriptorStorageImages = 16;
                    s->properties.limits.maxPerStageDescriptorUniformBuffers = 15;
                    s->properties.limits.maxPerStageResources = 200;
                    s->properties.limits.maxSamplerLodBias = 14;
                    s->properties.limits.maxUniformBufferRange = 65536;
                    s->properties.limits.mipmapPrecisionBits = 6;
                    s->properties.limits.standardSampleLocations = VK_TRUE;
                    s->properties.limits.subTexelPrecisionBits = 8;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* prettify_VkPhysicalDeviceProperties2KHR = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity <= 4096); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity <= 4096), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.bufferImageGranularity <= 4096");
                    ret = ret && ((4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0); VP_DEBUG_COND_MSG(!((4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0), "Unsupported properties condition: (4096 % prettify_VkPhysicalDeviceProperties2KHR->properties.limits.bufferImageGranularity) == 0");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxColorAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupInvocations >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupInvocations >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupInvocations >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[0] >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[0] >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[0] >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[1] >= 256); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[1] >= 256), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[1] >= 256");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[2] >= 64); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeWorkGroupSize[2] >= 64), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeWorkGroupSize[2] >= 64");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSampledImages >= 1800); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSampledImages >= 1800), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetSampledImages >= 1800");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSamplers >= 576); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetSamplers >= 576), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetSamplers >= 576");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 96); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 96), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetStorageBuffers >= 96");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageImages >= 144); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageImages >= 144), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetStorageImages >= 144");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 90); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 90), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetUniformBuffers >= 90");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentCombinedOutputResources >= 16); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentCombinedOutputResources >= 16), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFragmentCombinedOutputResources >= 16");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageArrayLayers >= 2048); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageArrayLayers >= 2048), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageArrayLayers >= 2048");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension1D >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension1D >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimension1D >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension2D >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimension2D >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimension2D >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimensionCube >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxImageDimensionCube >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxImageDimensionCube >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSampledImages >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSampledImages >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorSampledImages >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSamplers >= 64); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorSamplers >= 64), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorSamplers >= 64");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 30); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 30), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorStorageBuffers >= 30");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageImages >= 16); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageImages >= 16), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorStorageImages >= 16");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 15); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 15), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorUniformBuffers >= 15");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageResources >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageResources >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageResources >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxSamplerLodBias >= 14); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxSamplerLodBias >= 14), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxSamplerLodBias >= 14");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxUniformBufferRange >= 65536); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxUniformBufferRange >= 65536), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxUniformBufferRange >= 65536");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.mipmapPrecisionBits >= 6); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.mipmapPrecisionBits >= 6), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.mipmapPrecisionBits >= 6");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.standardSampleLocations >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.standardSampleLocations >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.standardSampleLocations >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subTexelPrecisionBits >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subTexelPrecisionBits >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.subTexelPrecisionBits >= 8");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements_roadmap2022
namespace vulkan11requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->samplerYcbcrConversion = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->samplerYcbcrConversion == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::samplerYcbcrConversion == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* s = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    s->subgroupSize = 4;
                    s->subgroupSupportedOperations |= (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT);
                    s->subgroupSupportedStages |= (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT);
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                    VkPhysicalDeviceVulkan11Properties* prettify_VkPhysicalDeviceVulkan11Properties = static_cast<VkPhysicalDeviceVulkan11Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSize >= 4");
                    ret = ret && ((prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0); VP_DEBUG_COND_MSG(!((prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0), "Unsupported properties condition: (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize & (prettify_VkPhysicalDeviceVulkan11Properties->subgroupSize - 1)) == 0");
                    ret = ret && (vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedOperations, (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT))); VP_DEBUG_COND_MSG(!(vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedOperations, (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT))), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations contains (VK_SUBGROUP_FEATURE_BASIC_BIT | VK_SUBGROUP_FEATURE_VOTE_BIT | VK_SUBGROUP_FEATURE_ARITHMETIC_BIT | VK_SUBGROUP_FEATURE_BALLOT_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_BIT | VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT | VK_SUBGROUP_FEATURE_QUAD_BIT)");
                    ret = ret && (vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedStages, (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT))); VP_DEBUG_COND_MSG(!(vpCheckFlags(prettify_VkPhysicalDeviceVulkan11Properties->subgroupSupportedStages, (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT))), "Unsupported properties condition: VkPhysicalDeviceVulkan11Properties::subgroupSupportedStages contains (VK_SHADER_STAGE_COMPUTE_BIT | VK_SHADER_STAGE_FRAGMENT_BIT)");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements_roadmap2022
namespace vulkan12requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->descriptorBindingPartiallyBound = VK_TRUE;
                    s->descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageImageUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingStorageTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUniformTexelBufferUpdateAfterBind = VK_TRUE;
                    s->descriptorBindingUpdateUnusedWhilePending = VK_TRUE;
                    s->descriptorBindingVariableDescriptorCount = VK_TRUE;
                    s->descriptorIndexing = VK_TRUE;
                    s->runtimeDescriptorArray = VK_TRUE;
                    s->scalarBlockLayout = VK_TRUE;
                    s->shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageImageArrayNonUniformIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderStorageTexelBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderUniformBufferArrayNonUniformIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayDynamicIndexing = VK_TRUE;
                    s->shaderUniformTexelBufferArrayNonUniformIndexing = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingPartiallyBound == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingPartiallyBound == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingSampledImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageImageUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingUpdateUnusedWhilePending == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingUpdateUnusedWhilePending == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorBindingVariableDescriptorCount == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorBindingVariableDescriptorCount == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->descriptorIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::descriptorIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->runtimeDescriptorArray == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::runtimeDescriptorArray == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->scalarBlockLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::scalarBlockLayout == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderSampledImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderSampledImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageImageArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageImageArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformBufferArrayNonUniformIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->maxDescriptorSetUpdateAfterBindInputAttachments = 7;
                    s->maxDescriptorSetUpdateAfterBindSampledImages = 500000;
                    s->maxDescriptorSetUpdateAfterBindSamplers = 500000;
                    s->maxDescriptorSetUpdateAfterBindStorageBuffers = 500000;
                    s->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 4;
                    s->maxDescriptorSetUpdateAfterBindStorageImages = 500000;
                    s->maxDescriptorSetUpdateAfterBindUniformBuffers = 72;
                    s->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 8;
                    s->maxPerStageDescriptorUpdateAfterBindInputAttachments = 7;
                    s->maxPerStageDescriptorUpdateAfterBindSampledImages = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindSamplers = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindStorageBuffers = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindStorageImages = 500000;
                    s->maxPerStageDescriptorUpdateAfterBindUniformBuffers = 12;
                    s->maxPerStageUpdateAfterBindResources = 500000;
                    s->shaderSignedZeroInfNanPreserveFloat16 = VK_TRUE;
                    s->shaderSignedZeroInfNanPreserveFloat32 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindInputAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindInputAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindInputAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSampledImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSampledImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindSampledImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSamplers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindSamplers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindSamplers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageBuffers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageBuffersDynamic >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindStorageImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindStorageImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffers >= 72); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffers >= 72), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindUniformBuffers >= 72");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxDescriptorSetUpdateAfterBindUniformBuffersDynamic >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindInputAttachments >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindSampledImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSamplers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindSamplers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindSamplers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindStorageBuffers >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindStorageImages >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageDescriptorUpdateAfterBindUniformBuffers >= 12");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageUpdateAfterBindResources >= 500000); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->maxPerStageUpdateAfterBindResources >= 500000), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::maxPerStageUpdateAfterBindResources >= 500000");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat16 >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat32 >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements_roadmap2022
namespace vulkan13requirements_roadmap2022 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* s = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    s->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                    VkPhysicalDeviceVulkan13Features* prettify_VkPhysicalDeviceVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan13Features->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan13Features::descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan13Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan13requirements_roadmap2022
namespace vulkan10requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* s = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    s->features.multiDrawIndirect = VK_TRUE;
                    s->features.shaderImageGatherExtended = VK_TRUE;
                    s->features.shaderInt16 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR: {
                    VkPhysicalDeviceFeatures2KHR* prettify_VkPhysicalDeviceFeatures2KHR = static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.multiDrawIndirect == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.multiDrawIndirect == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.multiDrawIndirect == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderImageGatherExtended == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderImageGatherExtended == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderImageGatherExtended == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceFeatures2KHR->features.shaderInt16 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFeatures2KHR->features.shaderInt16 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFeatures2KHR::features.shaderInt16 == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* s = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    s->properties.limits.maxBoundDescriptorSets = 7;
                    s->properties.limits.maxColorAttachments = 8;
                    s->properties.limits.timestampComputeAndGraphics = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* prettify_VkPhysicalDeviceProperties2KHR = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxBoundDescriptorSets >= 7); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxBoundDescriptorSets >= 7), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxBoundDescriptorSets >= 7");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxColorAttachments >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxColorAttachments >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.timestampComputeAndGraphics >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.timestampComputeAndGraphics >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.timestampComputeAndGraphics >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements_roadmap2024
namespace vulkan11requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* s = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    s->shaderDrawParameters = VK_TRUE;
                    s->storageBuffer16BitAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                    VkPhysicalDeviceVulkan11Features* prettify_VkPhysicalDeviceVulkan11Features = static_cast<VkPhysicalDeviceVulkan11Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->shaderDrawParameters == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->shaderDrawParameters == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::shaderDrawParameters == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan11Features->storageBuffer16BitAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan11Features->storageBuffer16BitAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan11Features::storageBuffer16BitAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan11Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan11requirements_roadmap2024
namespace vulkan12requirements_roadmap2024 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* s = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    s->shaderFloat16 = VK_TRUE;
                    s->shaderInt8 = VK_TRUE;
                    s->storageBuffer8BitAccess = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                    VkPhysicalDeviceVulkan12Features* prettify_VkPhysicalDeviceVulkan12Features = static_cast<VkPhysicalDeviceVulkan12Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderFloat16 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderFloat16 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderFloat16 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->shaderInt8 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->shaderInt8 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::shaderInt8 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Features->storageBuffer8BitAccess == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Features->storageBuffer8BitAccess == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan12Features::storageBuffer8BitAccess == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* s = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    s->shaderRoundingModeRTEFloat16 = VK_TRUE;
                    s->shaderRoundingModeRTEFloat32 = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                    VkPhysicalDeviceVulkan12Properties* prettify_VkPhysicalDeviceVulkan12Properties = static_cast<VkPhysicalDeviceVulkan12Properties*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat16 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat16 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat16 >= VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat32 >= VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan12Properties->shaderRoundingModeRTEFloat32 >= VK_TRUE), "Unsupported properties condition: VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat32 >= VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan12Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan12requirements_roadmap2024
namespace vulkanextensionrequirements_roadmap2024 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LOAD_STORE_OP_NONE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAP_MEMORY_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_MAXIMAL_RECONVERGENCE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_QUAD_CONTROL_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                    VkPhysicalDeviceShaderQuadControlFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderQuadControl = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderMaximalReconvergence = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderSubgroupUniformControlFlow = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                    VkPhysicalDeviceShaderQuadControlFeaturesKHR* prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR = static_cast<VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR->shaderQuadControl == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderQuadControlFeaturesKHR->shaderQuadControl == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderQuadControlFeaturesKHR::shaderQuadControl == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR = static_cast<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR->shaderMaximalReconvergence == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR->shaderMaximalReconvergence == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR::shaderMaximalReconvergence == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = static_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR->shaderSubgroupUniformControlFlow == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR->shaderSubgroupUniformControlFlow == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR::shaderSubgroupUniformControlFlow == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceShaderQuadControlFeaturesKHR physicalDeviceShaderQuadControlFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR, nullptr };
        VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR physicalDeviceShaderMaximalReconvergenceFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR, &physicalDeviceShaderQuadControlFeaturesKHR };
        VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR, &physicalDeviceShaderMaximalReconvergenceFeaturesKHR };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2024
namespace vulkan10requirements_roadmap2026 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* s = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    s->properties.limits.maxComputeSharedMemorySize = 32768;
                    s->properties.limits.maxDescriptorSetInputAttachments = 8;
                    s->properties.limits.maxDescriptorSetStorageBuffers = 1800;
                    s->properties.limits.maxDescriptorSetUniformBuffers = 1800;
                    s->properties.limits.maxFragmentInputComponents = 112;
                    s->properties.limits.maxFragmentOutputAttachments = 8;
                    s->properties.limits.maxFramebufferHeight = 8192;
                    s->properties.limits.maxFramebufferWidth = 8192;
                    s->properties.limits.maxGeometryOutputComponents = 128;
                    s->properties.limits.maxPerStageDescriptorInputAttachments = 8;
                    s->properties.limits.maxPerStageDescriptorStorageBuffers = 200;
                    s->properties.limits.maxPerStageDescriptorUniformBuffers = 200;
                    s->properties.limits.maxTessellationControlPerVertexInputComponents = 128;
                    s->properties.limits.maxTessellationControlPerVertexOutputComponents = 128;
                    s->properties.limits.maxTessellationControlTotalOutputComponents = 4096;
                    s->properties.limits.maxTessellationEvaluationInputComponents = 128;
                    s->properties.limits.maxTessellationEvaluationOutputComponents = 128;
                    s->properties.limits.maxVertexOutputComponents = 124;
                    s->properties.limits.maxViewportDimensions[0] = 8192;
                    s->properties.limits.maxViewportDimensions[1] = 8192;
                    s->properties.limits.subPixelPrecisionBits = 8;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR: {
                    VkPhysicalDeviceProperties2KHR* prettify_VkPhysicalDeviceProperties2KHR = static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeSharedMemorySize >= 32768); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxComputeSharedMemorySize >= 32768), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxComputeSharedMemorySize >= 32768");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetInputAttachments >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetInputAttachments >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetInputAttachments >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 1800); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetStorageBuffers >= 1800), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetStorageBuffers >= 1800");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 1800); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxDescriptorSetUniformBuffers >= 1800), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxDescriptorSetUniformBuffers >= 1800");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentInputComponents >= 112); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentInputComponents >= 112), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFragmentInputComponents >= 112");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentOutputAttachments >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFragmentOutputAttachments >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFragmentOutputAttachments >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFramebufferHeight >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFramebufferHeight >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFramebufferHeight >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFramebufferWidth >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxFramebufferWidth >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxFramebufferWidth >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxGeometryOutputComponents >= 128); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxGeometryOutputComponents >= 128), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxGeometryOutputComponents >= 128");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorInputAttachments >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorInputAttachments >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorInputAttachments >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorStorageBuffers >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorStorageBuffers >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 200); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxPerStageDescriptorUniformBuffers >= 200), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxPerStageDescriptorUniformBuffers >= 200");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlPerVertexInputComponents >= 128); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlPerVertexInputComponents >= 128), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxTessellationControlPerVertexInputComponents >= 128");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlPerVertexOutputComponents >= 128); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlPerVertexOutputComponents >= 128), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxTessellationControlPerVertexOutputComponents >= 128");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlTotalOutputComponents >= 4096); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationControlTotalOutputComponents >= 4096), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxTessellationControlTotalOutputComponents >= 4096");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationEvaluationInputComponents >= 128); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationEvaluationInputComponents >= 128), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxTessellationEvaluationInputComponents >= 128");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationEvaluationOutputComponents >= 128); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxTessellationEvaluationOutputComponents >= 128), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxTessellationEvaluationOutputComponents >= 128");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxVertexOutputComponents >= 124); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxVertexOutputComponents >= 124), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxVertexOutputComponents >= 124");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxViewportDimensions[0] >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxViewportDimensions[0] >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxViewportDimensions[0] >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxViewportDimensions[1] >= 8192); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.maxViewportDimensions[1] >= 8192), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.maxViewportDimensions[1] >= 8192");
                    ret = ret && (prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subPixelPrecisionBits >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceProperties2KHR->properties.limits.subPixelPrecisionBits >= 8), "Unsupported properties condition: VkPhysicalDeviceProperties2KHR::properties.limits.subPixelPrecisionBits >= 8");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(nullptr));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan10requirements_roadmap2026
namespace vulkan14requirements_roadmap2026 {

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->dynamicRenderingLocalRead = VK_TRUE;
                    s->globalPriorityQuery = VK_TRUE;
                    s->hostImageCopy = VK_TRUE;
                    s->indexTypeUint8 = VK_TRUE;
                    s->maintenance5 = VK_TRUE;
                    s->pushDescriptor = VK_TRUE;
                    s->shaderExpectAssume = VK_TRUE;
                    s->shaderFloatControls2 = VK_TRUE;
                    s->shaderSubgroupRotate = VK_TRUE;
                    s->vertexAttributeInstanceRateDivisor = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->dynamicRenderingLocalRead == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->dynamicRenderingLocalRead == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::dynamicRenderingLocalRead == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->globalPriorityQuery == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->globalPriorityQuery == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::globalPriorityQuery == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->hostImageCopy == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->hostImageCopy == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::hostImageCopy == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->indexTypeUint8 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->indexTypeUint8 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::indexTypeUint8 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->maintenance5 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->maintenance5 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::maintenance5 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->pushDescriptor == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->pushDescriptor == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::pushDescriptor == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->shaderExpectAssume == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->shaderExpectAssume == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::shaderExpectAssume == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->shaderFloatControls2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->shaderFloatControls2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::shaderFloatControls2 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->shaderSubgroupRotate == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->shaderSubgroupRotate == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::shaderSubgroupRotate == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->vertexAttributeInstanceRateDivisor == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->vertexAttributeInstanceRateDivisor == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::vertexAttributeInstanceRateDivisor == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026
namespace vulkan14requirements_roadmap2026_line0 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->rectangularLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->rectangularLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->rectangularLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::rectangularLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line0
namespace vulkan14requirements_roadmap2026_line1 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->bresenhamLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->bresenhamLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->bresenhamLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::bresenhamLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line1
namespace vulkan14requirements_roadmap2026_line2 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->smoothLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->smoothLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->smoothLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::smoothLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line2
namespace vulkan14requirements_roadmap2026_line3 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->stippledRectangularLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->stippledRectangularLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->stippledRectangularLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::stippledRectangularLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line3
namespace vulkan14requirements_roadmap2026_line4 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->stippledBresenhamLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->stippledBresenhamLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->stippledBresenhamLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::stippledBresenhamLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line4
namespace vulkan14requirements_roadmap2026_line5 {

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* s = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    s->stippledSmoothLines = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                    VkPhysicalDeviceVulkan14Features* prettify_VkPhysicalDeviceVulkan14Features = static_cast<VkPhysicalDeviceVulkan14Features*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceVulkan14Features->stippledSmoothLines == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceVulkan14Features->stippledSmoothLines == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceVulkan14Features::stippledSmoothLines == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceVulkan14Features));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkan14requirements_roadmap2026_line5
namespace vulkanextensionrequirements_roadmap2026 {

static const VkExtensionProperties instanceExtensions[] = {
    VkExtensionProperties{ VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SURFACE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SURFACE_MAINTENANCE_1_EXTENSION_NAME, 1 },
};

static const VkExtensionProperties deviceExtensions[] = {
    VkExtensionProperties{ VK_KHR_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_COOPERATIVE_MATRIX_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_COPY_MEMORY_INDIRECT_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_DEPTH_CLAMP_ZERO_ONE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_DYNAMIC_RENDERING_LOCAL_READ_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAINTENANCE_5_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAINTENANCE_7_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAINTENANCE_8_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_MAINTENANCE_9_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PIPELINE_BINARY_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PRESENT_ID_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PRESENT_MODE_FIFO_LATEST_READY_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PRESENT_WAIT_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_ROBUSTNESS_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_CLOCK_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_EXPECT_ASSUME_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_FLOAT_CONTROLS_2_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_SUBGROUP_ROTATE_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SHADER_UNTYPED_POINTERS_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SWAPCHAIN_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_SWAPCHAIN_MAINTENANCE_1_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, 1 },
    VkExtensionProperties{ VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_EXTENSION_NAME, 1 },
};

static const VpFeatureDesc featureDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR: {
                    VkPhysicalDeviceRobustness2FeaturesKHR* s = static_cast<VkPhysicalDeviceRobustness2FeaturesKHR*>(static_cast<void*>(p));
                    s->nullDescriptor = VK_TRUE;
                    s->robustBufferAccess2 = VK_TRUE;
                    s->robustImageAccess2 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR: {
                    VkPhysicalDevicePipelineBinaryFeaturesKHR* s = static_cast<VkPhysicalDevicePipelineBinaryFeaturesKHR*>(static_cast<void*>(p));
                    s->pipelineBinaries = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {
                    VkPhysicalDeviceFragmentShadingRateFeaturesKHR* s = static_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(static_cast<void*>(p));
                    s->pipelineFragmentShadingRate = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {
                    VkPhysicalDeviceShaderClockFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderSubgroupClock = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: {
                    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* s = static_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(static_cast<void*>(p));
                    s->workgroupMemoryExplicitLayout = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR: {
                    VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* s = static_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(static_cast<void*>(p));
                    s->computeDerivativeGroupLinear = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance7FeaturesKHR* s = static_cast<VkPhysicalDeviceMaintenance7FeaturesKHR*>(static_cast<void*>(p));
                    s->maintenance7 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance8FeaturesKHR* s = static_cast<VkPhysicalDeviceMaintenance8FeaturesKHR*>(static_cast<void*>(p));
                    s->maintenance8 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance9FeaturesKHR* s = static_cast<VkPhysicalDeviceMaintenance9FeaturesKHR*>(static_cast<void*>(p));
                    s->maintenance9 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR: {
                    VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* s = static_cast<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(static_cast<void*>(p));
                    s->depthClampZeroOne = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR: {
                    VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* s = static_cast<VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(static_cast<void*>(p));
                    s->indirectMemoryCopy = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR: {
                    VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* s = static_cast<VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(static_cast<void*>(p));
                    s->shaderUntypedPointers = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR: {
                    VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* s = static_cast<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(static_cast<void*>(p));
                    s->presentModeFifoLatestReady = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR: {
                    VkPhysicalDevicePresentId2FeaturesKHR* s = static_cast<VkPhysicalDevicePresentId2FeaturesKHR*>(static_cast<void*>(p));
                    s->presentId2 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR: {
                    VkPhysicalDevicePresentWait2FeaturesKHR* s = static_cast<VkPhysicalDevicePresentWait2FeaturesKHR*>(static_cast<void*>(p));
                    s->presentWait2 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR: {
                    VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* s = static_cast<VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(static_cast<void*>(p));
                    s->swapchainMaintenance1 = VK_TRUE;
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: {
                    VkPhysicalDeviceCooperativeMatrixFeaturesKHR* s = static_cast<VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(static_cast<void*>(p));
                    s->cooperativeMatrix = VK_TRUE;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p) -> bool { (void)p;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR: {
                    VkPhysicalDeviceRobustness2FeaturesKHR* prettify_VkPhysicalDeviceRobustness2FeaturesKHR = static_cast<VkPhysicalDeviceRobustness2FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceRobustness2FeaturesKHR->nullDescriptor == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceRobustness2FeaturesKHR->nullDescriptor == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceRobustness2FeaturesKHR::nullDescriptor == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceRobustness2FeaturesKHR->robustBufferAccess2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceRobustness2FeaturesKHR->robustBufferAccess2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceRobustness2FeaturesKHR::robustBufferAccess2 == VK_TRUE");
                    ret = ret && (prettify_VkPhysicalDeviceRobustness2FeaturesKHR->robustImageAccess2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceRobustness2FeaturesKHR->robustImageAccess2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceRobustness2FeaturesKHR::robustImageAccess2 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR: {
                    VkPhysicalDevicePipelineBinaryFeaturesKHR* prettify_VkPhysicalDevicePipelineBinaryFeaturesKHR = static_cast<VkPhysicalDevicePipelineBinaryFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDevicePipelineBinaryFeaturesKHR->pipelineBinaries == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDevicePipelineBinaryFeaturesKHR->pipelineBinaries == VK_TRUE), "Unsupported feature condition: VkPhysicalDevicePipelineBinaryFeaturesKHR::pipelineBinaries == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {
                    VkPhysicalDeviceFragmentShadingRateFeaturesKHR* prettify_VkPhysicalDeviceFragmentShadingRateFeaturesKHR = static_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceFragmentShadingRateFeaturesKHR->pipelineFragmentShadingRate == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceFragmentShadingRateFeaturesKHR->pipelineFragmentShadingRate == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceFragmentShadingRateFeaturesKHR::pipelineFragmentShadingRate == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {
                    VkPhysicalDeviceShaderClockFeaturesKHR* prettify_VkPhysicalDeviceShaderClockFeaturesKHR = static_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderClockFeaturesKHR->shaderSubgroupClock == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderClockFeaturesKHR->shaderSubgroupClock == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderClockFeaturesKHR::shaderSubgroupClock == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: {
                    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* prettify_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = static_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR->workgroupMemoryExplicitLayout == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR->workgroupMemoryExplicitLayout == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR: {
                    VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* prettify_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR = static_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR->computeDerivativeGroupLinear == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR->computeDerivativeGroupLinear == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR::computeDerivativeGroupLinear == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance7FeaturesKHR* prettify_VkPhysicalDeviceMaintenance7FeaturesKHR = static_cast<VkPhysicalDeviceMaintenance7FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7FeaturesKHR->maintenance7 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7FeaturesKHR->maintenance7 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceMaintenance7FeaturesKHR::maintenance7 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance8FeaturesKHR* prettify_VkPhysicalDeviceMaintenance8FeaturesKHR = static_cast<VkPhysicalDeviceMaintenance8FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance8FeaturesKHR->maintenance8 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance8FeaturesKHR->maintenance8 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceMaintenance8FeaturesKHR::maintenance8 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR: {
                    VkPhysicalDeviceMaintenance9FeaturesKHR* prettify_VkPhysicalDeviceMaintenance9FeaturesKHR = static_cast<VkPhysicalDeviceMaintenance9FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance9FeaturesKHR->maintenance9 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance9FeaturesKHR->maintenance9 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceMaintenance9FeaturesKHR::maintenance9 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR: {
                    VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* prettify_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR = static_cast<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR->depthClampZeroOne == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR->depthClampZeroOne == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceDepthClampZeroOneFeaturesKHR::depthClampZeroOne == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR: {
                    VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* prettify_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR = static_cast<VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR->indirectMemoryCopy == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR->indirectMemoryCopy == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR::indirectMemoryCopy == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR: {
                    VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* prettify_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR = static_cast<VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR->shaderUntypedPointers == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR->shaderUntypedPointers == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceShaderUntypedPointersFeaturesKHR::shaderUntypedPointers == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR: {
                    VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* prettify_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR = static_cast<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR->presentModeFifoLatestReady == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR->presentModeFifoLatestReady == VK_TRUE), "Unsupported feature condition: VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR::presentModeFifoLatestReady == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR: {
                    VkPhysicalDevicePresentId2FeaturesKHR* prettify_VkPhysicalDevicePresentId2FeaturesKHR = static_cast<VkPhysicalDevicePresentId2FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDevicePresentId2FeaturesKHR->presentId2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDevicePresentId2FeaturesKHR->presentId2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDevicePresentId2FeaturesKHR::presentId2 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR: {
                    VkPhysicalDevicePresentWait2FeaturesKHR* prettify_VkPhysicalDevicePresentWait2FeaturesKHR = static_cast<VkPhysicalDevicePresentWait2FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDevicePresentWait2FeaturesKHR->presentWait2 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDevicePresentWait2FeaturesKHR->presentWait2 == VK_TRUE), "Unsupported feature condition: VkPhysicalDevicePresentWait2FeaturesKHR::presentWait2 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR: {
                    VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* prettify_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR = static_cast<VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR->swapchainMaintenance1 == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR->swapchainMaintenance1 == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR::swapchainMaintenance1 == VK_TRUE");
                } break;
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: {
                    VkPhysicalDeviceCooperativeMatrixFeaturesKHR* prettify_VkPhysicalDeviceCooperativeMatrixFeaturesKHR = static_cast<VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceCooperativeMatrixFeaturesKHR->cooperativeMatrix == VK_TRUE); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceCooperativeMatrixFeaturesKHR->cooperativeMatrix == VK_TRUE), "Unsupported feature condition: VkPhysicalDeviceCooperativeMatrixFeaturesKHR::cooperativeMatrix == VK_TRUE");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpPropertyDesc propertyDesc = {
    [](VkBaseOutStructure* p) { (void)p;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR: {
                    VkPhysicalDeviceMaintenance7PropertiesKHR* s = static_cast<VkPhysicalDeviceMaintenance7PropertiesKHR*>(static_cast<void*>(p));
                    s->maxDescriptorSetTotalBuffersDynamic = 12;
                    s->maxDescriptorSetTotalStorageBuffersDynamic = 4;
                    s->maxDescriptorSetTotalUniformBuffersDynamic = 8;
                    s->maxDescriptorSetUpdateAfterBindTotalBuffersDynamic = 12;
                    s->maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic = 4;
                    s->maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic = 8;
                } break;
                default: break;
            }
    },
    [](VkBaseOutStructure* p, const VkPhysicalDeviceFeatures& features) -> bool { (void)p; (void)features;
        bool ret = true;
            switch (p->sType) {
                case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR: {
                    VkPhysicalDeviceMaintenance7PropertiesKHR* prettify_VkPhysicalDeviceMaintenance7PropertiesKHR = static_cast<VkPhysicalDeviceMaintenance7PropertiesKHR*>(static_cast<void*>(p));
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalBuffersDynamic >= 12); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalBuffersDynamic >= 12), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetTotalBuffersDynamic >= 12");
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalStorageBuffersDynamic >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalStorageBuffersDynamic >= 4), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetTotalStorageBuffersDynamic >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalUniformBuffersDynamic >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetTotalUniformBuffersDynamic >= 8), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetTotalUniformBuffersDynamic >= 8");
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalBuffersDynamic >= 12); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalBuffersDynamic >= 12), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetUpdateAfterBindTotalBuffersDynamic >= 12");
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic >= 4); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic >= 4), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic >= 4");
                    ret = ret && (prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic >= 8); VP_DEBUG_COND_MSG(!(prettify_VkPhysicalDeviceMaintenance7PropertiesKHR->maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic >= 8), "Unsupported properties condition: VkPhysicalDeviceMaintenance7PropertiesKHR::maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic >= 8");
                } break;
                default: break;
            }
        return ret;
    }
};

static const VpStructChainerDesc chainerDesc = {
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceRobustness2FeaturesKHR physicalDeviceRobustness2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR, nullptr };
        VkPhysicalDevicePipelineBinaryFeaturesKHR physicalDevicePipelineBinaryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR, &physicalDeviceRobustness2FeaturesKHR };
        VkPhysicalDeviceFragmentShadingRateFeaturesKHR physicalDeviceFragmentShadingRateFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, &physicalDevicePipelineBinaryFeaturesKHR };
        VkPhysicalDeviceShaderClockFeaturesKHR physicalDeviceShaderClockFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, &physicalDeviceFragmentShadingRateFeaturesKHR };
        VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR physicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR, &physicalDeviceShaderClockFeaturesKHR };
        VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR physicalDeviceComputeShaderDerivativesFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR, &physicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR };
        VkPhysicalDeviceMaintenance7FeaturesKHR physicalDeviceMaintenance7FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR, &physicalDeviceComputeShaderDerivativesFeaturesKHR };
        VkPhysicalDeviceMaintenance8FeaturesKHR physicalDeviceMaintenance8FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR, &physicalDeviceMaintenance7FeaturesKHR };
        VkPhysicalDeviceMaintenance9FeaturesKHR physicalDeviceMaintenance9FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR, &physicalDeviceMaintenance8FeaturesKHR };
        VkPhysicalDeviceDepthClampZeroOneFeaturesKHR physicalDeviceDepthClampZeroOneFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR, &physicalDeviceMaintenance9FeaturesKHR };
        VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR physicalDeviceCopyMemoryIndirectFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR, &physicalDeviceDepthClampZeroOneFeaturesKHR };
        VkPhysicalDeviceShaderUntypedPointersFeaturesKHR physicalDeviceShaderUntypedPointersFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR, &physicalDeviceCopyMemoryIndirectFeaturesKHR };
        VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR physicalDevicePresentModeFifoLatestReadyFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR, &physicalDeviceShaderUntypedPointersFeaturesKHR };
        VkPhysicalDevicePresentId2FeaturesKHR physicalDevicePresentId2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR, &physicalDevicePresentModeFifoLatestReadyFeaturesKHR };
        VkPhysicalDevicePresentWait2FeaturesKHR physicalDevicePresentWait2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR, &physicalDevicePresentId2FeaturesKHR };
        VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR physicalDeviceSwapchainMaintenance1FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR, &physicalDevicePresentWait2FeaturesKHR };
        VkPhysicalDeviceCooperativeMatrixFeaturesKHR physicalDeviceCooperativeMatrixFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR, &physicalDeviceSwapchainMaintenance1FeaturesKHR };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceCooperativeMatrixFeaturesKHR));
        pfnCb(p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, nullptr };
        VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, &physicalDeviceVulkan11Properties };
        VkPhysicalDeviceVulkan13Properties physicalDeviceVulkan13Properties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, &physicalDeviceVulkan12Properties };
        VkPhysicalDeviceMaintenance7PropertiesKHR physicalDeviceMaintenance7PropertiesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR, &physicalDeviceVulkan13Properties };
        p->pNext = static_cast<VkBaseOutStructure*>(static_cast<void*>(&physicalDeviceMaintenance7PropertiesKHR));
        pfnCb(p, pUser);
    },
    [](uint32_t count, VkBaseOutStructure* p, void* pUser, PFN_vpStructArrayChainerCb pfnCb) {
        pfnCb(count, p, pUser);
    },
    [](VkBaseOutStructure* p, void* pUser, PFN_vpStructChainerCb pfnCb) {
        pfnCb(p, pUser);
    },
};
} // namespace vulkanextensionrequirements_roadmap2026
} // namespace blocks
} // namespace VP_KHR_ROADMAP_2026
#endif // VP_KHR_roadmap_2026


#ifdef VP_KHR_roadmap_2022
namespace VP_KHR_ROADMAP_2022 {
    static const VpVariantDesc mergedCapabilities[] = {
        {
        "MERGED",
        nullptr,
        0, nullptr,
        static_cast<uint32_t>(std::size(deviceExtensions)), deviceExtensions,
        static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
            featureDesc,
        0, nullptr,
            propertyDesc,
        0, nullptr,
        0, nullptr,
        0, nullptr,
        0, nullptr,
        chainerDesc,
        0, nullptr,
        },
    };

    namespace blocks {
        namespace vulkan10requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements::featureDesc,
                    0, nullptr,
                    blocks::vulkan10requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements

        namespace vulkan11requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan11requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements

        namespace vulkan12requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements

        namespace vulkan13requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan13requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan13requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan13requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan13requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan13requirements

        namespace vulkan10requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan10requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements_roadmap2022

        namespace vulkan11requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan11requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements_roadmap2022

        namespace vulkan12requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements_roadmap2022

        namespace vulkan13requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan13requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan13requirements_roadmap2022::featureDesc,
                    0, nullptr,
                    blocks::vulkan13requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan13requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan13requirements_roadmap2022

        namespace vulkanextensionrequirements_roadmap2022_promoted_vulkan14 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2022_promoted_vulkan14",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2022_promoted_vulkan14
    } // namespace blocks

    static const VpCapabilitiesDesc capabilities[] = {
        { blocks::vulkan10requirements::variantCount, blocks::vulkan10requirements::variants },
        { blocks::vulkan11requirements::variantCount, blocks::vulkan11requirements::variants },
        { blocks::vulkan12requirements::variantCount, blocks::vulkan12requirements::variants },
        { blocks::vulkan13requirements::variantCount, blocks::vulkan13requirements::variants },
        { blocks::vulkan10requirements_roadmap2022::variantCount, blocks::vulkan10requirements_roadmap2022::variants },
        { blocks::vulkan11requirements_roadmap2022::variantCount, blocks::vulkan11requirements_roadmap2022::variants },
        { blocks::vulkan12requirements_roadmap2022::variantCount, blocks::vulkan12requirements_roadmap2022::variants },
        { blocks::vulkan13requirements_roadmap2022::variantCount, blocks::vulkan13requirements_roadmap2022::variants },
        { blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::variantCount, blocks::vulkanextensionrequirements_roadmap2022_promoted_vulkan14::variants },
    };
    static const uint32_t capabilityCount = static_cast<uint32_t>(std::size(capabilities));
} // namespace VP_KHR_ROADMAP_2022
#endif //VP_KHR_roadmap_2022

#ifdef VP_KHR_roadmap_2024
namespace VP_KHR_ROADMAP_2024 {
    namespace blocks {
        namespace vulkan10requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements_roadmap2024::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan10requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements_roadmap2024

        namespace vulkan11requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements_roadmap2024::featureDesc,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements_roadmap2024

        namespace vulkan12requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements_roadmap2024::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements_roadmap2024

        namespace vulkanextensionrequirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2024

        namespace vulkanextensionrequirements_roadmap2024_promoted_vulkan14 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2024_promoted_vulkan14",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2024_promoted_vulkan14

        namespace vulkanextensionrequirements_roadmap2024_line0_vulkanextensionrequirements_roadmap2024_line1_vulkanextensionrequirements_roadmap2024_line2_vulkanextensionrequirements_roadmap2024_line3_vulkanextensionrequirements_roadmap2024_line4_vulkanextensionrequirements_roadmap2024_line5_ {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2024_line0",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line0::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line0::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line0::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line0::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line0::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkanextensionrequirements_roadmap2024_line1",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line1::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line1::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line1::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line1::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line1::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkanextensionrequirements_roadmap2024_line2",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line2::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line2::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line2::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line2::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line2::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkanextensionrequirements_roadmap2024_line3",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line3::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line3::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line3::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line3::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line3::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkanextensionrequirements_roadmap2024_line4",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line4::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line4::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line4::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line4::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line4::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkanextensionrequirements_roadmap2024_line5",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024_line5::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024_line5::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024_line5::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line5::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024_line5::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2024_line0_vulkanextensionrequirements_roadmap2024_line1_vulkanextensionrequirements_roadmap2024_line2_vulkanextensionrequirements_roadmap2024_line3_vulkanextensionrequirements_roadmap2024_line4_vulkanextensionrequirements_roadmap2024_line5_
    } // namespace blocks

    static const VpCapabilitiesDesc capabilities[] = {
        { blocks::vulkan10requirements_roadmap2024::variantCount, blocks::vulkan10requirements_roadmap2024::variants },
        { blocks::vulkan11requirements_roadmap2024::variantCount, blocks::vulkan11requirements_roadmap2024::variants },
        { blocks::vulkan12requirements_roadmap2024::variantCount, blocks::vulkan12requirements_roadmap2024::variants },
        { blocks::vulkanextensionrequirements_roadmap2024::variantCount, blocks::vulkanextensionrequirements_roadmap2024::variants },
        { blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::variantCount, blocks::vulkanextensionrequirements_roadmap2024_promoted_vulkan14::variants },
        { blocks::vulkanextensionrequirements_roadmap2024_line0_vulkanextensionrequirements_roadmap2024_line1_vulkanextensionrequirements_roadmap2024_line2_vulkanextensionrequirements_roadmap2024_line3_vulkanextensionrequirements_roadmap2024_line4_vulkanextensionrequirements_roadmap2024_line5_::variantCount, blocks::vulkanextensionrequirements_roadmap2024_line0_vulkanextensionrequirements_roadmap2024_line1_vulkanextensionrequirements_roadmap2024_line2_vulkanextensionrequirements_roadmap2024_line3_vulkanextensionrequirements_roadmap2024_line4_vulkanextensionrequirements_roadmap2024_line5_::variants },
    };
    static const uint32_t capabilityCount = static_cast<uint32_t>(std::size(capabilities));

    static const VpProfileProperties profiles[] = {
        {VP_KHR_ROADMAP_2022_NAME, VP_KHR_ROADMAP_2022_SPEC_VERSION},
    };
    static const uint32_t profileCount = static_cast<uint32_t>(std::size(profiles));
} // namespace VP_KHR_ROADMAP_2024
#endif //VP_KHR_roadmap_2024

#ifdef VP_KHR_roadmap_2026
namespace VP_KHR_ROADMAP_2026 {
    namespace blocks {
        namespace vulkan10requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements::featureDesc,
                    0, nullptr,
                    blocks::vulkan10requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements

        namespace vulkan11requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan11requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements

        namespace vulkan12requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements

        namespace vulkan13requirements {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan13requirements",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan13requirements::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan13requirements::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan13requirements::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan13requirements

        namespace vulkan10requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan10requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements_roadmap2022

        namespace vulkan11requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan11requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements_roadmap2022

        namespace vulkan12requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements_roadmap2022::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements_roadmap2022

        namespace vulkan13requirements_roadmap2022 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan13requirements_roadmap2022",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan13requirements_roadmap2022::featureDesc,
                    0, nullptr,
                    blocks::vulkan13requirements_roadmap2022::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan13requirements_roadmap2022::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan13requirements_roadmap2022

        namespace vulkan10requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan10requirements_roadmap2024::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan10requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements_roadmap2024

        namespace vulkan11requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan11requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan11requirements_roadmap2024::featureDesc,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan11requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan11requirements_roadmap2024

        namespace vulkan12requirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan12requirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan12requirements_roadmap2024::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan12requirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan12requirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan12requirements_roadmap2024

        namespace vulkanextensionrequirements_roadmap2024 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2024",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2024::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2024::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2024::featureDesc,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2024::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2024

        namespace vulkan10requirements_roadmap2026 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan10requirements_roadmap2026",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2026::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkan10requirements_roadmap2026::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan10requirements_roadmap2026::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan10requirements_roadmap2026

        namespace vulkan14requirements_roadmap2026 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan14requirements_roadmap2026",
                    nullptr,
                    0, nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan14requirements_roadmap2026

        namespace vulkan14requirements_roadmap2026_line0_vulkan14requirements_roadmap2026_line1_vulkan14requirements_roadmap2026_line2_vulkan14requirements_roadmap2026_line3_vulkan14requirements_roadmap2026_line4_vulkan14requirements_roadmap2026_line5_ {
            static const VpVariantDesc variants[] = {
                {
                    "vulkan14requirements_roadmap2026_line0",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line0::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line0::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line0::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line0::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line0::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkan14requirements_roadmap2026_line1",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line1::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line1::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line1::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line1::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line1::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkan14requirements_roadmap2026_line2",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line2::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line2::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line2::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line2::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line2::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkan14requirements_roadmap2026_line3",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line3::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line3::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line3::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line3::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line3::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkan14requirements_roadmap2026_line4",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line4::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line4::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line4::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line4::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line4::chainerDesc,
                    0, nullptr,
                },
                {
                    "vulkan14requirements_roadmap2026_line5",
                    nullptr,
                    0, nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkan14requirements_roadmap2026_line5::deviceExtensions)), blocks::vulkan14requirements_roadmap2026_line5::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkan14requirements_roadmap2026_line5::featureDesc,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line5::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkan14requirements_roadmap2026_line5::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkan14requirements_roadmap2026_line0_vulkan14requirements_roadmap2026_line1_vulkan14requirements_roadmap2026_line2_vulkan14requirements_roadmap2026_line3_vulkan14requirements_roadmap2026_line4_vulkan14requirements_roadmap2026_line5_

        namespace vulkanextensionrequirements_roadmap2026 {
            static const VpVariantDesc variants[] = {
                {
                    "vulkanextensionrequirements_roadmap2026",
                    nullptr,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2026::instanceExtensions)), blocks::vulkanextensionrequirements_roadmap2026::instanceExtensions,
                    static_cast<uint32_t>(std::size(blocks::vulkanextensionrequirements_roadmap2026::deviceExtensions)), blocks::vulkanextensionrequirements_roadmap2026::deviceExtensions,
                    static_cast<uint32_t>(std::size(featureStructTypes)), featureStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2026::featureDesc,
                    static_cast<uint32_t>(std::size(propertyStructTypes)), propertyStructTypes,
                    blocks::vulkanextensionrequirements_roadmap2026::propertyDesc,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    0, nullptr,
                    blocks::vulkanextensionrequirements_roadmap2026::chainerDesc,
                    0, nullptr,
                },
            };
            static const uint32_t variantCount = static_cast<uint32_t>(std::size(variants));
        } // namespace vulkanextensionrequirements_roadmap2026
    } // namespace blocks

    static const VpCapabilitiesDesc capabilities[] = {
        { blocks::vulkan10requirements::variantCount, blocks::vulkan10requirements::variants },
        { blocks::vulkan11requirements::variantCount, blocks::vulkan11requirements::variants },
        { blocks::vulkan12requirements::variantCount, blocks::vulkan12requirements::variants },
        { blocks::vulkan13requirements::variantCount, blocks::vulkan13requirements::variants },
        { blocks::vulkan10requirements_roadmap2022::variantCount, blocks::vulkan10requirements_roadmap2022::variants },
        { blocks::vulkan11requirements_roadmap2022::variantCount, blocks::vulkan11requirements_roadmap2022::variants },
        { blocks::vulkan12requirements_roadmap2022::variantCount, blocks::vulkan12requirements_roadmap2022::variants },
        { blocks::vulkan13requirements_roadmap2022::variantCount, blocks::vulkan13requirements_roadmap2022::variants },
        { blocks::vulkan10requirements_roadmap2024::variantCount, blocks::vulkan10requirements_roadmap2024::variants },
        { blocks::vulkan11requirements_roadmap2024::variantCount, blocks::vulkan11requirements_roadmap2024::variants },
        { blocks::vulkan12requirements_roadmap2024::variantCount, blocks::vulkan12requirements_roadmap2024::variants },
        { blocks::vulkanextensionrequirements_roadmap2024::variantCount, blocks::vulkanextensionrequirements_roadmap2024::variants },
        { blocks::vulkan10requirements_roadmap2026::variantCount, blocks::vulkan10requirements_roadmap2026::variants },
        { blocks::vulkan14requirements_roadmap2026::variantCount, blocks::vulkan14requirements_roadmap2026::variants },
        { blocks::vulkan14requirements_roadmap2026_line0_vulkan14requirements_roadmap2026_line1_vulkan14requirements_roadmap2026_line2_vulkan14requirements_roadmap2026_line3_vulkan14requirements_roadmap2026_line4_vulkan14requirements_roadmap2026_line5_::variantCount, blocks::vulkan14requirements_roadmap2026_line0_vulkan14requirements_roadmap2026_line1_vulkan14requirements_roadmap2026_line2_vulkan14requirements_roadmap2026_line3_vulkan14requirements_roadmap2026_line4_vulkan14requirements_roadmap2026_line5_::variants },
        { blocks::vulkanextensionrequirements_roadmap2026::variantCount, blocks::vulkanextensionrequirements_roadmap2026::variants },
    };
    static const uint32_t capabilityCount = static_cast<uint32_t>(std::size(capabilities));
} // namespace VP_KHR_ROADMAP_2026
#endif //VP_KHR_roadmap_2026

static const VpProfileDesc profiles[] = {
#ifdef VP_KHR_roadmap_2022
    VpProfileDesc{
        VpProfileProperties{ VP_KHR_ROADMAP_2022_NAME, VP_KHR_ROADMAP_2022_SPEC_VERSION },
        VP_KHR_ROADMAP_2022_MIN_API_VERSION,
        VP_KHR_ROADMAP_2022::mergedCapabilities,
        0, nullptr,
        VP_KHR_ROADMAP_2022::capabilityCount, VP_KHR_ROADMAP_2022::capabilities,
        0, nullptr,
    },
#endif // VP_KHR_ROADMAP_2022
#ifdef VP_KHR_roadmap_2024
    VpProfileDesc{
        VpProfileProperties{ VP_KHR_ROADMAP_2024_NAME, VP_KHR_ROADMAP_2024_SPEC_VERSION },
        VP_KHR_ROADMAP_2024_MIN_API_VERSION,
        nullptr,
        VP_KHR_ROADMAP_2024::profileCount, VP_KHR_ROADMAP_2024::profiles,
        VP_KHR_ROADMAP_2024::capabilityCount, VP_KHR_ROADMAP_2024::capabilities,
        0, nullptr,
    },
#endif // VP_KHR_ROADMAP_2024
#ifdef VP_KHR_roadmap_2026
    VpProfileDesc{
        VpProfileProperties{ VP_KHR_ROADMAP_2026_NAME, VP_KHR_ROADMAP_2026_SPEC_VERSION },
        VP_KHR_ROADMAP_2026_MIN_API_VERSION,
        nullptr,
        0, nullptr,
        VP_KHR_ROADMAP_2026::capabilityCount, VP_KHR_ROADMAP_2026::capabilities,
        0, nullptr,
    },
#endif // VP_KHR_ROADMAP_2026
};
static const uint32_t profileCount = static_cast<uint32_t>(std::size(profiles));


struct FeaturesChain {
    std::map<VkStructureType, std::size_t> structureSize;

    template<typename T>
    constexpr std::size_t size() const {
        return (sizeof(T) - sizeof(VkBaseOutStructure)) / sizeof(VkBool32);
    }

	// Chain with all Vulkan Features structures
    VkPhysicalDeviceProtectedMemoryFeatures physicalDeviceProtectedMemoryFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, nullptr };
    VkPhysicalDevice16BitStorageFeatures physicalDevice16BitStorageFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, nullptr };
    VkPhysicalDeviceVariablePointersFeatures physicalDeviceVariablePointersFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, nullptr };
    VkPhysicalDeviceSamplerYcbcrConversionFeatures physicalDeviceSamplerYcbcrConversionFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, nullptr };
    VkPhysicalDeviceMultiviewFeatures physicalDeviceMultiviewFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, nullptr };
    VkPhysicalDeviceShaderDrawParametersFeatures physicalDeviceShaderDrawParametersFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, nullptr };
    VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
    VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
    VkPhysicalDeviceVulkanMemoryModelFeatures physicalDeviceVulkanMemoryModelFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES, nullptr };
    VkPhysicalDeviceHostQueryResetFeatures physicalDeviceHostQueryResetFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES, nullptr };
    VkPhysicalDeviceTimelineSemaphoreFeatures physicalDeviceTimelineSemaphoreFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES, nullptr };
    VkPhysicalDeviceBufferDeviceAddressFeatures physicalDeviceBufferDeviceAddressFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES, nullptr };
    VkPhysicalDevice8BitStorageFeatures physicalDevice8BitStorageFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES, nullptr };
    VkPhysicalDeviceShaderAtomicInt64Features physicalDeviceShaderAtomicInt64Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES, nullptr };
    VkPhysicalDeviceShaderFloat16Int8Features physicalDeviceShaderFloat16Int8Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES, nullptr };
    VkPhysicalDeviceDescriptorIndexingFeatures physicalDeviceDescriptorIndexingFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES, nullptr };
    VkPhysicalDeviceScalarBlockLayoutFeatures physicalDeviceScalarBlockLayoutFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES, nullptr };
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures physicalDeviceUniformBufferStandardLayoutFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES, nullptr };
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures physicalDeviceShaderSubgroupExtendedTypesFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES, nullptr };
    VkPhysicalDeviceImagelessFramebufferFeatures physicalDeviceImagelessFramebufferFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES, nullptr };
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures physicalDeviceSeparateDepthStencilLayoutsFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES, nullptr };
    VkPhysicalDeviceVulkan13Features physicalDeviceVulkan13Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, nullptr };
    VkPhysicalDevicePrivateDataFeatures physicalDevicePrivateDataFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES, nullptr };
    VkPhysicalDeviceSynchronization2Features physicalDeviceSynchronization2Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES, nullptr };
    VkPhysicalDeviceTextureCompressionASTCHDRFeatures physicalDeviceTextureCompressionASTCHDRFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES, nullptr };
    VkPhysicalDeviceMaintenance4Features physicalDeviceMaintenance4Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES, nullptr };
    VkPhysicalDeviceShaderTerminateInvocationFeatures physicalDeviceShaderTerminateInvocationFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES, nullptr };
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures physicalDeviceShaderDemoteToHelperInvocationFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES, nullptr };
    VkPhysicalDevicePipelineCreationCacheControlFeatures physicalDevicePipelineCreationCacheControlFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES, nullptr };
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures physicalDeviceZeroInitializeWorkgroupMemoryFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES, nullptr };
    VkPhysicalDeviceImageRobustnessFeatures physicalDeviceImageRobustnessFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES, nullptr };
    VkPhysicalDeviceSubgroupSizeControlFeatures physicalDeviceSubgroupSizeControlFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES, nullptr };
    VkPhysicalDeviceInlineUniformBlockFeatures physicalDeviceInlineUniformBlockFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES, nullptr };
    VkPhysicalDeviceShaderIntegerDotProductFeatures physicalDeviceShaderIntegerDotProductFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES, nullptr };
    VkPhysicalDeviceDynamicRenderingFeatures physicalDeviceDynamicRenderingFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES, nullptr };
    VkPhysicalDeviceVulkan14Features physicalDeviceVulkan14Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, nullptr };
    VkPhysicalDeviceGlobalPriorityQueryFeatures physicalDeviceGlobalPriorityQueryFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES, nullptr };
    VkPhysicalDeviceIndexTypeUint8Features physicalDeviceIndexTypeUint8Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES, nullptr };
    VkPhysicalDeviceMaintenance5Features physicalDeviceMaintenance5Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES, nullptr };
    VkPhysicalDeviceMaintenance6Features physicalDeviceMaintenance6Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES, nullptr };
    VkPhysicalDeviceHostImageCopyFeatures physicalDeviceHostImageCopyFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES, nullptr };
    VkPhysicalDeviceShaderSubgroupRotateFeatures physicalDeviceShaderSubgroupRotateFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES, nullptr };
    VkPhysicalDeviceShaderFloatControls2Features physicalDeviceShaderFloatControls2Features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES, nullptr };
    VkPhysicalDeviceShaderExpectAssumeFeatures physicalDeviceShaderExpectAssumeFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES, nullptr };
    VkPhysicalDevicePipelineProtectedAccessFeatures physicalDevicePipelineProtectedAccessFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES, nullptr };
    VkPhysicalDevicePipelineRobustnessFeatures physicalDevicePipelineRobustnessFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES, nullptr };
    VkPhysicalDeviceLineRasterizationFeatures physicalDeviceLineRasterizationFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES, nullptr };
    VkPhysicalDeviceVertexAttributeDivisorFeatures physicalDeviceVertexAttributeDivisorFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES, nullptr };
    VkPhysicalDeviceDynamicRenderingLocalReadFeatures physicalDeviceDynamicRenderingLocalReadFeatures{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES, nullptr };
    VkPhysicalDevicePerformanceQueryFeaturesKHR physicalDevicePerformanceQueryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderBfloat16FeaturesKHR physicalDeviceShaderBfloat16FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDevicePortabilitySubsetFeaturesKHR physicalDevicePortabilitySubsetFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR, nullptr };
#endif
    VkPhysicalDeviceShaderClockFeaturesKHR physicalDeviceShaderClockFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, nullptr };
    VkPhysicalDeviceFragmentShadingRateFeaturesKHR physicalDeviceFragmentShadingRateFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderConstantDataFeaturesKHR physicalDeviceShaderConstantDataFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderAbortFeaturesKHR physicalDeviceShaderAbortFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderQuadControlFeaturesKHR physicalDeviceShaderQuadControlFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR, nullptr };
    VkPhysicalDevicePresentWaitFeaturesKHR physicalDevicePresentWaitFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR, nullptr };
    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR physicalDevicePipelineExecutablePropertiesFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR, nullptr };
    VkPhysicalDevicePresentIdFeaturesKHR physicalDevicePresentIdFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR, nullptr };
    VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR physicalDeviceDeviceAddressCommandsFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR, nullptr };
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR physicalDeviceFragmentShaderBarycentricFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR, nullptr };
    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR physicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR, nullptr };
    VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR physicalDeviceRayTracingMaintenance1FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderUntypedPointersFeaturesKHR physicalDeviceShaderUntypedPointersFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR physicalDeviceShaderMaximalReconvergenceFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR, nullptr };
    VkPhysicalDevicePresentId2FeaturesKHR physicalDevicePresentId2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR, nullptr };
    VkPhysicalDevicePresentWait2FeaturesKHR physicalDevicePresentWait2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR, nullptr };
    VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR physicalDeviceRayTracingPositionFetchFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR, nullptr };
    VkPhysicalDevicePipelineBinaryFeaturesKHR physicalDevicePipelineBinaryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR, nullptr };
    VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR physicalDeviceSwapchainMaintenance1FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR, nullptr };
    VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR physicalDeviceInternallySynchronizedQueuesFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR, nullptr };
    VkPhysicalDeviceCooperativeMatrixFeaturesKHR physicalDeviceCooperativeMatrixFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR, nullptr };
    VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR physicalDeviceComputeShaderDerivativesFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoEncodeAV1FeaturesKHR physicalDeviceVideoEncodeAV1FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoDecodeVP9FeaturesKHR physicalDeviceVideoDecodeVP9FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoMaintenance1FeaturesKHR physicalDeviceVideoMaintenance1FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR, nullptr };
    VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR physicalDeviceUnifiedImageLayoutsFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR, nullptr };
    VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR physicalDeviceCopyMemoryIndirectFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR physicalDeviceVideoEncodeIntraRefreshFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR physicalDeviceVideoEncodeQuantizationMapFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR physicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance7FeaturesKHR physicalDeviceMaintenance7FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR, nullptr };
    VkPhysicalDeviceFaultFeaturesKHR physicalDeviceFaultFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance8FeaturesKHR physicalDeviceMaintenance8FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR, nullptr };
    VkPhysicalDeviceShaderFmaFeaturesKHR physicalDeviceShaderFmaFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance9FeaturesKHR physicalDeviceMaintenance9FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoMaintenance2FeaturesKHR physicalDeviceVideoMaintenance2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR, nullptr };
    VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR physicalDeviceVideoEncodeFeedback2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_FEEDBACK_2_FEATURES_KHR, nullptr };
    VkPhysicalDeviceDepthClampZeroOneFeaturesKHR physicalDeviceDepthClampZeroOneFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR, nullptr };
    VkPhysicalDeviceRobustness2FeaturesKHR physicalDeviceRobustness2FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR, nullptr };
    VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR physicalDevicePresentModeFifoLatestReadyFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR, nullptr };
    VkPhysicalDeviceOpacityMicromapFeaturesKHR physicalDeviceOpacityMicromapFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance10FeaturesKHR physicalDeviceMaintenance10FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR, nullptr };
    VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR physicalDevicePipelineLibraryGroupHandlesFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance11FeaturesKHR physicalDeviceMaintenance11FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR, nullptr };
    VkPhysicalDeviceExtendedFlagsFeaturesKHR physicalDeviceExtendedFlagsFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_FLAGS_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMaintenance12FeaturesKHR physicalDeviceMaintenance12FeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_12_FEATURES_KHR, nullptr };
    VkPhysicalDeviceTransformFeedbackFeaturesEXT physicalDeviceTransformFeedbackFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCornerSampledImageFeaturesNV physicalDeviceCornerSampledImageFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV, nullptr };
    VkPhysicalDeviceASTCDecodeFeaturesEXT physicalDeviceASTCDecodeFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceConditionalRenderingFeaturesEXT physicalDeviceConditionalRenderingFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDepthClipEnableFeaturesEXT physicalDeviceDepthClipEnableFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG physicalDeviceRelaxedLineRasterizationFeaturesIMG{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG, nullptr };
    VkPhysicalDeviceGpaFeaturesAMD physicalDeviceGpaFeaturesAMD{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDeviceShaderEnqueueFeaturesAMDX physicalDeviceShaderEnqueueFeaturesAMDX{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX, nullptr };
#endif
    VkPhysicalDeviceDescriptorHeapFeaturesEXT physicalDeviceDescriptorHeapFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_FEATURES_EXT, nullptr };
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT physicalDeviceBlendOperationAdvancedFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV physicalDeviceShaderSMBuiltinsFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV, nullptr };
    VkPhysicalDeviceShadingRateImageFeaturesNV physicalDeviceShadingRateImageFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV, nullptr };
    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV physicalDeviceRepresentativeFragmentTestFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV, nullptr };
    VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM physicalDeviceCooperativeMatrixConversionFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM physicalDeviceElapsedTimerQueryFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ELAPSED_TIMER_QUERY_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceMeshShaderFeaturesNV physicalDeviceMeshShaderFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV, nullptr };
    VkPhysicalDeviceShaderImageFootprintFeaturesNV physicalDeviceShaderImageFootprintFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV, nullptr };
    VkPhysicalDeviceExclusiveScissorFeaturesNV physicalDeviceExclusiveScissorFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV, nullptr };
    VkPhysicalDevicePresentTimingFeaturesEXT physicalDevicePresentTimingFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL physicalDeviceShaderIntegerFunctions2FeaturesINTEL{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL, nullptr };
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT physicalDeviceFragmentDensityMapFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCoherentMemoryFeaturesAMD physicalDeviceCoherentMemoryFeaturesAMD{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD, nullptr };
    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT physicalDeviceShaderImageAtomicInt64FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT, nullptr };
    VkPhysicalDeviceMemoryPriorityFeaturesEXT physicalDeviceMemoryPriorityFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV physicalDeviceDedicatedAllocationImageAliasingFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV, nullptr };
    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT physicalDeviceBufferDeviceAddressFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCooperativeMatrixFeaturesNV physicalDeviceCooperativeMatrixFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV, nullptr };
    VkPhysicalDeviceCoverageReductionModeFeaturesNV physicalDeviceCoverageReductionModeFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV, nullptr };
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT physicalDeviceFragmentShaderInterlockFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT, nullptr };
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT physicalDeviceYcbcrImageArraysFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceProvokingVertexFeaturesEXT physicalDeviceProvokingVertexFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT physicalDeviceShaderAtomicFloatFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT physicalDeviceExtendedDynamicStateFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceMapMemoryPlacedFeaturesEXT physicalDeviceMapMemoryPlacedFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT physicalDeviceShaderAtomicFloat2FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV physicalDeviceDeviceGeneratedCommandsFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV, nullptr };
    VkPhysicalDeviceInheritedViewportScissorFeaturesNV physicalDeviceInheritedViewportScissorFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV, nullptr };
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT physicalDeviceTexelBufferAlignmentFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDepthBiasControlFeaturesEXT physicalDeviceDepthBiasControlFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDeviceMemoryReportFeaturesEXT physicalDeviceDeviceMemoryReportFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCustomBorderColorFeaturesEXT physicalDeviceCustomBorderColorFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT, nullptr };
    VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT physicalDeviceTextureCompressionASTC3DFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT, nullptr };
    VkPhysicalDevicePresentBarrierFeaturesNV physicalDevicePresentBarrierFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV, nullptr };
    VkPhysicalDeviceDiagnosticsConfigFeaturesNV physicalDeviceDiagnosticsConfigFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV, nullptr };
    VkPhysicalDeviceQueuePerfHintFeaturesQCOM physicalDeviceQueuePerfHintFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceImageProcessing3FeaturesQCOM physicalDeviceImageProcessing3FeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_3_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM physicalDeviceShaderMultipleWaitQueuesFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceShaderSplitBarrierFeaturesEXT physicalDeviceShaderSplitBarrierFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_FEATURES_EXT, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDeviceCudaKernelLaunchFeaturesNV physicalDeviceCudaKernelLaunchFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV, nullptr };
#endif
    VkPhysicalDeviceTileShadingFeaturesQCOM physicalDeviceTileShadingFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceDescriptorBufferFeaturesEXT physicalDeviceDescriptorBufferFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT, nullptr };
    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT physicalDeviceGraphicsPipelineLibraryFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD physicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD, nullptr };
    VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV physicalDeviceFragmentShadingRateEnumsFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV, nullptr };
    VkPhysicalDeviceRayTracingMotionBlurFeaturesNV physicalDeviceRayTracingMotionBlurFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV, nullptr };
    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT physicalDeviceYcbcr2Plane444FormatsFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT physicalDeviceFragmentDensityMap2FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT, nullptr };
    VkPhysicalDeviceImageCompressionControlFeaturesEXT physicalDeviceImageCompressionControlFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT, nullptr };
    VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT physicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT, nullptr };
    VkPhysicalDevice4444FormatsFeaturesEXT physicalDevice4444FormatsFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceFaultFeaturesEXT physicalDeviceFaultFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT physicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT physicalDeviceRGBA10X6FormatsFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT physicalDeviceMutableDescriptorTypeFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT physicalDeviceVertexInputDynamicStateFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceAddressBindingReportFeaturesEXT physicalDeviceAddressBindingReportFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDepthClipControlFeaturesEXT physicalDeviceDepthClipControlFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT, nullptr };
    VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT physicalDevicePrimitiveTopologyListRestartFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT, nullptr };
    VkPhysicalDeviceSubpassShadingFeaturesHUAWEI physicalDeviceSubpassShadingFeaturesHUAWEI{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI, nullptr };
    VkPhysicalDeviceInvocationMaskFeaturesHUAWEI physicalDeviceInvocationMaskFeaturesHUAWEI{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI, nullptr };
    VkPhysicalDeviceExternalMemoryRDMAFeaturesNV physicalDeviceExternalMemoryRDMAFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV, nullptr };
    VkPhysicalDevicePipelinePropertiesFeaturesEXT physicalDevicePipelinePropertiesFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT, nullptr };
    VkPhysicalDeviceFrameBoundaryFeaturesEXT physicalDeviceFrameBoundaryFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT physicalDeviceMultisampledRenderToSingleSampledFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT, nullptr };
    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT physicalDeviceExtendedDynamicState2FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT, nullptr };
    VkPhysicalDeviceColorWriteEnableFeaturesEXT physicalDeviceColorWriteEnableFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT, nullptr };
    VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT physicalDevicePrimitivesGeneratedQueryFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE physicalDeviceVideoEncodeRgbConversionFeaturesVALVE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE, nullptr };
    VkPhysicalDeviceImageViewMinLodFeaturesEXT physicalDeviceImageViewMinLodFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT, nullptr };
    VkPhysicalDeviceMultiDrawFeaturesEXT physicalDeviceMultiDrawFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT, nullptr };
    VkPhysicalDeviceImage2DViewOf3DFeaturesEXT physicalDeviceImage2DViewOf3DFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderTileImageFeaturesEXT physicalDeviceShaderTileImageFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceOpacityMicromapFeaturesEXT physicalDeviceOpacityMicromapFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDeviceDisplacementMicromapFeaturesNV physicalDeviceDisplacementMicromapFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV, nullptr };
#endif
    VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI physicalDeviceClusterCullingShaderFeaturesHUAWEI{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI, nullptr };
    VkPhysicalDeviceBorderColorSwizzleFeaturesEXT physicalDeviceBorderColorSwizzleFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT, nullptr };
    VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT physicalDevicePageableDeviceLocalMemoryFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceSchedulingControlsFeaturesARM physicalDeviceSchedulingControlsFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM, nullptr };
    VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT physicalDeviceImageSlicedViewOf3DFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE physicalDeviceDescriptorSetHostMappingFeaturesVALVE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE, nullptr };
    VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT physicalDeviceNonSeamlessCubeMapFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT, nullptr };
    VkPhysicalDeviceRenderPassStripedFeaturesARM physicalDeviceRenderPassStripedFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM, nullptr };
    VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT physicalDeviceFragmentDensityMapOffsetFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCopyMemoryIndirectFeaturesNV physicalDeviceCopyMemoryIndirectFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV, nullptr };
    VkPhysicalDeviceMemoryDecompressionFeaturesEXT physicalDeviceMemoryDecompressionFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV physicalDeviceDeviceGeneratedCommandsComputeFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV, nullptr };
    VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV physicalDeviceRayTracingLinearSweptSpheresFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV, nullptr };
    VkPhysicalDeviceLinearColorAttachmentFeaturesNV physicalDeviceLinearColorAttachmentFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV, nullptr };
    VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT physicalDeviceImageCompressionControlSwapchainFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT, nullptr };
    VkPhysicalDeviceImageProcessingFeaturesQCOM physicalDeviceImageProcessingFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceNestedCommandBufferFeaturesEXT physicalDeviceNestedCommandBufferFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT, nullptr };
    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT physicalDeviceExtendedDynamicState3FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT, nullptr };
    VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT physicalDeviceSubpassMergeFeedbackFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT, nullptr };
    VkPhysicalDeviceTensorFeaturesARM physicalDeviceTensorFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM, nullptr };
    VkPhysicalDeviceDescriptorBufferTensorFeaturesARM physicalDeviceDescriptorBufferTensorFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM, nullptr };
    VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT physicalDeviceShaderModuleIdentifierFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT, nullptr };
    VkPhysicalDeviceOpticalFlowFeaturesNV physicalDeviceOpticalFlowFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV, nullptr };
    VkPhysicalDeviceLegacyDitheringFeaturesEXT physicalDeviceLegacyDitheringFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT, nullptr };
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VkPhysicalDeviceExternalFormatResolveFeaturesANDROID physicalDeviceExternalFormatResolveFeaturesANDROID{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID, nullptr };
#endif
    VkPhysicalDeviceAntiLagFeaturesAMD physicalDeviceAntiLagFeaturesAMD{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX physicalDeviceDenseGeometryFormatFeaturesAMDX{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX, nullptr };
#endif
    VkPhysicalDeviceShaderObjectFeaturesEXT physicalDeviceShaderObjectFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT, nullptr };
    VkPhysicalDeviceTilePropertiesFeaturesQCOM physicalDeviceTilePropertiesFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceAmigoProfilingFeaturesSEC physicalDeviceAmigoProfilingFeaturesSEC{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC, nullptr };
    VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM physicalDeviceMultiviewPerViewViewportsFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV physicalDeviceRayTracingInvocationReorderFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV, nullptr };
    VkPhysicalDeviceCooperativeVectorFeaturesNV physicalDeviceCooperativeVectorFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV, nullptr };
    VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV physicalDeviceExtendedSparseAddressSpaceFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV, nullptr };
    VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT physicalDeviceLegacyVertexAttributesFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM physicalDeviceShaderCoreBuiltinsFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM, nullptr };
    VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT physicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDataGraphFeaturesARM physicalDeviceDataGraphFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM, nullptr };
    VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM physicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM, nullptr };
    VkPhysicalDevicePerStageDescriptorSetFeaturesNV physicalDevicePerStageDescriptorSetFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV, nullptr };
    VkPhysicalDeviceImageProcessing2FeaturesQCOM physicalDeviceImageProcessing2FeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceCubicWeightsFeaturesQCOM physicalDeviceCubicWeightsFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceYcbcrDegammaFeaturesQCOM physicalDeviceYcbcrDegammaFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceCubicClampFeaturesQCOM physicalDeviceCubicClampFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT physicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT, nullptr };
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX physicalDeviceExternalMemoryScreenBufferFeaturesQNX{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX, nullptr };
#endif
    VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV physicalDeviceDescriptorPoolOverallocationFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV, nullptr };
    VkPhysicalDeviceTileMemoryHeapFeaturesQCOM physicalDeviceTileMemoryHeapFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceRawAccessChainsFeaturesNV physicalDeviceRawAccessChainsFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV, nullptr };
    VkPhysicalDeviceCommandBufferInheritanceFeaturesNV physicalDeviceCommandBufferInheritanceFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV, nullptr };
    VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV physicalDeviceShaderAtomicFloat16VectorFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV, nullptr };
    VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT physicalDeviceShaderReplicatedCompositesFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderFloat8FeaturesEXT physicalDeviceShaderFloat8FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT, nullptr };
    VkPhysicalDeviceRayTracingValidationFeaturesNV physicalDeviceRayTracingValidationFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV, nullptr };
    VkPhysicalDeviceClusterAccelerationStructureFeaturesNV physicalDeviceClusterAccelerationStructureFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV, nullptr };
    VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV physicalDevicePartitionedAccelerationStructureFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV, nullptr };
    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT physicalDeviceDeviceGeneratedCommandsFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceImageAlignmentControlFeaturesMESA physicalDeviceImageAlignmentControlFeaturesMESA{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA, nullptr };
    VkPhysicalDevicePushConstantBankFeaturesNV physicalDevicePushConstantBankFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV, nullptr };
    VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT physicalDeviceRayTracingInvocationReorderFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDepthClampControlFeaturesEXT physicalDeviceDepthClampControlFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT, nullptr };
    VkPhysicalDeviceHdrVividFeaturesHUAWEI physicalDeviceHdrVividFeaturesHUAWEI{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI, nullptr };
    VkPhysicalDeviceCooperativeMatrix2FeaturesNV physicalDeviceCooperativeMatrix2FeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV, nullptr };
    VkPhysicalDevicePipelineOpacityMicromapFeaturesARM physicalDevicePipelineOpacityMicromapFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM, nullptr };
    VkPhysicalDevicePerformanceCountersByRegionFeaturesARM physicalDevicePerformanceCountersByRegionFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM, nullptr };
    VkPhysicalDeviceShaderInstrumentationFeaturesARM physicalDeviceShaderInstrumentationFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_FEATURES_ARM, nullptr };
    VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT physicalDeviceVertexAttributeRobustnessFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT, nullptr };
    VkPhysicalDeviceFormatPackFeaturesARM physicalDeviceFormatPackFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM, nullptr };
    VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE physicalDeviceFragmentDensityMapLayeredFeaturesVALVE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE, nullptr };
    VkPhysicalDevicePresentMeteringFeaturesNV physicalDevicePresentMeteringFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV, nullptr };
    VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT physicalDeviceMultisampledRenderToSwapchainFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SWAPCHAIN_FEATURES_EXT, nullptr };
    VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT physicalDeviceZeroInitializeDeviceMemoryFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShader64BitIndexingFeaturesEXT physicalDeviceShader64BitIndexingFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCustomResolveFeaturesEXT physicalDeviceCustomResolveFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT, nullptr };
    VkPhysicalDeviceDataGraphModelFeaturesQCOM physicalDeviceDataGraphModelFeaturesQCOM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM, nullptr };
    VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM physicalDeviceDataGraphOpticalFlowFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM, nullptr };
    VkPhysicalDeviceShaderLongVectorFeaturesEXT physicalDeviceShaderLongVectorFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT, nullptr };
    VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC physicalDevicePipelineCacheIncrementalModeFeaturesSEC{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC, nullptr };
    VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT physicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT, nullptr };
    VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV physicalDeviceComputeOccupancyPriorityFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV, nullptr };
#ifdef VK_ENABLE_BETA_EXTENSIONS
    VkPhysicalDeviceMultiLevelAccelerationStructureFeaturesAMDX physicalDeviceMultiLevelAccelerationStructureFeaturesAMDX{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_LEVEL_ACCELERATION_STRUCTURE_FEATURES_AMDX, nullptr };
#endif
    VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT physicalDeviceCooperativeMatrixMaintenance1FeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_MAINTENANCE_1_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT physicalDeviceShaderSubgroupPartitionedFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCooperativeMatrixLayoutsFeaturesARM physicalDeviceCooperativeMatrixLayoutsFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_LAYOUTS_FEATURES_ARM, nullptr };
    VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT physicalDeviceShaderOCPMicroscalingTypesFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OCP_MICROSCALING_TYPES_FEATURES_EXT, nullptr };
    VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE physicalDeviceShaderMixedFloatDotProductFeaturesVALVE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE, nullptr };
    VkPhysicalDeviceThrottleHintFeaturesSEC physicalDeviceThrottleHintFeaturesSEC{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC, nullptr };
    VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM physicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM, nullptr };
    VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT physicalDevicePrimitiveRestartIndexFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT, nullptr };
    VkPhysicalDeviceVertexAddressBindingUnrestrictedFeaturesEXT physicalDeviceVertexAddressBindingUnrestrictedFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ADDRESS_BINDING_UNRESTRICTED_FEATURES_EXT, nullptr };
    VkPhysicalDeviceImageTilingControlFeaturesEXT physicalDeviceImageTilingControlFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_TILING_CONTROL_FEATURES_EXT, nullptr };
    VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV physicalDeviceCooperativeMatrixDecodeVectorFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_DECODE_VECTOR_FEATURES_NV, nullptr };
    VkPhysicalDevicePrivateDataBaseHandleFeaturesNV physicalDevicePrivateDataBaseHandleFeaturesNV{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_BASE_HANDLE_FEATURES_NV, nullptr };
    VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE physicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_ALLOCATION_ALIGNMENT_FEATURES_VALVE, nullptr };
    VkPhysicalDeviceHdrSmpteSt209450FeaturesGOOGLE physicalDeviceHdrSmpteSt209450FeaturesGOOGLE{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_SMPTE_ST_209450_FEATURES_GOOGLE, nullptr };
    VkPhysicalDeviceAccelerationStructureFeaturesKHR physicalDeviceAccelerationStructureFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR, nullptr };
    VkPhysicalDeviceRayTracingPipelineFeaturesKHR physicalDeviceRayTracingPipelineFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR, nullptr };
    VkPhysicalDeviceRayQueryFeaturesKHR physicalDeviceRayQueryFeaturesKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR, nullptr };
    VkPhysicalDeviceMeshShaderFeaturesEXT physicalDeviceMeshShaderFeaturesEXT{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT, nullptr };
    VkPhysicalDeviceFeatures2KHR physicalDeviceFeatures2KHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR, nullptr };

    FeaturesChain() {
        // Initializing all feature structures, number of Features (VkBool32) per structure.
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, size<VkPhysicalDeviceProtectedMemoryFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, size<VkPhysicalDevice16BitStorageFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, size<VkPhysicalDeviceVariablePointersFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, size<VkPhysicalDeviceSamplerYcbcrConversionFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, size<VkPhysicalDeviceMultiviewFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, size<VkPhysicalDeviceShaderDrawParametersFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, size<VkPhysicalDeviceVulkan11Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, size<VkPhysicalDeviceVulkan12Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES, size<VkPhysicalDeviceVulkanMemoryModelFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES, size<VkPhysicalDeviceHostQueryResetFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES, size<VkPhysicalDeviceTimelineSemaphoreFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES, size<VkPhysicalDeviceBufferDeviceAddressFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES, size<VkPhysicalDevice8BitStorageFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES, size<VkPhysicalDeviceShaderAtomicInt64Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES, size<VkPhysicalDeviceShaderFloat16Int8Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES, size<VkPhysicalDeviceDescriptorIndexingFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES, size<VkPhysicalDeviceScalarBlockLayoutFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES, size<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES, size<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES, size<VkPhysicalDeviceImagelessFramebufferFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES, size<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, size<VkPhysicalDeviceVulkan13Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES, size<VkPhysicalDevicePrivateDataFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES, size<VkPhysicalDeviceSynchronization2Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES, size<VkPhysicalDeviceTextureCompressionASTCHDRFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES, size<VkPhysicalDeviceMaintenance4Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES, size<VkPhysicalDeviceShaderTerminateInvocationFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES, size<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES, size<VkPhysicalDevicePipelineCreationCacheControlFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES, size<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES, size<VkPhysicalDeviceImageRobustnessFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES, size<VkPhysicalDeviceSubgroupSizeControlFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES, size<VkPhysicalDeviceInlineUniformBlockFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES, size<VkPhysicalDeviceShaderIntegerDotProductFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES, size<VkPhysicalDeviceDynamicRenderingFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES, size<VkPhysicalDeviceVulkan14Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES, size<VkPhysicalDeviceGlobalPriorityQueryFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES, size<VkPhysicalDeviceIndexTypeUint8Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES, size<VkPhysicalDeviceMaintenance5Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES, size<VkPhysicalDeviceMaintenance6Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES, size<VkPhysicalDeviceHostImageCopyFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES, size<VkPhysicalDeviceShaderSubgroupRotateFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES, size<VkPhysicalDeviceShaderFloatControls2Features>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES, size<VkPhysicalDeviceShaderExpectAssumeFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES, size<VkPhysicalDevicePipelineProtectedAccessFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES, size<VkPhysicalDevicePipelineRobustnessFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES, size<VkPhysicalDeviceLineRasterizationFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES, size<VkPhysicalDeviceVertexAttributeDivisorFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES, size<VkPhysicalDeviceDynamicRenderingLocalReadFeatures>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR, size<VkPhysicalDevicePerformanceQueryFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR, size<VkPhysicalDeviceShaderBfloat16FeaturesKHR>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR, size<VkPhysicalDevicePortabilitySubsetFeaturesKHR>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, size<VkPhysicalDeviceShaderClockFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, size<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR, size<VkPhysicalDeviceShaderConstantDataFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR, size<VkPhysicalDeviceShaderAbortFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR, size<VkPhysicalDeviceShaderQuadControlFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR, size<VkPhysicalDevicePresentWaitFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR, size<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR, size<VkPhysicalDevicePresentIdFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR, size<VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR, size<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR, size<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR, size<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR, size<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR, size<VkPhysicalDeviceShaderUntypedPointersFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR, size<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR, size<VkPhysicalDevicePresentId2FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR, size<VkPhysicalDevicePresentWait2FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR, size<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR, size<VkPhysicalDevicePipelineBinaryFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR, size<VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR, size<VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR, size<VkPhysicalDeviceCooperativeMatrixFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR, size<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR, size<VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR, size<VkPhysicalDeviceVideoDecodeVP9FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR, size<VkPhysicalDeviceVideoMaintenance1FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR, size<VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR, size<VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR, size<VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR, size<VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR, size<VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR, size<VkPhysicalDeviceMaintenance7FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR, size<VkPhysicalDeviceFaultFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR, size<VkPhysicalDeviceMaintenance8FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR, size<VkPhysicalDeviceShaderFmaFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR, size<VkPhysicalDeviceMaintenance9FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR, size<VkPhysicalDeviceVideoMaintenance2FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_FEEDBACK_2_FEATURES_KHR, size<VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR, size<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR, size<VkPhysicalDeviceRobustness2FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR, size<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_KHR, size<VkPhysicalDeviceOpacityMicromapFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR, size<VkPhysicalDeviceMaintenance10FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_KHR, size<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR, size<VkPhysicalDeviceMaintenance11FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_FLAGS_FEATURES_KHR, size<VkPhysicalDeviceExtendedFlagsFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_12_FEATURES_KHR, size<VkPhysicalDeviceMaintenance12FeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT, size<VkPhysicalDeviceTransformFeedbackFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV, size<VkPhysicalDeviceCornerSampledImageFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT, size<VkPhysicalDeviceASTCDecodeFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT, size<VkPhysicalDeviceConditionalRenderingFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, size<VkPhysicalDeviceDepthClipEnableFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG, size<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD, size<VkPhysicalDeviceGpaFeaturesAMD>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX, size<VkPhysicalDeviceShaderEnqueueFeaturesAMDX>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_FEATURES_EXT, size<VkPhysicalDeviceDescriptorHeapFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, size<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV, size<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV, size<VkPhysicalDeviceShadingRateImageFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV, size<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM, size<VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ELAPSED_TIMER_QUERY_FEATURES_QCOM, size<VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV, size<VkPhysicalDeviceMeshShaderFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV, size<VkPhysicalDeviceShaderImageFootprintFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV, size<VkPhysicalDeviceExclusiveScissorFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT, size<VkPhysicalDevicePresentTimingFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL, size<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT, size<VkPhysicalDeviceFragmentDensityMapFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD, size<VkPhysicalDeviceCoherentMemoryFeaturesAMD>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT, size<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT, size<VkPhysicalDeviceMemoryPriorityFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV, size<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT, size<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV, size<VkPhysicalDeviceCooperativeMatrixFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV, size<VkPhysicalDeviceCoverageReductionModeFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT, size<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT, size<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT, size<VkPhysicalDeviceProvokingVertexFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT, size<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT, size<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT, size<VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT, size<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV, size<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV, size<VkPhysicalDeviceInheritedViewportScissorFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT, size<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT, size<VkPhysicalDeviceDepthBiasControlFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT, size<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT, size<VkPhysicalDeviceCustomBorderColorFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT, size<VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV, size<VkPhysicalDevicePresentBarrierFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV, size<VkPhysicalDeviceDiagnosticsConfigFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM, size<VkPhysicalDeviceQueuePerfHintFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_3_FEATURES_QCOM, size<VkPhysicalDeviceImageProcessing3FeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_FEATURES_QCOM, size<VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_FEATURES_EXT, size<VkPhysicalDeviceShaderSplitBarrierFeaturesEXT>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV, size<VkPhysicalDeviceCudaKernelLaunchFeaturesNV>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM, size<VkPhysicalDeviceTileShadingFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT, size<VkPhysicalDeviceDescriptorBufferFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT, size<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD, size<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV, size<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV, size<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT, size<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT, size<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT, size<VkPhysicalDeviceImageCompressionControlFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT, size<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT, size<VkPhysicalDevice4444FormatsFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT, size<VkPhysicalDeviceFaultFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT, size<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT, size<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT, size<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT, size<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT, size<VkPhysicalDeviceAddressBindingReportFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT, size<VkPhysicalDeviceDepthClipControlFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT, size<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI, size<VkPhysicalDeviceSubpassShadingFeaturesHUAWEI>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI, size<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV, size<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT, size<VkPhysicalDevicePipelinePropertiesFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT, size<VkPhysicalDeviceFrameBoundaryFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT, size<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT, size<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT, size<VkPhysicalDeviceColorWriteEnableFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT, size<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE, size<VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT, size<VkPhysicalDeviceImageViewMinLodFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT, size<VkPhysicalDeviceMultiDrawFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT, size<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT, size<VkPhysicalDeviceShaderTileImageFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT, size<VkPhysicalDeviceOpacityMicromapFeaturesEXT>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV, size<VkPhysicalDeviceDisplacementMicromapFeaturesNV>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI, size<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT, size<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT, size<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM, size<VkPhysicalDeviceSchedulingControlsFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT, size<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE, size<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT, size<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM, size<VkPhysicalDeviceRenderPassStripedFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT, size<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV, size<VkPhysicalDeviceCopyMemoryIndirectFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT, size<VkPhysicalDeviceMemoryDecompressionFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV, size<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV, size<VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV, size<VkPhysicalDeviceLinearColorAttachmentFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT, size<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM, size<VkPhysicalDeviceImageProcessingFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT, size<VkPhysicalDeviceNestedCommandBufferFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT, size<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT, size<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM, size<VkPhysicalDeviceTensorFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM, size<VkPhysicalDeviceDescriptorBufferTensorFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT, size<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV, size<VkPhysicalDeviceOpticalFlowFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT, size<VkPhysicalDeviceLegacyDitheringFeaturesEXT>() });
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID, size<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD, size<VkPhysicalDeviceAntiLagFeaturesAMD>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX, size<VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT, size<VkPhysicalDeviceShaderObjectFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM, size<VkPhysicalDeviceTilePropertiesFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC, size<VkPhysicalDeviceAmigoProfilingFeaturesSEC>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM, size<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV, size<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV, size<VkPhysicalDeviceCooperativeVectorFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV, size<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT, size<VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM, size<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT, size<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM, size<VkPhysicalDeviceDataGraphFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM, size<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV, size<VkPhysicalDevicePerStageDescriptorSetFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM, size<VkPhysicalDeviceImageProcessing2FeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM, size<VkPhysicalDeviceCubicWeightsFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM, size<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM, size<VkPhysicalDeviceCubicClampFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT, size<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>() });
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX, size<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV, size<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM, size<VkPhysicalDeviceTileMemoryHeapFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV, size<VkPhysicalDeviceRawAccessChainsFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV, size<VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV, size<VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT, size<VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT, size<VkPhysicalDeviceShaderFloat8FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV, size<VkPhysicalDeviceRayTracingValidationFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV, size<VkPhysicalDeviceClusterAccelerationStructureFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV, size<VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT, size<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA, size<VkPhysicalDeviceImageAlignmentControlFeaturesMESA>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV, size<VkPhysicalDevicePushConstantBankFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT, size<VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT, size<VkPhysicalDeviceDepthClampControlFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI, size<VkPhysicalDeviceHdrVividFeaturesHUAWEI>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV, size<VkPhysicalDeviceCooperativeMatrix2FeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM, size<VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM, size<VkPhysicalDevicePerformanceCountersByRegionFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_FEATURES_ARM, size<VkPhysicalDeviceShaderInstrumentationFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT, size<VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM, size<VkPhysicalDeviceFormatPackFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE, size<VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV, size<VkPhysicalDevicePresentMeteringFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SWAPCHAIN_FEATURES_EXT, size<VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT, size<VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT, size<VkPhysicalDeviceShader64BitIndexingFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT, size<VkPhysicalDeviceCustomResolveFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM, size<VkPhysicalDeviceDataGraphModelFeaturesQCOM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM, size<VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT, size<VkPhysicalDeviceShaderLongVectorFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC, size<VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT, size<VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV, size<VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV>() });
#ifdef VK_ENABLE_BETA_EXTENSIONS
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_LEVEL_ACCELERATION_STRUCTURE_FEATURES_AMDX, size<VkPhysicalDeviceMultiLevelAccelerationStructureFeaturesAMDX>() });
#endif
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_MAINTENANCE_1_FEATURES_EXT, size<VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT, size<VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_LAYOUTS_FEATURES_ARM, size<VkPhysicalDeviceCooperativeMatrixLayoutsFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OCP_MICROSCALING_TYPES_FEATURES_EXT, size<VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE, size<VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC, size<VkPhysicalDeviceThrottleHintFeaturesSEC>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM, size<VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT, size<VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ADDRESS_BINDING_UNRESTRICTED_FEATURES_EXT, size<VkPhysicalDeviceVertexAddressBindingUnrestrictedFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_TILING_CONTROL_FEATURES_EXT, size<VkPhysicalDeviceImageTilingControlFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_DECODE_VECTOR_FEATURES_NV, size<VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_BASE_HANDLE_FEATURES_NV, size<VkPhysicalDevicePrivateDataBaseHandleFeaturesNV>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_ALLOCATION_ALIGNMENT_FEATURES_VALVE, size<VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_SMPTE_ST_209450_FEATURES_GOOGLE, size<VkPhysicalDeviceHdrSmpteSt209450FeaturesGOOGLE>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR, size<VkPhysicalDeviceAccelerationStructureFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR, size<VkPhysicalDeviceRayTracingPipelineFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR, size<VkPhysicalDeviceRayQueryFeaturesKHR>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT, size<VkPhysicalDeviceMeshShaderFeaturesEXT>() });
        this->structureSize.insert({ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR, size<VkPhysicalDeviceFeatures2KHR>() });

        //Initializing the full list of available structure features
        void* pNext = nullptr;
        physicalDeviceProtectedMemoryFeatures.pNext = pNext;
        pNext = &physicalDeviceProtectedMemoryFeatures;
        physicalDevice16BitStorageFeatures.pNext = pNext;
        pNext = &physicalDevice16BitStorageFeatures;
        physicalDeviceVariablePointersFeatures.pNext = pNext;
        pNext = &physicalDeviceVariablePointersFeatures;
        physicalDeviceSamplerYcbcrConversionFeatures.pNext = pNext;
        pNext = &physicalDeviceSamplerYcbcrConversionFeatures;
        physicalDeviceMultiviewFeatures.pNext = pNext;
        pNext = &physicalDeviceMultiviewFeatures;
        physicalDeviceShaderDrawParametersFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderDrawParametersFeatures;
        physicalDeviceVulkan11Features.pNext = pNext;
        pNext = &physicalDeviceVulkan11Features;
        physicalDeviceVulkan12Features.pNext = pNext;
        pNext = &physicalDeviceVulkan12Features;
        physicalDeviceVulkanMemoryModelFeatures.pNext = pNext;
        pNext = &physicalDeviceVulkanMemoryModelFeatures;
        physicalDeviceHostQueryResetFeatures.pNext = pNext;
        pNext = &physicalDeviceHostQueryResetFeatures;
        physicalDeviceTimelineSemaphoreFeatures.pNext = pNext;
        pNext = &physicalDeviceTimelineSemaphoreFeatures;
        physicalDeviceBufferDeviceAddressFeatures.pNext = pNext;
        pNext = &physicalDeviceBufferDeviceAddressFeatures;
        physicalDevice8BitStorageFeatures.pNext = pNext;
        pNext = &physicalDevice8BitStorageFeatures;
        physicalDeviceShaderAtomicInt64Features.pNext = pNext;
        pNext = &physicalDeviceShaderAtomicInt64Features;
        physicalDeviceShaderFloat16Int8Features.pNext = pNext;
        pNext = &physicalDeviceShaderFloat16Int8Features;
        physicalDeviceDescriptorIndexingFeatures.pNext = pNext;
        pNext = &physicalDeviceDescriptorIndexingFeatures;
        physicalDeviceScalarBlockLayoutFeatures.pNext = pNext;
        pNext = &physicalDeviceScalarBlockLayoutFeatures;
        physicalDeviceUniformBufferStandardLayoutFeatures.pNext = pNext;
        pNext = &physicalDeviceUniformBufferStandardLayoutFeatures;
        physicalDeviceShaderSubgroupExtendedTypesFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderSubgroupExtendedTypesFeatures;
        physicalDeviceImagelessFramebufferFeatures.pNext = pNext;
        pNext = &physicalDeviceImagelessFramebufferFeatures;
        physicalDeviceSeparateDepthStencilLayoutsFeatures.pNext = pNext;
        pNext = &physicalDeviceSeparateDepthStencilLayoutsFeatures;
        physicalDeviceVulkan13Features.pNext = pNext;
        pNext = &physicalDeviceVulkan13Features;
        physicalDevicePrivateDataFeatures.pNext = pNext;
        pNext = &physicalDevicePrivateDataFeatures;
        physicalDeviceSynchronization2Features.pNext = pNext;
        pNext = &physicalDeviceSynchronization2Features;
        physicalDeviceTextureCompressionASTCHDRFeatures.pNext = pNext;
        pNext = &physicalDeviceTextureCompressionASTCHDRFeatures;
        physicalDeviceMaintenance4Features.pNext = pNext;
        pNext = &physicalDeviceMaintenance4Features;
        physicalDeviceShaderTerminateInvocationFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderTerminateInvocationFeatures;
        physicalDeviceShaderDemoteToHelperInvocationFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderDemoteToHelperInvocationFeatures;
        physicalDevicePipelineCreationCacheControlFeatures.pNext = pNext;
        pNext = &physicalDevicePipelineCreationCacheControlFeatures;
        physicalDeviceZeroInitializeWorkgroupMemoryFeatures.pNext = pNext;
        pNext = &physicalDeviceZeroInitializeWorkgroupMemoryFeatures;
        physicalDeviceImageRobustnessFeatures.pNext = pNext;
        pNext = &physicalDeviceImageRobustnessFeatures;
        physicalDeviceSubgroupSizeControlFeatures.pNext = pNext;
        pNext = &physicalDeviceSubgroupSizeControlFeatures;
        physicalDeviceInlineUniformBlockFeatures.pNext = pNext;
        pNext = &physicalDeviceInlineUniformBlockFeatures;
        physicalDeviceShaderIntegerDotProductFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderIntegerDotProductFeatures;
        physicalDeviceDynamicRenderingFeatures.pNext = pNext;
        pNext = &physicalDeviceDynamicRenderingFeatures;
        physicalDeviceVulkan14Features.pNext = pNext;
        pNext = &physicalDeviceVulkan14Features;
        physicalDeviceGlobalPriorityQueryFeatures.pNext = pNext;
        pNext = &physicalDeviceGlobalPriorityQueryFeatures;
        physicalDeviceIndexTypeUint8Features.pNext = pNext;
        pNext = &physicalDeviceIndexTypeUint8Features;
        physicalDeviceMaintenance5Features.pNext = pNext;
        pNext = &physicalDeviceMaintenance5Features;
        physicalDeviceMaintenance6Features.pNext = pNext;
        pNext = &physicalDeviceMaintenance6Features;
        physicalDeviceHostImageCopyFeatures.pNext = pNext;
        pNext = &physicalDeviceHostImageCopyFeatures;
        physicalDeviceShaderSubgroupRotateFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderSubgroupRotateFeatures;
        physicalDeviceShaderFloatControls2Features.pNext = pNext;
        pNext = &physicalDeviceShaderFloatControls2Features;
        physicalDeviceShaderExpectAssumeFeatures.pNext = pNext;
        pNext = &physicalDeviceShaderExpectAssumeFeatures;
        physicalDevicePipelineProtectedAccessFeatures.pNext = pNext;
        pNext = &physicalDevicePipelineProtectedAccessFeatures;
        physicalDevicePipelineRobustnessFeatures.pNext = pNext;
        pNext = &physicalDevicePipelineRobustnessFeatures;
        physicalDeviceLineRasterizationFeatures.pNext = pNext;
        pNext = &physicalDeviceLineRasterizationFeatures;
        physicalDeviceVertexAttributeDivisorFeatures.pNext = pNext;
        pNext = &physicalDeviceVertexAttributeDivisorFeatures;
        physicalDeviceDynamicRenderingLocalReadFeatures.pNext = pNext;
        pNext = &physicalDeviceDynamicRenderingLocalReadFeatures;
        physicalDevicePerformanceQueryFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePerformanceQueryFeaturesKHR;
        physicalDeviceShaderBfloat16FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderBfloat16FeaturesKHR;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDevicePortabilitySubsetFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePortabilitySubsetFeaturesKHR;
#endif
        physicalDeviceShaderClockFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderClockFeaturesKHR;
        physicalDeviceFragmentShadingRateFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceFragmentShadingRateFeaturesKHR;
        physicalDeviceShaderConstantDataFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderConstantDataFeaturesKHR;
        physicalDeviceShaderAbortFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderAbortFeaturesKHR;
        physicalDeviceShaderQuadControlFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderQuadControlFeaturesKHR;
        physicalDevicePresentWaitFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePresentWaitFeaturesKHR;
        physicalDevicePipelineExecutablePropertiesFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePipelineExecutablePropertiesFeaturesKHR;
        physicalDevicePresentIdFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePresentIdFeaturesKHR;
        physicalDeviceDeviceAddressCommandsFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceDeviceAddressCommandsFeaturesKHR;
        physicalDeviceFragmentShaderBarycentricFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceFragmentShaderBarycentricFeaturesKHR;
        physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
        physicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
        physicalDeviceRayTracingMaintenance1FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceRayTracingMaintenance1FeaturesKHR;
        physicalDeviceShaderUntypedPointersFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderUntypedPointersFeaturesKHR;
        physicalDeviceShaderMaximalReconvergenceFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderMaximalReconvergenceFeaturesKHR;
        physicalDevicePresentId2FeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePresentId2FeaturesKHR;
        physicalDevicePresentWait2FeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePresentWait2FeaturesKHR;
        physicalDeviceRayTracingPositionFetchFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceRayTracingPositionFetchFeaturesKHR;
        physicalDevicePipelineBinaryFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePipelineBinaryFeaturesKHR;
        physicalDeviceSwapchainMaintenance1FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceSwapchainMaintenance1FeaturesKHR;
        physicalDeviceInternallySynchronizedQueuesFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceInternallySynchronizedQueuesFeaturesKHR;
        physicalDeviceCooperativeMatrixFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixFeaturesKHR;
        physicalDeviceComputeShaderDerivativesFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceComputeShaderDerivativesFeaturesKHR;
        physicalDeviceVideoEncodeAV1FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoEncodeAV1FeaturesKHR;
        physicalDeviceVideoDecodeVP9FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoDecodeVP9FeaturesKHR;
        physicalDeviceVideoMaintenance1FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoMaintenance1FeaturesKHR;
        physicalDeviceUnifiedImageLayoutsFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceUnifiedImageLayoutsFeaturesKHR;
        physicalDeviceCopyMemoryIndirectFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceCopyMemoryIndirectFeaturesKHR;
        physicalDeviceVideoEncodeIntraRefreshFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoEncodeIntraRefreshFeaturesKHR;
        physicalDeviceVideoEncodeQuantizationMapFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoEncodeQuantizationMapFeaturesKHR;
        physicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR;
        physicalDeviceMaintenance7FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance7FeaturesKHR;
        physicalDeviceFaultFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceFaultFeaturesKHR;
        physicalDeviceMaintenance8FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance8FeaturesKHR;
        physicalDeviceShaderFmaFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceShaderFmaFeaturesKHR;
        physicalDeviceMaintenance9FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance9FeaturesKHR;
        physicalDeviceVideoMaintenance2FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoMaintenance2FeaturesKHR;
        physicalDeviceVideoEncodeFeedback2FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceVideoEncodeFeedback2FeaturesKHR;
        physicalDeviceDepthClampZeroOneFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceDepthClampZeroOneFeaturesKHR;
        physicalDeviceRobustness2FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceRobustness2FeaturesKHR;
        physicalDevicePresentModeFifoLatestReadyFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePresentModeFifoLatestReadyFeaturesKHR;
        physicalDeviceOpacityMicromapFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceOpacityMicromapFeaturesKHR;
        physicalDeviceMaintenance10FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance10FeaturesKHR;
        physicalDevicePipelineLibraryGroupHandlesFeaturesKHR.pNext = pNext;
        pNext = &physicalDevicePipelineLibraryGroupHandlesFeaturesKHR;
        physicalDeviceMaintenance11FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance11FeaturesKHR;
        physicalDeviceExtendedFlagsFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceExtendedFlagsFeaturesKHR;
        physicalDeviceMaintenance12FeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceMaintenance12FeaturesKHR;
        physicalDeviceTransformFeedbackFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceTransformFeedbackFeaturesEXT;
        physicalDeviceCornerSampledImageFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCornerSampledImageFeaturesNV;
        physicalDeviceASTCDecodeFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceASTCDecodeFeaturesEXT;
        physicalDeviceConditionalRenderingFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceConditionalRenderingFeaturesEXT;
        physicalDeviceDepthClipEnableFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDepthClipEnableFeaturesEXT;
        physicalDeviceRelaxedLineRasterizationFeaturesIMG.pNext = pNext;
        pNext = &physicalDeviceRelaxedLineRasterizationFeaturesIMG;
        physicalDeviceGpaFeaturesAMD.pNext = pNext;
        pNext = &physicalDeviceGpaFeaturesAMD;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDeviceShaderEnqueueFeaturesAMDX.pNext = pNext;
        pNext = &physicalDeviceShaderEnqueueFeaturesAMDX;
#endif
        physicalDeviceDescriptorHeapFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDescriptorHeapFeaturesEXT;
        physicalDeviceBlendOperationAdvancedFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceBlendOperationAdvancedFeaturesEXT;
        physicalDeviceShaderSMBuiltinsFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceShaderSMBuiltinsFeaturesNV;
        physicalDeviceShadingRateImageFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceShadingRateImageFeaturesNV;
        physicalDeviceRepresentativeFragmentTestFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRepresentativeFragmentTestFeaturesNV;
        physicalDeviceCooperativeMatrixConversionFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixConversionFeaturesQCOM;
        physicalDeviceElapsedTimerQueryFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceElapsedTimerQueryFeaturesQCOM;
        physicalDeviceMeshShaderFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceMeshShaderFeaturesNV;
        physicalDeviceShaderImageFootprintFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceShaderImageFootprintFeaturesNV;
        physicalDeviceExclusiveScissorFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceExclusiveScissorFeaturesNV;
        physicalDevicePresentTimingFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePresentTimingFeaturesEXT;
        physicalDeviceShaderIntegerFunctions2FeaturesINTEL.pNext = pNext;
        pNext = &physicalDeviceShaderIntegerFunctions2FeaturesINTEL;
        physicalDeviceFragmentDensityMapFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFragmentDensityMapFeaturesEXT;
        physicalDeviceCoherentMemoryFeaturesAMD.pNext = pNext;
        pNext = &physicalDeviceCoherentMemoryFeaturesAMD;
        physicalDeviceShaderImageAtomicInt64FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderImageAtomicInt64FeaturesEXT;
        physicalDeviceMemoryPriorityFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMemoryPriorityFeaturesEXT;
        physicalDeviceDedicatedAllocationImageAliasingFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
        physicalDeviceBufferDeviceAddressFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceBufferDeviceAddressFeaturesEXT;
        physicalDeviceCooperativeMatrixFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixFeaturesNV;
        physicalDeviceCoverageReductionModeFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCoverageReductionModeFeaturesNV;
        physicalDeviceFragmentShaderInterlockFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFragmentShaderInterlockFeaturesEXT;
        physicalDeviceYcbcrImageArraysFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceYcbcrImageArraysFeaturesEXT;
        physicalDeviceProvokingVertexFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceProvokingVertexFeaturesEXT;
        physicalDeviceShaderAtomicFloatFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderAtomicFloatFeaturesEXT;
        physicalDeviceExtendedDynamicStateFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceExtendedDynamicStateFeaturesEXT;
        physicalDeviceMapMemoryPlacedFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMapMemoryPlacedFeaturesEXT;
        physicalDeviceShaderAtomicFloat2FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderAtomicFloat2FeaturesEXT;
        physicalDeviceDeviceGeneratedCommandsFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDeviceGeneratedCommandsFeaturesNV;
        physicalDeviceInheritedViewportScissorFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceInheritedViewportScissorFeaturesNV;
        physicalDeviceTexelBufferAlignmentFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceTexelBufferAlignmentFeaturesEXT;
        physicalDeviceDepthBiasControlFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDepthBiasControlFeaturesEXT;
        physicalDeviceDeviceMemoryReportFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDeviceMemoryReportFeaturesEXT;
        physicalDeviceCustomBorderColorFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceCustomBorderColorFeaturesEXT;
        physicalDeviceTextureCompressionASTC3DFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceTextureCompressionASTC3DFeaturesEXT;
        physicalDevicePresentBarrierFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePresentBarrierFeaturesNV;
        physicalDeviceDiagnosticsConfigFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDiagnosticsConfigFeaturesNV;
        physicalDeviceQueuePerfHintFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceQueuePerfHintFeaturesQCOM;
        physicalDeviceImageProcessing3FeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceImageProcessing3FeaturesQCOM;
        physicalDeviceShaderMultipleWaitQueuesFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceShaderMultipleWaitQueuesFeaturesQCOM;
        physicalDeviceShaderSplitBarrierFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderSplitBarrierFeaturesEXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDeviceCudaKernelLaunchFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCudaKernelLaunchFeaturesNV;
#endif
        physicalDeviceTileShadingFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceTileShadingFeaturesQCOM;
        physicalDeviceDescriptorBufferFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDescriptorBufferFeaturesEXT;
        physicalDeviceGraphicsPipelineLibraryFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceGraphicsPipelineLibraryFeaturesEXT;
        physicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD.pNext = pNext;
        pNext = &physicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
        physicalDeviceFragmentShadingRateEnumsFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceFragmentShadingRateEnumsFeaturesNV;
        physicalDeviceRayTracingMotionBlurFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRayTracingMotionBlurFeaturesNV;
        physicalDeviceYcbcr2Plane444FormatsFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
        physicalDeviceFragmentDensityMap2FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFragmentDensityMap2FeaturesEXT;
        physicalDeviceImageCompressionControlFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImageCompressionControlFeaturesEXT;
        physicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
        physicalDevice4444FormatsFeaturesEXT.pNext = pNext;
        pNext = &physicalDevice4444FormatsFeaturesEXT;
        physicalDeviceFaultFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFaultFeaturesEXT;
        physicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
        physicalDeviceRGBA10X6FormatsFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceRGBA10X6FormatsFeaturesEXT;
        physicalDeviceMutableDescriptorTypeFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMutableDescriptorTypeFeaturesEXT;
        physicalDeviceVertexInputDynamicStateFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceVertexInputDynamicStateFeaturesEXT;
        physicalDeviceAddressBindingReportFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceAddressBindingReportFeaturesEXT;
        physicalDeviceDepthClipControlFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDepthClipControlFeaturesEXT;
        physicalDevicePrimitiveTopologyListRestartFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePrimitiveTopologyListRestartFeaturesEXT;
        physicalDeviceSubpassShadingFeaturesHUAWEI.pNext = pNext;
        pNext = &physicalDeviceSubpassShadingFeaturesHUAWEI;
        physicalDeviceInvocationMaskFeaturesHUAWEI.pNext = pNext;
        pNext = &physicalDeviceInvocationMaskFeaturesHUAWEI;
        physicalDeviceExternalMemoryRDMAFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceExternalMemoryRDMAFeaturesNV;
        physicalDevicePipelinePropertiesFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePipelinePropertiesFeaturesEXT;
        physicalDeviceFrameBoundaryFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFrameBoundaryFeaturesEXT;
        physicalDeviceMultisampledRenderToSingleSampledFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
        physicalDeviceExtendedDynamicState2FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceExtendedDynamicState2FeaturesEXT;
        physicalDeviceColorWriteEnableFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceColorWriteEnableFeaturesEXT;
        physicalDevicePrimitivesGeneratedQueryFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePrimitivesGeneratedQueryFeaturesEXT;
        physicalDeviceVideoEncodeRgbConversionFeaturesVALVE.pNext = pNext;
        pNext = &physicalDeviceVideoEncodeRgbConversionFeaturesVALVE;
        physicalDeviceImageViewMinLodFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImageViewMinLodFeaturesEXT;
        physicalDeviceMultiDrawFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMultiDrawFeaturesEXT;
        physicalDeviceImage2DViewOf3DFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImage2DViewOf3DFeaturesEXT;
        physicalDeviceShaderTileImageFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderTileImageFeaturesEXT;
        physicalDeviceOpacityMicromapFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceOpacityMicromapFeaturesEXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDeviceDisplacementMicromapFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDisplacementMicromapFeaturesNV;
#endif
        physicalDeviceClusterCullingShaderFeaturesHUAWEI.pNext = pNext;
        pNext = &physicalDeviceClusterCullingShaderFeaturesHUAWEI;
        physicalDeviceBorderColorSwizzleFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceBorderColorSwizzleFeaturesEXT;
        physicalDevicePageableDeviceLocalMemoryFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePageableDeviceLocalMemoryFeaturesEXT;
        physicalDeviceSchedulingControlsFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceSchedulingControlsFeaturesARM;
        physicalDeviceImageSlicedViewOf3DFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImageSlicedViewOf3DFeaturesEXT;
        physicalDeviceDescriptorSetHostMappingFeaturesVALVE.pNext = pNext;
        pNext = &physicalDeviceDescriptorSetHostMappingFeaturesVALVE;
        physicalDeviceNonSeamlessCubeMapFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceNonSeamlessCubeMapFeaturesEXT;
        physicalDeviceRenderPassStripedFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceRenderPassStripedFeaturesARM;
        physicalDeviceFragmentDensityMapOffsetFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceFragmentDensityMapOffsetFeaturesEXT;
        physicalDeviceCopyMemoryIndirectFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCopyMemoryIndirectFeaturesNV;
        physicalDeviceMemoryDecompressionFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMemoryDecompressionFeaturesEXT;
        physicalDeviceDeviceGeneratedCommandsComputeFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
        physicalDeviceRayTracingLinearSweptSpheresFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRayTracingLinearSweptSpheresFeaturesNV;
        physicalDeviceLinearColorAttachmentFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceLinearColorAttachmentFeaturesNV;
        physicalDeviceImageCompressionControlSwapchainFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImageCompressionControlSwapchainFeaturesEXT;
        physicalDeviceImageProcessingFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceImageProcessingFeaturesQCOM;
        physicalDeviceNestedCommandBufferFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceNestedCommandBufferFeaturesEXT;
        physicalDeviceExtendedDynamicState3FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceExtendedDynamicState3FeaturesEXT;
        physicalDeviceSubpassMergeFeedbackFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceSubpassMergeFeedbackFeaturesEXT;
        physicalDeviceTensorFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceTensorFeaturesARM;
        physicalDeviceDescriptorBufferTensorFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceDescriptorBufferTensorFeaturesARM;
        physicalDeviceShaderModuleIdentifierFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderModuleIdentifierFeaturesEXT;
        physicalDeviceOpticalFlowFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceOpticalFlowFeaturesNV;
        physicalDeviceLegacyDitheringFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceLegacyDitheringFeaturesEXT;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        physicalDeviceExternalFormatResolveFeaturesANDROID.pNext = pNext;
        pNext = &physicalDeviceExternalFormatResolveFeaturesANDROID;
#endif
        physicalDeviceAntiLagFeaturesAMD.pNext = pNext;
        pNext = &physicalDeviceAntiLagFeaturesAMD;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDeviceDenseGeometryFormatFeaturesAMDX.pNext = pNext;
        pNext = &physicalDeviceDenseGeometryFormatFeaturesAMDX;
#endif
        physicalDeviceShaderObjectFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderObjectFeaturesEXT;
        physicalDeviceTilePropertiesFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceTilePropertiesFeaturesQCOM;
        physicalDeviceAmigoProfilingFeaturesSEC.pNext = pNext;
        pNext = &physicalDeviceAmigoProfilingFeaturesSEC;
        physicalDeviceMultiviewPerViewViewportsFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceMultiviewPerViewViewportsFeaturesQCOM;
        physicalDeviceRayTracingInvocationReorderFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRayTracingInvocationReorderFeaturesNV;
        physicalDeviceCooperativeVectorFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCooperativeVectorFeaturesNV;
        physicalDeviceExtendedSparseAddressSpaceFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceExtendedSparseAddressSpaceFeaturesNV;
        physicalDeviceLegacyVertexAttributesFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceLegacyVertexAttributesFeaturesEXT;
        physicalDeviceShaderCoreBuiltinsFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceShaderCoreBuiltinsFeaturesARM;
        physicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;
        physicalDeviceDataGraphFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceDataGraphFeaturesARM;
        physicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
        physicalDevicePerStageDescriptorSetFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePerStageDescriptorSetFeaturesNV;
        physicalDeviceImageProcessing2FeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceImageProcessing2FeaturesQCOM;
        physicalDeviceCubicWeightsFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceCubicWeightsFeaturesQCOM;
        physicalDeviceYcbcrDegammaFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceYcbcrDegammaFeaturesQCOM;
        physicalDeviceCubicClampFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceCubicClampFeaturesQCOM;
        physicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        physicalDeviceExternalMemoryScreenBufferFeaturesQNX.pNext = pNext;
        pNext = &physicalDeviceExternalMemoryScreenBufferFeaturesQNX;
#endif
        physicalDeviceDescriptorPoolOverallocationFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceDescriptorPoolOverallocationFeaturesNV;
        physicalDeviceTileMemoryHeapFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceTileMemoryHeapFeaturesQCOM;
        physicalDeviceRawAccessChainsFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRawAccessChainsFeaturesNV;
        physicalDeviceCommandBufferInheritanceFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCommandBufferInheritanceFeaturesNV;
        physicalDeviceShaderAtomicFloat16VectorFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceShaderAtomicFloat16VectorFeaturesNV;
        physicalDeviceShaderReplicatedCompositesFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderReplicatedCompositesFeaturesEXT;
        physicalDeviceShaderFloat8FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderFloat8FeaturesEXT;
        physicalDeviceRayTracingValidationFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceRayTracingValidationFeaturesNV;
        physicalDeviceClusterAccelerationStructureFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceClusterAccelerationStructureFeaturesNV;
        physicalDevicePartitionedAccelerationStructureFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePartitionedAccelerationStructureFeaturesNV;
        physicalDeviceDeviceGeneratedCommandsFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDeviceGeneratedCommandsFeaturesEXT;
        physicalDeviceImageAlignmentControlFeaturesMESA.pNext = pNext;
        pNext = &physicalDeviceImageAlignmentControlFeaturesMESA;
        physicalDevicePushConstantBankFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePushConstantBankFeaturesNV;
        physicalDeviceRayTracingInvocationReorderFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceRayTracingInvocationReorderFeaturesEXT;
        physicalDeviceDepthClampControlFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceDepthClampControlFeaturesEXT;
        physicalDeviceHdrVividFeaturesHUAWEI.pNext = pNext;
        pNext = &physicalDeviceHdrVividFeaturesHUAWEI;
        physicalDeviceCooperativeMatrix2FeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrix2FeaturesNV;
        physicalDevicePipelineOpacityMicromapFeaturesARM.pNext = pNext;
        pNext = &physicalDevicePipelineOpacityMicromapFeaturesARM;
        physicalDevicePerformanceCountersByRegionFeaturesARM.pNext = pNext;
        pNext = &physicalDevicePerformanceCountersByRegionFeaturesARM;
        physicalDeviceShaderInstrumentationFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceShaderInstrumentationFeaturesARM;
        physicalDeviceVertexAttributeRobustnessFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceVertexAttributeRobustnessFeaturesEXT;
        physicalDeviceFormatPackFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceFormatPackFeaturesARM;
        physicalDeviceFragmentDensityMapLayeredFeaturesVALVE.pNext = pNext;
        pNext = &physicalDeviceFragmentDensityMapLayeredFeaturesVALVE;
        physicalDevicePresentMeteringFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePresentMeteringFeaturesNV;
        physicalDeviceMultisampledRenderToSwapchainFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMultisampledRenderToSwapchainFeaturesEXT;
        physicalDeviceZeroInitializeDeviceMemoryFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceZeroInitializeDeviceMemoryFeaturesEXT;
        physicalDeviceShader64BitIndexingFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShader64BitIndexingFeaturesEXT;
        physicalDeviceCustomResolveFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceCustomResolveFeaturesEXT;
        physicalDeviceDataGraphModelFeaturesQCOM.pNext = pNext;
        pNext = &physicalDeviceDataGraphModelFeaturesQCOM;
        physicalDeviceDataGraphOpticalFlowFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceDataGraphOpticalFlowFeaturesARM;
        physicalDeviceShaderLongVectorFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderLongVectorFeaturesEXT;
        physicalDevicePipelineCacheIncrementalModeFeaturesSEC.pNext = pNext;
        pNext = &physicalDevicePipelineCacheIncrementalModeFeaturesSEC;
        physicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT;
        physicalDeviceComputeOccupancyPriorityFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceComputeOccupancyPriorityFeaturesNV;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        physicalDeviceMultiLevelAccelerationStructureFeaturesAMDX.pNext = pNext;
        pNext = &physicalDeviceMultiLevelAccelerationStructureFeaturesAMDX;
#endif
        physicalDeviceCooperativeMatrixMaintenance1FeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixMaintenance1FeaturesEXT;
        physicalDeviceShaderSubgroupPartitionedFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderSubgroupPartitionedFeaturesEXT;
        physicalDeviceCooperativeMatrixLayoutsFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixLayoutsFeaturesARM;
        physicalDeviceShaderOCPMicroscalingTypesFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceShaderOCPMicroscalingTypesFeaturesEXT;
        physicalDeviceShaderMixedFloatDotProductFeaturesVALVE.pNext = pNext;
        pNext = &physicalDeviceShaderMixedFloatDotProductFeaturesVALVE;
        physicalDeviceThrottleHintFeaturesSEC.pNext = pNext;
        pNext = &physicalDeviceThrottleHintFeaturesSEC;
        physicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM.pNext = pNext;
        pNext = &physicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM;
        physicalDevicePrimitiveRestartIndexFeaturesEXT.pNext = pNext;
        pNext = &physicalDevicePrimitiveRestartIndexFeaturesEXT;
        physicalDeviceVertexAddressBindingUnrestrictedFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceVertexAddressBindingUnrestrictedFeaturesEXT;
        physicalDeviceImageTilingControlFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceImageTilingControlFeaturesEXT;
        physicalDeviceCooperativeMatrixDecodeVectorFeaturesNV.pNext = pNext;
        pNext = &physicalDeviceCooperativeMatrixDecodeVectorFeaturesNV;
        physicalDevicePrivateDataBaseHandleFeaturesNV.pNext = pNext;
        pNext = &physicalDevicePrivateDataBaseHandleFeaturesNV;
        physicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE.pNext = pNext;
        pNext = &physicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE;
        physicalDeviceHdrSmpteSt209450FeaturesGOOGLE.pNext = pNext;
        pNext = &physicalDeviceHdrSmpteSt209450FeaturesGOOGLE;
        physicalDeviceAccelerationStructureFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceAccelerationStructureFeaturesKHR;
        physicalDeviceRayTracingPipelineFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceRayTracingPipelineFeaturesKHR;
        physicalDeviceRayQueryFeaturesKHR.pNext = pNext;
        pNext = &physicalDeviceRayQueryFeaturesKHR;
        physicalDeviceMeshShaderFeaturesEXT.pNext = pNext;
        pNext = &physicalDeviceMeshShaderFeaturesEXT;
        physicalDeviceFeatures2KHR.pNext = pNext;

    }


    VkPhysicalDeviceFeatures2KHR requiredFeaturesChain{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR, nullptr};
    VkBaseOutStructure* current = nullptr;

    void ApplyRobustness(const VpDeviceCreateInfo* pCreateInfo) {
#ifdef VK_VERSION_1_1
        VkPhysicalDeviceFeatures2KHR* pFeatures2 = static_cast<VkPhysicalDeviceFeatures2KHR*>(
            vpGetStructure(&this->requiredFeaturesChain, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR));
        if (pFeatures2 != nullptr && (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_BUFFER_ACCESS_BIT)) {
            pFeatures2->features.robustBufferAccess = VK_FALSE;
        }
#endif

#ifdef VK_EXT_robustness2
        VkPhysicalDeviceRobustness2FeaturesEXT* pRobustness2FeaturesEXT = static_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(
            vpGetStructure(&this->requiredFeaturesChain, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT));
        if (pRobustness2FeaturesEXT != nullptr) {
            if (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_BUFFER_ACCESS_BIT) {
                pRobustness2FeaturesEXT->robustBufferAccess2 = VK_FALSE;
            }
            if (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_IMAGE_ACCESS_BIT) {
                pRobustness2FeaturesEXT->robustImageAccess2 = VK_FALSE;
            }
        }
#endif
#ifdef VK_EXT_image_robustness
        VkPhysicalDeviceImageRobustnessFeaturesEXT* pImageRobustnessFeaturesEXT =
            static_cast<VkPhysicalDeviceImageRobustnessFeaturesEXT*>(vpGetStructure(
                &this->requiredFeaturesChain, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT));
        if (pImageRobustnessFeaturesEXT != nullptr && (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_IMAGE_ACCESS_BIT)) {
            pImageRobustnessFeaturesEXT->robustImageAccess = VK_FALSE;
        }
#endif
#ifdef VK_VERSION_1_3
        VkPhysicalDeviceVulkan13Features* pVulkan13Features = static_cast<VkPhysicalDeviceVulkan13Features*>(
            vpGetStructure(&this->requiredFeaturesChain, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES));
        if (pVulkan13Features != nullptr && (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_IMAGE_ACCESS_BIT)) {
            pVulkan13Features->robustImageAccess = VK_FALSE;
        }
#endif
    }

    void ApplyFeatures(const VpDeviceCreateInfo* pCreateInfo) {
        const std::size_t offset = sizeof(VkBaseOutStructure);
        const VkBaseOutStructure* q = reinterpret_cast<const VkBaseOutStructure*>(pCreateInfo->pCreateInfo->pNext);
        while (q) {
            const std::size_t count = this->structureSize[q->sType];
            for (std::size_t index = 0; index < count; ++index) {
                const VkBaseOutStructure* pInputStruct = reinterpret_cast<const VkBaseOutStructure*>(q);
                VkBaseOutStructure* pOutputStruct = reinterpret_cast<VkBaseOutStructure*>(detail::vpGetStructure(&this->requiredFeaturesChain, q->sType));
                const uint8_t* pInputData = reinterpret_cast<const uint8_t*>(pInputStruct) + offset;
                uint8_t* pOutputData = reinterpret_cast<uint8_t*>(pOutputStruct) + offset;
                const VkBool32* input = reinterpret_cast<const VkBool32*>(pInputData);
                VkBool32* output = reinterpret_cast<VkBool32*>(pOutputData);

                output[index] = (output[index] == VK_TRUE || input[index] == VK_TRUE) ? VK_TRUE : VK_FALSE;
            }
            q = q->pNext;
        }

        this->ApplyRobustness(pCreateInfo);
    }

    void PushBack(VkBaseOutStructure* found) {
        VkBaseOutStructure* last = reinterpret_cast<VkBaseOutStructure*>(&requiredFeaturesChain);
        while (last->pNext != nullptr) {
            last = last->pNext;
        }
        last->pNext = found;
    }

    void Build(const std::vector<VkStructureType>& requiredList) {
        for (std::size_t i = 0, n = requiredList.size(); i < n; ++i) {
            const VkStructureType sType = requiredList[i];
            if (sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR) {
                continue;
            }

            VkBaseOutStructure* found = vpExtractStructure(&physicalDeviceFeatures2KHR, sType);
            if (found == nullptr) {
                continue;
            }

            PushBack(found);
        }
    }
}; // struct FeaturesChain

VPAPI_ATTR const VpProfileDesc* vpGetProfileDesc(const char profileName[VP_MAX_PROFILE_NAME_SIZE]) {
    for (uint32_t profileIndex = 0; profileIndex < profileCount; ++profileIndex) {
        if (strncmp(profiles[profileIndex].props.profileName, profileName, VP_MAX_PROFILE_NAME_SIZE) == 0) {
            return &profiles[profileIndex];
        }
    }
    return nullptr;
}

VPAPI_ATTR std::vector<VpProfileProperties> GatherProfiles(const VpProfileProperties& profile, const char* pBlockName = nullptr) {
    std::vector<VpProfileProperties> gatheredProfiles;

    if (pBlockName == nullptr) {
        const detail::VpProfileDesc* profileDesc = detail::vpGetProfileDesc(profile.profileName);
        if (profileDesc != nullptr) {
            for (uint32_t profileIndex = 0; profileIndex < profileDesc->requiredProfileCount; ++profileIndex) {
                gatheredProfiles.push_back(profileDesc->pRequiredProfiles[profileIndex]);
            }
        }
    }

    gatheredProfiles.push_back(profile);

    return gatheredProfiles;
}

VPAPI_ATTR bool vpCheckVersion(uint32_t actual, uint32_t expected) {
    uint32_t actualMajor = VK_API_VERSION_MAJOR(actual);
    uint32_t actualMinor = VK_API_VERSION_MINOR(actual);
    uint32_t expectedMajor = VK_API_VERSION_MAJOR(expected);
    uint32_t expectedMinor = VK_API_VERSION_MINOR(expected);
    return actualMajor > expectedMajor || (actualMajor == expectedMajor && actualMinor >= expectedMinor);
}

VPAPI_ATTR bool HasExtension(const std::vector<VkExtensionProperties>& list, const VkExtensionProperties& element) {
    for (std::size_t i = 0, n = list.size(); i < n; ++i) {
        if (strcmp(list[i].extensionName, element.extensionName) == 0) {
            return true;
        }
    }

    return false;
}

VPAPI_ATTR bool CheckExtension(const VkExtensionProperties* supportedProperties, size_t supportedSize, const char *requestedExtension) {
    bool found = false;
    for (size_t i = 0, n = supportedSize; i < n; ++i) {
        if (strcmp(supportedProperties[i].extensionName, requestedExtension) == 0) {
            found = true;
            break;
            // Drivers don't actually update their spec version, so we cannot rely on this
            // if (supportedProperties[i].specVersion >= expectedVersion) found = true;
        }
    }
    VP_DEBUG_COND_MSGF(!found, "Unsupported extension: %s", requestedExtension);
    return found;
}

VPAPI_ATTR bool CheckExtension(const std::vector<const char*>& extensions, const char* extension) {
    for (const char* c : extensions) {
        if (strcmp(c, extension) == 0) {
            return true;
        }
    }
    return false;
}

VPAPI_ATTR void GetExtensions(uint32_t extensionCount, const VkExtensionProperties *pExtensions, std::vector<const char *> &extensions) {
    for (uint32_t ext_index = 0; ext_index < extensionCount; ++ext_index) {
        if (CheckExtension(extensions, pExtensions[ext_index].extensionName)) {
            continue;
        }
        extensions.push_back(pExtensions[ext_index].extensionName);
    }
}

VPAPI_ATTR std::vector<VpBlockProperties> GatherBlocks(
    uint32_t enabledFullProfileCount, const VpProfileProperties* pEnabledFullProfiles,
    uint32_t enabledProfileBlockCount, const VpBlockProperties* pEnabledProfileBlocks) {
    std::vector<VpBlockProperties> results;

    for (std::size_t profile_index = 0; profile_index < enabledFullProfileCount; ++profile_index) {
        const std::vector<VpProfileProperties>& gathered_profiles = GatherProfiles(pEnabledFullProfiles[profile_index]);

        for (std::size_t gathered_index = 0; gathered_index < gathered_profiles.size(); ++gathered_index) {
            VpBlockProperties block{gathered_profiles[gathered_index], 0, ""};
            results.push_back(block);
        }
    }

    for (std::size_t block_index = 0; block_index < enabledProfileBlockCount; ++block_index) {
        results.push_back(pEnabledProfileBlocks[block_index]);
    }

    return results;
}

VPAPI_ATTR VkResult vpGetInstanceProfileSupportSingleProfile(
    uint32_t                                    api_version,
    const std::vector<VkExtensionProperties>&   supported_extensions,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported,
    std::vector<VpBlockProperties>&             supportedBlocks,
    std::vector<VpBlockProperties>&             unsupportedBlocks) {
    assert(pProfile != nullptr);

    const detail::VpProfileDesc* pProfileDesc = vpGetProfileDesc(pProfile->profileName);
    if (pProfileDesc == nullptr) {
        *pSupported = VK_FALSE;
        return VK_ERROR_UNKNOWN;
    }

    VpBlockProperties block{*pProfile, api_version};

    if (pProfileDesc->props.specVersion < pProfile->specVersion) {
        *pSupported = VK_FALSE;
        unsupportedBlocks.push_back(block);
    }

    // Required API version is built in root profile, not need to check dependent profile API versions
    if (api_version != 0) {
        if (!vpCheckVersion(api_version, pProfileDesc->minApiVersion)) {
            VP_DEBUG_MSGF("Unsupported Profile API version %u.%u.%u on a Vulkan system with version %u.%u.%u", VK_API_VERSION_MAJOR(pProfileDesc->minApiVersion), VK_API_VERSION_MINOR(pProfileDesc->minApiVersion), VK_API_VERSION_PATCH(pProfileDesc->minApiVersion), VK_API_VERSION_MAJOR(api_version), VK_API_VERSION_MINOR(api_version), VK_API_VERSION_PATCH(api_version));

            *pSupported = VK_FALSE;
            unsupportedBlocks.push_back(block);
        }
    }

    for (uint32_t capability_index = 0; capability_index < pProfileDesc->requiredCapabilityCount; ++capability_index) {
        const VpCapabilitiesDesc& capabilities_desc = pProfileDesc->pRequiredCapabilities[capability_index];

        VkBool32 supported_capabilities = VK_FALSE;
        for (uint32_t variant_index = 0; variant_index < capabilities_desc.variantCount; ++variant_index) {
            const VpVariantDesc& variant_desc = capabilities_desc.pVariants[variant_index];

            // The 'depends' condition of a capability block is evaluated against a physical device:
            // the capability block requirements are not instance requirements
            if (variant_desc.pfnDepends != nullptr) {
                supported_capabilities = VK_TRUE;
                continue;
            }

            VkBool32 supported_variant = VK_TRUE;
            for (uint32_t i = 0; i < variant_desc.instanceExtensionCount; ++i) {
                if (!detail::CheckExtension(supported_extensions.data(), supported_extensions.size(),
                                              variant_desc.pInstanceExtensions[i].extensionName)) {
                    supported_variant = VK_FALSE;
                    memcpy(block.blockName, variant_desc.blockName, VP_MAX_PROFILE_NAME_SIZE * sizeof(char));
                    unsupportedBlocks.push_back(block);
                }
            }

            if (supported_variant == VK_TRUE) {
                supported_capabilities = VK_TRUE;
                memcpy(block.blockName, variant_desc.blockName, VP_MAX_PROFILE_NAME_SIZE * sizeof(char));
                supportedBlocks.push_back(block);
            }
        }

        if (supported_capabilities == VK_FALSE) {
            *pSupported = VK_FALSE;
            return VK_SUCCESS;
        }
    }

    return VK_SUCCESS;
}

enum structure_type {
    STRUCTURE_FEATURE = 0,
    STRUCTURE_PROPERTY,
    STRUCTURE_QUEUE_FAMILY,
    STRUCTURE_FORMAT
};

VPAPI_ATTR VkResult vpGetProfileStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    structure_type                              type,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    std::vector<VkStructureType> results;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                uint32_t count = 0;
                const VkStructureType* data = nullptr;

                switch (type) {
                    default:
                    case STRUCTURE_FEATURE:
                        count = variant.featureStructTypeCount;
                        data = variant.pFeatureStructTypes;
                        break;
                    case STRUCTURE_PROPERTY:
                        count = variant.propertyStructTypeCount;
                        data = variant.pPropertyStructTypes;
                        break;
                    case STRUCTURE_QUEUE_FAMILY:
                        count = variant.queueFamilyStructTypeCount;
                        data = variant.pQueueFamilyStructTypes;
                        break;
                    case STRUCTURE_FORMAT:
                        count = variant.formatStructTypeCount;
                        data = variant.pFormatStructTypes;
                        break;
                }

                for (uint32_t type_index = 0; type_index < count; ++type_index) {
                    const VkStructureType dataType = data[type_index];
                    if (std::find(results.begin(), results.end(), dataType) == std::end(results)) {
                        results.push_back(dataType);
                    }
                }
            }
        }
    }

    const uint32_t count = static_cast<uint32_t>(results.size());
    std::sort(results.begin(), results.end());

    if (pStructureTypes == nullptr) {
        *pStructureTypeCount = count;
    } else {
        if (*pStructureTypeCount < count) {
            result = VK_INCOMPLETE;
        } else {
            *pStructureTypeCount = count;
        }

        if (*pStructureTypeCount > 0) {
            memcpy(pStructureTypes, &results[0], *pStructureTypeCount * sizeof(VkStructureType));
        }
    }

    return result;
}

enum ExtensionType {
    EXTENSION_INSTANCE,
    EXTENSION_DEVICE,
};

VPAPI_ATTR VkResult vpGetProfileExtensionProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    ExtensionType                               type,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    std::vector<VkExtensionProperties> results;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile, pBlockName);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                switch (type) {
                    default:
                    case EXTENSION_INSTANCE:
                        for (uint32_t ext_index = 0; ext_index < variant.instanceExtensionCount; ++ext_index) {
                            if (detail::HasExtension(results, variant.pInstanceExtensions[ext_index])) {
                                continue;
                            }
                            results.push_back(variant.pInstanceExtensions[ext_index]);
                        }
                        break;
                    case EXTENSION_DEVICE:
                        for (uint32_t ext_index = 0; ext_index < variant.deviceExtensionCount; ++ext_index) {
                            if (detail::HasExtension(results, variant.pDeviceExtensions[ext_index])) {
                                continue;
                            }
                            results.push_back(variant.pDeviceExtensions[ext_index]);
                        }
                        break;
                }
            }
        }
    }

    const uint32_t count = static_cast<uint32_t>(results.size());

    if (pProperties == nullptr) {
        *pPropertyCount = count;
    } else {
        if (*pPropertyCount < count) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = count;
        }
        if (*pPropertyCount > 0) {
            memcpy(pProperties, &results[0], *pPropertyCount * sizeof(VkExtensionProperties));
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoProfileDesc(
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    const detail::VpVideoProfileDesc**          ppVideoProfileDesc) {
    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    uint32_t curr_base_video_profile_index = 0;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                if (videoProfileIndex < curr_base_video_profile_index + variant.videoProfileCount) {
                    *ppVideoProfileDesc = &variant.pVideoProfiles[videoProfileIndex - curr_base_video_profile_index];
                    return result;
                } else {
                    curr_base_video_profile_index += variant.videoProfileCount;
                }
            }
        }
    }

    *ppVideoProfileDesc = nullptr;
    return VK_ERROR_UNKNOWN;
}

} // namespace detail

#ifdef VP_USE_OBJECT

VPAPI_ATTR VkResult vpCreateFunctions(
    const VpFunctionsCreateInfo*                pFunctionsCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VpFunctions*                                pFunctions) {
    (void)pAllocator;
    (void)pFunctionsCreateInfo;
    VpFunctions_T* functions = new (std::nothrow) VpFunctions_T();
    *pFunctions = functions;
    if (!functions) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

#define VP_COPY_IF_NOT_NULL(funcName)     if(pFunctionsCreateInfo->funcName != nullptr)         functions->funcName = pFunctionsCreateInfo->funcName;

    VP_COPY_IF_NOT_NULL(GetInstanceProcAddr);

    VP_COPY_IF_NOT_NULL(EnumerateInstanceVersion);
    VP_COPY_IF_NOT_NULL(EnumerateInstanceExtensionProperties);
    VP_COPY_IF_NOT_NULL(EnumerateDeviceExtensionProperties);

    VP_COPY_IF_NOT_NULL(GetPhysicalDeviceFeatures2);
    VP_COPY_IF_NOT_NULL(GetPhysicalDeviceProperties2);
    VP_COPY_IF_NOT_NULL(GetPhysicalDeviceFormatProperties2);
    VP_COPY_IF_NOT_NULL(GetPhysicalDeviceQueueFamilyProperties2);

    VP_COPY_IF_NOT_NULL(CreateInstance);
    VP_COPY_IF_NOT_NULL(CreateDevice);

#undef VP_COPY_IF_NOT_NULL

    return functions->validate();
}

/// Destroys allocator object.
VPAPI_ATTR void vpDestroyFunctions(
    VpFunctions                                 functions,
    const VkAllocationCallbacks*                pAllocator) {
    (void)pAllocator;
    
    delete functions;
}

#endif//VP_USE_OBJECT

/// Helper function to initialize VpFunctions instance with global Vulkan functions
VPAPI_ATTR VkResult vpInitializeGlobalFunctions(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    PFN_vkGetInstanceProcAddr                   GetInstanceProcAddr) {

#ifdef VP_USE_OBJECT
    VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    if (GetInstanceProcAddr == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    vp.GetInstanceProcAddr = GetInstanceProcAddr;

#define VP_FETCH_FUNC(memberName, functionNameString)     vp.memberName = (PFN_vk##memberName)vp.GetInstanceProcAddr(nullptr, functionNameString)

    VP_FETCH_FUNC(EnumerateInstanceVersion, "vkEnumerateInstanceVersion");
    VP_FETCH_FUNC(EnumerateInstanceExtensionProperties, "vkEnumerateInstanceExtensionProperties");
    VP_FETCH_FUNC(CreateInstance, "vkCreateInstance");

#undef VP_FETCH_FUNC

    return vp.validate();
}

/// Initializes capabilities with instance functions
VPAPI_ATTR VkResult vpInitializeInstanceFunctions(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VpInstanceFunctionsLoadFlags                flags) {
#ifdef VP_USE_OBJECT
    VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

#define VP_FETCH_FUNC(memberName, functionNameString)     if (((flags & VP_INSTANCE_FUNCTIONS_LOAD_MISSING_ONLY_BIT) && vp.memberName == nullptr) || !(flags & VP_INSTANCE_FUNCTIONS_LOAD_MISSING_ONLY_BIT))         vp.memberName = (PFN_vk##memberName)vp.GetInstanceProcAddr(instance, functionNameString);

    VP_FETCH_FUNC(EnumerateDeviceExtensionProperties, "vkEnumerateDeviceExtensionProperties");
    VP_FETCH_FUNC(GetPhysicalDeviceFeatures2, "vkGetPhysicalDeviceFeatures2");
    if (!vp.GetPhysicalDeviceFeatures2 && (flags & VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT)) {
        VP_FETCH_FUNC(GetPhysicalDeviceFeatures2, "vkGetPhysicalDeviceFeatures2KHR");
    }

    VP_FETCH_FUNC(GetPhysicalDeviceProperties2, "vkGetPhysicalDeviceProperties2");
    if (!vp.GetPhysicalDeviceProperties2 && (flags & VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT)) {
        VP_FETCH_FUNC(GetPhysicalDeviceProperties2, "vkGetPhysicalDeviceProperties2KHR");
    }

    VP_FETCH_FUNC(GetPhysicalDeviceFormatProperties2, "vkGetPhysicalDeviceFormatProperties2");
    if (!vp.GetPhysicalDeviceFormatProperties2 && (flags & VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT)) {
        VP_FETCH_FUNC(GetPhysicalDeviceFormatProperties2, "vkGetPhysicalDeviceFormatProperties2KHR");
    }

    VP_FETCH_FUNC(GetPhysicalDeviceQueueFamilyProperties2, "vkGetPhysicalDeviceQueueFamilyProperties2");
    if (!vp.GetPhysicalDeviceQueueFamilyProperties2 && (flags & VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT)) {
        VP_FETCH_FUNC(GetPhysicalDeviceQueueFamilyProperties2, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    }

    VP_FETCH_FUNC(CreateDevice, "vkCreateDevice");
#undef VP_FETCH_FUNC

    // Validate the instance functions are loaded correctly
    if (vp.EnumerateDeviceExtensionProperties == nullptr ||
        vp.CreateDevice == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    bool requiresProperties2 = (flags & VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT);

    if (vp.GetPhysicalDeviceFeatures2 == nullptr ||
        vp.GetPhysicalDeviceProperties2 == nullptr ||
        vp.GetPhysicalDeviceFormatProperties2 == nullptr ||
        vp.GetPhysicalDeviceQueueFamilyProperties2 == nullptr) {
        return requiresProperties2 ? VK_ERROR_INITIALIZATION_FAILED : VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    return VK_SUCCESS;
}

VPAPI_ATTR VkResult vpGetProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = VK_SUCCESS;

    if (pProperties == nullptr) {
        *pPropertyCount = detail::profileCount;
    } else {
        if (*pPropertyCount < detail::profileCount) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = detail::profileCount;
        }
        for (uint32_t property_index = 0; property_index < *pPropertyCount; ++property_index) {
            pProperties[property_index] = detail::profiles[property_index].props;
        }
    }
    return result;
}

VPAPI_ATTR VkResult vpGetProfileRequiredProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = VK_SUCCESS;

    const detail::VpProfileDesc* desc = detail::vpGetProfileDesc(pProfile->profileName);
    if (desc == nullptr) {
        return VK_ERROR_UNKNOWN;
    }

    if (pProperties == nullptr) {
        *pPropertyCount = desc->requiredProfileCount;
    } else {
        if (*pPropertyCount < desc->requiredProfileCount) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = desc->requiredProfileCount;
        }
        for (uint32_t property_index = 0; property_index < *pPropertyCount; ++property_index) {
            pProperties[property_index] = desc->pRequiredProfiles[property_index];
        }
    }
    return result;
}

VPAPI_ATTR uint32_t vpGetProfileAPIVersion(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return 0;
    }

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile, nullptr);

    uint32_t major = 0;
    uint32_t minor = 0;
    uint32_t patch = 0;

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (desc == nullptr) {
            return 0;
        }

        major = std::max<uint32_t>(major, VK_API_VERSION_MAJOR(desc->minApiVersion));
        minor = std::max<uint32_t>(minor, VK_API_VERSION_MINOR(desc->minApiVersion));
        patch = std::max<uint32_t>(patch, VK_API_VERSION_PATCH(desc->minApiVersion));
    }

    return VK_MAKE_API_VERSION(0, major, minor, patch);
}

VPAPI_ATTR VkResult vpGetProfileFallbacks(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    uint32_t*                                   pPropertyCount,
    VpProfileProperties*                        pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(true);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = VK_SUCCESS;

    const detail::VpProfileDesc* desc = detail::vpGetProfileDesc(pProfile->profileName);
    if (desc == nullptr) {
        return VK_ERROR_UNKNOWN;
    }

    if (pProperties == nullptr) {
        *pPropertyCount = desc->fallbackCount;
    } else {
        if (*pPropertyCount < desc->fallbackCount) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = desc->fallbackCount;
        }
        for (uint32_t i = 0; i < *pPropertyCount; ++i) {
            pProperties[i] = desc->pFallbacks[i];
        }
    }
    return result;
}

VPAPI_ATTR VkResult vpHasMultipleVariantsProfile(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pHasMultipleVariants) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(true);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile, nullptr);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (desc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        for (uint32_t caps_index = 0, caps_count = desc->requiredCapabilityCount; caps_index < caps_count; ++caps_index) {
            if (desc->pRequiredCapabilities[caps_index].variantCount > 1) {
                *pHasMultipleVariants = VK_TRUE;
                return VK_SUCCESS;
            }
        }
    }

    *pHasMultipleVariants = VK_FALSE;
    return VK_SUCCESS;
}

VPAPI_ATTR VkResult vpGetInstanceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const char*                         pLayerName,
    const VpProfileProperties*          pProfile,
    VkBool32*                           pSupported,
    uint32_t*                           pPropertyCount,
    VpBlockProperties*                  pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = VK_SUCCESS;

    uint32_t api_version = VK_API_VERSION_1_0;
    PFN_vkEnumerateInstanceVersion pfnEnumerateInstanceVersion = vp.EnumerateInstanceVersion;
    if (pfnEnumerateInstanceVersion != nullptr) {
        result = pfnEnumerateInstanceVersion(&api_version);
        if (result != VK_SUCCESS) {
            *pSupported = VK_FALSE;
            return result;
        } /* else {
            VP_DEBUG_MSGF("Instance API version %u.%u.%u", VK_API_VERSION_MAJOR(api_version), VK_API_VERSION_MINOR(api_version), VK_API_VERSION_PATCH(api_version));
        } */
    }

    uint32_t supported_instance_extension_count = 0;
    result = vp.EnumerateInstanceExtensionProperties(pLayerName, &supported_instance_extension_count, nullptr);
    if (result != VK_SUCCESS) {
        *pSupported = VK_FALSE;
        return result;
    }
    std::vector<VkExtensionProperties> supported_instance_extensions;
    if (supported_instance_extension_count > 0) {
        supported_instance_extensions.resize(supported_instance_extension_count);
    }
    result = vp.EnumerateInstanceExtensionProperties(pLayerName, &supported_instance_extension_count, supported_instance_extensions.data());
    if (result != VK_SUCCESS) {
        *pSupported = VK_FALSE;
        return result;
    }

    VkBool32 supported = VK_TRUE;

    // We require VK_KHR_get_physical_device_properties2 if we are on Vulkan 1.0
    if (api_version < VK_API_VERSION_1_1) {
        bool foundGPDP2 = false;
        for (size_t ext_index = 0, ext_count = supported_instance_extensions.size(); ext_index < ext_count; ++ext_index) {
            if (strcmp(supported_instance_extensions[ext_index].extensionName, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
                foundGPDP2 = true;
                break;
            }
        }
        if (!foundGPDP2) {
            VP_DEBUG_MSG("Unsupported mandatory extension VK_KHR_get_physical_device_properties2 on Vulkan 1.0");
            supported = VK_FALSE;
        }
    }

    const detail::VpProfileDesc* pProfileDesc = detail::vpGetProfileDesc(pProfile->profileName);
    if (pProfileDesc == nullptr) return VK_ERROR_UNKNOWN;

    std::vector<VpBlockProperties> supported_blocks;
    std::vector<VpBlockProperties> unsupported_blocks;

    result = detail::vpGetInstanceProfileSupportSingleProfile(api_version, supported_instance_extensions, pProfile, &supported, supported_blocks, unsupported_blocks);
    if (result != VK_SUCCESS) {
        *pSupported = supported;
        return result;
    }

    for (std::size_t required_profile_index = 0; required_profile_index < pProfileDesc->requiredProfileCount; ++required_profile_index) {
        result = detail::vpGetInstanceProfileSupportSingleProfile(0, supported_instance_extensions, &pProfileDesc->pRequiredProfiles[required_profile_index], &supported, supported_blocks, unsupported_blocks);
        if (result != VK_SUCCESS) {
            *pSupported = supported;
            return result;
        }
    }

    const std::vector<VpBlockProperties>& blocks = supported ? supported_blocks : unsupported_blocks;

    if (pProperties == nullptr) {
        *pPropertyCount = static_cast<uint32_t>(blocks.size());
    } else {
        if (*pPropertyCount < static_cast<uint32_t>(blocks.size())) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = static_cast<uint32_t>(blocks.size());
        }
        for (uint32_t block_index = 0, block_count = static_cast<uint32_t>(blocks.size()); block_index < block_count; ++block_index) {
            pProperties[block_index] = blocks[block_index];
        }
    }

    *pSupported = supported;
    return result;
}

VPAPI_ATTR VkResult vpGetInstanceProfileSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const char*                                 pLayerName,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    uint32_t count = 0;
    return vpGetInstanceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pLayerName, pProfile, pSupported, &count, nullptr);
}

VPAPI_ATTR VkResult vpCreateInstance(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(false);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    if (pCreateInfo == nullptr || pInstance == nullptr) {
        return vp.CreateInstance(pCreateInfo == nullptr ? nullptr : pCreateInfo->pCreateInfo, pAllocator, pInstance);
    }

    const std::vector<VpBlockProperties>& blocks = detail::GatherBlocks(
        pCreateInfo->enabledFullProfileCount, pCreateInfo->pEnabledFullProfiles,
        pCreateInfo->enabledProfileBlockCount, pCreateInfo->pEnabledProfileBlocks);

    std::vector<const char*> extensions;
    for (std::uint32_t ext_index = 0, ext_count = pCreateInfo->pCreateInfo->enabledExtensionCount; ext_index < ext_count; ++ext_index) {
        extensions.push_back(pCreateInfo->pCreateInfo->ppEnabledExtensionNames[ext_index]);
    }

    for (std::size_t block_index = 0, block_count = blocks.size(); block_index < block_count; ++block_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(blocks[block_index].profiles.profileName);
        if (profile_desc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        for (std::size_t caps_index = 0, caps_count = profile_desc->requiredCapabilityCount; caps_index < caps_count; ++caps_index) {
            const detail::VpCapabilitiesDesc* caps_desc = &profile_desc->pRequiredCapabilities[caps_index];

            for (std::size_t variant_index = 0, variant_count = caps_desc->variantCount; variant_index < variant_count; ++variant_index) {
                const detail::VpVariantDesc* variant = &caps_desc->pVariants[variant_index];

                if (strcmp(blocks[block_index].blockName, "") != 0) {
                    if (strcmp(variant->blockName, blocks[block_index].blockName) != 0) {
                        continue;
                    }
                }

                // The 'depends' condition of a capability block is evaluated against a physical device:
                // the instance extensions of the capability block are not enabled
                if (variant->pfnDepends != nullptr) {
                    continue;
                }

                detail::GetExtensions(variant->instanceExtensionCount, variant->pInstanceExtensions, extensions);
            }
        }
    }

    VkApplicationInfo appInfo{VK_STRUCTURE_TYPE_APPLICATION_INFO};
    if (pCreateInfo->pCreateInfo->pApplicationInfo != nullptr) {
        appInfo = *pCreateInfo->pCreateInfo->pApplicationInfo;
    } else if (!blocks.empty()) {
        appInfo.apiVersion = vpGetProfileAPIVersion(
#ifdef VP_USE_OBJECT
            functions,
#endif//VP_USE_OBJECT
            &blocks[0].profiles);
    }

    VkInstanceCreateInfo createInfo = *pCreateInfo->pCreateInfo;
    createInfo.pApplicationInfo = &appInfo;

    bool use_gpdp2 = false;

    // Need to include VK_KHR_get_physical_device_properties2 if we are on Vulkan 1.0
    if (createInfo.pApplicationInfo->apiVersion < VK_API_VERSION_1_1) {
        bool foundGPDP2 = false;
        for (size_t ext_index = 0, ext_count = extensions.size(); ext_index < ext_count; ++ext_index) {
            if (strcmp(extensions[ext_index], VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
                foundGPDP2 = true;
                break;
            }
        }
        if (!foundGPDP2) {
            extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            use_gpdp2 = true;
        }
    }

#ifdef __APPLE__
    bool has_portability_ext = false;
    for (std::size_t ext_index = 0, ext_count = extensions.size(); ext_index < ext_count; ++ext_index) {
        if (strcmp(extensions[ext_index], VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME) == 0) {
            has_portability_ext = true;
            break;
        }
    }

    if (!has_portability_ext) {
        extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    }

    createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
#endif

    if (!extensions.empty()) {
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();
    }

    VkResult result = vp.CreateInstance(&createInfo, pAllocator, pInstance);

    if (result == VK_SUCCESS) {
        VpInstanceFunctionsLoadFlags flags = VP_INSTANCE_FUNCTIONS_LOAD_MISSING_ONLY_BIT;
        if (use_gpdp2) {
            flags |= VP_INSTANCE_FUNCTIONS_LOAD_KHR_GET_PHYSICAL_DEVICE_PROPERTIES2_BIT;
        }

        result = vpInitializeInstanceFunctions(
#ifdef VP_USE_OBJECT
            functions,
#endif//VP_USE_OBJECT
            *pInstance, flags);
    }

    return result;
}

VPAPI_ATTR VkResult vpGetPhysicalDeviceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VkPhysicalDevice                            physicalDevice,
    const VpProfileProperties*                  pProfile,
    VkBool32*                                   pSupported,
    uint32_t*                                   pPropertyCount,
    VpBlockProperties*                          pProperties) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    VkResult result_validate = vp.validate(true);
    if (result_validate != VK_SUCCESS) {
        return result_validate;
    }

    VkResult result = VK_SUCCESS;

    uint32_t supported_device_extension_count = 0;
    result = vp.EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &supported_device_extension_count, nullptr);
    if (result != VK_SUCCESS) {
        return result;
    }
    std::vector<VkExtensionProperties> supported_device_extensions;
    if (supported_device_extension_count > 0) {
        supported_device_extensions.resize(supported_device_extension_count);
    }
    result = vp.EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &supported_device_extension_count, supported_device_extensions.data());
    if (result != VK_SUCCESS) {
        return result;
    }

    // Workaround old loader bug where count could be smaller on the second call to vkEnumerateDeviceExtensionProperties
    if (supported_device_extension_count > 0) {
        supported_device_extensions.resize(supported_device_extension_count);
    }

    {
        const detail::VpProfileDesc* pProfileDesc = detail::vpGetProfileDesc(pProfile->profileName);
        if (pProfileDesc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }
    }

    struct GPDP2EntryPoints {
        PFN_vkGetPhysicalDeviceFeatures2KHR                 pfnGetPhysicalDeviceFeatures2;
        PFN_vkGetPhysicalDeviceProperties2KHR               pfnGetPhysicalDeviceProperties2;
        PFN_vkGetPhysicalDeviceFormatProperties2KHR         pfnGetPhysicalDeviceFormatProperties2;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR    pfnGetPhysicalDeviceQueueFamilyProperties2;
    };

#ifdef VK_KHR_video_queue
    struct VideoInfo {
        PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR         pfnGetPhysicalDeviceVideoCapabilitiesKHR;
        PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR     pfnGetPhysicalDeviceVideoFormatPropertiesKHR;
        const detail::VpVideoProfileDesc*                   pProfileDesc;
        VkVideoProfileInfoKHR                               profileInfo;
        VkPhysicalDeviceVideoFormatInfoKHR                  formatInfo;
        bool                                                supportedProfile;
        uint32_t                                            matchingProfiles;
    };
#endif  // VK_KHR_video_queue

    std::vector<VpBlockProperties> supported_blocks;
    std::vector<VpBlockProperties> unsupported_blocks;

    struct UserData {
        VkPhysicalDevice physicalDevice;
        std::vector<VpBlockProperties>& supported_blocks;
        std::vector<VpBlockProperties>& unsupported_blocks;
        const detail::VpVariantDesc* variant;
        GPDP2EntryPoints gpdp2;
#ifdef VK_KHR_video_queue
        VideoInfo video;
#endif  // VK_KHR_video_queue
        uint32_t index;
        detail::PFN_vpStructChainerCb pfnCb;
        bool supported;
    } userData{physicalDevice, supported_blocks, unsupported_blocks};

    userData.gpdp2.pfnGetPhysicalDeviceFeatures2 = vp.GetPhysicalDeviceFeatures2;
    userData.gpdp2.pfnGetPhysicalDeviceProperties2 = vp.GetPhysicalDeviceProperties2;
    userData.gpdp2.pfnGetPhysicalDeviceFormatProperties2 = vp.GetPhysicalDeviceFormatProperties2;
    userData.gpdp2.pfnGetPhysicalDeviceQueueFamilyProperties2 = vp.GetPhysicalDeviceQueueFamilyProperties2;

    if (userData.gpdp2.pfnGetPhysicalDeviceFeatures2 == nullptr ||
        userData.gpdp2.pfnGetPhysicalDeviceProperties2 == nullptr ||
        userData.gpdp2.pfnGetPhysicalDeviceFormatProperties2 == nullptr ||
        userData.gpdp2.pfnGetPhysicalDeviceQueueFamilyProperties2 == nullptr) {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    detail::VpDependsContext depends_context{};
    {
        VkPhysicalDeviceProperties2KHR properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR };
        userData.gpdp2.pfnGetPhysicalDeviceProperties2(physicalDevice, &properties2);
        depends_context.physicalDevice = physicalDevice;
        depends_context.pfnGetPhysicalDeviceFeatures2 = userData.gpdp2.pfnGetPhysicalDeviceFeatures2;
        depends_context.apiVersion = properties2.properties.apiVersion;
        depends_context.extensionCount = static_cast<uint32_t>(supported_device_extensions.size());
        depends_context.pExtensions = supported_device_extensions.data();
    }

#ifdef VK_KHR_video_queue
    PFN_vkGetInstanceProcAddr gipa = vp.GetInstanceProcAddr;
    userData.video.pfnGetPhysicalDeviceVideoCapabilitiesKHR =
        (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)gipa(instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    userData.video.pfnGetPhysicalDeviceVideoFormatPropertiesKHR =
        (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)gipa(instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif  // VK_KHR_video_queue

    bool supported = true;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const char* profile_name = gathered_profiles[profile_index].profileName;

        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(profile_name);
        if (profile_desc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        bool supported_profile = true;

        if (profile_desc->props.specVersion < gathered_profiles[profile_index].specVersion) {
            VP_DEBUG_MSGF("Unsupported requested %s profile version: %u, profile supported at version %u", profile_name, profile_desc->props.specVersion, pProfile->specVersion);
            supported_profile = false;
        }

        VpBlockProperties block{gathered_profiles[profile_index], profile_desc->minApiVersion};

        {
            VkPhysicalDeviceProperties2KHR properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR };
            userData.gpdp2.pfnGetPhysicalDeviceProperties2(physicalDevice, &properties2);
            if (!detail::vpCheckVersion(properties2.properties.apiVersion, profile_desc->minApiVersion)) {
                VP_DEBUG_MSGF("Unsupported API version: %u.%u.%u", VK_API_VERSION_MAJOR(profile_desc->minApiVersion), VK_API_VERSION_MINOR(profile_desc->minApiVersion), VK_API_VERSION_PATCH(profile_desc->minApiVersion));
                supported_profile = false;
            }
        }

        for (uint32_t required_capability_index = 0; required_capability_index < profile_desc->requiredCapabilityCount; ++required_capability_index) {
            const detail::VpCapabilitiesDesc* required_capabilities = &profile_desc->pRequiredCapabilities[required_capability_index];

            bool supported_block = false;

            for (uint32_t variant_index = 0; variant_index < required_capabilities->variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant_desc = required_capabilities->pVariants[variant_index];

                // The requirements of a capability block don't apply when the device doesn't satisfy its 'depends' condition
                if (variant_desc.pfnDepends != nullptr && !variant_desc.pfnDepends(depends_context)) {
                    VP_DEBUG_MSGF("Capability block %s requirements don't apply: 'depends' condition not satisfied", variant_desc.blockName);
                    supported_block = true;
                    break;
                }

                bool supported_variant = true;

                for (uint32_t ext_index = 0; ext_index < variant_desc.deviceExtensionCount; ++ext_index) {
                    const char *requested_extension = variant_desc.pDeviceExtensions[ext_index].extensionName;
                    if (!detail::CheckExtension(supported_device_extensions.data(), supported_device_extensions.size(), requested_extension)) {
                        supported_variant = false;
                    }
                }

                userData.variant = &variant_desc;

                if (supported_variant) {
                    VkPhysicalDeviceFeatures2KHR features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR };
                    userData.variant->chainers.pfnFeature(
                        static_cast<VkBaseOutStructure*>(static_cast<void*>(&features)), &userData,
                        [](VkBaseOutStructure* p, void* pUser) {
                            UserData* pUserData = static_cast<UserData*>(pUser);
                            pUserData->gpdp2.pfnGetPhysicalDeviceFeatures2(
                                pUserData->physicalDevice,
                                static_cast<VkPhysicalDeviceFeatures2KHR*>(static_cast<void*>(p)));

                            pUserData->supported = true;
                            while (p != nullptr) {
                                if (!pUserData->variant->feature.pfnComparator(p)) {
                                    pUserData->supported = false;
                                }
                                p = p->pNext;
                            }
                        }
                    );
                    if (!userData.supported) {
                        supported_variant = false;
                    }
                }

                if (supported_variant) {
                    VkPhysicalDeviceProperties2KHR device_properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR };
                    userData.variant->chainers.pfnProperty(
                        static_cast<VkBaseOutStructure*>(static_cast<void*>(&device_properties2)), &userData,
                        [](VkBaseOutStructure* p, void* pUser) {
                            UserData* pUserData = static_cast<UserData*>(pUser);
                            pUserData->gpdp2.pfnGetPhysicalDeviceProperties2(
                                pUserData->physicalDevice,
                                static_cast<VkPhysicalDeviceProperties2KHR*>(static_cast<void*>(p)));

                            VkPhysicalDeviceFeatures2KHR device_features2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR };
                            pUserData->gpdp2.pfnGetPhysicalDeviceFeatures2(pUserData->physicalDevice, &device_features2);

                            pUserData->supported = true;
                            while (p != nullptr) {
                                if (!pUserData->variant->property.pfnComparator(p, device_features2.features)) {
                                    pUserData->supported = false;
                                }
                                p = p->pNext;
                            }
                        }
                    );
                    if (!userData.supported) {
                        supported_variant = false;
                    }
                }

                if (supported_variant && userData.variant->queueFamilyCount > 0) {
                    uint32_t queue_family_count = 0;
                    userData.gpdp2.pfnGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &queue_family_count, nullptr);
                    std::vector<VkQueueFamilyProperties2KHR> queueFamilyProps(queue_family_count, { VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR });
                    userData.variant->chainers.pfnQueueFamily(
                        queue_family_count, static_cast<VkBaseOutStructure*>(static_cast<void*>(queueFamilyProps.data())), &userData,
                        [](uint32_t queue_family_count, VkBaseOutStructure* pBaseArray, void* pUser) {
                            UserData* pUserData = static_cast<UserData*>(pUser);
                            VkQueueFamilyProperties2KHR* pArray = static_cast<VkQueueFamilyProperties2KHR*>(static_cast<void*>(pBaseArray));
                            pUserData->gpdp2.pfnGetPhysicalDeviceQueueFamilyProperties2(pUserData->physicalDevice, &queue_family_count, pArray);
                            pUserData->supported = true;
                            for (uint32_t profile_qf_idx = 0; profile_qf_idx < pUserData->variant->queueFamilyCount; ++profile_qf_idx) {
                                bool found_matching = false;
                                for (uint32_t queue_family_index = 0; queue_family_index < queue_family_count; ++queue_family_index) {
                                    bool this_matches = true;
                                    VkBaseOutStructure* p = static_cast<VkBaseOutStructure*>(static_cast<void*>(&pArray[queue_family_index]));
                                    while (p != nullptr) {
                                        if (!pUserData->variant->pQueueFamilies[profile_qf_idx].pfnComparator(p)) {
                                            this_matches = false;
                                        }
                                        p = p->pNext;
                                    }
                                    if (this_matches) {
                                        found_matching = true;
                                        break;
                                    }
                                }
                                if (!found_matching) {
                                    pUserData->supported = false;
                                    break;
                                }
                            }
                        }
                    );
                    if (!userData.supported) {
                        supported_variant = false;
                    }
                }

                for (uint32_t format_index = 0; supported_variant && (format_index < userData.variant->formatCount); ++format_index) {
                    userData.index = format_index;
                    VkFormatProperties2KHR format_properties2{ VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR };
                    userData.variant->chainers.pfnFormat(
                        static_cast<VkBaseOutStructure*>(static_cast<void*>(&format_properties2)), &userData,
                        [](VkBaseOutStructure* p, void* pUser) {
                            UserData* pUserData = static_cast<UserData*>(pUser);
                            pUserData->gpdp2.pfnGetPhysicalDeviceFormatProperties2(
                                pUserData->physicalDevice,
                                pUserData->variant->pFormats[pUserData->index].format,
                                static_cast<VkFormatProperties2KHR*>(static_cast<void*>(p)));
                            // Query again the structures returning arrays (e.g. VkDrmFormatModifierPropertiesListEXT) once allocated
                            std::vector<std::vector<uint64_t>> arrays_storage;
                            if (detail::vpAllocateFormatPropertiesArrays(p, arrays_storage)) {
                                pUserData->gpdp2.pfnGetPhysicalDeviceFormatProperties2(
                                    pUserData->physicalDevice,
                                    pUserData->variant->pFormats[pUserData->index].format,
                                    static_cast<VkFormatProperties2KHR*>(static_cast<void*>(p)));
                            }
                            pUserData->supported = true;
                            while (p != nullptr) {
                                if (!pUserData->variant->pFormats[pUserData->index].pfnComparator(p)) {
                                    pUserData->supported = false;
                                }
                                p = p->pNext;
                            }
                        }
                    );
                    if (!userData.supported) {
                        supported_variant = false;
                    }
                }

#ifdef VK_KHR_video_queue
                if (supported_variant && (userData.variant->videoProfileCount > 0)) {
                    VkVideoProfileListInfoKHR profile_list{ VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR };
                    profile_list.profileCount = 1;
                    profile_list.pProfiles = &userData.video.profileInfo;
                    userData.video.formatInfo.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR;
                    userData.video.formatInfo.pNext = &profile_list;

                    if (userData.video.pfnGetPhysicalDeviceVideoCapabilitiesKHR != nullptr &&
                        userData.video.pfnGetPhysicalDeviceVideoFormatPropertiesKHR != nullptr) {
                        for (uint32_t video_profile_index = 0; video_profile_index < userData.variant->videoProfileCount; ++video_profile_index) {
                            userData.video.profileInfo = VkVideoProfileInfoKHR{ VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR };
                            userData.video.pProfileDesc = &userData.variant->pVideoProfiles[video_profile_index];
                            userData.supported = true;
                            userData.video.matchingProfiles = 0;

                            detail::vpForEachMatchingVideoProfiles(&userData.video.profileInfo, &userData,
                                [](VkBaseOutStructure* p, void* pUser) {
                                    UserData* pUserData = static_cast<UserData*>(pUser);
                                    while (p != nullptr) {
                                        if (!pUserData->video.pProfileDesc->info.pfnComparator(p)) {
                                            return;
                                        }
                                        p = p->pNext;
                                    }

                                    pUserData->video.supportedProfile = true;

                                    VkVideoCapabilitiesKHR capabilities{ VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR };
                                    pUserData->video.pProfileDesc->chainers.pfnCapability(
                                        static_cast<VkBaseOutStructure*>(static_cast<void*>(&capabilities)), pUserData,
                                        [](VkBaseOutStructure* p, void* pUser) {
                                            UserData* pUserData = static_cast<UserData*>(pUser);
                                            VkResult result = pUserData->video.pfnGetPhysicalDeviceVideoCapabilitiesKHR(
                                                pUserData->physicalDevice,
                                                &pUserData->video.profileInfo,
                                                static_cast<VkVideoCapabilitiesKHR*>(static_cast<void*>(p)));
                                            if (result != VK_SUCCESS) {
                                                pUserData->video.supportedProfile = false;
                                                return;
                                            }
                                            while (p != nullptr) {
                                                if (!pUserData->video.pProfileDesc->capability.pfnComparator(p)) {
                                                    pUserData->supported = false;
                                                }
                                                p = p->pNext;
                                            }
                                        }
                                    );

                                    if (pUserData->video.supportedProfile) {
                                        pUserData->video.matchingProfiles++;
                                    } else {
                                        return;
                                    }

                                    std::vector<VkVideoFormatPropertiesKHR> format_props;
                                    for (uint32_t format_index = 0; format_index < pUserData->video.pProfileDesc->formatCount; ++format_index) {
                                        pUserData->index = format_index;
                                        {
                                            VkVideoFormatPropertiesKHR tmp_props{ VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR };
                                            pUserData->video.pProfileDesc->pFormats[format_index].pfnFiller(static_cast<VkBaseOutStructure*>(static_cast<void*>(&tmp_props)));
                                            pUserData->video.formatInfo.imageUsage = tmp_props.imageUsageFlags;
                                        }

                                        uint32_t format_count = 0;
                                        pUserData->video.pfnGetPhysicalDeviceVideoFormatPropertiesKHR(pUserData->physicalDevice, &pUserData->video.formatInfo, &format_count, nullptr);
                                        format_props.resize(format_count, { VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR });
                                        pUserData->video.pProfileDesc->chainers.pfnFormat(
                                            format_count, static_cast<VkBaseOutStructure*>(static_cast<void*>(format_props.data())), pUserData,
                                            [](uint32_t format_count, VkBaseOutStructure* pBaseArray, void* pUser) {
                                                UserData* pUserData = static_cast<UserData*>(pUser);
                                                VkVideoFormatPropertiesKHR* pArray = static_cast<VkVideoFormatPropertiesKHR*>(static_cast<void*>(pBaseArray));
                                                pUserData->video.pfnGetPhysicalDeviceVideoFormatPropertiesKHR(pUserData->physicalDevice, &pUserData->video.formatInfo, &format_count, pArray);
                                                bool found_matching = false;
                                                for (uint32_t i = 0; i < format_count; ++i) {
                                                    bool this_matches = true;
                                                    VkBaseOutStructure* p = static_cast<VkBaseOutStructure*>(static_cast<void*>(&pArray[i]));
                                                    while (p != nullptr) {
                                                        if (!pUserData->video.pProfileDesc->pFormats[pUserData->index].pfnComparator(p)) {
                                                            this_matches = false;
                                                        }
                                                        p = p->pNext;
                                                    }
                                                    if (this_matches) {
                                                        found_matching = true;
                                                        break;
                                                    }
                                                }
                                                if (!found_matching) {
                                                    pUserData->supported = false;
                                                }
                                            }
                                        );
                                    }
                                }
                            );
                            if (!userData.supported || userData.video.matchingProfiles == 0) {
                                supported_variant = false;
                            }
                        }
                    } else {
                        supported_variant = false;
                    }
                }
#endif  // VK_KHR_video_queue

                memcpy(block.blockName, variant_desc.blockName, VP_MAX_PROFILE_NAME_SIZE * sizeof(char));
                if (supported_variant) {
                    supported_blocks.push_back(block);
                    supported_block = true;
                    break;
                } else {
                    unsupported_blocks.push_back(block);
                }
            }

            if (!supported_block) {
                supported_profile = false;
            }
        }

        if (!supported_profile) {
            supported = false;
        }
    }

    const std::vector<VpBlockProperties>& blocks = supported ? supported_blocks : unsupported_blocks;

    if (pProperties == nullptr) {
        *pPropertyCount = static_cast<uint32_t>(blocks.size());
    } else {
        if (*pPropertyCount < static_cast<uint32_t>(blocks.size())) {
            result = VK_INCOMPLETE;
        } else {
            *pPropertyCount = static_cast<uint32_t>(blocks.size());
        }
        for (uint32_t i = 0, n = static_cast<uint32_t>(blocks.size()); i < n; ++i) {
            pProperties[i] = blocks[i];
        }
    }

    *pSupported = supported ? VK_TRUE : VK_FALSE;
    return VK_SUCCESS;
}

VPAPI_ATTR VkResult vpGetPhysicalDeviceProfileSupport(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkInstance                                  instance,
    VkPhysicalDevice                            physicalDevice,
    const VpProfileProperties*                  pProfile,
    VkBool32 *pSupported) {
    uint32_t count = 0;

    return vpGetPhysicalDeviceProfileVariantsSupport(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        instance, physicalDevice, pProfile, pSupported, &count, nullptr);
}

VPAPI_ATTR VkResult vpCreateDevice(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    VkPhysicalDevice                            physicalDevice,
    const VpDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice) {
#ifdef VP_USE_OBJECT
    const VpFunctions_T& vp = functions == nullptr ? VpFunctions_T::Get() : *functions;
#else
    const VpFunctions_T& vp = VpFunctions_T::Get();
#endif//VP_USE_OBJECT

    if (physicalDevice == VK_NULL_HANDLE || pCreateInfo == nullptr || pDevice == nullptr) {
        return vp.CreateDevice(physicalDevice, pCreateInfo == nullptr ? nullptr : pCreateInfo->pCreateInfo, pAllocator, pDevice);
    }

    const std::vector<VpBlockProperties>& blocks = detail::GatherBlocks(
        pCreateInfo->enabledFullProfileCount, pCreateInfo->pEnabledFullProfiles,
        pCreateInfo->enabledProfileBlockCount, pCreateInfo->pEnabledProfileBlocks);

    std::unique_ptr<detail::FeaturesChain> chain = std::make_unique<detail::FeaturesChain>();
    std::vector<VkStructureType> structureTypes;

    std::vector<const char*> extensions;
    for (std::uint32_t ext_index = 0, ext_count = pCreateInfo->pCreateInfo->enabledExtensionCount; ext_index < ext_count; ++ext_index) {
        extensions.push_back(pCreateInfo->pCreateInfo->ppEnabledExtensionNames[ext_index]);
    }

    // The capability blocks with a 'depends' condition are only enabled when the physical device satisfies the condition
    std::vector<VkExtensionProperties> device_extensions;
    detail::VpDependsContext depends_context{};
    bool depends_context_initialized = false;
    auto is_variant_enabled = [&](const detail::VpVariantDesc* variant) -> bool {
        if (variant->pfnDepends == nullptr) {
            return true;
        }
        if (!depends_context_initialized) {
            depends_context_initialized = true;
            if (vp.EnumerateDeviceExtensionProperties == nullptr || vp.GetPhysicalDeviceProperties2 == nullptr) {
                return false;
            }
            uint32_t device_extension_count = 0;
            if (vp.EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &device_extension_count, nullptr) == VK_SUCCESS) {
                device_extensions.resize(device_extension_count);
                if (vp.EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &device_extension_count, device_extensions.data()) == VK_SUCCESS) {
                    device_extensions.resize(device_extension_count);
                } else {
                    device_extensions.clear();
                }
            }
            VkPhysicalDeviceProperties2KHR properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR };
            vp.GetPhysicalDeviceProperties2(physicalDevice, &properties2);
            depends_context.physicalDevice = physicalDevice;
            depends_context.pfnGetPhysicalDeviceFeatures2 = vp.GetPhysicalDeviceFeatures2;
            depends_context.apiVersion = properties2.properties.apiVersion;
            depends_context.extensionCount = static_cast<uint32_t>(device_extensions.size());
            depends_context.pExtensions = device_extensions.data();
        }
        if (depends_context.pfnGetPhysicalDeviceFeatures2 == nullptr) {
            return false;
        }
        return variant->pfnDepends(depends_context);
    };

    for (std::size_t block_index = 0, block_count = blocks.size(); block_index < block_count; ++block_index) {
        const detail::VpProfileDesc* pProfileDesc = detail::vpGetProfileDesc(blocks[block_index].profiles.profileName);
        if (pProfileDesc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        for (std::size_t caps_index = 0, caps_count = pProfileDesc->requiredCapabilityCount; caps_index < caps_count; ++caps_index) {
            const detail::VpCapabilitiesDesc* pCapsDesc = &pProfileDesc->pRequiredCapabilities[caps_index];

            for (std::size_t variant_index = 0, variant_count = pCapsDesc->variantCount; variant_index < variant_count; ++variant_index) {
                const detail::VpVariantDesc* variant = &pCapsDesc->pVariants[variant_index];

                if (strcmp(blocks[block_index].blockName, "") != 0) {
                    if (strcmp(variant->blockName, blocks[block_index].blockName) != 0) {
                        continue;
                    }
                }

                if (!is_variant_enabled(variant)) {
                    continue;
                }

                for (uint32_t type_index = 0; type_index < variant->featureStructTypeCount; ++type_index) {
                    const VkStructureType type = variant->pFeatureStructTypes[type_index];
                    if (std::find(structureTypes.begin(), structureTypes.end(), type) == std::end(structureTypes)) {
                        structureTypes.push_back(type);
                    }
                }

                detail::GetExtensions(variant->deviceExtensionCount, variant->pDeviceExtensions, extensions);
            }
        }
    }

    VkBaseOutStructure* pNext = static_cast<VkBaseOutStructure*>(const_cast<void*>(pCreateInfo->pCreateInfo->pNext));
    detail::GatherStructureTypes(structureTypes, pNext);

    chain->Build(structureTypes);

    VkPhysicalDeviceFeatures2KHR* pFeatures = &chain->requiredFeaturesChain;
    if (pCreateInfo->pCreateInfo->pEnabledFeatures) {
        pFeatures->features = *pCreateInfo->pCreateInfo->pEnabledFeatures;
    }

    for (std::size_t block_index = 0, block_count = blocks.size(); block_index < block_count; ++block_index) {
        const detail::VpProfileDesc* pProfileDesc = detail::vpGetProfileDesc(blocks[block_index].profiles.profileName);
        if (pProfileDesc == nullptr) {
            return VK_ERROR_UNKNOWN;
        }

        for (std::size_t caps_index = 0, caps_count = pProfileDesc->requiredCapabilityCount; caps_index < caps_count; ++caps_index) {
            const detail::VpCapabilitiesDesc* pCapsDesc = &pProfileDesc->pRequiredCapabilities[caps_index];

            if (pCapsDesc->variantCount > 1) {
                continue; // Multiple variants are not supported by this version of vpCreateDevice
            }

            for (std::size_t variant_index = 0, variant_count = pCapsDesc->variantCount; variant_index < variant_count; ++variant_index) {
                const detail::VpVariantDesc* variant = &pCapsDesc->pVariants[variant_index];

                if (!is_variant_enabled(variant)) {
                    continue;
                }

                VkBaseOutStructure* base_ptr = reinterpret_cast<VkBaseOutStructure*>(pFeatures);
                if (variant->feature.pfnFiller != nullptr) {
                    while (base_ptr != nullptr) {
                        variant->feature.pfnFiller(base_ptr);
                        base_ptr = base_ptr->pNext;
                    }
                }
            }
        }
    }

    chain->ApplyFeatures(pCreateInfo);

    if (pCreateInfo->flags & VP_DEVICE_CREATE_DISABLE_ROBUST_BUFFER_ACCESS_BIT) {
        pFeatures->features.robustBufferAccess = VK_FALSE;
    }

    VkDeviceCreateInfo createInfo{VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO};
    createInfo.pNext = &chain->requiredFeaturesChain;
    createInfo.queueCreateInfoCount = pCreateInfo->pCreateInfo->queueCreateInfoCount;
    createInfo.pQueueCreateInfos = pCreateInfo->pCreateInfo->pQueueCreateInfos;
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    return vp.CreateDevice(physicalDevice, &createInfo, pAllocator, pDevice);
}

VPAPI_ATTR VkResult vpGetProfileInstanceExtensionProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) {
    return detail::vpGetProfileExtensionProperties(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::EXTENSION_INSTANCE, pPropertyCount, pProperties);
}

VPAPI_ATTR VkResult vpGetProfileDeviceExtensionProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) {
    return detail::vpGetProfileExtensionProperties(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::EXTENSION_DEVICE, pPropertyCount, pProperties);
}

VPAPI_ATTR VkResult vpGetProfileFeatures(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    void*                                       pNext) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                if (variant.feature.pfnFiller == nullptr) continue;

                VkBaseOutStructure* p = static_cast<VkBaseOutStructure*>(pNext);
                while (p != nullptr) {
                    variant.feature.pfnFiller(p);
                    p = p->pNext;
                }
            }
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    void*                                       pNext) {
    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    VkBool32 multiple_variants = VK_FALSE;
    if (vpHasMultipleVariantsProfile(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile,
        &multiple_variants) == VK_ERROR_UNKNOWN) {
        return VK_ERROR_UNKNOWN;
    }
    if (multiple_variants == VK_TRUE && pBlockName == nullptr) {
        return VK_ERROR_UNKNOWN;
    }

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                if (variant.property.pfnFiller == nullptr) continue;

                VkBaseOutStructure* p = static_cast<VkBaseOutStructure*>(pNext);
                while (p != nullptr) {
                    variant.property.pfnFiller(p);
                    p = p->pNext;
                }
            }
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileQueueFamilyProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pPropertyCount,
    VkQueueFamilyProperties2KHR*                pProperties) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    if (pPropertyCount == nullptr) return VK_ERROR_UNKNOWN;

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    uint32_t total_queue_family_count = 0;

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                if (pProperties != nullptr) {
                    for (uint32_t i = 0; i < variant.queueFamilyCount; ++i) {
                        if (total_queue_family_count < *pPropertyCount) {
                            if (variant.pQueueFamilies[i].pfnFiller == nullptr) continue;

                            VkBaseOutStructure* p = reinterpret_cast<VkBaseOutStructure*>(pProperties);
                            while (p != nullptr) {
                                variant.pQueueFamilies[i].pfnFiller(p);
                                p = p->pNext;
                            }

                            total_queue_family_count++;
                            pProperties++;
                        } else {
                            result = VK_INCOMPLETE;
                            break;
                        }
                    }
                } else {
                    total_queue_family_count += variant.queueFamilyCount;
                }
            }
        }
    }

    *pPropertyCount = total_queue_family_count;
    return result;
}

VPAPI_ATTR VkResult vpGetProfileFormats(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pFormatCount,
    VkFormat*                                   pFormats) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    std::vector<VkFormat> results;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                for (uint32_t format_index = 0; format_index < variant.formatCount; ++format_index) {
                    if (std::find(results.begin(), results.end(), variant.pFormats[format_index].format) == std::end(results)) {
                        results.push_back(variant.pFormats[format_index].format);
                    }
                }
            }
        }
    }

    const uint32_t count = static_cast<uint32_t>(results.size());

    if (pFormats == nullptr) {
        *pFormatCount = count;
    } else {
        if (*pFormatCount < count) {
            result = VK_INCOMPLETE;
        } else {
            *pFormatCount = count;
        }

        if (*pFormatCount > 0) {
            memcpy(pFormats, &results[0], *pFormatCount * sizeof(VkFormat));
        }
    }
    return result;
}

VPAPI_ATTR VkResult vpGetProfileFormatProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    VkFormat                                    format,
    void*                                       pNext) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const char* profile_name = gathered_profiles[profile_index].profileName;

        const detail::VpProfileDesc* pProfileDesc = detail::vpGetProfileDesc(profile_name);
        if (pProfileDesc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t required_capability_index = 0; required_capability_index < pProfileDesc->requiredCapabilityCount;
                ++required_capability_index) {
            const detail::VpCapabilitiesDesc& required_capabilities = pProfileDesc->pRequiredCapabilities[required_capability_index];

            for (uint32_t required_variant_index = 0; required_variant_index < required_capabilities.variantCount; ++required_variant_index) {
                const detail::VpVariantDesc& variant = required_capabilities.pVariants[required_variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                for (uint32_t format_index = 0; format_index < variant.formatCount; ++format_index) {
                    if (variant.pFormats[format_index].format != format) {
                        continue;
                    }

                    VkBaseOutStructure* base_ptr = static_cast<VkBaseOutStructure*>(static_cast<void*>(pNext));
                    while (base_ptr != nullptr) {
                        variant.pFormats[format_index].pfnFiller(base_ptr);
                        base_ptr = base_ptr->pNext;
                    }
#if defined(VK_VERSION_1_3) || defined(VK_KHR_format_feature_flags2)
                    VkFormatProperties2KHR* fp2 = static_cast<VkFormatProperties2KHR*>(
                        detail::vpGetStructure(pNext, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR));
                    VkFormatProperties3KHR* fp3 = static_cast<VkFormatProperties3KHR*>(
                        detail::vpGetStructure(pNext, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR));
                    if (fp3 != nullptr) {
                        VkFormatProperties2KHR fp{ VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR };
                        variant.pFormats[format_index].pfnFiller(static_cast<VkBaseOutStructure*>(static_cast<void*>(&fp)));
                        fp3->linearTilingFeatures |= static_cast<VkFormatFeatureFlags2KHR>(fp3->linearTilingFeatures | fp.formatProperties.linearTilingFeatures);
                        fp3->optimalTilingFeatures |= static_cast<VkFormatFeatureFlags2KHR>(fp3->optimalTilingFeatures | fp.formatProperties.optimalTilingFeatures);
                        fp3->bufferFeatures |= static_cast<VkFormatFeatureFlags2KHR>(fp3->bufferFeatures | fp.formatProperties.bufferFeatures);
                    }
                    if (fp2 != nullptr) {
                        VkFormatProperties3KHR fp{ VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR };
                        variant.pFormats[format_index].pfnFiller(static_cast<VkBaseOutStructure*>(static_cast<void*>(&fp)));
                        fp2->formatProperties.linearTilingFeatures |= static_cast<VkFormatFeatureFlags>(fp2->formatProperties.linearTilingFeatures | fp.linearTilingFeatures);
                        fp2->formatProperties.optimalTilingFeatures |= static_cast<VkFormatFeatureFlags>(fp2->formatProperties.optimalTilingFeatures | fp.optimalTilingFeatures);
                        fp2->formatProperties.bufferFeatures |= static_cast<VkFormatFeatureFlags>(fp2->formatProperties.bufferFeatures | fp.bufferFeatures);
                    }
#endif
                }
            }
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileFeatureStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
    return detail::vpGetProfileStructureTypes(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::STRUCTURE_FEATURE, pStructureTypeCount, pStructureTypes);
}

VPAPI_ATTR VkResult vpGetProfilePropertyStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
    return detail::vpGetProfileStructureTypes(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::STRUCTURE_PROPERTY, pStructureTypeCount, pStructureTypes);
}

VPAPI_ATTR VkResult vpGetProfileQueueFamilyStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
    return detail::vpGetProfileStructureTypes(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::STRUCTURE_QUEUE_FAMILY, pStructureTypeCount, pStructureTypes);
}

VPAPI_ATTR VkResult vpGetProfileFormatStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
    return detail::vpGetProfileStructureTypes(
#ifdef VP_USE_OBJECT
        functions,
#endif//VP_USE_OBJECT
        pProfile, pBlockName, detail::STRUCTURE_FORMAT, pStructureTypeCount, pStructureTypes);
}

#ifdef VK_KHR_video_queue
// Query the list of video profiles specified by the profile
VPAPI_ATTR VkResult vpGetProfileVideoProfiles(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t*                                   pVideoProfileCount,
    VpVideoProfileProperties*                   pVideoProfiles) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT
    if (pVideoProfileCount == nullptr) return VK_ERROR_UNKNOWN;

    VkResult result = pBlockName == nullptr ? VK_SUCCESS : VK_INCOMPLETE;

    uint32_t total_video_profile_count = 0;

    const std::vector<VpProfileProperties>& gathered_profiles = detail::GatherProfiles(*pProfile);

    for (std::size_t profile_index = 0, profile_count = gathered_profiles.size(); profile_index < profile_count; ++profile_index) {
        const detail::VpProfileDesc* profile_desc = detail::vpGetProfileDesc(gathered_profiles[profile_index].profileName);
        if (profile_desc == nullptr) return VK_ERROR_UNKNOWN;

        for (uint32_t capability_index = 0; capability_index < profile_desc->requiredCapabilityCount; ++capability_index) {
            const detail::VpCapabilitiesDesc& cap_desc = profile_desc->pRequiredCapabilities[capability_index];

            for (uint32_t variant_index = 0; variant_index < cap_desc.variantCount; ++variant_index) {
                const detail::VpVariantDesc& variant = cap_desc.pVariants[variant_index];
                if (pBlockName != nullptr) {
                    if (strcmp(variant.blockName, pBlockName) != 0) {
                        continue;
                    }
                    result = VK_SUCCESS;
                } else if (variant.pfnDepends != nullptr) {
                    continue; // The capability blocks with a 'depends' condition are only returned when explicitly requested
                }

                if (pVideoProfiles != nullptr) {
                    for (uint32_t i = 0; i < variant.videoProfileCount; ++i) {
                        if (total_video_profile_count < *pVideoProfileCount) {
                            *pVideoProfiles = variant.pVideoProfiles[i].properties;
                            total_video_profile_count++;
                            pVideoProfiles++;
                        } else {
                            result = VK_INCOMPLETE;
                            break;
                        }
                    }
                } else {
                    total_video_profile_count += variant.videoProfileCount;
                }
            }
        }
    }

    *pVideoProfileCount = total_video_profile_count;
    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoProfileInfo(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    VkVideoProfileInfoKHR*                      pVideoProfileInfo) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    if (pVideoProfileDesc != nullptr) {
        VkBaseOutStructure* p = reinterpret_cast<VkBaseOutStructure*>(pVideoProfileInfo);
        while (p != nullptr) {
            pVideoProfileDesc->info.pfnFiller(p);
            p = p->pNext;
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoCapabilities(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    void*                                       pNext) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    if (pVideoProfileDesc != nullptr) {
        VkBaseOutStructure* p = reinterpret_cast<VkBaseOutStructure*>(pNext);
        while (p != nullptr) {
            pVideoProfileDesc->capability.pfnFiller(p);
            p = p->pNext;
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoFormatProperties(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pPropertyCount,
    VkVideoFormatPropertiesKHR*                 pProperties) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    uint32_t property_count = 0;
    if (pVideoProfileDesc != nullptr) {
        if (pProperties != nullptr) {
            for (; property_count < pVideoProfileDesc->formatCount; ++property_count) {
                if (property_count < *pPropertyCount) {
                    VkBaseOutStructure* p = reinterpret_cast<VkBaseOutStructure*>(&pProperties[property_count]);
                    while (p != nullptr) {
                        pVideoProfileDesc->pFormats[property_count].pfnFiller(p);
                        p = p->pNext;
                    }
                } else {
                    result = VK_INCOMPLETE;
                    break;
                }
            }
        } else {
            property_count = pVideoProfileDesc->formatCount;
        }
    }

    *pPropertyCount = property_count;
    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoProfileInfoStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    if (pVideoProfileDesc != nullptr) {
        if (pStructureTypes != nullptr) {
            if (*pStructureTypeCount < pVideoProfileDesc->infoStructTypeCount) {
                result = VK_INCOMPLETE;
            } else {
                *pStructureTypeCount = pVideoProfileDesc->infoStructTypeCount;
            }
            if (*pStructureTypeCount > 0) {
                memcpy(pStructureTypes, pVideoProfileDesc->pInfoStructTypes, *pStructureTypeCount * sizeof(VkStructureType));
            }
        } else {
            *pStructureTypeCount = pVideoProfileDesc->infoStructTypeCount;
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoCapabilityStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    if (pVideoProfileDesc != nullptr) {
        if (pStructureTypes != nullptr) {
            if (*pStructureTypeCount < pVideoProfileDesc->capabilityStructTypeCount) {
                result = VK_INCOMPLETE;
            } else {
                *pStructureTypeCount = pVideoProfileDesc->capabilityStructTypeCount;
            }
            if (*pStructureTypeCount > 0) {
                memcpy(pStructureTypes, pVideoProfileDesc->pCapabilityStructTypes, *pStructureTypeCount * sizeof(VkStructureType));
            }
        } else {
            *pStructureTypeCount = pVideoProfileDesc->capabilityStructTypeCount;
        }
    }

    return result;
}

VPAPI_ATTR VkResult vpGetProfileVideoFormatStructureTypes(
#ifdef VP_USE_OBJECT
    VpFunctions                                 functions,
#endif//VP_USE_OBJECT
    const VpProfileProperties*                  pProfile,
    const char*                                 pBlockName,
    uint32_t                                    videoProfileIndex,
    uint32_t*                                   pStructureTypeCount,
    VkStructureType*                            pStructureTypes) {
#ifdef VP_USE_OBJECT
    (void)functions;
#endif//VP_USE_OBJECT

    const detail::VpVideoProfileDesc* pVideoProfileDesc = nullptr;
    VkResult result = detail::vpGetProfileVideoProfileDesc(pProfile, pBlockName, videoProfileIndex, &pVideoProfileDesc);

    if (pVideoProfileDesc != nullptr) {
        if (pStructureTypes != nullptr) {
            if (*pStructureTypeCount < pVideoProfileDesc->formatStructTypeCount) {
                result = VK_INCOMPLETE;
            } else {
                *pStructureTypeCount = pVideoProfileDesc->formatStructTypeCount;
            }
            if (*pStructureTypeCount > 0) {
                memcpy(pStructureTypes, pVideoProfileDesc->pFormatStructTypes, *pStructureTypeCount * sizeof(VkStructureType));
            }
        } else {
            *pStructureTypeCount = pVideoProfileDesc->formatStructTypeCount;
        }
    }

    return result;
}
#endif  // VK_KHR_video_queue
