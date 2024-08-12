class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>>ret;
        for(int i=0;i<=rowIndex;i++){
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=ret[i-1][j-1]+ret[i-1][j];
            }
            ret.push_back(row);
        }
        return ret[rowIndex];
    }
};