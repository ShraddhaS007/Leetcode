class Solution {
public:
   void dfs(int i,int j,int &x,vector<vector<char>>&a,vector<vector<int>>&v){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]=='X' || v[i][j]==1) return ;
                if((i==0 || j==0 || i==a.size()-1 || j==a[0].size()-1) && a[i][j]=='O') x++;
        v[i][j]=1;
        a[i][j]='A';

        dfs(i-1,j,x,a,v);
        dfs(i+1,j,x,a,v);
        dfs(i,j-1,x,a,v);
        dfs(i,j+1,x,a,v);
   }
   void dfs2(int i,int j,vector<vector<char>>&a,vector<vector<int>>&v){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]=='X' || v[i][j]==2) return;
        v[i][j]=2;
        a[i][j]='O';
        dfs2(i-1,j,a,v);
        dfs2(i+1,j,a,v);
        dfs2(i,j-1,a,v);
        dfs2(i,j+1,a,v);
   }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int x;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x=0;
                if(!vis[i][j] && board[i][j]=='O'){
                    dfs(i,j,x,board,vis);
                    cout<<x;
                    if(x!=0) dfs2(i,j,board,vis);
                }
                
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if( board[i][j]=='A') board[i][j]='X';
                
            }
        }
        
    }
};