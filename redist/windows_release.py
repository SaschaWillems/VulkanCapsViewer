import shutil
import os
import zipfile

release_name = '2_03'

dst_path = './windows/vulkancapsviewer'
if not os.path.exists(dst_path):
    os.makedirs(dst_path)
if not os.path.exists(dst_path+ '/platforms'):
    os.makedirs(dst_path+ '/platforms')

shutil.copy2('../Win32/Release/vulkanCapsViewer.exe', dst_path)

qt_path = 'V:/Qt/5.13.2/msvc2017_64'
qt_files = ['Qt5Core.dll', 'Qt5Gui.dll', 'Qt5Network.dll', 'Qt5Svg.dll', 'Qt5Widgets.dll']

for qt_file in qt_files:
    shutil.copy2(qt_path + '/bin/' + qt_file, dst_path)

shutil.copy2(qt_path + '/plugins/platforms/qwindows.dll', dst_path + '/platforms')

os.chdir('windows')
zip_file = zipfile.ZipFile('../vulkancapsviewer_'+release_name+'_win64.zip', 'w')
for root, dirs, files in os.walk('vulkancapsviewer'):
    for file in files:
        zip_file.write(os.path.join(root, file), compress_type=zipfile.ZIP_LZMA)
zip_file.close()
os.chdir('..')