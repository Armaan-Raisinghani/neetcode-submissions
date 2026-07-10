class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int total = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(grid, total, i, j, 0, max);
                }
            }
        }
        return max;
    }
    void dfs(vector<vector<int>>& grid, int& total, int i, int j, int depth, int& max) {
        grid[i][j] = 0;
        total++;
        if (i + 1 < grid.size() && grid[i + 1][j]) {
            dfs(grid, total, i + 1, j, depth + 1, max);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1]) {
            dfs(grid, total, i, j + 1, depth + 1, max);
        }
        if (i > 0 && grid[i - 1][j]) {
            dfs(grid, total, i - 1, j, depth + 1, max);
        }
        if (j > 0 && grid[i][j - 1]) {
            dfs(grid, total, i, j - 1, depth + 1, max);
        }
        if (depth == 0) {
            if (total > max) max = total;
            total = 0;
        }
    }
};