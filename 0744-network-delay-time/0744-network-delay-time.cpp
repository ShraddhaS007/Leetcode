class Solution {
public:
    
    int dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> d(n);
        for(int i=0;i<n;i++) d[i]=1e5;
        d[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                
                if(dis+edgeWeight< d[adjNode]){
                    d[adjNode]=dis+edgeWeight;
                    pq.push({d[adjNode],adjNode});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<d.size();i++){
            cout<<d[i]<<" ";
            maxi=max(maxi,d[i]);
        }
        if(maxi==1e5) return -1;
        return maxi;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& f : times) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }
        return dijkstra(adj,k);

    }
};