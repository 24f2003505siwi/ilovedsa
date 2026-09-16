class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited){
        visited[i] = true;
        for (int neighbor : adj[i]){
            if (!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() + 1 < n) return -1;
        vector<vector<int>> adj(n);
        for (const auto& conn : connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            if (visited[i] == false){
                components++;
                dfs(i, adj, visited);
            }
        }
        return components-1;
    }
};