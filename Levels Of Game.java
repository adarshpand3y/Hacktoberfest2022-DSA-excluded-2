class Solution {
    public static int maxLevel(int h,int m) {
          // code here
        int[][]dp=new int[2000][2000];
        for(int i=0;i<2000;i++){
            Arrays.fill(dp[i],-1);
        }

        return dfs(h,m,dp)-1;
    }
    static int dfs(int h,int m,int[][]dp){
        if(h<=0 || m<=0)return 0;

        if(dp[h][m]!=-1)return dp[h][m];

        int a=dfs(h+3-5,m+2-10,dp)+2;
        int b=dfs(h+3-20,m+2+5,dp)+2;
        return dp[h][m]=Math.max(a,b);
    }
}