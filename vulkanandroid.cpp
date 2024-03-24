#include "vulkanandroid.h"

#ifdef ANDROID
    #include <android/log.h>
    #include <dlfcn.h>

PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkCreateInstance vkCreateInstance;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;

// Dynamically load Vulkan library and base function pointers
bool loadVulkanLibrary()
{        
    __android_log_print(ANDROID_LOG_INFO, "vulkanCapsViewer", "Loading libvulkan.so...\n");

    // Load vulkan library
    void *libVulkan = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    if (!libVulkan)
    {
        __android_log_print(ANDROID_LOG_INFO, "vulkanCapsViewer", "Could not load vulkan library : %s!\n", dlerror());
        return false;
    }

    // Load base function pointers
    vkEnumerateInstanceExtensionProperties = reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(dlsym(libVulkan, "vkEnumerateInstanceExtensionProperties"));
    vkEnumerateInstanceLayerProperties = reinterpret_cast<PFN_vkEnumerateInstanceLayerProperties>(dlsym(libVulkan, "vkEnumerateInstanceLayerProperties"));
    vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(dlsym(libVulkan, "vkEnumerateInstanceVersion"));
    vkCreateInstance = reinterpret_cast<PFN_vkCreateInstance>(dlsym(libVulkan, "vkCreateInstance"));
    vkDestroyInstance = reinterpret_cast<PFN_vkDestroyInstance>(dlsym(libVulkan, "vkDestroyInstance"));
    vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(dlsym(libVulkan, "vkGetInstanceProcAddr"));
    vkGetDeviceProcAddr = reinterpret_cast<PFN_vkGetDeviceProcAddr>(dlsym(libVulkan, "vkGetDeviceProcAddr"));

    return true;
}

// Load instance based Vulkan function pointers
void loadVulkanFunctions()
{
    __android_log_print(ANDROID_LOG_INFO, "vulkanCapsViewer", "Loading instance based function pointers...\n");

    vkEnumeratePhysicalDevices = reinterpret_cast<PFN_vkEnumeratePhysicalDevices>(vkGetInstanceProcAddr(vulkanContext.instance, "vkEnumeratePhysicalDevices"));
    vkGetPhysicalDeviceProperties = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceProperties"));
    vkGetPhysicalDeviceProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceProperties2"));
    vkEnumerateDeviceLayerProperties = reinterpret_cast<PFN_vkEnumerateDeviceLayerProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkEnumerateDeviceLayerProperties"));
    vkEnumerateDeviceExtensionProperties = reinterpret_cast<PFN_vkEnumerateDeviceExtensionProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkEnumerateDeviceExtensionProperties"));
    vkGetPhysicalDeviceQueueFamilyProperties = reinterpret_cast<PFN_vkGetPhysicalDeviceQueueFamilyProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceQueueFamilyProperties"));
    vkGetPhysicalDeviceQueueFamilyProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceQueueFamilyProperties2>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceQueueFamilyProperties2"));
    vkGetPhysicalDeviceFeatures = reinterpret_cast<PFN_vkGetPhysicalDeviceFeatures>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFeatures"));
    vkGetPhysicalDeviceFeatures2 = reinterpret_cast<PFN_vkGetPhysicalDeviceFeatures2>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFeatures2"));
    vkCreateDevice = reinterpret_cast<PFN_vkCreateDevice>(vkGetInstanceProcAddr(vulkanContext.instance, "vkCreateDevice"));
    vkDestroyDevice = reinterpret_cast<PFN_vkDestroyDevice>(vkGetInstanceProcAddr(vulkanContext.instance, "vkDestroyDevice"));
    vkGetPhysicalDeviceFormatProperties = reinterpret_cast<PFN_vkGetPhysicalDeviceFormatProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFormatProperties"));
    vkGetPhysicalDeviceFormatProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceFormatProperties2>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFormatProperties2"));
    vkGetPhysicalDeviceMemoryProperties = reinterpret_cast<PFN_vkGetPhysicalDeviceMemoryProperties>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceMemoryProperties"));

    vkCreateAndroidSurfaceKHR = reinterpret_cast<PFN_vkCreateAndroidSurfaceKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkCreateAndroidSurfaceKHR"));;
    vkDestroySurfaceKHR = reinterpret_cast<PFN_vkDestroySurfaceKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkDestroySurfaceKHR"));;
    vkGetPhysicalDeviceSurfaceSupportKHR = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfaceSupportKHR"));
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR = reinterpret_cast< PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    vkGetPhysicalDeviceSurfaceFormatsKHR = reinterpret_cast< PFN_vkGetPhysicalDeviceSurfaceFormatsKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
    vkGetPhysicalDeviceSurfacePresentModesKHR = reinterpret_cast< PFN_vkGetPhysicalDeviceSurfacePresentModesKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfacePresentModesKHR"));
}

#endif
