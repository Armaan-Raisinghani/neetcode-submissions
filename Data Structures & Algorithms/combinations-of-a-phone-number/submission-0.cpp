class Solution {
   public:
    vector<string> mp = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz"   // 9
    };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string sub;
        if(!digits.size()) return res;
        dfs(0, res, sub, digits);
        return res;
    }
    void dfs(int i, vector<string>& res, string& sub, string digits) {
        if (i == digits.size()) {
            res.push_back(sub);
            return;
        }
        for (int j = 0; j < mp[digits[i] - '0'].size(); j++) {
            sub.push_back(mp[digits[i] - '0'][j]);
            dfs(i + 1, res, sub, digits);
            sub.pop_back();
        }
    }
};
