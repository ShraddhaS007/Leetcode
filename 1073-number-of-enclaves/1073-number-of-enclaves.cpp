class Solution {
public:
// Surrounded Regions Code
   void dfs(int i,int j,int &x,vector<vector<int>>&a,vector<vector<int>>&v){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==0 || v[i][j]==1) return ;
                if((i==0 || j==0 || i==a.size()-1 || j==a[0].size()-1) && a[i][j]==1) x++;
        v[i][j]=1;
        a[i][j]=2;

        dfs(i-1,j,x,a,v);
        dfs(i+1,j,x,a,v);
        dfs(i,j-1,x,a,v);
        dfs(i,j+1,x,a,v);
   }
   void dfs2(int i,int j,vector<vector<int>>&a,vector<vector<int>>&v){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==0 || v[i][j]==2) return;
        v[i][j]=2;
        a[i][j]=1;
        dfs2(i-1,j,a,v);
        dfs2(i+1,j,a,v);
        dfs2(i,j-1,a,v);
        dfs2(i,j+1,a,v);
   }
    int numEnclaves(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        int x;int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1) ans++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x=0;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,x,grid,vis);
                    cout<<x;
                    if(x!=0) dfs2(i,j,grid,vis);
                }
                
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==2) grid[i][j]=0;
            }
        }
        int c=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1) c++;
            }
        }
        return ans-c;
        
    }
};