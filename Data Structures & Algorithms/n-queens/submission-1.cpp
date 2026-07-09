class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sol;
        unordered_set<int> diag;

        unordered_set<int> diag2;
        unordered_set<int> col;
        dfs(res, sol, 0, diag, diag2, col, n);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& sol, int i, unordered_set<int>& diag,
             unordered_set<int> diag2, unordered_set<int>& col, int n) {
        if (i == n) {
            res.push_back(sol);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!col.count(j) && !diag.count(j - i) && !diag2.count(j + i)) {
                string s;
                int k;
                for (k = 0; k < j; k++) {
                    s.push_back('.');
                }
                s.push_back('Q');
                k++;
                for (; k < n; k++) {
                    s.push_back('.');
                }
                sol.push_back(s);
                col.insert(j);
                diag.insert(j - i);
                diag2.insert(j + i);
                dfs(res, sol, i + 1, diag, diag2, col, n);
                col.erase(j);
                sol.pop_back();
                diag.erase(j - i);
                diag2.erase(j + i);
            }
        }
    }
};
