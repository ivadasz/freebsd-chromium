--- chrome/common/chrome_paths.h.orig	2015-06-11 21:05:28 UTC
+++ chrome/common/chrome_paths.h
@@ -57,7 +57,7 @@
                                  // Getting this path does not create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -114,7 +114,7 @@
   DIR_SUPERVISED_USERS_DEFAULT_APPS,  // Directory where installer places .crx
                                       // files to be installed when managed user
                                       // session starts.
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
