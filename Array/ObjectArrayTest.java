class ObjectArrayTest {
  static {
    System.loadLibrary("ObjectArrayTest");
  }
  private static native int[][] initInt2DArray(int size);
  public static void main(String[] args) {
      int[][] i2arr = initInt2DArray(3);
      for (int i =0; i < 3; ++i) {
        for (int j = 0; j < 3; j ++) {
          System.out.print(" " + i2arr[i][j]);
        }
        System.out.println();
      }


  }
}
