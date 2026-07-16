class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0) return 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    fresh--;
                    q.push({i + 1, j});
                }
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    fresh--;
                    q.push({i - 1, j});
                }
                if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    fresh--;
                    q.push({i, j + 1});
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    fresh--;
                    q.push({i, j - 1});
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};