import java.util.*;
public class GoogleKickstartRoundG_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int T = sc.nextInt();
        int max = 0;
        int sum = 0;
        for(int k = 1; k<= T ; k++)
        {

            int M = sc.nextInt();
            int N = sc.nextInt();
            int P = sc.nextInt();
            int [][] arr = new int [M][N];
            int i,j;
            for(i=0;i<M;i++)
            {
                for(j=0;j<N;j++)
                {
                    arr[i][j] = sc.nextInt();
                }
            }
            for(i=0;i<N;i++)
            {
                for(j= 0;j<M;j++)
                {

                    if(arr[j][i] >= max)
                        max = arr[j][i];
                }
                sum += max-arr[P-1][i];
                //System.out.print(max-arr[P-1][i]+" ");
                max = 0;
            }
            System.out.println("Case #"+k+": "+sum);
            sum = 0;
            //System.out.println();
            max = 0;
        }
    }
}
