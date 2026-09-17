class Solution {
private:
    int n;
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int dfs(int r, int c, int islandid, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) {
            return 0;
        }
        int size = 1;
        grid[r][c] = islandid;
        for (int i = 0; i < 4; i++) {
            size += dfs(r + dirs[i][0], c + dirs[i][1], islandid, grid);
        }
        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int islandid = 2;
        unordered_map<int, int> islandsizes;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] == 1){
                    islandsizes[islandid] = dfs(r, c, islandid, grid);
                    islandid++;
                }
            }
        }
        //edge cases
        if (islandsizes.size() == 0) return 1;
        int maxisland = 0;
        for (auto& pair : islandsizes){
            maxisland = max(maxisland, pair.second);
        }
        if (maxisland == n * n) return n * n;

        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] == 0){
                    unordered_set<int> neighborislands;
                    for (int i = 0; i < 4; i++){
                        int row = r + dirs[i][0];
                        int col = c + dirs[i][1];
                        if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] != 0){
                            neighborislands.insert(grid[row][col]);
                        }
                    }
                    int currentsize = 1;
                    for (int size : neighborislands){
                        currentsize += islandsizes[size];
                    }
                    maxisland = max(maxisland, currentsize);
                }
            }
        }
        return maxisland;
    }
};