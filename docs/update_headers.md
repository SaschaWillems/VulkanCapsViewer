# Updating Vulkan Headers

Run the ```updateheaders.bat``` batch file located in the tools folder. This will:

- Update the Vulkan-Headers submodule to the latest commit on main
- Generate the device extension C++ header and source file from the Vulkan xml registry using a PHP script
- Copies them to the root directory

*Note*: This requires a current PHP 7.4 (or newer) installation in your system path.