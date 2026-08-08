class Solution {
   public:
    unordered_map<int, vector<int>> hmap;
    unordered_set<int> temp_set;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) hmap[i].clear();
        for (auto pre : prerequisites) hmap[pre[0]].push_back(pre[1]);
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int c) {
        if (temp_set.contains(c)) return false;
        if (hmap[c].empty()) return true;
        temp_set.insert(c);
        for (int i : hmap[c]) {
            if (!dfs(i)) return false;
        }
        temp_set.erase(c);
        hmap[c].clear();
        return true;
    }
};
