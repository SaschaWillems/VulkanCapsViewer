# Generating the AppImage for Linux

Required file structure:

```
└── dist
    ├── bin
    │   └── vulkanCapsViewer (binary)
    └── share
        ├── applications
        │   └── vulkanCapsViewer.desktop
        └── icons
            └── vulkanCapsViewer.png
```

Use the latest release from https://github.com/probonopd/linuxdeployqt

Run from where the ```linuxdeployqt``` is located

```bash
./linuxdexployqt-6-x86_64.AppImage "/PATH_TO_ABOVE_STRUCTURE/share/applications/vulkanCapsViewer.desktop" -qmake="PATH_TO_QMAKE_BINARY" -appimage
```

