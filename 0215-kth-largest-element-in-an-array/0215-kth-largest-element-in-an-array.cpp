class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> m;
        for(int i : nums){
            m.push(i);
            if(m.size()>k){
                m.pop();
            }
        }
        return m.top();
    }
};