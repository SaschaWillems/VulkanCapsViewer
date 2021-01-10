/*
*
* Vulkan hardware capability viewer
*
* Surface information class
*
* Copyright (C) 2016-2020 by Sascha Willems (www.saschawillems.de)
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

#include <QWidget>

#include <vector>
#include "vulkan/vulkan.h"

#include "vulkanandroid.h"

struct VulkanSurfaceInfo
{
    bool validSurface = false;
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkPresentModeKHR> presentModes;
    std::vector<VkSurfaceFormatKHR> formats;
    std::string surfaceExtension;

    void get(VkPhysicalDevice device, VkSurfaceKHR surface)
    {
        if (!validSurface) {
           return;
        }

        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &capabilities);

        // Present modes
        uint32_t presentModeCount;
        if (vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, nullptr) == VK_SUCCESS)
        {
            presentModes.resize(presentModeCount);
            if (presentModeCount > 0)
            {
                vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, presentModes.data());
            }
        }

        // Surface formats
        uint32_t surfaceFormatCount;
        if (vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &surfaceFormatCount, nullptr) == VK_SUCCESS)
        {
            formats.resize(surfaceFormatCount);
            if (surfaceFormatCount > 0)
            {
                vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &surfaceFormatCount, formats.data());
            }
        }
    }
};
