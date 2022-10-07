/**
 * Check given string is plandrome or not 
 * for example 
 * input: 
 * cat 
 * output: 
 * not plandrome 
 * input : 
 * tat
 * output:
 * plandrome
 */

import java.util.Scanner;

public class StringPlandromeOrNot {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Any String : ");

        String str = scan.nextLine();
        String temp = str;
        String newStr = "";

        for(int i=str.length()-1; i>=0; i--){
            newStr = newStr + str.charAt(i);
        }
        
        if(temp.equals(newStr)){
            System.out.println("This string is plandrome ");
        }
        else{
            System.out.println("This string is not plandrome ");
        }
    }
}
