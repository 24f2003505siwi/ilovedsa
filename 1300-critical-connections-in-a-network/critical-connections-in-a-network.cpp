class Solution {
private:

        int timer = 0;
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& result){
        tin[u] = low[u] = timer++;
        for (int v : adj[u]){
            if (v == parent){
                continue;
            } else if (tin[v] == -1){
                dfs(v, u, adj, tin, low, result);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]){
                    result.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (const auto& conn : connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n, -1);
        vector<int> low(n);
        vector<vector<int>> result;
        dfs(0, -1, adj, tin, low, result);
        return result;
    }
};