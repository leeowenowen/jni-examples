public class Window{
  static {
    initIDs();
  }
  long handle;
  int length;
  int width;
  static native void initIDs();
}
