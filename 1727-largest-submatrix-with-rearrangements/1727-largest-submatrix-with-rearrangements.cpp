class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int l = matrix.size();
        int b = matrix[0].size();
        int maxi = 0;

        vector<vector<int>> mat(l, vector<int>(b, 0));
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < b; j++) {
                if (i == 0)
                    mat[i][j] = matrix[i][j];
                else {
                    if(matrix[i][j]!=0){
                    mat[i][j] = mat[i - 1][j] + matrix[i][j];}
                    else{
                         mat[i][j] = matrix[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < l; i++) {
            sort(mat[i].begin(), mat[i].end(), greater<int>());

            int mini = INT_MAX;

            for (int j = 0; j < b; j++) {
                mini = min(mini, mat[i][j]);

                int area = mini * (j + 1);
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};
