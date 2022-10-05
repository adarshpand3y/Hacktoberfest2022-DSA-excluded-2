def LCS(s1,s2,l1,l2):
    dp = [[None]*(l2+1) for _ in range(l1+1)]

    # Initialise dp
    # If length of any substring is 0 then length of LCS will be zero
    # So dp[0][i] and dp[j][0] will be zero

    for i in range(l1+1):
        dp[i][0] = 0
    for j in range(l2+1):
        dp[0][j] = 0

    # if s1[i] == s2[j] then increase by 1 else search in i-1 and j or i and j-1
    for i in range(1,l1+1):
        for j in range(1,l2+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1],dp[i-1][j])

    # dp[l1][l2] contains the length of LCS of s1 and s2
    return dp[l1][l2]



if __name__ == '__main__':
    s1 = 'abbacdcba'
    s2 = 'bcdbbcaa'
    maxlen = LCS(s1,s2,len(s1),len(s2))
    print("Length of LCS = ",maxlen)
