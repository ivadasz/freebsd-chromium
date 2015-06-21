--- base/files/file_path_watcher_stub.cc.orig	2015-06-11 21:05:27 UTC
+++ base/files/file_path_watcher_stub.cc
@@ -19,7 +19,9 @@
     return false;
   }
 
-  virtual void Cancel() override {}
+  virtual void Cancel() override {
+    set_cancelled();
+  }
 
   virtual void CancelOnMessageLoopThread() override {}
 
