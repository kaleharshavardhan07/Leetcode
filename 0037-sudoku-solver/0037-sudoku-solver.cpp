class Solution {
public:
    bool rec(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (tf(board, i, j, c)) {
                            board[i][j] = c;
                            if (rec(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool tf(vector<vector<char>>& board, int r, int c, char k){
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == k)
                return false; 
            if (board[i][c] == k)
                return false; 
            int br = 3 * (r / 3) + i / 3;
            int bc = 3 * (c / 3) + i % 3;
            if (board[br][bc] == k)
                return false; 
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) { rec(board); }
};
