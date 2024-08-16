class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false;
        int col = matrix[0].size();
        
        int srow = -1; 
        
        for (int i = 0; i < row - 1; i++) {
            if (target == matrix[i][0])
                return true;
            if (target == matrix[i + 1][0])
                return true;
            if (target > matrix[i][0] && target < matrix[i + 1][0]) {
                srow = i;
                break;
            }
        }

        if (srow == -1) {
            if (target >= matrix[row-1][0] && target <= matrix[row-1][col-1]) {
                srow = row - 1;
            } else {
                return false;
            }
        }
        
        for (int i = 0; i < col; i++) {
            if (matrix[srow][i] == target)
                return true;
        }
        
        return false;
    }
};
