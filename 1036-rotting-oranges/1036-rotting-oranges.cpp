class Solution {
public:
      int bfs(int n,int m,vector<vector<int>>& a,vector<vector<int>>& vis){
        
        queue<pair<pair<int,int>,int>>q;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==2) {
                    q.push({{i,j},c});
                    vis[i][j]=1;
                }
            }
        }
        
        int ans=0;
       
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int x=q.front().second;
            ans=max(ans,x);
            q.pop();
            if(i-1>=0 && a[i-1][j]!=0 && !vis[i-1][j]){
             q.push({{i-1,j},x+1}); vis[i-1][j]=1; a[i-1][j]=2;
            }
            if(i+1<n && a[i+1][j]!=0 && !vis[i+1][j]){
                q.push({{i+1,j},x+1}); vis[i+1][j]=1; a[i+1][j]=2;
            } 
             if(j-1>=0 && a[i][j-1]!=0 && !vis[i][j-1]){
               q.push({{i,j-1},x+1}); vis[i][j-1]=1; a[i][j-1]=2;
             } 
             if(j+1<m && a[i][j+1]!=0 && !vis[i][j+1]){
                 q.push({{i,j+1},x+1}); vis[i][j+1]=1; a[i][j+1]=2;
             }
             

        }
        return ans;
        //   dfs(n,m,i-1,j,a,vis,c);
        //  dfs(n,m,i+1,j,a,vis,c);
        //  dfs(n,m,i,j-1,a,vis,c);
        // dfs(n,m,i,j+1,a,vis,c);
        
       
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    ans=bfs(n,m,grid,vis);
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                    return -1;
                }
            }
        }
        return ans;

    }
};