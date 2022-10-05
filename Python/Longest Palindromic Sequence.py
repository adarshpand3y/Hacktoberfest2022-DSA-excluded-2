def LCS(s1,s2):
    l1 = len(s1)
    l2 = len(s2)
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

def LPS(s):
    # Length of the Largest palindromic subsequence is equal to Longest Common Subsequence of string s and reversed(s)
    srev = s[::-1]
    return LCS(s,srev)

if __name__ == '__main__':
    s = 'agbdba'
    length = LPS(s)
    print(f'Length of the largest Palindromic Subsequence is {length}')
