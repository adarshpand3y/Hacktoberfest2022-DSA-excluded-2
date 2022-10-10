import java.util.*;
public class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the element you want to search = ");
        int Key = sc.nextInt();
        int flag = 0;
        int i =0;
        int arr[] ={1,2,7,8};
        // while(i<arr.length){
        //     if(arr[i]==number){
        //         System.out.println("Element found at index number " +i);  
        //         break;  
        //     }i++;
        // }
        // if(flag==1){
        //     System.out.println("Element found at index number" +i);
        // }
        // else{
        //     System.out.println("Element not found");
        // }
        while(i<arr.length && arr[i]!=Key){
            i++;
        }
        if(i<arr.length){
            System.out.println("Element found at index number: " +i);
        }
        else{
            System.out.println("Element not found");
        }

    }
}