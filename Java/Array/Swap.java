package com.devansh;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Swap {
    public static void main(String[] args) {
        int[] array= {1,2,3,4,5};
        System.out.println("Before Swapping"+Arrays.toString(array));
        swap(array,0,1);
        System.out.println("After Swapping"+Arrays.toString(array));
    }
    static void swap(int[] arr, int ind1, int ind2){
        int temp= arr[ind1];
        arr[ind1]=arr[ind2];
        arr[ind2]=temp;
    }
}
/*
taking from user
package com.devansh;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Swap {
    public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
        System.out.println("Enter the array elements:");
        int[] array=new int[5];
        for (int i = 0; i < 5 ; i++) {
            array[i]=sc.nextInt();
        }
        for (int i = 0; i <1 ; i++) {
            System.out.println("Before Swapping"+Arrays.toString(array));
        }
        swap(array,0,1);
        System.out.println("After Swapping"+Arrays.toString(array));
    }
    static void swap(int[] arr, int ind1, int ind2){
        int temp= arr[ind1];
        arr[ind1]=arr[ind2];
        arr[ind2]=temp;
    }
}*/

/* using array list
* public class Swap {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> list= new ArrayList<>();
        Scanner sc= new Scanner(System.in);

        //initialization of list
        for (int i = 0; i <3 ; i++) {
            list.add(new ArrayList<>());
        }
        //adding the elements
        for (int i = 0; i <3 ; i++) {
            for (int j = 0; j <3 ; j++) {
                list.get(i).add(sc.nextInt());
            }
        }
        System.out.println("Before swapping"+ list);
        swap(list, 1,2);
        System.out.println("After swapping"+list);
    }
    static void swap(ArrayList<ArrayList<Integer>> arr, int ind1, int ind2){
        ArrayList<Integer> temp= arr.get(ind1);
        arr.set(ind1, arr.get(2));
        arr.set(2, temp);
    }
}*/
