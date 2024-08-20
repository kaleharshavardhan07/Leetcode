class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        vector<int> nums(10, 0); // To track numbers 1 to 9
        int sum = grid[r][c] + grid[r][c + 1] +
                  grid[r][c + 2]; // Sum of the first row

        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] !=
                    sum ||
                grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] !=
                    sum) // Column
                return false;

            for (int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || nums[val]++)
                    return false;
            }
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum ||
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                vector<int> vis(10, 0);
                int flag = 0;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (grid[k][l]> 9) {
                            flag = 1;
                            break;
                        } else if (vis[grid[k][l]] == 0) {
                            vis[grid[k][l]] = 1;
                        } else {
                            flag = 1;
                        }
                    }
                    if (flag != 0)
                        break;
                }

                if (flag == 0 && isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};