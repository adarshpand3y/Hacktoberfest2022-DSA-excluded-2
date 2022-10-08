public class Search {

   public static void main(String[] args) {
      int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
      int key = 40; // search key

      // binary search
      int index = binarySearch(arr, 0, arr.length, key);

      // display result
      if (index == -1)
         System.out.println(key + " not Found.");
      else
         System.out.println(key + " Found at Index = " + index);
   }

   // Method for binary search
   /* if match found then return index of search key
      else return -1 */
   public static int binarySearch(int[] arr, int low,
                           int high, int key) {
      if (high >= low) {
         // find middle index
         int mid = low + (high - low) / 2; 
     
         // find middle term and compare
         if (arr[mid] == key) return mid; // key found 
     
         // If key is smaller than middle term, then 
         // it can only be present in left subarray 
         if (arr[mid] > key) 
            return binarySearch(arr, low, mid - 1, key); 
     
         // Else the key can only be present 
         // in right subarray 
         return binarySearch(arr, mid + 1, high, key); 
      } 
     
      // key not found
      return -1; 
   }

}
