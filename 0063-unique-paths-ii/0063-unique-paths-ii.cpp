class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[row-1][col-1]==1){
            return 0;
        }

        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = 1;
        for (int i = 1; i < col; ++i) {
            dp[0][i] = (obstacleGrid[0][i] == 0) ? dp[0][i - 1] : 0;
        }

        for (int i = 1; i < row; ++i) {
            dp[i][0] = (obstacleGrid[i][0] == 0) ? dp[i - 1][0] : 0;
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[row-1][col-1];
    }
};

// class Solution {
// public:
//     void mini(vector<vector<int>>& obstacleGrid, int& count, int r, int d) {
//         int row = obstacleGrid.size()-1;
//         int col = obstacleGrid[0].size()-1;
//         if (obstacleGrid[d][r] != 1) {
//             if (r < col && d < row) {
//                 mini(obstacleGrid, count, r + 1, d);
//                 mini(obstacleGrid, count, r, d + 1);
//             }
//             else if(d<row){
//                    mini(obstacleGrid, count, r, d + 1);
//             }
//             else if(r<col){
//                 mini(obstacleGrid, count, r + 1, d);
//             }
//             else{
//                 count++;
//                 return;
//             }
//         }
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int count=0;
//         mini(obstacleGrid,count,0,0);
//         return count;
//     }
// };