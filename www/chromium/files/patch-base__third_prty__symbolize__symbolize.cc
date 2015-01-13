--- base/third_party/symbolize/symbolize.cc.orig	2014-12-10 04:36:04 UTC
+++ base/third_party/symbolize/symbolize.cc
@@ -511,9 +511,15 @@
                                              int out_file_name_size) {
   int object_fd;
 
+#if defined(OS_FREEBSD)
+  // Open /proc/curproc/map.
+  int maps_fd;
+  NO_INTR(maps_fd = open("/proc/curproc/map", O_RDONLY));
+#else
   // Open /proc/self/maps.
   int maps_fd;
   NO_INTR(maps_fd = open("/proc/self/maps", O_RDONLY));
+#endif
   FileDescriptor wrapped_maps_fd(maps_fd);
   if (wrapped_maps_fd.get() < 0) {
     return -1;
@@ -540,12 +546,25 @@
     // (r-xp) and file name (/bin/cat).
 
     // Read start address.
+#if defined(OS_FREEBSD)
+    cursor += 2;  // Skip "0x".
+#endif
     cursor = GetHex(cursor, eol, &start_address);
+#if defined(OS_FREEBSD)
+    if (cursor == eol || *cursor != ' ') {
+      return -1;  // Malformed line.
+    }
+    ++cursor;  // Skip ' '.
+#else
     if (cursor == eol || *cursor != '-') {
       return -1;  // Malformed line.
     }
     ++cursor;  // Skip '-'.
+#endif
 
+#if defined(OS_FREEBSD)
+    cursor += 2;  // Skip "0x".
+#endif
     // Read end address.
     uint64_t end_address;
     cursor = GetHex(cursor, eol, &end_address);
@@ -559,15 +578,28 @@
       continue;  // We skip this map.  PC isn't in this map.
     }
 
+#if defined(OS_FREEBSD)
+    // Skip until we reach flags.  Skip until we encounter an 'r', '-' or eol.
+    while (cursor < eol && *cursor != '-' && *cursor != 'r') {
+      ++cursor;
+    }
+#endif
     // Read flags.  Skip flags until we encounter a space or eol.
     const char * const flags_start = cursor;
     while (cursor < eol && *cursor != ' ') {
       ++cursor;
     }
+#if defined(OS_FREEBSD)
+    // We expect at least three letters for flags (ex. "r-x").
+    if (cursor == eol || cursor < flags_start + 3) {
+      return -1;  // Malformed line.
+    }
+#else
     // We expect at least four letters for flags (ex. "r-xp").
     if (cursor == eol || cursor < flags_start + 4) {
       return -1;  // Malformed line.
     }
+#endif
 
     // Check flags.  We are only interested in "r-x" maps.
     if (memcmp(flags_start, "r-x", 3) != 0) {  // Not a "r-x" map.
@@ -575,6 +607,14 @@
     }
     ++cursor;  // Skip ' '.
 
+#if defined(OS_FREEBSD)
+    // Only for the first mapping, we can rely on the file offset to be 0.
+    // Since /proc/curproc/map doesn't give us file offsets, we have to abort
+    // if num_maps != 1.
+    if (num_maps != 1)
+      return -1;
+    base_address = 0;
+#else
     // Read file offset.
     uint64_t file_offset;
     cursor = GetHex(cursor, eol, &file_offset);
@@ -595,7 +635,16 @@
     //   shadow memory of the tool), so the module can't be the
     //   first entry.
     base_address = ((num_maps == 1) ? 0U : start_address) - file_offset;
+#endif
 
+#if defined(OS_FREEBSD)
+    /* Skip until file name. */
+    while (cursor < eol) {
+      if (*cursor == '/')
+        break;
+      cursor++;
+    }
+#else
     // Skip to file name.  "cursor" now points to dev.  We need to
     // skip at least two spaces for dev and inode.
     int num_spaces = 0;
@@ -612,6 +661,7 @@
     if (cursor == eol) {
       return -1;  // Malformed line.
     }
+#endif
 
     // Finally, "cursor" now points to file name of our interest.
     NO_INTR(object_fd = open(cursor, O_RDONLY));
