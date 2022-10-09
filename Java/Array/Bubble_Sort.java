import java.util.Arrays;

class Main {
  static void bubbleSort(int array[]) {
    int size = array.length;
    // applying loop on every element
    for (int i = 0; i < size - 1; i++)
      // compare the elements of the array with a loop
      for (int j = 0; j < size - i - 1; j++)
        // compare each elements in array
        if (array[j] > array[j + 1]) {
          // swap elements if it's not in order
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
  }

  public static void main(String args[]) {
    int[] data = { 5, 3, 4, 1, 2 };
    Main.bubbleSort(data);
    
    System.out.println("Array sorted with bubble sort: ");
    System.out.println(Arrays.toString(data));
  }
}