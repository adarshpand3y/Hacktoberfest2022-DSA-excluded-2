'''
Capacity of knapsack = W
weight list : wt = []
price list : pr = []
No. of items = N
'''
def kProfit(W,N,wt,pr,dp):
    # Base Condition
    if N==0 or W==0:
        return 0
    # If sub problem is previously solved tehn return it.
    if dp[N][W] is not None:
        return dp[N][W]
    if wt[N-1] <= W:
        dp[N][W] = max(pr[N-1]+kProfit(W-wt[N-1],N-1,wt,pr,dp), kProfit(W,N-1,wt,pr,dp))
        return dp[N][W]
    else:
        dp[N][W] = kProfit(W,N-1,wt,pr,dp)
        return dp[N][W]
if __name__ == '__main__':
    W = 11
    wt = [1, 2, 5, 6, 7]
    pr = [1, 6, 18, 22, 28]
    N = len(pr)
    # define DP array
    dp = [[None] * (W + 1) for _ in range(N + 1)]
    # Call for kProfit to calculate max profit
    maxProfit = kProfit(W,N,wt,pr,dp)
    print('Maximum Profit is : ',maxProfit)
