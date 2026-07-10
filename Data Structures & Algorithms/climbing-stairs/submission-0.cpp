class Solution {
   public:
    vector<int> cache;
    int climbStairs(int n) {
        cache.resize(n, -1);
        return dfs(0, n);
    }
    int dfs(int i, int n) {
        if (i < n && cache[i] != -1) return cache[i];
        if (i == n) return 1;
        if (i > n) return 0;
        int a = dfs(i + 1, n) + dfs(i + 2, n);
        cache[i] = a;
        return a;
    }
};
