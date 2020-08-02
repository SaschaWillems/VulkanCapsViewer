import shutil
import os
import sys
import zipfile
import argparse

parser = argparse.ArgumentParser(description='Android redistribution')
parser.add_argument('--release', type=str, help='Release version')
args = parser.parse_args()

if args.release == None:
    sys.exit('No release specified')

release_name = args.release

# Windows

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
        zip_file.write(os.path.join(root, file), compress_type=zipfile.ZIP_DEFLATED)
zip_file.close()
os.chdir('..')

# Android

dst_path = './'

shutil.copy2('../android-build/build/outputs/apk/android-build-release-signed.apk', dst_path + 'vulkancapsviewer_'+release_name+'_arm.apk')