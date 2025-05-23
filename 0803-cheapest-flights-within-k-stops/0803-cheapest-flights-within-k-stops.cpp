

   class Solution {
public:
    int fun(vector<vector<pair<int, int>>>&adj,int s,int dst,int k){
        queue<pair<int,pair<int,int>>>q;
        vector<int>d(adj.size(),1e9);
        q.push({0,{s,0}});
        d[s]=0;
        while(!q.empty()){
            int dis=((q.front()).second).second;
            int node=((q.front()).second).first;
            int stop=(q.front()).first;
            q.pop();
            if(stop>k) continue;
            for(auto it : adj[node]){
                int w=it.second;
                int n=it.first;
                if(dis+w<d[n] && stop<=k){
                    d[n]=dis+w;
                    q.push({stop+1,{n,d[n]}});
                }
            }
        }
        if(d[dst]==1e9) return -1;
        return d[dst];

    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        return fun(adj,src,dst,k);
    }
};
