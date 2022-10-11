import java.util.*;
public class FASCINATING_NUMBER
{
    static int countRepeatingDigits(int N)
    {
        int res = 0;
        int cnt[] = new int[10];
        while (N > 0)
        {int rem = N % 10;
            cnt[rem]++;
            N = N / 10;
        }
        for (int i = 0; i < 10; i++)
        {if (cnt[i] > 1)
                res++;
        }
        return res;
    }
    static int fasc(int num)
    {int ans=0;
        ans=num+1;
        while(countRepeatingDigits(ans)!=0)
        ans++;
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t= sc.nextInt();
        while(t-->0)
        {
            int m= sc.nextInt();
            System.out.println(fasc(m));
        }
    }
}