class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            long long time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<long long> mintime(n, LLONG_MAX);
        mintime[0] = 0;
        vector<long long> paths(n, 0);
        paths[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        while (!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();
            if (t > mintime[u]) continue;
            for (const auto& neighbor : adj[u]){
                int v = neighbor.first;
                long long time = neighbor.second;
                if (mintime[v] > mintime[u] + time){
                    mintime[v] = mintime[u] + time;
                    paths[v] = paths[u];
                    pq.push({mintime[v], v});
                } else if (mintime[v] == mintime[u] + time){
                    paths[v] = (paths[v] + paths[u]) % mod;
                }
            }
        }
        return paths[n-1];
    }
};