class Solution {
   public:
    vector<int> cache;
    int minCostClimbingStairs(vector<int>& cost) {
        cache.resize(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
    int dfs(vector<int>& cost, int i) {
        if (i < cache.size() && cache[i] != -1) return cache[i];
        if (i >= cache.size()) return 0;
        return cache[i] = min(dfs(cost, i + 1), dfs(cost, i + 2))+cost[i];
    }
};
