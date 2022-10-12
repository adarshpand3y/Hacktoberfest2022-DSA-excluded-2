import java.util.Arrays;

public class cyclic_sort {
    public static void main(String[] args) {
        System.out.println();
        int[] arr = {6,3,5,4,3,1};
        cycleSort(arr);
        System.out.println(1);
        System.out.println(Arrays.toString(arr));
    }

    static void cycleSort(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int index = arr[i] - 1;
            if (arr[i] != arr[index]) {// if element is not present at it's correct position then place it at it's
                                       // correct position.
                swap(arr, i, index);
            } else {
                i++;
            }
        }
    }

    static void swap(int[] arr, int i, int index) {
        int temp = i;
        i = index;
        index = temp;
    }

}
