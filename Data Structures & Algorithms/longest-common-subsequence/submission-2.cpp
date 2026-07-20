class Solution {
   public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }
    int dfs(string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int r;
        if (text1[i] == text2[j])
            r = 1 + dfs(text1, text2, i + 1, j + 1);
        else
            r = max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1));
        dp[i][j] = r;
        return r;
    }
};
