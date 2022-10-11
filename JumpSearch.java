public class JumpSearchAlgorithm {

  public static void main(String[] args) {
    int[] arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int ele = 60;

    int foundIndex = jumpSearch(arr, ele);
    System.out.println(foundIndex > 0 ? "Found at index : " + foundIndex : "Element Not Found");
  }

  public static int jumpSearch(int[] arr, int ele) {

    int prev = 0;
    int n = arr.length;
    int step = (int) Math.floor(Math.sqrt(n));
    while (arr[Math.min(step, n) - 1] < ele) {
      prev = step;
      step += (int) Math.floor(Math.sqrt(n));
      if (prev >= n) return -1;
    }
    while (arr[prev] < ele) {
      prev++;
      if (prev == Math.min(step, n)) return -1;
    }
    if (arr[prev] == ele) return prev;

    return -1;
  }
}
