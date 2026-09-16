class Solution {
public:
    vector<int> parent;
    int find(int i){
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unionnodes(int i, int j){
        int rooti = find(i);
        int rootj = find(j);
        if (rooti != rootj){
            parent[rooti] = rootj;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (const auto& conn : connections){
            unionnodes(conn[0], conn[1]);
        }
        int components = 0;
        for (int i = 0; i < n; i++){
            if (parent[i] == i) components++;
        }
        return components - 1;
    }
};