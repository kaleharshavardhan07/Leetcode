class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int l = 0;
        int r = matrix[0].size();
        int t = 0;
        int b = matrix.size();
        vector<int> ret;
        while (l < r && t < b) {
            for (int i = l; i < r; i++) {
                ret.push_back(matrix[t][i]);
            }
            t++;
            for (int i = t; i < b; i++) {
                ret.push_back(matrix[i][r - 1]);
            }
            r--;
            if (!(l < r && t < b)) {
                break;
            }
            for (int i = r - 1; i >= l ; i--) {
                ret.push_back(matrix[b - 1][i]);
            }
            b--;
            for (int i = b - 1; i >= t ; i--) {
                ret.push_back(matrix[i][l]);
            }
            l++;
            
        }
        return ret;
    }

}
;