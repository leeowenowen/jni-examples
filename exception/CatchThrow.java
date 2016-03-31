public class CatchThrow {
  static {
    System.loadLibrary("CatchThrow");
  }
  private native void doit() throws IllegalArgumentException;
  private void callback() throws NullPointerException {
    throw new NullPointerException("CatchThrow.callback");
  }
  public static void main(String[] args){
    CatchThrow c = new CatchThrow();
    try {
      c.doit();
    }catch (Exception e){
      System.out.println("In Java:\n\t" + e);
    }
  }
}
