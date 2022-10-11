// Question:-
//   You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

// Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
// Output: 2
// Explanation: There are two paths where the sum of the elements on the path is divisible by k.
// The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
// The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
// Example 2:


// Input: grid = [[0,0]], k = 5
// Output: 1
// Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
// Example 3:


// Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
// Output: 10
// Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
  
//   Solution:-
    
    int numberOfPaths(vector<vector<int>>& g, int k) {
    int dp[50001][51] = {}, m = g.size(), n = g[0].size();
    function<int(int, int, int)> dfs = [&](int i, int j, int mod){
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return (mod + g[i][j]) % k ? 0 : 1;
        if (dp[i * n + j][mod] == 0)
            dp[i * n + j][mod] = (1 + dfs(i + 1, j, (mod + g[i][j]) % k) + 
                dfs(i, j + 1, (mod + g[i][j]) % k)) % 1000000007;
        return dp[i * n + j][mod] - 1;
    };
    return dfs(0, 0, 0);
}
