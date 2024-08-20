class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
       
        for(auto it :ops){
            if(it[0]>0 && it[1]>0){
              
                m=min(m,it[0]);
                n=min(n,it[1]);

            }
        }
       
        return m*n;
    }
};