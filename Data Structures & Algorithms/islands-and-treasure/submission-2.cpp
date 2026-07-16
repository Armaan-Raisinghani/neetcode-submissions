class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i < grid.size() - 1 && grid[i + 1][j] == 2147483647) {
                grid[i + 1][j] = grid[i][j] + 1;
                q.push({i + 1, j});
            }
            if (i > 0 && grid[i - 1][j] == 2147483647) {
                grid[i - 1][j] = grid[i][j] + 1;
                q.push({i - 1, j});
            }
            if (j < grid[0].size() - 1 && grid[i][j + 1] == 2147483647) {
                grid[i][j + 1] = grid[i][j] + 1;
                q.push({i, j + 1});
            }
            if (j > 0 && grid[i][j - 1] == 2147483647) {
                grid[i][j - 1] = grid[i][j] + 1;
                q.push({i, j - 1});
            }
        }
    }
};