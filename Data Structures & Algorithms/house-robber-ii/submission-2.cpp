class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(dfs(nums, 1, nums.size()), dfs(nums, 0, nums.size() - 1));
    }
    int dfs(vector<int>& nums, int start, int end) {
        int n = end - start;
        if (n == 1) return nums[start + 0];
        int r0 = nums[start + 0];
        int r1 = max(nums[start + 0], nums[start + 1]);
        int temp;
        for (int i = 2; i < n; i++) {
            temp = max(nums[start + i] + r0, r1);
            r0 = r1;
            r1 = temp;
        }
        return r1;
    }
};
