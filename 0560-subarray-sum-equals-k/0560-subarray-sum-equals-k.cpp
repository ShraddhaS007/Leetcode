class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> m;
        int s=0;
        m[0]++;
        int ans=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(!m.empty() && m[s-k]!=0){
               ans+=m[s-k];
            }
            m[s]++;;
        }
        return ans;
    }
};