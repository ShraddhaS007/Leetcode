class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int t=0-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]==t){
                    v.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }else if(nums[l]+nums[r]>t){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return v;
    }
};