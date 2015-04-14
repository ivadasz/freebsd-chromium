--- chrome/browser/ui/views/app_list/linux/app_list_linux.cc.orig.port	Sat Dec 27 12:59:28 2014
+++ chrome/browser/ui/views/app_list/linux/app_list_linux.cc	Sat Dec 27 13:07:15 2014
@@ -91,7 +91,7 @@ void AppListLinux::MoveNearCursor(app_list::AppListVie
   view->SetBubbleArrow(views::BubbleBorder::FLOAT);
 
   AppListPositioner::ScreenEdge edge;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // In the Unity desktop environment, special case SCREEN_EDGE_LEFT. It is
   // always on the left side in Unity, but ShelfLocationInDisplay will not
   // detect this if the shelf is hidden.
