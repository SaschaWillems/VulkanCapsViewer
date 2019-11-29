import os
import subprocess
import tarfile
from glob import glob

release_name = '2_03'

dst_path = './'

subprocess.call(['./linuxdeployqt-6-x86_64.AppImage "../vulkanCapsViewer.desktop" -qmake="/home/sascha/Qt/5.12.4/gcc_64/bin/qmake" -appimage'], shell=True)

fname = glob(os.path.join("*.AppImage"))[0]
os.rename(fname, "Vulkan_Caps_Viewer-x86_64.AppImage")

tar = tarfile.open('vulkancapsviewer_'+release_name+'_linux.tar.gz', "w:gz");
tar.add("Vulkan_Caps_Viewer-x86_64.AppImage")
tar.close()
