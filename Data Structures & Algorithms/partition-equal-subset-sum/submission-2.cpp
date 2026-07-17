class Solution {
   public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        dp.resize(nums.size(), vector<int>(sum / 2 + 1, 0));
        return dfs(nums, sum / 2, 0);
    }
    bool dfs(vector<int>& nums, int target, int i) {
        if (i == nums.size()) return false;
        if (target == 0) return true;
        if (target < 0) return false;
        if (dp[i][target] != 0) return dp[i][target] == 1;
        bool res = dfs(nums, target, i + 1) || dfs(nums, target - nums[i], i + 1);
        dp[i][target] = res ? 1 : -1;
        return res;
    }
};
