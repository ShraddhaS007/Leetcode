class Solution {
public:
     int fun(string &a, int i, int j, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == a[j])
        return dp[i][j] = 2 + fun(a, i + 1, j - 1, dp);
    else
        return dp[i][j] = max(fun(a, i + 1, j, dp), fun(a, i, j - 1, dp));
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fun(s, 0, n - 1, dp);
}

};