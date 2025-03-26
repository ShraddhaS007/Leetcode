class Solution {
public:
int diff(int a,int b){
    if(a>b) return a-b;
    return b-a;
}
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int>v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int c=0;
        int mid=v[n/2];  
        for(int i=1;i<n;i++){
            if((v[i]-v[i-1])%x!=0) return -1;
        }
        for(int i=0;i<n;i++){
            c+=diff(v[i],mid)/x;
        }
        return c;


    }
};