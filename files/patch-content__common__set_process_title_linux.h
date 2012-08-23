--- ./content/common/set_process_title_linux.h.orig	2012-08-17 03:01:27.000000000 +0200
+++ ./content/common/set_process_title_linux.h	2012-08-23 22:31:44.000000000 +0200
@@ -6,6 +6,9 @@
 #define CONTENT_COMMON_SET_PROCESS_TITLE_LINUX_H_
 #pragma once
 
+#include "build/build_config.h"
+
+#if !defined(OS_FREEBSD)
 // Set the process title that will show in "ps" and similar tools. Takes
 // printf-style format string and arguments. After calling setproctitle()
 // the original main() argv[] array should not be used. By default, the
@@ -15,6 +18,7 @@
 // This signature and naming is to be compatible with most other Unix
 // implementations of setproctitle().
 void setproctitle(const char* fmt, ...);
+#endif
 
 // Initialize state needed for setproctitle() on Linux. Pass the argv pointer
 // from main() to setproctitle_init() before calling setproctitle().
