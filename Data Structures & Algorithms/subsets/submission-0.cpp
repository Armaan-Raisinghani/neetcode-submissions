class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> subset = {};
        subs(nums, 0, res, subset);
        return res;
    };
    void subs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& subset) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        subs(nums, i + 1, res, subset);
        subset.pop_back();
        subs(nums, i + 1, res, subset);
    }
};
