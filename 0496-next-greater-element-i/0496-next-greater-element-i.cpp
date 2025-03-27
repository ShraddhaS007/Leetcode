class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int> m;
        vector<int> v;
       // s.push(nums2[0]);
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && s.top()<=nums2[i]){
                m[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(m[nums1[i]]>0) v.push_back(m[nums1[i]]);
            else v.push_back(-1);
        }
        return v;

    }
};