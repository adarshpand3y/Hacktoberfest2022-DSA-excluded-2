package matrix;

import java.util.Arrays;

public class SortMatrix {

	public static void main(String[] args) {
		
		int a[][] = {{10,20,30,40},
		         	{15,25,35,45},
		         	{27,29,37,48},
		         	{32,33,39,50}};

		System.out.println("abb print kare ??");

		for (int i = 0; i < 4; i++)	            
		 { 
			for (int j = 0; j < 4; j++)
				System.out.print(a[i][j] + " ");

				System.out.println();
		 }
		
		 int temp[] = new int[4 * 4];
	        int k = 0;
	    
	        for (int i = 0; i < 4; i++)
	            for (int j = 0; j < 4; j++)
	                temp[k++] = a[i][j];
	      
	        Arrays.sort(temp);
	        
	        k = 0;
	        for (int i = 0; i < 4; i++)
	            for (int j = 0; j <4; j++)
	                a[i][j] = temp[k++];
	        
	        System.out.println();
	        
	        for (int i = 0; i < 4; i++)	            
			 { 
				for (int j = 0; j < 4; j++)
					System.out.print(a[i][j] + " ");

					System.out.println();
			 }
	        
	    }
	}


