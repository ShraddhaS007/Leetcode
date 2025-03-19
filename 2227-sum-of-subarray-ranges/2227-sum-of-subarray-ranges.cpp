class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long int maxi,mini,c=0;
        for(int i=0;i<n-1;i++){
            mini=nums[i];
            maxi=nums[i];
            for(int j=i+1;j<n;j++){
                if(maxi<nums[j]) maxi=nums[j];
                if(mini>nums[j]) mini=nums[j];
                c+=maxi-mini;
            }
        }
        return c;
    }
};