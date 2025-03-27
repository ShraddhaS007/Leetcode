class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>c1;
        unordered_map<int,int>c2;
        int v1[n];
        int v2[n];

        for(int i=0;i<n;i++){
           c1[nums[i]]++;
           if(c1[nums[i]]>(i+1)/2) {
              v1[i]=nums[i];
           }else if(c1[v1[i-1]]>(i+1)/2){
              v1[i]=v1[i-1];
           }
           else{
             v1[i]=-1;
           }
        }
         for(int i=n-1;i>=0;i--){
           c2[nums[i]]++;
           if(c2[nums[i]]>(n-i)/2) {
              v2[i]=nums[i];
           }else if(c2[v2[i+1]]>(n-i)/2){
                v2[i]=v2[i+1];
            }else{
             v2[i]=-1;
           }
        }
        // for(int i=0;i<n;i++){
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<v2[i]<<" ";
        // }
        //   cout<<endl;
        for(int i=0;i<n-1;i++){
            if(v1[i]==v2[i+1] && v1[i]!=-1) {
                ans=i;
                break;
            }
        }
        return ans;
        
    }
};