import shutil
import os

release_name = '2_03'

dst_path = './'

shutil.copy2('../android-build/build/outputs/apk/android-build-release-signed.apk', dst_path + 'vulkancapsviewer_'+release_name+'_arm.apk')