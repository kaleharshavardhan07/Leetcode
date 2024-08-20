class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int count=0;
        int minr=m;
        int mincol=n;
        for(auto it :ops){
            if(it[0]>0 && it[1]>0){
                count++;
                minr=min(minr,it[0]);
                mincol=min(mincol,it[1]);

            }
        }
        if(minr==INT_MAX || mincol==INT_MAX)return 0;
        return minr*mincol;
    }
};