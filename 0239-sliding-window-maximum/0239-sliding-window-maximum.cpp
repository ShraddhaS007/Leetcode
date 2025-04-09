class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> d;
        vector<int> v;
        for(int i=0;i<k;i++){ 
            while(!d.empty() && nums[i]>d.back().first){
                d.pop_back();
            }
            d.push_back({nums[i],i});
        }
        
        for(int i=k;i<n;i++){
            v.push_back(d.front().first);
            while(!d.empty() && nums[i]>d.back().first){
                d.pop_back();
            }
            while(!d.empty() && i-d.front().second>=k) d.pop_front();
            d.push_back({nums[i],i});
        }
        v.push_back(d.front().first);
        return v;
    }
};