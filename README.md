# Vulkan Hardware Capability Viewer

![Vulkan Logo](./images/vulkanlogo.png)

Client application to display hardware implementation details for GPUs supporting the new [Vulkan(tm)](https://www.khronos.org/vulkan]) API by Khronos.

The hardware reports can be submitted to a public [online database](http://vulkan.gpuinfo.org/) that allows comparing different devices, browsing available features, extensions, formats, etc.

<img src="/images/screen01.png" width="320px">

# Supported platforms
**A Vulkan compatible driver (or on Android image) is required**
- Windows (x64)
- Linux (x64)
- Android (Including Android TV)

# API version
Due to the explicit nature of Vulkan, the API version of the Vulkan driver (or Android image) must fit the API level against which the application was build.

# Building
The repository includes a project file for the [Qt creator IDE](http://www.qt.io/ide/) that has been tested to work with Windows, Linux and Android. This is the preferred (and easiest) way of building the application if you want to build it yourself.
It also includes a CMakeLists.txt for use with https://cmake.org/.

# Dependencies
- Vulkan SDK (not available yet)
- [Qt 5.5](https://qt-project.org/) - Older versions may not work due to missing functionality
