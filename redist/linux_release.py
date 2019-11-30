import os
import subprocess
import tarfile
import shutil
from glob import glob

release_name = '2_03'

qmake_path = '/home/sascha/Qt/5.12.4/gcc_64/bin/qmake'

# Create separate AppImage folder structure
dst_path = './linux/vulkancapsviewer'
dirs = ['/usr', '/usr/bin', '/usr/share/applications/', '/usr/icons/hicolor/256x256/apps']
for dir_name in dirs:
    if not os.path.exists(dst_path + dir_name):
        os.makedirs(dst_path + dir_name)

shutil.copy2('../vulkanCapsViewer', dst_path+'/usr/bin/')
shutil.copy2('../vulkanCapsViewer.desktop', dst_path+'/usr/share/applications/')
shutil.copy2('../vulkanCapsViewer.png', dst_path+'/usr/icons/hicolor/256x256/apps')

if not os.path.isfile('./linuxdeployqt-6-x86_64.AppImage'):
    print("linuxdeployqt binary not found!")
    quit()

fnames = glob(os.path.join("*.AppImage"))
for fname in fnames:
    os.remove(fname)

subprocess.call(['./linuxdeployqt-6-x86_64.AppImage "./linux/vulkancapsviewer/usr/share/applications/vulkanCapsViewer.desktop" -qmake="'+qmake_path+'" -appimage'], shell=True)

fname = glob(os.path.join("Vulkan*.AppImage"))[0]
os.rename(fname, "Vulkan_Caps_Viewer-x86_64.AppImage")

tar = tarfile.open('vulkancapsviewer_'+release_name+'_linux64.tar.gz', "w:gz")
tar.add("Vulkan_Caps_Viewer-x86_64.AppImage")
tar.close()
