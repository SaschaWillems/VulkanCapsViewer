#!/bin/sh

if [ "$TARGET_PLATFORM" = "osx" ] then
    if [ "$TRAVIS_TAG" = ""]; then 
        curl -F "data=@Vulkan_Caps_Viewer-osx-x86_64.dmg" ${upload_url}?release_type=tag
    else
        curl -F "data=@Vulkan_Caps_Viewer-osx-x86_64.dmg" ${upload_url}?release_type=latest
    fi 
else
    if [ "$TRAVIS_TAG" = ""]; then 
        curl -F "data=@Vulkan_Caps_Viewer-$TARGET_PLATFORM-x86_64.AppImage" ${upload_url}?release_type=tag
    else
        curl -F "data=@Vulkan_Caps_Viewer-$TARGET_PLATFORM-x86_64.AppImage" ${upload_url}?release_type=latest
    fi 
fi
