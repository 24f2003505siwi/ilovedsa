class Solution {
public:
    unordered_map<int, int> parent;
    int find(int i){
        if (parent.find(i) == parent.end()){
            parent[i] = i;
        }
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
    int removeStones(vector<vector<int>>& stones) {
        parent.clear();
        for (const auto& stone : stones){
            unionnodes(stone[0], stone[1] + 10001);
        }
        unordered_set<int> components;
        for (const auto& stone : stones){
            components.insert(find(stone[0]));
        }
        return stones.size() - components.size();
    }
};