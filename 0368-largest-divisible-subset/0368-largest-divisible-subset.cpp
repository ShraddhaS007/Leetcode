class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
      
         vector<int>h;
         for(int i=0;i<n;i++){
           h.push_back(i);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                      dp[i]=dp[j]+1;
                      h[i]=j;
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
          maxi=max(maxi,dp[i]);
        }
        int x;
        for(int i=0;i<n;i++){
           if(dp[i]==maxi){
               x=i;
               break;
           }
        }
        vector<int>ans;
        ans.push_back(nums[x]);
        while(ans.size()<maxi){
            x=h[x];
            ans.push_back(nums[x]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};