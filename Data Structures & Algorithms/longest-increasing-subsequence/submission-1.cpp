class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int m = 1;
        vector<int> dp = {1};
        for (int i = 1; i < nums.size(); i++) {
            int tmp = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) tmp = max(tmp, dp[j] + 1);
            }
            m = max(m, tmp);
            dp.push_back(tmp);
        }
        return m;
    }
};
