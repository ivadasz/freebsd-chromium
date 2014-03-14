--- ./chrome/browser/media/webrtc_log_uploader.cc.orig	2014-03-12 20:21:55.000000000 +0100
+++ ./chrome/browser/media/webrtc_log_uploader.cc	2014-03-14 09:23:25.000000000 +0100
@@ -155,6 +155,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
