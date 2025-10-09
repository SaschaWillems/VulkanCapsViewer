#!/bin/bash
# Exclude system libraries
export LINUXDEPLOY_EXCLUDED_LIBRARIES="libsystemd.so.*;libresolv.so.*;libcap.so.*;libmount.so.*;libbsd.so.*;libblkid.so.*;libffi*;libX11*;libxcb*;libXcomposite*;libXrender*;libXrandr*;libxkbcommon*;libXau*;libXdmcp*;libdrm*;libdbus-1*;libwayland*;libvulkan*;libdbus-1*;libgcrypt.so.*;libkeyutils.so.*;libkrb5.so.*;libk5crypto.so.*;libmd.so.*;libkrb5support.so.*;libgssapi_krb5.so*;libglib-2.0*;libgobject-2.0*;libgio-2.0*;"
export NO_STRIP=1
if [[ ${TARGET_PLATFORM} == "wayland" ]]; then
  export EXTRA_QT_PLUGINS=waylandcompositor
  export EXTRA_PLATFORM_PLUGINS="libqwayland-egl.so;libqwayland-generic.so"
fi