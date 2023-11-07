cd ..
if not exist "Vulkan-Headers\" (
    git clone https://github.com/KhronosGroup/Vulkan-Headers.git
)
cd Vulkan-Headers
git pull origin main
cd ..
cd tools
php deviceExtensionsFileGenerator.php