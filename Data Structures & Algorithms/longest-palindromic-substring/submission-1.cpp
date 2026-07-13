class Solution {
   public:
    string longestPalindrome(string s) {
        int res = 0;
        int reslen = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i + 1 <= 3 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if ((j - i + 1) > reslen) {
                            reslen = j - i + 1;
                            res = i;
                        }
                    }
                }
            }
        }
        return s.substr(res, reslen);
    }
};
