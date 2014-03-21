--- ./net/dns/dns_session.cc.orig	2014-03-19 20:01:35.000000000 +0100
+++ ./net/dns/dns_session.cc	2014-03-21 00:27:13.000000000 +0100
@@ -178,7 +178,7 @@
   base::TimeDelta current_error = rtt - estimate;
   estimate += current_error / 8;  // * alpha
   base::TimeDelta abs_error = base::TimeDelta::FromInternalValue(
-      std::abs(current_error.ToInternalValue()));
+      std::labs(current_error.ToInternalValue()));
   deviation += (abs_error - deviation) / 4;  // * delta
 
   // Histogram-based method.
