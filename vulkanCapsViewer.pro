# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = vulkanCapsViewer
QT += core network widgets gui
CONFIG += c++17
#CONFIG += release bad for debugging
DEFINES += QT_DLL QT_NETWORK_LIB QT_WIDGETS_LIB VK_ENABLE_BETA_EXTENSIONS
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Release
INCLUDEPATH += "Vulkan-Headers/include"
INCLUDEPATH += "/Vulkan-Headers/include"
win32 {
    DEFINES += WIN64
    DEFINES += VK_USE_PLATFORM_WIN32_KHR
    win32:contains(QMAKE_HOST.arch, x86_64) {
        LIBS += "$$PWD/libs/vulkan/lib/vulkan-1.lib"
    } else {
        LIBS += "$$PWD/libs/vulkan/lib32/vulkan-1.lib"
    }
    LIBS += Advapi32.lib
}
linux:!android {
    LIBS += -lvulkan
    contains(DEFINES, X11) {
        message("Building for X11")
        LIBS += -lxcb
        DEFINES += VK_USE_PLATFORM_XCB_KHR
    }
    contains(DEFINES, WAYLAND) {
        message("Building for Wayland")
        LIBS += -lwayland-client
        DEFINES += VK_USE_PLATFORM_WAYLAND_KHR
    }
    target.path = /usr/bin
    INSTALLS += target
    desktop.files = vulkanCapsViewer.desktop
    desktop.path = /usr/share/applications
    icon.extra = cp $$PWD/gfx/android_icon_256.png vulkanCapsViewer.png
    icon.files = vulkanCapsViewer.png
    icon.path = /usr/share/icons/hicolor/256x256/apps/
    INSTALLS += desktop icon
}
android {
    DEFINES += VK_NO_PROTOTYPES
    DEFINES += VK_USE_PLATFORM_ANDROID_KHR
    QT += androidextras
    CONFIG += mobility
    MOBILITY =
    LIBS += -landroid
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/res/values/libs.xml
}
macx {
    DEFINES += VK_USE_PLATFORM_METAL_EXT
    VULKAN_DYLIB = $(VULKAN_SDK)/lib/libvulkan.dylib
    LIBS += $$VULKAN_DYLIB -framework Cocoa -framework QuartzCore
    OBJECTIVE_SOURCES += appleutils.mm
    ICON = $${PWD}/vulkanCapsViewer.icns
}
ios {
    TARGET = "Vulkan Caps Viewer"
    QMAKE_INFO_PLIST = iOS/Info.plist
    DEFINES += VK_USE_PLATFORM_METAL_EXT
    DEFINES += VK_USE_PLATFORM_MACOS_MVK
    LIBS += $(VULKAN_SDK)/lib/MoltenVk.xcframework/ios-arm64/libMoltenVK.a
    LIBS += -framework QuartzCore
    OBJECTIVE_SOURCES += appleutils.mm
    ICON = $${PWD}/iOS/vulkanCapsViewer.png
    }

DEPENDPATH += .
android {
    MOC_DIR = ./GeneratedFiles/release_$${QT_ARCH}
    OBJECTS_DIR = release_$${QT_ARCH}
} else {
    MOC_DIR = ./GeneratedFiles/release
    OBJECTS_DIR = release
}
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(vulkanCapsViewer.pri)
win32:RC_FILE = vulkanCapsViewer.rc

HEADERS +=

SOURCES +=

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

contains(ANDROID_TARGET_ARCH,x86) {
    ANDROID_EXTRA_LIBS = \
        $$PWD/libs/openssl/x86/libcrypto.so \
        $$PWD/libs/openssl/x86/libssl.so
}
