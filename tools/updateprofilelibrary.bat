curl -o vulkan_profiles.hpp https://raw.githubusercontent.com/KhronosGroup/Vulkan-Profiles/master/library/include/vulkan/vulkan_profiles.hpp
copy /Y vulkan_profiles.hpp ..\profiles
del vulkan_profiles.hpp