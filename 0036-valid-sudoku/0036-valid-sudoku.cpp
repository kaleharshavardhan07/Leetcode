class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            int a[10] = {0};
            for (int j = 0; j < 9; j++) {

                char c = board[i][j];
                if (c == '.')
                    continue;
                if (a[c - '0'] == 1) {
                    return false;
                } else {
                    a[c - '0'] = 1;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            int a[10] = {0};
            for (int j = 0; j < 9; j++) {

                char c = board[j][i];
                if (c == '.')
                    continue;
                if (a[c - '0'] == 1) {
                    return false;
                } else {
                    a[c - '0'] = 1;
                }
            }
        }
        for (int blockRow = 0; blockRow < 9; blockRow += 3) {
            for (int blockCol = 0; blockCol < 9; blockCol += 3) {
                int a[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[blockRow + i][blockCol + j];
                        if (c == '.')
                            continue;
                        if (a[c - '0'] == 1) {
                            return false;
                        } else {
                            a[c - '0'] = 1;
                        }
                    }
                }
            }
        }
        return true;
     
    }
};