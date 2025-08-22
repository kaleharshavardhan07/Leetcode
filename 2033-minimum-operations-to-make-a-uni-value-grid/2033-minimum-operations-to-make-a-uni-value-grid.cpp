class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ret;
        int c = 0;
        for (int i = 0; i < grid.size(); i++) {
            for( int j=0;j< grid[0].size();j++)
            ret.push_back(grid[i][j]);
        }

        sort(ret.begin(), ret.end());

        int med = ret[(ret.size() ) / 2];
        int n = ret.size();
        for (int i = 0; i < n; i++) {
            int temp = abs(ret[i] - med);
            if (temp% x != 0) return -1;
            c += temp / x;
        }

        return c;
    }
};