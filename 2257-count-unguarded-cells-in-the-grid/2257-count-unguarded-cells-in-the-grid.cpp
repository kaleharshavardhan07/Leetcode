// class Solution {
// public:
//     int countUnguarded(int m, int n, vector<vector<int>>& guards,
//                        vector<vector<int>>& walls) {

//         vector<vector<int>> out(m, vector<int>(n, 0));

//         for (vector<int> a : walls) {
//             out[a[0]][a[1]] = -1;
//         }
//         int co = 0;
//         for (vector<int> a : guards) {

//             int y = a[0];
//             int x = a[1];
//             if (out[y][x] == 1)
//                 continue;
//             else {
//                 out[y][x] = 1;
//                 co++;
//                 for (int i = y + 1; i < m; i++) {
//                     if (out[i][x] ==0 ) {
//                         out[i][x] = 1;
//                         co++;

//                     } else
//                         break;
//                 }

//                 for (int i = y - 1; i >= 0; i--) {
//                     if (out[i][x] ==0) {
//                         out[i][x] = 1;
//                         co++;

//                     } else
//                         break;
//                 }
//                 for (int i = x + 1; i < n; i++) {
//                     if (out[y][i]==0) {
//                         out[y][i] = 1;
//                         co++;

//                     } else
//                         break;
//                 }
//                 for (int i = x - 1; i >= 0; i--) {
//                     if (out[y][i] ==0) {
//                         out[y][i] = 1;

//                     } else
//                         break;
//                 }
//             }
//         }
//         return (m * n) - co - walls.size();
//     }

// };

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0: empty, -1: wall, 1: guard, 2: illuminated
        
        // Mark walls and guards on the grid
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = -1; // Wall
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1; // Guard
        }
        
        // Function to illuminate cells in a specific direction
        auto illuminate = [&](int y, int x, int dy, int dx) {
            while (true) {
                y += dy;
                x += dx;
                if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == -1 || grid[y][x] == 1) {
                    break; // Stop if out of bounds, wall, or another guard
                }
                if (grid[y][x] == 0) {
                    grid[y][x] = 2; // Illuminate the cell
                }
            }
        };
        
        // Illuminate cells for each guard
        for (auto& guard : guards) {
            int y = guard[0], x = guard[1];
            illuminate(y, x, -1, 0); // Up
            illuminate(y, x, 1, 0);  // Down
            illuminate(y, x, 0, -1); // Left
            illuminate(y, x, 0, 1);  // Right
        }
        
        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++unguarded;
                }
            }
        }
        
        return unguarded;
    }
};
