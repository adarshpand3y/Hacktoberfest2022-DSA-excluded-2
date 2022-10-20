
// the chosen dog house 
//the simple prefix array will do .from left to right side of index
import java.util.Scanner;
class HelloWorld {
    public int counter(int N, int I, int arr[])
    {
        int c = 0;
        for(int i = 0; i<(I-1); i++)
            while(arr[i]!=0)
            {
                arr[i] = arr[i]-1;
                arr[i+1] = arr[i+1]+1;
                c++;
            }
        
        for(int i = N-1; i>(I-1); i--)
            while(arr[i]!=0)
            {
                arr[i] = arr[i]-1;
                arr[i-1] = arr[i-1]+1;
                c++;
            }
            
        return c;
    }
    public static void main(String[] args) {
    HelloWorld ob = new HelloWorld();
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int I = sc.nextInt();
    int arr [] = new int [N];
    for(int i = 0; i<N; i++)
        arr[i] = sc.nextInt();
    System.out.println(ob.counter(N,I,arr));
    }
}
