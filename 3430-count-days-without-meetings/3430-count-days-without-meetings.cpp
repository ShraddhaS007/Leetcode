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
            while (i<n-1 && intervals[i+1][0]<=r){
              l=min(l,intervals[i+1][0]);
              r=max(r,intervals[i+1][1]);
              i++;
            }
            v.push_back({l,r});
            i++;
           
        }
        int s=0;
        for(int i=0;i<v.size();i++){
            s+=v[i][1]-v[i][0]+1;
        }
        return s;;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        return days-merge(meetings);
    }
};