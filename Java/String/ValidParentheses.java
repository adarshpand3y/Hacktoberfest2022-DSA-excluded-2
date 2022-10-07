
/*

Question:- Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

//I coded this program in very simplified way so that user can easily understand.



//NOTE: Stack data structure is used to keep the track of brackets if it is in sequence or not
import java.util.Stack;

public class ValidParentheses {
    static boolean isValid(String s) {
        Stack<Character>stack=new Stack<>();//initialization of stack
        int count=0;
        for (int i = 0; i <s.length(); i++) {
            if(s.charAt(i)=='('|| s.charAt(i)=='{'|| s.charAt(i)=='['){
                stack.push(s.charAt(i));//implementation of stack
            }
            else {
                if(stack.isEmpty())
                    return false;
                count++;
                char ch=stack.pop();
                int a1=(int)ch;//extracted the ascii value of character ch
                int a2=(int)s.charAt(i);
                int diff=Math.abs(a1-a2);
                if(diff==1 || diff==2)
                    continue;
                else
                    return false;
            }
        }
        if(count==s.length()/2 && s.length()%2==0)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        String str="([]){";// you can give input according to your choice
        System.out.println(isValid(str));
    }
}
