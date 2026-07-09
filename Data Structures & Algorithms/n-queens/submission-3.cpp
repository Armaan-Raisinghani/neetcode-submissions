class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sol;
        vector<bool> diag(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        vector<bool> col(n, false);

        dfs(res, sol, 0, diag, diag2, col, n);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& sol, int i,
             vector<bool>& diag, vector<bool>& diag2,
             vector<bool>& col, int n) {
        if (i == n) {
            res.push_back(sol);
            return;
        }

        for (int j = 0; j < n; j++) {
            int d1 = i - j + n - 1;
            int d2 = i + j;

            if (!col[j] && !diag[d1] && !diag2[d2]) {
                string s(n, '.');
                s[j] = 'Q';

                sol.push_back(s);
                col[j] = true;
                diag[d1] = true;
                diag2[d2] = true;

                dfs(res, sol, i + 1, diag, diag2, col, n);

                col[j] = false;
                diag[d1] = false;
                diag2[d2] = false;
                sol.pop_back();
            }
        }
    }
};