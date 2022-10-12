import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int arr [] = new int[n];
        Arrays.fill(arr,0);
        while (q>0){
            int opr =sc.nextInt();
            if (opr==1){
                int x = sc.nextInt();
                arr[x-1]=2*arr[x-1]+1;
            } else if (opr==2) {
                int x = sc.nextInt();
                arr[x-1]=2*arr[x-1]/2;
                arr[x-1]=(int)Math.floor(arr[x-1]);
            } else if (opr==3) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int sum = 0;
                for (int j=x-1;j<=y-1;j++){
                    sum+=arr[j];
                }
                System.out.println(sum);
            }
            q--;
        }
    }
}
