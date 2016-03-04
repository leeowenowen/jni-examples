class InstanceMethodCall {
  static {
    System.loadLibrary("InstanceMethodCall");
  }
  private native void nativeMethod(); 
  private void callback() {
    System.out.println("In Java");
  }
  public static void main(String[] args) {
    InstanceMethodCall c = new InstanceMethodCall();
    c.nativeMethod();
  }
}
