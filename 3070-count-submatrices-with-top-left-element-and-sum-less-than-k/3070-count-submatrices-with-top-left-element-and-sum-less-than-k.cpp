class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        
        int c=0;
        dp[0][0]=grid[0][0];
        if( dp[0][0]<=k)c++;
        else{return 0;}

        for( int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
            if(dp[i][0]<=k){
                c++;

            }
        }
        for( int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
            if(dp[0][j]<=k)c++;
        }
        for( int i=1;i<m;i++ ){
            for( int j=1;j<n;j++){
                dp[i][j] = grid[i][j] 
                         + dp[i-1][j] 
                         + dp[i][j-1] 
                         - dp[i-1][j-1];
                 if( dp[i][j]<=k)c++;
            }
           
        }
        return c;
    }
};