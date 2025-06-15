class Solution {
public:
    int fun(vector<int>&a, int i,vector<int>& dp){
        if(i==a.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=100000;
        int j=i+1;
        while(j<a.size() && j<=i+a[i]){
          mini=min(mini,fun(a,j,dp)+1);
          j++;
        }
        
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fun(nums,0,dp);
    }
};