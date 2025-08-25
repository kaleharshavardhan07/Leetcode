class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int i = 0;
        int j = 0;
        int n = mat.size();
        int m = mat[0].size();
        int tot = m + n - 1;
        vector<int> ret;
        for (int k=0;k< tot;k++) {
            if (k % 2 == 0) {
while (i >= 0 && i < n && j >= 0 && j < m){
                    ret.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                 if (j >= m) { 
                    i += 2; j = m - 1; 
                } else { 
                    i = 0; 
                }

            } else {
              while (i >= 0 && i < n && j >= 0 && j < m)
 {
                    ret.push_back(mat[i][j]);
                    i++;
                    j--;
                }

               if (i >= n) { 
                    j += 2; i = n - 1; 
                } else { 
                    j = 0; 
                }
                
            }
        }
        return ret;
    }
};