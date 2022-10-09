import java.util.Scanner;

public class RotationCountRotatedSortedArray {

    private static int findRotationCount(int[] a) {
        int n = a.length;
        int start = 0;
        int end = n - 1;

        while(start <= end) {
            int mid = (start + end) / 2;

            // If the middle element is smaller than its previous element, then it is the minimum element
            if(mid > 0 && a[mid] < a[mid-1]) {
                return mid;
            }

            // If the middle is greater than its next element, then the next element is the minimum element
            if(mid < n-1 && a[mid] > a[mid+1]) { 
                return mid+1;
            }

            if(a[start] <= a[mid]) { // left array is sorted. So the pivot (min element) is on the right side
                start = mid+1;
            } else { //right array is sorted. So the pivot (min element) is on the left side
                end = mid-1;
            }
        }

        return 0; // the array has not been rotated
    }    

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int n = keyboard.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
          a[i] = keyboard.nextInt(); 
        }
        keyboard.close();

        System.out.printf("Rotation Count = %d%n", findRotationCount(a));
    }
}
