--- ./third_party/libusb/libusb.gyp.orig	2014-03-19 20:01:41.000000000 +0100
+++ ./third_party/libusb/libusb.gyp	2014-03-21 00:27:13.000000000 +0100
@@ -93,6 +93,19 @@
           ],
           'msvs_disabled_warnings': [ 4267 ],
         }],
+        ['OS == "freebsd"', {
+          'type': 'none',
+          'sources/': [
+            ['exclude', '^src/libusb/'],
+          ],
+          'direct_dependent_settings': {
+            'link_settings': {
+              'libraries': [
+                '-lusb',
+              ],
+            },
+          },
+        }],
       ],
     },
   ],
