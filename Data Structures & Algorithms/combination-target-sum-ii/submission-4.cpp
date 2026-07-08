class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, subset);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int i, vector<vector<int>>& res,
             vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        int n = candidates.size();
        if (i == n || candidates[i] > target) {
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1, res, subset);
        subset.pop_back();
        int a = candidates[i];
        while (i < candidates.size() && candidates[i] == a) i++;
        dfs(candidates, target, i, res, subset);
    }
};
