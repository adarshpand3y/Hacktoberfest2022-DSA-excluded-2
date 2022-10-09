import java.util.Scanner;

class CeilOfElementInSortedArray {
    private static int findCeilBinarySearch(int[] a, int x) {
        int n = a.length;
        int start = 0;
        int end = n-1;

        int ceil = -1;

        while(start <= end) {
            int mid = (start+end)/2;

            if(x == a[mid]) {
                // a[mid] is the ceiling
                return a[mid];
            } else if (x < a[mid]) {
                // a[mid] is the smallest element found so far that is greater than x. So it is a candidate for the ceiling of x
                ceil = a[mid];
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return ceil;
    }

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int n = keyboard.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
          a[i] = keyboard.nextInt(); 
        }
        int x = keyboard.nextInt();
        keyboard.close();

        System.out.printf("Ceil(%d) = %d%n", x, findCeilBinarySearch(a, x));
    }
}
