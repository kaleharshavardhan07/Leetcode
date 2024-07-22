#include <algorithm>
#include <iostream>
#include <string.h>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::vector<std::string> cols;
        std::vector<std::string> rows;

        int rowsize = grid.size();
        int colsize = grid[0].size();

        for (int i = 0; i < rowsize; i++) {
            string s;
            for (int j = 0; j < colsize; j++) {
                // int k = grid[i][j];

                s += std::to_string(grid[i][j]) + ",";
            }
            rows.push_back(s);
        }
        for (int i = 0; i < colsize; i++) {
            string s;
            for (int j = 0; j < rowsize; j++) {
                // int k = grid[j][i];

                s += std::to_string(grid[j][i]) + ",";
            }
            cols.push_back(s);
        }
        int count = 0;
        for (const auto& str : cols) {
            for (const auto& row : rows) {
                if (str == row) {
                    count++;
                }
            }
        }
        return count;
    }
};