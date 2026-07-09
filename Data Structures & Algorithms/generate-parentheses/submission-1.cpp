class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sub;
        dfs(res, sub, 0, n, 0);
        return res;
    }
    void dfs(vector<string>& res, string& sub, int i, int n, int open) {
        if (i == n && open == 0) {
            res.push_back(sub);
            return;
        }
        if (i < n) {
            sub.push_back('(');
            open += 1;
            dfs(res, sub, i + 1, n, open);
            sub.pop_back();
            open -= 1;
        }
        if (open > 0) {
            sub.push_back(')');
            open -= 1;
            dfs(res, sub, i, n, open);
            sub.pop_back();
        }
    }
};
