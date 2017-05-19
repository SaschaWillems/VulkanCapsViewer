Newer Android versions no longer come with SSL libraries and using a recent Qt version will result in crashes when these are not installed and the app tries to do http requests (even non-https).

So the Android builds now require manually built OpenSSL libraries.

Put the built shared libraries for your target platform in the appropriate folder.

For details see http://doc.qt.io/qt-5/opensslsupport.html