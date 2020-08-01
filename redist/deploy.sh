#!/bin/sh

if [ "$TRAVIS_TAG" = ""]; then 
    curl -F "data=@Vulkan_Caps_Viewer-$TARGET_PLATFORM-x86_64.AppImage" ${upload_url}?release_type=tag
else
    curl -F "data=@Vulkan_Caps_Viewer-$TARGET_PLATFORM-x86_64.AppImage" ${upload_url}?release_type=latest
fi 
