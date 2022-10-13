import java.util.Scanner;

public class lab3 {
    static int n;
    static int arr[];

    static int[] input_array() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("\nEnter " + n + " elements of array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        // display
        System.out.print("Array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n");
        sc.close();
        return arr;

    }

    public static void main(String args[]) {
        int f = 1;
        int arr[] = input_array();
        while (f == 1) {
            System.out.println(
                    "\n\nEnter a no. to perform the following:\n1.Display sum\n2.Print elements of even indices\n3.Print elements of odd indices\n4.Print even elements\n5.Print odd elements\n6.Sort array in ascending order\n7.Sort array in descending order\n8.Exit");
            Scanner sc = new Scanner(System.in);
            int c = sc.nextInt();
            switch (c) {
                case 1:
                    // sum of array elements
                    int sum = 0;
                    for (int i = 0; i < n; i++) {
                        sum += arr[i];
                    }
                    System.out.println("\nSum of elements= " + sum);
                    break;
                case 2:
                    // even indices elements
                    System.out.println("Elements at even indices: ");
                    for (int i = 0; i < n; i += 2) {
                        System.out.print(arr[i] + " ");
                    }
                    break;
                case 3:
                    // odd indices elements
                    System.out.println("Elements at odd indices: ");
                    for (int i = 1; i < n; i += 2) {
                        System.out.print(arr[i] + " ");
                    }
                    break;
                case 4:
                    // even elements
                    System.out.println("\nEven elements: ");
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            System.out.print(arr[i] + " ");
                        }
                    }
                    break;
                case 5:
                    // odd elements
                    System.out.println("\nOdd elements: ");
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 != 0) {
                            System.out.print(arr[i] + " ");
                        }
                    }
                    break;
                case 6:
                    // Sort in ascending order
                    for (int p = 0; p < n - 1; p++) {
                        for (int i = 1; i < n; i++) {
                            if (arr[i - 1] > arr[i]) {
                                int x = arr[i - 1];
                                arr[i - 1] = arr[i];
                                arr[i] = x;
                            }
                        }
                    }
                    System.out.println("\nSorted array in acsending order: ");
                    for (int i = 0; i < n; i++) {
                        System.out.print(arr[i] + " ");
                    }
                    break;
                case 7:
                    // Sort in descending order
                    for (int p = 0; p < n - 1; p++) {
                        for (int i = 1; i < n; i++) {
                            if (arr[i - 1] < arr[i]) {
                                int x = arr[i - 1];
                                arr[i - 1] = arr[i];
                                arr[i] = x;
                            }
                        }
                    }
                    System.out.println("\nSorted array in descending order: ");
                    for (int i = 0; i < n; i++) {
                        System.out.print(arr[i] + " ");
                    }
                    break;
                case 8:
                    f = 0;
                    break;
            }
            sc.close();
        }

    }

}
