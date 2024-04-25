/*
*
* Vulkan hardware capability viewer
*
* Layer information struct
*
* Copyright (C) 2015-2024 by Sascha Willems (www.saschawillems.de)
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

#include "vulkan/vulkan.h"

struct VulkanFormatInfo
{
	VkFormat format;

	uint64_t linearTilingFeatures;
	uint64_t optimalTilingFeatures;
	uint64_t bufferFeatures;

	bool isFeatureFlags2{ false };

	// @todo: deprecate
	bool supported;
};