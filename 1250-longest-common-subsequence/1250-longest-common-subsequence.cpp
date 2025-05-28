class Solution {
public:
    int fun(string a,string b,int i,int j,vector<vector<int>>&dp){
        
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) {
            if(a[i]==b[j]) return dp[i][j]=1;
            else return dp[i][j]=0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=fun(a,b,i-1,j-1,dp)+1;
        else return dp[i][j]=max(fun(a,b,i-1,j,dp),fun(a,b,i,j-1,dp));
        //return fun()
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // 1-based indexing

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
    }
};