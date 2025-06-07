class Solution {
public:
     int fun(vector<int>& a, int i, int c,vector<vector<int>>& dp){
        if(i>=a.size()) return 0;
        if(dp[i][c]!=-1)  return dp[i][c];
        if(c==0){
            return dp[i][c]=max(fun(a,i+1,0,dp),fun(a,i+1,1,dp)-a[i]);
        }else{
            return dp[i][c]=max(fun(a,i+1,1,dp),fun(a,i+1,0,dp)+a[i]);
        }

     }
    //  int fun2(vector<int>& a, int i, int j, vector<vector<int>>& dp) {
    //     if (i >= j) return 0;
    //     if (dp[i][j] != -1) return dp[i][j];

    //     int x = 0;
    //     for (int k = i + 1; k < j; k++) {
    //         if (a[k] > a[i]) {
    //             x = max(x, fun(a, k + 1, j, dp) + a[k] - a[i]);
    //         }
    //     }
    //     x = max(x, fun(a, i + 1, j, dp)); // skip current i
    //     return dp[i][j] = x;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2,-1));
        return fun(prices, 0, 0,dp);
    }
};