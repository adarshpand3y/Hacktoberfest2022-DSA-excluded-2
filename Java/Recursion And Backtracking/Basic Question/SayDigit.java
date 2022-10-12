package RECURSION;

import java.util.Scanner;

public class SayDigit {
    static void AnsDigit(int n,String arr[]){
        if(n==0){
            return;
        }

        int digit = n%10;
        n=n/10;

        AnsDigit(n,arr);
        System.out.println(arr[digit]);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"} ;
        AnsDigit(n, arr);
    }
}
