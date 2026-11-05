# Copyright (c) 2026, Sascha Willems
# SPDX-License-Identifier: GPL-3.0-only

cmake_minimum_required(VERSION 3.16)
project(reportJsonTests LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core)

enable_testing()
add_executable(reportJsonTests reportJsonTests.cpp)
target_compile_features(reportJsonTests PRIVATE cxx_std_17)
target_link_libraries(reportJsonTests PRIVATE Qt6::Core)
add_test(NAME reportJsonTests COMMAND reportJsonTests)

option(REPORT_JSON_INTEGRATION_TESTS "Build report export integration tests" OFF)
if(REPORT_JSON_INTEGRATION_TESTS)
    find_package(Qt6 REQUIRED COMPONENTS Gui Widgets Network)
    find_package(Vulkan REQUIRED)
    add_executable(reportExportTests
        reportExportTests.cpp
        ../vulkanDeviceInfo.cpp
        ../vulkanDeviceInfoExtensions.cpp
        ../vulkanContext.cpp
        ../vulkanAndroid.cpp)
    target_compile_features(reportExportTests PRIVATE cxx_std_20)
    target_compile_definitions(reportExportTests PRIVATE DISABLE_PROFILES VK_ENABLE_BETA_EXTENSIONS)
    if(WIN32)
        target_compile_definitions(reportExportTests PRIVATE VK_USE_PLATFORM_WIN32_KHR)
    endif()
    target_include_directories(reportExportTests PRIVATE ../Vulkan-Headers/include ..)
    target_link_libraries(reportExportTests PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Vulkan::Vulkan)
    add_test(NAME reportExportTests COMMAND reportExportTests)
endif()
