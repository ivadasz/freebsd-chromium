--- base/memory/ref_counted.h.orig	2015-01-12 12:43:12 UTC
+++ base/memory/ref_counted.h
@@ -17,7 +17,7 @@
 #include "base/threading/thread_collision_warner.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS)) || defined(OS_BSD)
 #define DISABLE_SCOPED_REFPTR_CONVERSION_OPERATOR
 #endif
 
