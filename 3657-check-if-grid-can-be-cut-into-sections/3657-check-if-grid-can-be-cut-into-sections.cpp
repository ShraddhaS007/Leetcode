class Solution {
public:
    int merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        int n=intervals.size();
        int i=0;
        int l,r;
        while(i<n){     
            l=intervals[i][0]; r=intervals[i][1];
            while (i<n-1 && intervals[i+1][0]<r){
              l=min(l,intervals[i+1][0]);
              r=max(r,intervals[i+1][1]);
              i++;
            }
            v.push_back({l,r});
            i++;
           
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl;
        // }
        return v.size();
    }
   bool fun(int nn,vector<vector<int>>&v){
     vector<vector<int>> v1;
     vector<vector<int>> v2;
        for(int i=0;i<v.size();i++){
           v1.push_back({v[i][0],v[i][2]});
           v2.push_back({v[i][1],v[i][3]});
     }
    
     if(merge(v1)>=3 || merge(v2)>=3) return true;
     return false;
   }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return fun(n,rectangles);
    }
};