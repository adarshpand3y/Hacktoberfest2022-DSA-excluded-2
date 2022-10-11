// Program - Two strings, a and b, are called anagrams if they contain all the same characters in the same frequencies.

import java.util.Scanner;

public class Anagram {

static boolean isAnagram(String a, String b) {
        
    if(a.length() != b.length()){      // we checked that if the length is not same of the string it cant be anagrams
        return false;
    }
    char chr_a[] = a.toLowerCase().toCharArray();   //converted string a to lower case and inserted in character array a
    char chr_b[] = b.toLowerCase().toCharArray();   //converted string b to lower case and inserted in character array b
    
    int count[] = new int[256];   //made an array to counter add and subtract the values in the array at specific index 
    
    for(int i = 0 ; i<a.length() ; i++){    // as the length of both the string is same we make loop run till anyone string's length
        count[chr_a[i]]++;                  // this line will increment the counter of that specific index in count array i.e.. Count[<Any alphabetic or index counting> of a array]
        count[chr_b[i]]--;                  // this line will decrement the counter of that specific index in count array i.e.. Count[<Any alphabetic or index counting> of b array]
     }
    
    for(int i = 0 ; i < 256 ; i++){      //traversing the count array and checking if any value of element in count array is non zero
        if (count[i] != 0){
            return false;
        }
    }
    return true;
}
public static void main(String[] args) {
    
    Scanner scan = new Scanner(System.in);
    String a = scan.next();
    String b = scan.next();
    scan.close();
    boolean ret = isAnagram(a, b);     //boolean return value is stored in ret
    System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );    //used ternary operator to check if return value is true what to print
 }
}
