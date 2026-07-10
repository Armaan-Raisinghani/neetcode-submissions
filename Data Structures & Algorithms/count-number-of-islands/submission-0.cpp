class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int total = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, total, i, j, 0);
                }
            }
        }
        return total;
    }
    void dfs(vector<vector<char>>& grid, int& total, int i, int j, int depth) {
        grid[i][j] = '0';
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
            dfs(grid, total, i + 1, j, depth + 1);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') {
            dfs(grid, total, i, j + 1, depth + 1);
        }
        if (i > 0 && i - 1 < grid.size() && grid[i - 1][j] == '1') {
            dfs(grid, total, i - 1, j, depth + 1);
        }
        if (j > 0 && j - 1 < grid[0].size() && grid[i][j - 1] == '1') {
            dfs(grid, total, i, j - 1, depth + 1);
        }
        if (depth == 0) total += 1;
    }
};
