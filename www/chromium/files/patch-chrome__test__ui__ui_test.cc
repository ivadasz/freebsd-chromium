--- ./chrome/test/ui/ui_test.cc.orig	2014-03-12 20:22:30.000000000 +0100
+++ ./chrome/test/ui/ui_test.cc	2014-03-14 09:23:25.000000000 +0100
@@ -68,7 +68,7 @@
     L"NOTE: This test is expected to fail if crash_service.exe is not "
     L"running. Start it manually before running this test (see the build "
     L"output directory).";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
     L"NOTE: This test is expected to fail if breakpad is not built in "
     L"or if chromium is not running headless (try CHROME_HEADLESS=1).";
 #else
