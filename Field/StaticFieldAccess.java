class StaticFieldAccess {
  static {
    System.loadLibrary("StaticFieldAccess");
  }
  private static int si;
  private native void accessField();
  public static void main(String args[]) {
    StaticFieldAccess c = new StaticFieldAccess();
    StaticFieldAccess.si = 100;
    c.accessField();
    System.out.println("In Java:");
    System.out.println("    StaticFieldAccess.si = " + si);
  }
}
