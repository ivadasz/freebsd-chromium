--- ./chrome/browser/chrome_browser_main_posix.cc.orig	2014-03-19 20:02:53.000000000 +0100
+++ ./chrome/browser/chrome_browser_main_posix.cc	2014-03-21 00:27:12.000000000 +0100
@@ -314,6 +314,11 @@
     g_pipe_pid = getpid();
     g_shutdown_pipe_read_fd = pipefd[0];
     g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_FREEBSD)
+    // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+    // we request the default pthread stack size by specifying 0 here.
+    const size_t kShutdownDetectorThreadStackSize = 0;
+#else
 #if !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
@@ -322,6 +327,7 @@
     // size to avoid hitting the guard page.
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
 #endif
+#endif // OS_FREEBSD
     // TODO(viettrungluu,willchan): crbug.com/29675 - This currently leaks, so
     // if you change this, you'll probably need to change the suppression.
     if (!base::PlatformThread::CreateNonJoinable(
