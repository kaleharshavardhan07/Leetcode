class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector < vector<int>> ret;
        int c=0;
        if( m*n!=original.size()){
            return {};
        }
        for (int i = 0; i < m; i++) {
            vector<int> reti;
            for (int j = 0; j < n; j++) {
                reti.push_back(original[c]);
                c++;
            }
            ret.push_back(reti);
        }
        return ret;
    }
};