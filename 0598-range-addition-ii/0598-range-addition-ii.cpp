class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int minr=m;
        int mincol=n;
        for(auto it :ops){
            if(it[0]>0 && it[1]>0){
              
                minr=min(minr,it[0]);
                mincol=min(mincol,it[1]);

            }
        }
       
        return minr*mincol;
    }
};