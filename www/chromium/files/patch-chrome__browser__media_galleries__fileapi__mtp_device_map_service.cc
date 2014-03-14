--- ./chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2014-03-12 20:21:58.000000000 +0100
+++ ./chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc	2014-03-14 09:23:25.000000000 +0100
@@ -33,9 +33,11 @@
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !defined(OS_FREEBSD)
     CreateMTPDeviceAsyncDelegate(device_location,
         base::Bind(&MTPDeviceMapService::AddAsyncDelegate,
                    base::Unretained(this), device_location));
+#endif
     mtp_device_usage_map_[device_location] = 0;
   }
 
