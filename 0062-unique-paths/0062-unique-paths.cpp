// class Solution {
// public:
//     int ret(int i, int j, int m, int n) {
//         int k, l;
//         if (i < m-1) {
//             k = ret(i + 1, j, m, n);
//         }
//         if (j < n-1) {
//             l = ret(i, j + 1, m, n);
//         }
//         if (i == m-1) {
//             return 1;
//         }
//         if (j == n-1) {
//             return 1;
//         }
//         return k + l;
//     }
//     int uniquePaths(int m, int n) {
//         int i = 0;
//         int j = 0;
//         int ans = ret(i, j, m, n);

//             return ans;
//     }
// };



class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));

   dp[0][0]=1;
  for(int i=1;i<m;i++){
	  dp[i][0]=1;
  }
   for(int i=1;i<n;i++){
	  dp[0][i]=1;
  }


   for(int i=1;i<m;i++){
	   for(int j=1;j<n;j++){
             int up=dp[i-1][j];
			 int left=dp[i][j-1];
			 dp[i][j]=left+up;


	   }
   }

   return dp[m-1][n-1];
    }
};
