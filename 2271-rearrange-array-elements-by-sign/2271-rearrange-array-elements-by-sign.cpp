class Solution {
public:
     void swap(vector<int>& a,int l,int r){
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
     }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        int p=0;
        int n=1;
        int m=nums.size();
       
            for(int i=0;i<m;i++){
                  v.push_back(0);
            }
             for(int i=0;i<m;i++){
                if(nums[i]>0) {
                    v[p]=nums[i];p+=2;
                }else{
                    v[n]=nums[i];n+=2;
                }
            }
        
        return v;
    }
};