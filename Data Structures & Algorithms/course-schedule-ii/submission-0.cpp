class Solution {
   public:
    unordered_map<int, vector<int>> hmap;
    unordered_set<int> temp_set;
    vector<int> res;
    unordered_set<int> res_set;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) hmap[i].clear();
        res.clear();
        for (auto pre : prerequisites) hmap[pre[0]].push_back(pre[1]);
        temp_set.clear();
        res_set.clear();
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return vector<int>();
            }
        }
        return res;
    }

    bool dfs(int c) {
        if (temp_set.contains(c)) return false;
        if (hmap[c].empty()) {
            if (!res_set.contains(c)) {
                res.push_back(c);
                res_set.insert(c);
            }
            return true;
        }
        temp_set.insert(c);
        for (int i : hmap[c]) {
            if (!dfs(i)) return false;
        }
        temp_set.erase(c);
        hmap[c].clear();
        if (!res_set.contains(c)) {
            res.push_back(c);
            res_set.insert(c);
        }
        return true;
    }
};