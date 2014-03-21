--- ./base/test/launcher/test_launcher.cc.orig	2014-03-19 20:01:55.000000000 +0100
+++ ./base/test/launcher/test_launcher.cc	2014-03-21 00:27:12.000000000 +0100
@@ -39,6 +39,10 @@
 #include "base/mac/scoped_nsautorelease_pool.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
