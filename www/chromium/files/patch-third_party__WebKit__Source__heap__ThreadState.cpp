--- ./third_party/WebKit/Source/heap/ThreadState.cpp.orig	2014-04-02 21:08:51.000000000 +0200
+++ ./third_party/WebKit/Source/heap/ThreadState.cpp	2014-04-04 01:39:18.000000000 +0200
@@ -43,13 +43,21 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
 namespace WebCore {
 
 static void* getStackStart()
 {
-#if defined(__GLIBC__) || OS(ANDROID)
+#if defined(__GLIBC__) || OS(ANDROID) || OS(FREEBSD)
     pthread_attr_t attr;
+#if OS(FREEBSD)
+    if (!pthread_attr_get_np(pthread_self(), &attr)) {
+#else
     if (!pthread_getattr_np(pthread_self(), &attr)) {
+#endif
         void* base;
         size_t size;
         int error = pthread_attr_getstack(&attr, &base, &size);