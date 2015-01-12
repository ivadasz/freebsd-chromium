--- content/browser/time_zone_monitor_linux.cc.orig	2014-12-10 04:54:34 UTC
+++ content/browser/time_zone_monitor_linux.cc
@@ -51,6 +51,9 @@
       : base::RefCountedThreadSafe<TimeZoneMonitorLinuxImpl>(),
         file_path_watchers_(),
         owner_(owner) {
+  }
+
+  void StartWatching() {
     DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
     BrowserThread::PostTask(
         BrowserThread::FILE,
@@ -147,6 +150,9 @@
   // changed.
   if (!getenv("TZ")) {
     impl_ = new TimeZoneMonitorLinuxImpl(this);
+    if (impl_.get()) {
+      impl_->StartWatching();
+    }
   }
 }
 
