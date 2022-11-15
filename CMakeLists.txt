cmake_minimum_required(VERSION 3.10.2)
project(VK_CAPS_VIEWER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network QUIET)

# See docs on globbing, not recommended: https://cmake.org/cmake/help/latest/command/file.html?highlight=file%20glob#filesystem
file(GLOB FILES_UI ./*.ui)

source_group("UI Files" FILES ${FILES_UI})

# See docs on globbing, not recommended: https://cmake.org/cmake/help/latest/command/file.html?highlight=file%20glob#filesystem
file(GLOB FILES_SOURCE ./*.cpp)
file(GLOB FILES_HEADER ./*.h)

set(FILES_ALL ${FILES_UI} ${FILES_SOURCE} ${FILES_HEADER} vulkancapsviewer.qrc)

add_executable(vulkanCapsViewer WIN32 ${FILES_ALL} ${FILES_UI})
target_compile_definitions(vulkanCapsViewer PRIVATE _CRT_SECURE_NO_WARNINGS)

target_compile_definitions(vulkanCapsViewer PRIVATE QT_NO_DEBUG_OUTPUT)
target_compile_definitions(vulkanCapsViewer PRIVATE QT_NO_WARNING_OUTPUT)
target_compile_definitions(vulkanCapsViewer PRIVATE VK_ENABLE_BETA_EXTENSIONS)

if(WIN32 AND "${VULKAN_LOADER_INSTALL_DIR}" STREQUAL "LOADER-NOTFOUND")
    if(CMAKE_CL_64)
        set(VULKAN_LOADER_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/x64")
    else()
        set(VULKAN_LOADER_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/x86")
    endif()
endif()

# Define GNU standard installation directories.
include(GNUInstallDirs)
install(TARGETS vulkanCapsViewer DESTINATION ${CMAKE_INSTALL_BINDIR})

if(WIN32)
# Windows: if install locations not set by user, set install prefix to "<build_dir>\install".
#set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE)
endif()



target_include_directories(vulkanCapsViewer PRIVATE "${VULKAN_HEADERS_INSTALL_DIR}/include" "./")

if(WIN32)
target_link_libraries(vulkanCapsViewer Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/vulkan-1.lib")
else()
target_link_libraries(vulkanCapsViewer Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.1.dylib")
endif()

target_compile_definitions(vulkanCapsViewer PRIVATE ${VULKANCAPSVIEWER_DEFINITIONS})


if(WIN32)
get_target_property(QMAKE_EXE Qt5::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXE}" DIRECTORY)
endif()

