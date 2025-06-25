class Solution {
public:
//    int fun(int i, int j, vector<vector<int>>& a, vector<vector<int>>& vis) {
//     if(i<0 || j<0 || i>=a.size() || j>=a[0].size()) return 1000000;
//     if(a[i][j]==0) return 0;
//     if(vis[i][j]) return 1000000;

//     vis[i][j] = 1;

//     int up = fun(i-1, j, a, vis);
//     int left = fun(i, j-1, a, vis);
//     int down = fun(i+1, j, a, vis);
//     int right = fun(i, j+1, a, vis);

//     vis[i][j] = 0; // Unmark to allow other paths

//     return min({up, left, down, right}) + 1;
// }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        int x=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(mat[i][j]==0) {
                  q.push({{i,j},x});
                  vis[i][j]=1;
               }
            }
        }
        while(!q.empty()){
           int i=q.front().first.first;
           int j=q.front().first.second;
           x=q.front().second;
           q.pop();
           x++;
           if(i-1>=0 && vis[i-1][j]==0) {
              q.push({{i-1,j},x}); vis[i-1][j]=1; ans[i-1][j]=x;
           }
            if(j-1>=0 && vis[i][j-1]==0) {
                q.push({{i,j-1},x}); vis[i][j-1]=1; ans[i][j-1]=x;
            }
            if(i+1<n && vis[i+1][j]==0){
                q.push({{i+1,j},x}); vis[i+1][j]=1; ans[i+1][j]=x;
            } 
             if(j+1<m && vis[i][j+1]==0) {
                 q.push({{i,j+1},x}); vis[i][j+1]=1; ans[i][j+1]=x;
             }
        }
        return ans;
        

    }
};