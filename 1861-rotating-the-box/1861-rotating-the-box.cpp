class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();

        for (int i = 0; i < row; i++) {
            int emptyPos = col - 1; 
            for (int j = col - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptyPos = j - 1;
                } else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][emptyPos]);
                    emptyPos--;
                }
               
            }
        }

        vector<vector<char>> ret(col, vector<char>(row));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ret[j][row - i - 1] = box[i][j];
            }
        }

        return ret;
    }
};
