package januaryLongChallengeCODECHEF;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class Cpl {

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(System.in);
	        int t = scan.nextInt();
	        while(t-- !=0){
	            int n = scan.nextInt();
	            int k = scan.nextInt();
	            int h[] = new int[n];
	            LinkedHashSet<Integer> h1 = new LinkedHashSet<Integer>();
	            
	            int sum = 0;
	            for(int i = 0; i < n; i++){
	                h[i] = scan.nextInt();
	            }
	            Arrays.sort(h);
	            h1.add(h[n - 1]);
	            sum=h[n - 1];
	            int z = -1;
	            for(int i = n - 2; i >= 0; i--){
	                LinkedHashSet<Integer> h2 = new LinkedHashSet<Integer>();
	                sum = sum + h[i];
	                Iterator i1 = h1.iterator();
	                while(i1.hasNext()){
	                    int p=(int)(i1.next());
	                    h2.add(p);
	                    h2.add(h[i]);
	                    h2.add(p + h[i]);
	                    if(((p + h[i]) >= k) && ((sum - p - h[i]) >= k)){
	                        z = n - i;
	                        break;
	                    }
	                    if(((h[i]) >= k) && ((sum - h[i]) >= k)){
	                        z = n - i;
	                        break;
	                    }
	                }
	                if(z != -1){
	                    break;
	                }
	                h1 = h2;
	            }
	            System.out.println(z);
	        }
		}catch (Exception e) {
		}

	}

}