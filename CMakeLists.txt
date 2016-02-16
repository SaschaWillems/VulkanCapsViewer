cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(VERSION 2.8)

set(VK_INCLUDE_DIRS ${VK_INCLUDE_DIRS} "/usr/include/vulkan")
set (LIBRARIES "vulkan-1")

project(vulkancapsviewer)
set(NAME vulkancapsviewer)

set(CMAKE_INCLUDE_CURRENT_DIR OFF)
set(CMAKE_AUTOMOC ON)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-std=c++11)
add_definitions(-std=c++0x)

include_directories("." "GeneratedFiles")

file(GLOB SOURCE *.cpp)
file(GLOB HEADER *.h)

#Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
file (GLOB Resources *.qrc)
QT5_ADD_RESOURCES(ResourceSources ${Resources})

include_directories(external/vulkan)

IF(WIN32)
	find_library(VULKAN_LIB NAMES vulkan-0 vulkan PATHS ${CMAKE_SOURCE_DIR}/libs/vulkan)
ELSE(WIN32)
	find_library(VULKAN NAMES vulkan-0 vulkan PATHS /usr/include/vulkan)
ENDIF(WIN32)


include(FindPackageHandleStandardArgs)

set(LIBRARIES "vulkan")

# Compiler specific stuff
IF(MSVC)
    SET(CMAKE_CXX_FLAGS "/EHsc")
ENDIF(MSVC)

# Set preprocessor define for Vulkan prototypes
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES -DQT_NO_SIGNALS_SLOTS_KEYWORDS")
# Vulkan has some vars named slots that collide with Qt slots


# Unicode
add_definitions(-DUNICODE -D_UNICODE)

link_libraries(${XCB_LIBRARIES} vulkan-1)

add_executable(${NAME} WIN32
${SOURCE}
${HEADER}
${ResourceSources})

target_link_libraries(${NAME} Qt5::Core)	
target_link_libraries(${NAME} Qt5::Gui)	
target_link_libraries(${NAME} Qt5::Network)	
target_link_libraries(${NAME} Qt5::Widgets)
