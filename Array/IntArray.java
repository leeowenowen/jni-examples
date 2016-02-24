class IntArray {
  static {
    System.loadLibrary("IntArray");
  }
  private native int sumArray(int[] arr);
  public static void main(String[] args) {
    IntArray p = new IntArray();
    int[] arr = new int[10];
    for (int i = 0; i < 10; i ++) {
      arr[i] = i;
    }
    int sum = p.sumArray(arr);
    System.out.println("sum = " + sum);
  }
}
