class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});    //elevation, row, col
        visited[0][0] = true;
        int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
            if (row == n-1 && col == n-1) return time;
            for (int i = 0; i < 4; i++){
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];
                if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]){
                    int t = max(grid[r][c], time);
                    pq.push({t, r, c});
                    visited[r][c] = true;
                }
            }
        }
        return 0;
    }
};