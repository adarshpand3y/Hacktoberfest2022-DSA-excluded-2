def subSum(arr,target):
    n = len(arr)
    dp = [[None]*(target+1) for _ in range(n+1)]

    # Initialise DP array !!
    # If no. of elements in arr are 0 then Target sum is not possible
    # Target sum = 0 is always possible i.e, by keeping the array subset as null/phi.
    for i in range(target+1):
        dp[0][i] = False
    for j in range(n+1):
        dp[j][0] = True

    # An element can be chosen only if sum is less han arr[i] else it cannot be included
    for i in range(1,n+1):
        for j in range(target+1):
            if arr[i-1] <= j:
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][target]

if __name__ == '__main__':
    arr = [0, 3, 2, 7, 1]
    target = 6
    exists =  subSum(arr,target)
    print('Subset with Target sum exists : ', str(exists))
