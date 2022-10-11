import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Length of array: ");
        int a = sc.nextInt();
        System.out.print("Enter the value for search: ");
        int key = sc.nextInt();
        int[] arr = new int[a];
        int i, strat = 0, end = arr.length - 1;
        for (i = 0; i < arr.length - 1; i++) {
            System.out.print("Enter the number for array: ");
            arr[i] = sc.nextInt();
        }
        while (strat <= end) {
            int mid = (strat + end) / 2;
            if (mid == key) {
                System.out.print("Number found");
                break;
            } else if (mid < key) {
                strat = key;
                mid = strat - end / 2;

            } else if (mid > key) {
                end = key;
                mid = strat - end / 2;
            }
            if (end > strat) {
                System.out.print("Number not found");
            }
            // System.out.println("number not found");
        }
    }
}
