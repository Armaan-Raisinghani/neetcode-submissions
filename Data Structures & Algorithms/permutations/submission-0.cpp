class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<vector<int>> res;
        vector<int> sub;
        backtrack(res, pick, nums, sub);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<bool>& pick, vector<int>& nums,
                   vector<int> sub) {
        if (sub.size() == nums.size()) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                sub.push_back(nums[i]);
                pick[i] = true;
                backtrack(res, pick, nums, sub);
                sub.pop_back();
                pick[i] = false;
            }
        }
    }
};
