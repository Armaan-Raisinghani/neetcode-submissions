class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        set<pair<int, int>> s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, res, 0, i, j, s);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, string& word, bool& res, int k, int i, int j,
             set<pair<int, int>>& s) {
        if (res) return;
        s.insert({i, j});
        k++;
        if (k == word.size() || res) {
            res = true;
            return;
        }
        if (i - 1 >= 0 && !s.count({i - 1, j}) && board[i - 1][j] == word[k]) {
            dfs(board, word, res, k, i - 1, j, s);
        }
        if (j - 1 >= 0 && !s.count({i, j - 1}) && board[i][j - 1] == word[k]) {
            dfs(board, word, res, k, i, j - 1, s);
        }
        if (i + 1 < board.size() && !s.count({i + 1, j}) && board[i + 1][j] == word[k]) {
            dfs(board, word, res, k, i + 1, j, s);
        }
        if (j + 1 < board[0].size() && !s.count({i, j + 1}) && board[i][j + 1] == word[k]) {
            dfs(board, word, res, k, i, j + 1, s);
        }
        s.erase({i, j});
    }
};
