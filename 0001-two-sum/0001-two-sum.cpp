class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
      map<int,pair<int,int>> m;
      for(int i=0;i<n;i++){
          m[nums[i]]={1,i};
      }
      for(int i=0;i<n;i++){
          if(m[target-nums[i]].first!=0 && m[target-nums[i]].second!=i) return {i,m[target-nums[i]].second};
      }
      return {};
    }
};