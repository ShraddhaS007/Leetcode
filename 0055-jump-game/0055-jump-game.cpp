class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp){
        if(dp[i]!=-1) return dp[i];
        if(i>=nums.size()-1){
             return dp[i]=1;
        }
        for(int j=1;j<=nums[i];j++){
            if(fun(i+j,nums,dp)) return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(fun(0,nums,dp)){
            return true;
        }
        return false;
    }
};