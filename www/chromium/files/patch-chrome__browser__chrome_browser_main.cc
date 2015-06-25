--- chrome/browser/chrome_browser_main.cc.orig	2015-06-11 21:05:27 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -718,7 +718,7 @@
 
 // CurrentProcessInfo::CreationTime() is currently only implemented on some
 // platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   const base::Time process_creation_time =
       base::CurrentProcessInfo::CreationTime();
 
@@ -726,7 +726,7 @@
     base::TimeDelta delay = base::Time::Now() - process_creation_time;
     UMA_HISTOGRAM_LONG_TIMES_100("Startup.BrowserMessageLoopStartTime", delay);
   }
-#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
   // Record collected startup metrics.
   startup_metric_utils::OnBrowserStartupComplete(is_first_run);
@@ -990,7 +990,7 @@
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
       chrome::VersionInfo::GetVersionStringModifier());
