class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(dfs(nums, 1, nums.size()), dfs(nums, 0, nums.size() - 1));
    }
    int dfs(vector<int>& nums, int start, int end) {
        int n = end-start;
        if (n == 1) return nums[start + 0];
        vector<int> a(n, -1);
        a[0] = nums[start + 0];
        a[1] = max(nums[start + 0], nums[start + 1]);
        for (int i = 2; i < n; i++) {
            a[i] = max(nums[start + i] + a[i - 2], a[i - 1]);
        }
        return a[n - 1];
    }
};
