val = [6,10,12]
wt = [1,2,3]
n = 3
W = 4
t = [[-1 for x in range(W+1)] for x in range(n+1)]
def solve(wt,val,W,n):
    global t
    if n==0 or W ==0:
        return 0
    if t[n][W]!=-1:
        return t[n][W]
    if wt[n-1]<=W:
        t[n][W]=max(val[n-1]+solve(wt,val,W-wt[n-1],n-1),solve(wt,val,W,n-1))
        return t[n][W]
    else:
        t[n][W] = solve(wt,val,W,n-1)
        return t[n][W]
print(solve(wt,val,W,n))
print(t)