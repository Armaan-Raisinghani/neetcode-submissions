class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        dfs(res, sub, 0, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& sub, int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(res, sub, i + 1, nums);
        int a = nums[i];
        sub.pop_back();
        while (i < nums.size() && nums[i] == a) i++;
        dfs(res, sub, i, nums);
    }
};
