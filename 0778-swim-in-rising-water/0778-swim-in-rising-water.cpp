// class Solution {
// public:
//     void solve(int i, int j, vector<vector<int>>& grid, int t, int& mini,
//                vector<vector<int>> vis) {
//         int n = grid.size();
//         int curr = grid[i][j];
//         vis[i][j] = 1;
//         if (i == n - 1 && j == n - 1) {
//             mini = min(mini, t);
//             return;
//         }

//         if (i < n - 1) {
//             int x = grid[i + 1][j];
//             int y = x - curr;
//             solve(i + 1, j, grid, t + max(0, y), mini, vis);
//         }
//         if (i > 0) {
//             int x = grid[i - 1][j];
//             int y = x - curr;
//             solve(i - 1, j, grid, t + max(0, y), mini, vis);
//         }
//         if (j > 0) {
//             int x = grid[i][j - 1];
//             int y = x - curr;
//             solve(i, j - 1, grid, t + max(0, y), mini, vis);
//         }

//         if (j < n - 1) {
//             int x = grid[i][j + 1];
//             int y = x - curr;
//             solve(i, j + 1, grid, t + max(0, y), mini, vis);
//         }

//         vis[i][j] = 0;
//         return;
//     }
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int mini = 0;
//         vector < vector<int> >vis(n, vector<int>(n, 0));

//         solve(0, 0, grid,0, mini, vis);

//         return mini;
//     }
// };


#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
     
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int time = t[0], i = t[1], j = t[2];
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            
            if (i == n - 1 && j == n - 1)
                return time;
            
            for (auto& d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]) {
                    pq.push({max(time, grid[x][y]), x, y});
                }
            }
        }
        return -1;
    }
};
