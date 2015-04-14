--- chrome/browser/ui/views/panels/panel_frame_view.cc.orig.port	Tue Mar 10 23:41:40 2015
+++ chrome/browser/ui/views/panels/panel_frame_view.cc	Wed Mar 11 07:22:50 2015
@@ -581,7 +581,7 @@ bool PanelFrameView::OnMousePressed(const ui::MouseEve
 }
 
 bool PanelFrameView::OnMouseDragged(const ui::MouseEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Converting the mouse location to screen coordinates returns an incorrect
   // location while the panel is moving. See crbug.com/353393 for more details.
   // TODO(pkotwicz): Fix conversion to screen coordinates
