class Solution {
   public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, 0));
        return dfs(0, 0);
    }
    int dfs(int i, int j) {
        if (i >= dp.size() || j >= dp[0].size()) return 0;
        if (i == dp.size() - 1 && j == dp[0].size() - 1) return 1;
        if (dp[i][j] != 0) return dp[i][j];
        int tmp = dfs(i, j + 1) + dfs(i + 1, j);
        dp[i][j] = tmp;
        return tmp;
    }
};
