def SubString(s1,s2,l1,l2):

    dp = [[None]*(l2+1) for _ in range(l1+1)] 

    # Initialise dp

    # If length of any substring is 0 then length of LCS will be zero

    # So dp[0][i] and dp[j][0] will be zero 

    for i in range(l1+1):

        dp[i][0] = 0

    for j in range(l2+1):

        dp[0][j] = 0


    # If s1[i] == s2[j] then increase by 1 else dp[i][j] will be 0 as substring will break

    for i in range(1,l1+1):

        for j in range(1,l2+1):

            if s1[i-1] == s2[j-1]:

                dp[i][j] = 1 + dp[i-1][j-1]

            else:

                dp[i][j] = 0


    maximum = -9999

    for i in dp:

        maximum = max(maximum,max(i))

    return maximum

 

if __name__ == '__main__':

    s1 = 'aabcdaf'

    s2 = 'gbcdf'

    maxlen = SubString(s1,s2,len(s1),len(s2))

    print("Length of Longest Common Substring  = ",maxlen)
