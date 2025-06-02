class Solution {
public:
    int fun(string &s, string &t, int i, int j, vector<vector<int>> &dp,int n,int m) {
    // Base Cases
    if (j < 0) return i+1;  
    if (i < 0) return j+1; 

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] != t[j]) {
        // Two choices: match or skip
        return dp[i][j] = min(min(fun(s, t, i - 1, j - 1, dp,n,m),fun(s, t, i - 1, j, dp,n,m)),fun(s,t,i,j-1,dp,n,m))+1;
    } else {
        // Can't match, skip s[i]
        return dp[i][j] = min(fun(s, t, i - 1, j-1, dp,n,m),fun(s,t,i,j-1,dp,n,m)+1);
    }
    return dp[n-1][m-1];
    
}
    int minDistance(string word1, string word2) {
         int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(word1, word2, n - 1, m - 1, dp,n,m);
    }
};