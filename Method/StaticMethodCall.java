class StaticMethodCall {
    static {
      System.loadLibrary("StaticMethodCall");
    }
    private native void nativeMethod();
    private static void callback(){
      System.out.println("In Java");
    }
    public static void main(String[] args){
      StaticMethodCall c = new StaticMethodCall();
      c.nativeMethod();
    }
}
