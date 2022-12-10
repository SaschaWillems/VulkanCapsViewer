<?php

function download($remote, $local) {
    $remote_file = fopen("https://www.vulkan.gpuinfo.org/downloads/automated/$remote", 'r');
    if ($remote_file) {
        file_put_contents($local, $remote_file);
        fclose($remote_file);
    } else {
        throw new Exception("Could not download remote file!");
        exit();
    }
}

$version = "3.27";
$name_template = "vulkancapsviewer_".$version."_%s";

# Windows 64 bit
download('Vulkan_Caps_Viewer-windows.zip', sprintf($name_template, 'win64.zip'));

# Windows 32 bit
download('Vulkan_Caps_Viewer-windows_x86.zip', sprintf($name_template, 'winx86.zip'));

# Linux X11
download('Vulkan_Caps_Viewer-X11-x86_64.AppImage', sprintf($name_template, 'linux64.AppImage'));

# Linux Wayland
download('Vulkan_Caps_Viewer-wayland-x86_64.AppImage', sprintf($name_template, 'linux64_wayland.AppImage'));

# OSX
download('Vulkan_Caps_Viewer-osx-x86_64.dmg', sprintf($name_template, 'osx.dmg'));