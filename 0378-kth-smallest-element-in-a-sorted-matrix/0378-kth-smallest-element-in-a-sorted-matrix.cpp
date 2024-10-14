class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ret;
        for( int i=0;i<matrix.size();i++){
            for( int j=0;j<matrix.size();j++){
                ret.push_back(matrix[i][j]);
            }

        }
        sort(ret.begin(),ret.end());
        return ret[k-1];
    }
};