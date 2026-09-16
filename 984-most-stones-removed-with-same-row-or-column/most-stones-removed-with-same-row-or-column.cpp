class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[i] = true;
        for (int neighbor : adj[i]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++){
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }
        return n - components;
    }
};