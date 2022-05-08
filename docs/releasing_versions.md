# Releasing new releases

## Before

- Update ```VulkanCapsViewer::version``` in ```vulkancapsviewer.cpp```
- Update ```versionName``` and ```versionCode``` in the Android manifest

## After

Gitlab CI automatically builds packages for:

- Windows 64 bit
- Windows 32 bit
- Linux X11
- Linux Wayland
- OSX

For those platforms, update the ```$version``` in the ```download_releases.php``` file in the ```tools``` folder and run that script. It'll download those packages and rename them accordingly so they can be uploaded via FTP.

Android still needs to be manually build and signed using QT Creator so it can be uploaded to Google Play.