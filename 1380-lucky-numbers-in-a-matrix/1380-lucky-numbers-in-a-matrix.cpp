class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
vector<int>mini;
vector<int>ret;
vector<int>maxi;
        for(int i=0;i<row;i++){
            int min =INT_MAX;
            for(int j=0;j<col;j++){
                if(min>matrix[i][j]){
                    min=matrix[i][j];
                }
            }
            mini.push_back(min);
        }
     
        for(int i=0;i<col;i++){
               int max=INT_MIN;
            for(int j=0;j<row;j++){
                if(max<matrix[j][i]){
                    max=matrix[j][i];
                }
            }
            maxi.push_back(max);
        }

         for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == mini[i] && matrix[i][j] == maxi[j]) {
                    ret.push_back(matrix[i][j]);
                }
            }
        }
        
        return ret;

    }
};