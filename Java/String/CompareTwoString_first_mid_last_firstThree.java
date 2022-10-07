/**
 * take two string from the user 
 * print yes 
 * if last and first index char is equal or mid is equeal or first three index char is equal 
 */

import java.util.Scanner;

import javax.lang.model.util.ElementScanner6;

public class MatchString {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter first word: ");
        String word1 = scan.nextLine();
        System.out.println("Enter second word: ");
        String word2 = scan.nextLine();

        int len1 = word1.length();
        int len2 = word2.length();
        int low1 = 0;
        int low2 = 0;
        int mid1 = (low1+len1)/2;
        int mid2 = (low2 + len2)/2;
        int count=0;
       

        if(word1.charAt(low1) == word2.charAt(low2) && word1.charAt(len1-1) == word2.charAt(len2-1)){
            System.out.println("Yes");
        }

        else if(word1.charAt(mid1)==word2.charAt(mid2)){
           System.out.println("Yes");
        }
        else{
            for(int i=0; i<3; i++){
                if(word1.charAt(i) ==word2.charAt(i)){
                  count++;
                }
            }
        }

        if(count==3){
            System.out.println("Yes");
        }
    }
}
