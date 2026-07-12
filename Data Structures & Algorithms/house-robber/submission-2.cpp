class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> a(nums.size(), -1);
        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            a[i] = max(nums[i] + a[i - 2], a[i - 1]);
        }
        return a[nums.size() - 1];
    }
};
