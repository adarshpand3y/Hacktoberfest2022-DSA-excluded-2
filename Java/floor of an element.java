import java.util.Scanner;

class FloorOfElementInSortedArray {
    private static int findFloorBinarySearch(int[] a, int x) {
        int n = a.length;
        int start = 0;
        int end = n-1;

        int floor = -1;

        while(start <= end) {
            int mid = (start+end)/2;

            if(x == a[mid]) {
                // a[mid] is the floor               
                return a[mid];
            } else if (x < a[mid]) {
                end = mid-1;
            } else {
                // a[mid] is the largest element found so far that is smaller than x. So it is a candidate for the floor of x
                floor = a[mid]; 
                start = mid+1;
            }
        }

        return floor;
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

        System.out.printf("Floor(%d) = %d%n", x, findFloorBinarySearch(a, x));
    }
}
