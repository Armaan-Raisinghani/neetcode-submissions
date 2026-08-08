class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int total = 0;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, total, i, 0);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                dfs(board, total, i, n - 1);
            }
        }

        // Top edge
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, total, 0, j);
            }
        }

        // Bottom edge
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O') {
                dfs(board, total, m - 1, j);
            }
        }

        // Replace cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '@')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

    }

    void dfs(vector<vector<char>>& board, int& total, int i, int j) {
        board[i][j] = '@';
        if (i + 1 < board.size() && board[i + 1][j] == 'O') {
            dfs(board, total, i + 1, j);
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O') {
            dfs(board, total, i, j + 1);
        }
        if (i > 0 && i - 1 < board.size() && board[i - 1][j] == 'O') {
            dfs(board, total, i - 1, j);
        }
        if (j > 0 && j - 1 < board[0].size() && board[i][j - 1] == 'O') {
            dfs(board, total, i, j - 1);
        }
    }
};