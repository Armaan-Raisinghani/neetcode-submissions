class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices, dp);
    }
    int dfs(int i, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (canBuy) {
            if (i >= prices.size()) return 0;
            if (dp[i][0] != -1) {
                return dp[i][0];
            }
            return dp[i][0] = max(dfs(i + 1, false, prices, dp) - prices[i], dfs(i + 1, true, prices, dp));
            
        } else {
            if (i >= prices.size()) return 0;
            if(dp[i][1] != -1) return dp[i][1];
            return dp[i][1] = max(dfs(i+2, true, prices,dp)+prices[i], dfs(i+1, false, prices, dp));
        }
    }
};
