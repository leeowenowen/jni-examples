class InstanceFieldAccess {
  static {
    System.loadLibrary("InstanceFieldAccess");
  }
  private String s;
  private native void accessField();
  public static void main(String[] args) {
    InstanceFieldAccess c = new InstanceFieldAccess();
    c.s = "abc";
    c.accessField();
    System.out.println("In Java:");
    System.out.println("    c.s = \"" + c.s + "\"");
  }
}
