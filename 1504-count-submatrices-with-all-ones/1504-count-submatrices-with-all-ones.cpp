class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int result = 0;

        vector<vector<int>> width(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    width[i][j] = (j == 0 ? 1 : width[i][j - 1] + 1);

                   
                    int minWidth = width[i][j];
                   for (int k = i; k >= 0; k--) {
                       if (width[k][j] == 0)
                           break;
                       minWidth = min(minWidth, width[k][j]);
                       result += minWidth;
                   }
                }
            }
        }
        return result;
    }
};
