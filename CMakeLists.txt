cmake_minimum_required(VERSION 3.10.2)
project(VK_CAPS_VIEWER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network QUIET)

file(GLOB FILES_UI ./*.ui)

source_group("UI Files" FILES ${FILES_UI})

file(GLOB FILES_SOURCE ./*.cpp)
file(GLOB FILES_HEADER ./*.h)

set(FILES_ALL ${FILES_UI} ${FILES_SOURCE} ${FILES_HEADER} appleutils.mm vulkancapsviewer.qrc)

if(NOT APPLE)
    if(WIN32)
        add_executable(vulkanCapsViewer WIN32 ${FILES_ALL} ${FILES_UI})
        target_compile_definitions(vulkanCapsViewer PRIVATE _CRT_SECURE_NO_WARNINGS VK_USE_PLATFORM_WIN32_KHR)
    else()
    	# Linux only
	find_package(REQUIRED COMPONENTS waylandclient QUIET)
 	add_executable(vulkanCapsViewer ${FILES_ALL} ${FILES_UI})
        target_compile_definitions(vulkanCapsViewer PRIVATE  VK_USE_PLATFORM_WAYLAND_KHR)
    endif()
else()
    # APPLE only
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

target_include_directories(vulkanCapsViewer PRIVATE "${VULKAN_HEADERS_INSTALL_DIR}/include" "./")
target_compile_definitions(vulkanCapsViewer PRIVATE ${VULKANCAPSVIEWER_DEFINITIONS})

if(NOT APPLE)
    if(WIN32)
        target_link_libraries(vulkanCapsViewer Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/vulkan-1.lib")
    else()
        # Linux...
        target_link_libraries(vulkanCapsViewer Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network waylandclient "${VULKAN_LOADER_INSTALL_DIR}/lib/vulkan")
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
    target_link_libraries(vulkanCapsViewer Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network "${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.1.dylib")
endif()


get_target_property(QMAKE_EXE Qt5::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXE}" DIRECTORY)

