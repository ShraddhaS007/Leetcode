class Solution {
public:

    int fun(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    // Base Cases
    if (j < 0) return 1;  // Entire t matched
    if (i < 0) return 0;  // s exhausted, but t not matched

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        // Two choices: match or skip
        return dp[i][j] = fun(s, t, i - 1, j - 1, dp) + fun(s, t, i - 1, j, dp);
    } else {
        // Can't match, skip s[i]
        return dp[i][j] = fun(s, t, i - 1, j, dp);
    }
}

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(s, t, n - 1, m - 1, dp);
}

};