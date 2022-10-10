package q1;

public class StringBasic {

	public static void main(String[] args) {
		
		//Ia
		String str="Hello";
		System.out.println("Q1 Ia: " +str);
		
		//create string object
		str = new String("Hello");
		//System.out.println(str);
		
		//Ib
		char c[] = {'H', 'e', 'l', 'l', 'o'};
		str = new String(c);
		System.out.println("Q1 Ib: " + str);
		
		//Ic
		String s="Hello";
		str = new String(s);
		System.out.println("Q1 Ic: "+ str);
		
		//IIa
		String result = str.concat(" World");
		System.out.println("Q1 IIa: " + result);
		
		//IIb
		String rep = str.replace('H', 'h');
		System.out.println("Q1 IIb: " + rep);
		
		//IIc-Yes
		
		/*IIe-The replace() method takes two arguments: 
		 * the substring you want to find, 
		 * and the string to replace it with. 
		 * Note that replace() does not change the original String object; 
		 * it returns a new String object with all occurrences of the first argument replaced by the second argument.
		 */
	
	}

}
