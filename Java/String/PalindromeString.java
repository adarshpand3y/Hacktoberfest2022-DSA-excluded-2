/* Write a JAVA Program to find whether a string is palindrome or not.  */

import java.util.*;

class Solution {

    int isPalindrome(String S) {
        StringBuilder sb = new StringBuilder(S);
        sb.reverse();
        if(S.contains(sb))
         return 1;
        return 0;
    }

}

public class PalindromeString{
        
    public static void main(String[] a){
        System.out.println("Enter a String:");
        Scanner scan=new Scanner(System.in);
        String p=scan.nextLine();
        Solution obj =new Solution();

        int  q= obj.isPalindrome(p);
        if(q!=0){
            System.out.println("palindrome string ");
        }
        else{
            System.out.println("not palindrome");
        }
        

    }
}
