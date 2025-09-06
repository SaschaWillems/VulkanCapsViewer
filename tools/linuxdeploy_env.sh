#!/bin/bash
# Exclude system libraries
export LINUXDEPLOY_EXCLUDED_LIBRARIES="libsystemd.so.*;libresolv.so.*;libcap.so.*;libmount.so.*;libblkid.so.*;libX11*;libxcb*;libXcomposite*;libxkbcommon*;libXau*;libXdmcp*;libdrm*;libdbus-1*;libwayland*;libvulkan*"
export NO_STRIP=1
if [[ ${TARGET_PLATFORM} == "wayland" ]]; then
  export EXTRA_QT_PLUGINS=waylandcompositor
  export EXTRA_PLATFORM_PLUGINS="libqwayland-egl.so;libqwayland-generic.so"
fi