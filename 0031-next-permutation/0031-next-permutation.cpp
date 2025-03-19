class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int c=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                c=i-1;
                break;
            }
        }
        if(c==-1){
            sort(nums.begin(),nums.end());
        }else{
        vector<int> v;
        for(int i=c;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        int x;
        for(int i=0;i<v.size();i++){
            if(v[i]>nums[c]) {
                x=v[i];
                break;
            }
        }
        nums[c]=x;
        int j=0;
        int f=0;
      //  for(int i=c+1;i<nums.size();i++){
        int i=c+1;
        while(i<nums.size()){
            if(f==0 && v[j]==x){
                f=1;
                j++;
            }else{
            nums[i]=v[j];
            i++;
            j++;
            }
        }
        }
    }
};