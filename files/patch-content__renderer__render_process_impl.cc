--- ./content/renderer/render_process_impl.cc.orig	2012-08-17 03:01:28.000000000 +0200
+++ ./content/renderer/render_process_impl.cc	2012-08-23 22:31:44.000000000 +0200
@@ -115,7 +115,7 @@
     defined(OS_OPENBSD) || defined(OS_ANDROID)
   // Windows and Linux create transport DIBs inside the renderer
   return TransportDIB::Create(size, transport_dib_next_sequence_number_++);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Mac creates transport DIBs in the browser, so we need to do a sync IPC to
   // get one.  The TransportDIB is cached in the browser.
   TransportDIB::Handle handle;
@@ -132,7 +132,7 @@
   if (!dib)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac we need to tell the browser that it can drop a reference to the
   // shared memory.
   IPC::Message* msg = new ViewHostMsg_FreeTransportDIB(dib->id());
@@ -150,7 +150,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvas::StrideForWidth(rect.width());
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
