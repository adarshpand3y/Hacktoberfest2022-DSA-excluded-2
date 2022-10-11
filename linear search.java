import java.util.Scanner;

public class Search {

   public static void main(String[] args) {
      // Scanner class object to read input
      Scanner scan = new Scanner(System.in);
      
      // array
      int arr[] = { 50, 90, 30, 70, 60 };

      // read search key
      int key = 0;
      System.out.print("Enter search key: ");
      key = scan.nextInt();

      // find size of array
      int size = arr.length;

      // linear search
      int index = linearSearch(arr, size, key);

      // display result
      if (index == -1)
         System.out.println(key + " not Found.");
      else
         System.out.println(key + " Found at Index = " + index);
      
      // close Scanner class object
      scan.close();

   }

   public static int linearSearch(int[] arr, int size, int key) {
      // traverse through the array
      for (int i = 0; i < size; i++) {
         if (key == arr[i])
            return i;
      }
      return -1;
   }

}
