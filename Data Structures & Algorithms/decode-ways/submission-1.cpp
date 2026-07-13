class Solution {
   public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.resize(s.size() + 1, -1);
        return dfs(s, 0);
    }
    int dfs(string& s, int i) {
        if (i == s.size()) return 1;

        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];
        int a = 0;
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            a = dfs(s, i + 2) + dfs(s, i + 1);
        } else
            a = dfs(s, i + 1);
        dp[i] = a;
        return a;
    }
};
