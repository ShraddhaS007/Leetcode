class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&a,vector<vector<int>>&vis,int c,int x){
        if(i<0 || i>=a.size() || j<0 || j>=a[0].size() || vis[i][j]) return ;
        vis[i][j]=1;
        a[i][j]=c;
        if(i-1>=0 && a[i-1][j]==x) dfs(i-1,j,a,vis,c,x);
        if(i+1<a.size() && a[i+1][j]==x) dfs(i+1,j,a,vis,c,x);
        if(j-1>=0 &&  a[i][j-1]==x) dfs(i,j-1,a,vis,c,x);
        if(j+1<a[0].size() &&  a[i][j+1]==x) dfs(i,j+1,a,vis,c,x);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int x=image[sr][sc];
        dfs(sr,sc,image,vis,color,x);
        return image;
    }
};