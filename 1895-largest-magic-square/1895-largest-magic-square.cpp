class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int l = grid.size();
        int k = grid[0].size();

        vector<vector<int>> row(l, vector<int>(k, 0));
        vector<vector<int>> col(l, vector<int>(k, 0));
        vector<vector<int>> diag1(l, vector<int>(k, 0));
        vector<vector<int>> diag2(l, vector<int>(k, 0));

        for(int i=0;i<l;i++){
            for(int j=0;j<k;j++){
                row[i][j] = grid[i][j] + (j?row[i][j-1]:0);
            }
        }

        for(int j=0;j<k;j++){
            for(int i=0;i<l;i++){
                col[i][j] = grid[i][j] + (i?col[i-1][j]:0);
            }
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<k;j++){
                diag1[i][j] = grid[i][j] + ((i && j)?diag1[i-1][j-1]:0);
            }
        }

        for(int i=0;i<l;i++){
            for(int j=k-1;j>=0;j--){
                diag2[i][j] = grid[i][j] + ((i && j<k-1)?diag2[i-1][j+1]:0);
            }
        }

        int ans = 1;

        for(int i=0;i<l;i++){
            for(int j=0;j<k;j++){

                for(int s=2; i+s-1<l && j+s-1<k; s++){

                    int r2 = i+s-1, c2 = j+s-1;

                    int target = row[i][c2] - (j?row[i][j-1]:0);

                    bool ok = true;

                    for(int r=i;r<=r2 && ok;r++){
                        int sum = row[r][c2] - (j?row[r][j-1]:0);
                        if(sum != target) ok=false;
                    }

                    for(int c=j;c<=c2 && ok;c++){
                        int sum = col[r2][c] - (i?col[i-1][c]:0);
                        if(sum != target) ok=false;
                    }

                  
                    int d1 = diag1[r2][c2] - ((i&&j)?diag1[i-1][j-1]:0);

                    
                    int d2 = diag2[r2][j] - ((i&&c2<k-1)?diag2[i-1][c2+1]:0);

                    if(d1 != target || d2 != target) ok=false;

                    if(ok) ans = max(ans, s);
                }
            }
        }

        return ans;
    }
};
