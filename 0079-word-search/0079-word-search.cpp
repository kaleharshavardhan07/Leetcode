class Solution {
public:
    bool solve(int cq, string word, vector<vector<char>>& board,
               vector<vector<int>>& vis, int r, int c) {
                  int row = board.size();
        int col = board[0].size();
        if (cq == word.size())
            return true;

        if (r < 0 || c < 0 || r >= row || c >= col || vis[r][c] ||
            board[r][c] != word[cq]) {
            return false;
        }

        vis[r][c] = 1;

        bool found = solve(cq + 1, word, board, vis, r + 1, c) || // down
                     solve(cq + 1, word, board, vis, r - 1, c) || // up
                     solve(cq + 1, word, board, vis, r, c + 1) || // right
                     solve(cq + 1, word, board, vis, r, c - 1);   // left

        vis[r][c] = 0;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int c = 0;
        char cur = word[0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[c]) {
                    // vis[i][j] = 1;
                    bool flag = solve(c, word, board, vis, i, j);
                    // vis[i][j] = 0;
                    if (flag)
                        return true;
                }
            }
        }
        return false;
    }
};