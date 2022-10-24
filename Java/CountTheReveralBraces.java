package Strings;

public class CountTheReveralBraces {

	public static void main(String[] args) {
		
		String s = "}{{}}{{{";
		
		 // your code here  
        if(s.length()%2!=0) System.out.println(-1);
        
        else {
        int open=0,close=0,rev=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='{') open++;
            else
            {
                if(open==0) close++;
                else open--;
            }
        }
        rev=(int)(Math.ceil(open/2.0) + Math.ceil(close/2.0)); 
		
        System.out.println("ha too = " + rev);
        }
        
	}
	
}
