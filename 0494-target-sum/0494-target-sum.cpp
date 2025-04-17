class Solution {
public:
    int fun(vector<int>&a,int n, int k,vector<vector<int>>&dp){
        if(n==0){
           if(k==a[n] && k==(a[n]*-1)) return 2;
           else if(k==a[n] || k==(a[n]*-1)) return 1;
           else return 0;
        }
        if(dp[n][k+2000]!=-1) return dp[n][k+2000];
        return dp[n][k+2000]=fun(a,n-1,k-a[n],dp)+fun(a,n-1,k+a[n],dp);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(4005,-1));
        return fun(nums,nums.size()-1,target,dp);
    }
};