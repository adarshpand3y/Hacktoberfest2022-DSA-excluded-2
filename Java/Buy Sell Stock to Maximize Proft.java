public class Main
{
	public static void main(String[] args) {
		int[] a={100, 180, 260, 310, 40, 535, 695};
		int maxi=0;
		for(int i=1;i<a.length;i++){
		    if (a[i]>a[i-1]){
		        maxi+=a[i]-a[i-1];
		    }
		}
		System.out.println(maxi);
	}
}
