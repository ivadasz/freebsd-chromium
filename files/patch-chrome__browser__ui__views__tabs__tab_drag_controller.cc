--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig.port	Wed Dec  3 03:13:21 2014
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc	Sat Dec  6 11:34:25 2014
@@ -266,7 +266,7 @@ void TabDragController::Init(
   //     synchronous on desktop Linux, so use that.
   // - Ash
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   can_release_capture_ = false;
 #else
   can_release_capture_ =
@@ -621,7 +621,7 @@ TabDragController::DragBrowserToNewTabStrip(
     // that to effect the position of any windows.
     SetWindowPositionManaged(browser_widget->GetNativeWindow(), false);
 
-#if !defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -1791,7 +1791,7 @@ gfx::NativeWindow TabDragController::GetLocalProcessWi
     if (dragged_window)
       exclude.insert(dragged_window);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
