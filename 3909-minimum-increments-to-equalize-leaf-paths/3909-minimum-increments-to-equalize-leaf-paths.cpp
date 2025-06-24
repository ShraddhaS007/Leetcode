class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
      

    vector<long long> lcost(cost.begin(), cost.end());
    vector<vector<int>> adj(n);
    vector<int> l(n, 0);
    vector<int> par(n, -1);
    int ans = 0;
     // int t;
    for (auto &i : edges) {
        if(i[1]==0) {
           swap(i[0],i[1]);
        }
    }
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
        par[i[1]] = i[0];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    l[0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        l[x] = y;
        q.pop();
        for (auto i : adj[x]) {
            q.push({i, y + 1});
        }
    }

    vector<vector<pair<int, int>>> adj2(n);
    for (auto i : edges) {
        adj2[i[0]].push_back({i[1], l[i[1]]});
    }

    vector<pair<int, vector<pair<int, int>>>> temp;

    for (int i = 0; i < n; ++i) {
        temp.push_back({i, adj2[i]});
    }

    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b) {
        int valA = a.second.empty() ? -1 : a.second[0].second;
        int valB = b.second.empty() ? -1 : b.second[0].second;
        return valA > valB;
    });

    long long maxi;
    for (const auto &p : temp) {

        maxi = 0;
        for (const auto &pr : p.second) {
            maxi = max(maxi, lcost[pr.first]);
        }
        for (const auto &pr : p.second) {
            if (lcost[pr.first] != maxi) {
                lcost[pr.first] = maxi;
                ans++;
            }
        }
        lcost[p.first] += maxi;
    }

    return ans;
}

};