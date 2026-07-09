class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res = {};
        vector<string> sub = {};
        dfs(res, sub, s, 0, 0);
        return res;
    }
    bool isPal(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& sub, string& s, int start, int current) {
        if (start == s.size()) {
            res.push_back(sub);
        }
        while (current < s.size() && !isPal(s.substr(start, current - start + 1))) current++;
        if (current == s.size()) return;
        sub.push_back(s.substr(start, current - start + 1));
        dfs(res, sub, s, current + 1, current + 1);
        sub.pop_back();
        dfs(res, sub, s, start, current + 1);
    }
};
