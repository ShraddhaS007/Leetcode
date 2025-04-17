class Solution {
public:
    int fun(vector<int> &a,vector<vector<int>>&dp,int n,int k){
        int x=k/a[n];
        if(n==0){
            if(k%a[n]==0) return 1;
            else return 0;
        }
        if(dp[n][k]) return dp[n][k];
        for(int i=0;i<=x;i++){
            dp[n][k]+=fun(a,dp,n-1,k-(a[n]*i));
        }
        return dp[n][k];
    }
    // int change(int amount, vector<int>& coins) {
    //     vector<vector<int>>dp(coins.size(),vector<int>(5005,0));
    //     return fun(coins,dp,coins.size()-1,amount);
    // }
  int change(int amount, vector<int>& coins) {
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[amount];
}




};