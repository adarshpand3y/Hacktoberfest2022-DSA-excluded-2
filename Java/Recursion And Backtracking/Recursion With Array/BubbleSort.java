











/*
 In this Program i used the concept of recursion and implemented the bubble sort program through recursion.

 Now you may want to know what is Recursion?
 Ans-> The function which calls itself is called Recusrion. WE uses it to prevent the re-write of same code again and again.

 In this Program the function "sort" is doing the same work again and again i.e. comparing each value of arr[i] with all values of arr[j]. if it finds arr[i]>arr[j], it then swaps the elements 
 */

import java.util.ArrayList;
import java.util.Arrays;

public class BubbleSort {
    public static void sort(int arr[],int i, int k){
        if(k==arr.length-2)
            return;
        if(i==arr.length-1){
            i=0;
            k=k+1;
        }
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        sort(arr,i+1,k);
    }

    public static void main(String[] args) {
        int arr[]={5,4,3,2,1};
        sort(arr,0,0);
        System.out.println(Arrays.toString(arr));
    }
}


































