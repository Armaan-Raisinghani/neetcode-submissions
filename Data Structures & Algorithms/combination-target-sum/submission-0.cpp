class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, res, subset, target);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& subset, int target) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i == nums.size()) return;
        subset.push_back(nums[i]);
        dfs(nums, i, res, subset, target - nums[i]);
        subset.pop_back();
        dfs(nums, i + 1, res, subset, target);
    }
};
