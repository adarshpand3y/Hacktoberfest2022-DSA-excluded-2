import java.util.*;
public class gcd {
    static long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long a= sc.nextLong();
        long b= sc.nextLong();
        System.out.println(gcd(a,b));
    }
}
