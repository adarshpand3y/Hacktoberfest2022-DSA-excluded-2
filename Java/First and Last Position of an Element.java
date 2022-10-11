import java.util.Scanner;

class FirstLastPositionOfElement {
    private static int binarySearchFirstPosition(int[] a, int target) {
        int start = 0;
        int end = a.length-1;

        int firstPosition = -1;
        
        while(start <= end) {
            int mid = (start + end)/2;

            if(target == a[mid]) {
                // Found target, update firstPosition and move to the left to find a smaller position by setting end=mid-1
                firstPosition = mid;
                end = mid-1;
            } else if (target < a[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return firstPosition;
    }

    private static int binarySearchLastPosition(int[] a, int target) {
        int start = 0;
        int end = a.length-1;

        int lastPosition = -1;
        while(start <= end) {
            int mid = (start + end)/2;

            if(target == a[mid]) {
                // Found target, update lastPosition and move to the right to find a higher position by setting start=mid+1
                lastPosition = mid;
                start = mid+1;
            } else if (target < a[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return lastPosition;
    }

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int n = keyboard.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
          a[i] = keyboard.nextInt(); 
        }
        int target = keyboard.nextInt();
        keyboard.close();

        int firstPosition = binarySearchFirstPosition(a, target);
        int lastPosition = binarySearchLastPosition(a, target);

        System.out.printf("First position = %d, Last position = %d%n", firstPosition, lastPosition);
    }
}
