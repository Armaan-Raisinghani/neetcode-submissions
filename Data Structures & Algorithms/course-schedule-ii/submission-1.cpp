class Solution {
   public:
    vector<vector<int>> hmap;
    vector<int> state;
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        hmap.assign(numCourses, {});
        state.assign(numCourses, 0);
        res.clear();

        for (auto pre : prerequisites)
            hmap[pre[0]].push_back(pre[1]);

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c))
                return {};
        }

        return res;
    }

    bool dfs(int c) {
        if (state[c] == 1)
            return false;

        if (state[c] == 2)
            return true;

        state[c] = 1;

        for (int i : hmap[c]) {
            if (!dfs(i))
                return false;
        }

        state[c] = 2;
        res.push_back(c);

        return true;
    }
};