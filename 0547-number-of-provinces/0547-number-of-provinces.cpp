class Solution {
public:
    void dfs(int n,int nd,vector<vector<int>>& a,vector<int>& vis){
        vis[nd]=1;
        for(int i=0;i<n;i++){
          if(!vis[i] && a[nd][i]==1 && nd!=i) dfs(n,i,a,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(n,i,isConnected,vis);
                c++;
            }
        }
        return c;

    }
};