package com.pranit.BinarySearch;

public class Valid_Squares {
   
    public static void main(String arg[])
    {
        System.out.println(mySqrt(40));
    }
    public static int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        int l = 1;
        int h = x;
        int ans = -1;

        while(l <= h){
            int mid = l + (h - l)/2;

            //mid*mid gives overflow
            if(mid < x/mid){
                ans = mid;
                l = mid + 1;
            } else if(mid > x/mid) {
                h = mid - 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
    public boolean isPerfectSquare(int num) {
        int sqrt = mySqrt(num);
        if(sqrt * sqrt == num){
            return true;
        } else{
            return false;
        }
    }
}

