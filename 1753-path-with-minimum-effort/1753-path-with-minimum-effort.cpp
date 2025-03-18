class Solution {
public:

    int abs(int a,int b){
        if(a>b) return a-b;
        return b-a;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {

        int dx[] = {-1, 1, 0, 0}; 
        int dy[] = {0, 0, -1, 1};

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> d(n,vector<int>(m,1e7));
        d[0][0]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dis=pq.top().first;
            int nodei=pq.top().second.first;
            int nodej=pq.top().second.second;
            pq.pop();
            
            for (int k = 0; k < 4; k++) { 
                int ni = nodei + dx[k];
                int nj = nodej + dy[k];

                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                     int edgeWeight=abs(heights[ni][nj],heights[nodei][nodej]);
             
                
                if(max(edgeWeight,dis)< d[ni][nj]){
                    d[ni][nj]=max(edgeWeight,dis);
                    pq.push({d[ni][nj],{ni,nj}});
                   
                }
                }
            }
           
        }
        return d[n-1][m-1];
        
    }
};