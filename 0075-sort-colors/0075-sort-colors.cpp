class Solution {
public:
    void swap(vector<int>&nums,int l,int m){
        int t=nums[l];
        nums[l]=nums[m];
        nums[m]=t;
    }
    void sortColors(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int m=0;
        while(m<=r){
        if(nums[m]==0){
            swap(nums,l,m);
            l++;m++;
        }else if(nums[m]==2){
            swap(nums,m,r);
            r--;        
        }else{
            m++;
        }
        }
        
    }
};