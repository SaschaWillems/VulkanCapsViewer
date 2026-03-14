# example usage:
# You must tell cmake where to find the Vulkan Headers and a loader library. For example on macOS:
#
# cmake .. -DVULKAN_LOADER_INSTALL_DIR=/Users/lunarg/VulkanSDK/1.3.230.0/macOS
# cmake --build . --config Release  

cmake_minimum_required(VERSION 3.10.2)

if(WIN32)
    # Use the static runtime library? This allows Windows to link against static builds of Qt
    # Note, this has to come early in the CMakeLists.txt
    if(USE_STATIC_RT)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        message(STATUS "Vulkan Caps Viewer will link against static runtime on Windows")
    endif()    
endif()

project(VK_CAPS_VIEWER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network QUIET)

option(USE_STATIC_RT "Use static C runtime (for when linking against static Qt libraries")


file(GLOB FILES_UI ./*.ui)

source_group("UI Files" FILES ${FILES_UI})

file(GLOB FILES_SOURCE ./*.cpp)
file(GLOB FILES_HEADER ./*.h)


if(NOT APPLE)
    set(FILES_ALL ${FILES_UI} ${FILES_SOURCE} ${FILES_HEADER} vulkancapsviewer.qrc)

    if(WIN32)
        add_executable(vulkanCapsViewer WIN32 ${FILES_ALL} ${FILES_UI})
        target_compile_definitions(vulkanCapsViewer PRIVATE _CRT_SECURE_NO_WARNINGS VK_USE_PLATFORM_WIN32_KHR)
    else()
    	# Linux only
	# find_package(Qt6 REQUIRED COMPONENTS x11extras QUIET)
 	add_executable(vulkanCapsViewer ${FILES_ALL} ${FILES_UI})
 	if(X11)
	    target_compile_definitions(vulkanCapsViewer PRIVATE  VK_USE_PLATFORM_XCB_KHR)
	endif()
	if(WAYLAND)
      find_package(Qt6 REQUIRED COMPONENTS WaylandClient)
	    target_compile_definitions(vulkanCapsViewer PRIVATE  VK_USE_PLATFORM_WAYLAND_KHR)	
	endif()
    endif()
else()
    # APPLE only
    set(FILES_ALL ${FILES_UI} ${FILES_SOURCE} ${FILES_HEADER} appleutils.mm vulkancapsviewer.qrc)

    add_executable(vulkanCapsViewer MACOSX_BUNDLE ${FILES_ALL} ${FILES_UI} ${CMAKE_CURRENT_SOURCE_DIR}/vulkanCapsViewer.icns)

    set_target_properties(vulkanCapsViewer PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/macOS/Info.plist)
    set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/vulkanCapsViewer.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    target_compile_definitions(vulkanCapsViewer PRIVATE VK_USE_PLATFORM_MACOS_MVK)
endif()

target_compile_definitions(vulkanCapsViewer PRIVATE QT_NO_DEBUG_OUTPUT)
target_compile_definitions(vulkanCapsViewer PRIVATE QT_NO_WARNING_OUTPUT)
target_compile_definitions(vulkanCapsViewer PRIVATE VK_ENABLE_BETA_EXTENSIONS)
target_compile_definitions(vulkanCapsViewer PRIVATE QT_NETWORK_LIB)
target_compile_definitions(vulkanCapsViewer PRIVATE QT_WIDGETS_LIB)


# Define GNU standard installation directories.
include(GNUInstallDirs)
install(TARGETS vulkanCapsViewer DESTINATION ${CMAKE_INSTALL_BINDIR})

if (NOT VULKAN_HEADERS_INSTALL_DIR)
    # By default use the Vulkan-Headers submodule
    target_include_directories(vulkanCapsViewer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Headers/include" "./")
else()
    target_include_directories(vulkanCapsViewer PRIVATE "${VULKAN_HEADERS_INSTALL_DIR}/include" "./")
endif()
target_compile_definitions(vulkanCapsViewer PRIVATE ${VULKANCAPSVIEWER_DEFINITIONS})

if(NOT APPLE)
    if(WIN32)
        target_link_libraries(vulkanCapsViewer Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/vulkan-1.lib")
    else()
        # Linux...
	if(X11)
	    target_link_libraries(vulkanCapsViewer Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::x11extras "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.so")
        elseif(WAYLAND)
          target_link_libraries(vulkanCapsViewer Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::WaylandClient "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.so")
        else()
	    target_link_libraries(vulkanCapsViewer Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.so")        
        endif()
    endif()
else() 
    # APPLE
    target_link_libraries(vulkanCapsViewer "-framework Cocoa -framework QuartzCore")

    add_custom_command(TARGET vulkanCapsViewer POST_BUILD
        COMMAND cp
        "${CMAKE_CURRENT_SOURCE_DIR}/macOS/Info.plist"
        "${CMAKE_CURRENT_BINARY_DIR}/vulkanCapsViewer.app/Contents/"
        COMMENT "Copying Info.plist to vulkanCapsViewer.app...")


    set_target_properties(vulkanCapsViewer PROPERTIES SKIP_BUILD_RPATH FALSE)
    set_target_properties(vulkanCapsViewer PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
    set_target_properties(vulkanCapsViewer PROPERTIES INSTALL_RPATH "")
    set_target_properties(vulkanCapsViewer PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
    target_link_libraries(vulkanCapsViewer Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.1.dylib")
endif()


get_target_property(QMAKE_EXE Qt6::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXE}" DIRECTORY)

