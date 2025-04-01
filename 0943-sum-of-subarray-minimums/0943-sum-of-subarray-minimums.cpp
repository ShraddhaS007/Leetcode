class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N=1e9+7;
        int n=arr.size();
        vector<int> lm(n,-1);
        vector<int> rm(n,n);
   
        stack<pair<int,int>> s1;
        stack<pair<int,int>> s2;
        
        s1.push({arr[0],0});
        s2.push({arr[n-1],n-1});
        for(int i=1;i<n;i++){
          while(!s1.empty() && arr[i]<=(s1.top()).first){
            rm[(s1.top()).second]=i;
            s1.pop();
          }
          s1.push({arr[i],i});
        }
        for(int i=n-2;i>=0;i--){
          while(!s2.empty() && arr[i]<(s2.top()).first){
            lm[(s2.top()).second]=i;
            s2.pop();
          }
          s2.push({arr[i],i});
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<lm[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<rm[i]<<" ";
        // }
        long long int s=0;
        for(int i=0;i<n;i++){
           s = (s + (1LL * (i - lm[i]) * (rm[i] - i) % N * arr[i] % N) % N) % N;

        }
        return s;
      
    }
};