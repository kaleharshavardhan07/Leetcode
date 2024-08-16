class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>> mini;
        vector<vector<int>> maxi;

       for (int i = 0; i < arrays.size(); i++) {
        mini.push_back({arrays[i][0], i});
        maxi.push_back({arrays[i][arrays[i].size() - 1], i});
    }
        sort(mini.begin(), mini.end());
        sort(maxi.begin(), maxi.end());
        if (mini[0][1] != maxi[maxi.size() - 1][1]) {
            return maxi[maxi.size() - 1][0] - mini[0][0];
        }
        else {
            return max(maxi[maxi.size() - 1][0] - mini[1][0],
                       maxi[maxi.size() - 2][0] - mini[0][0]);
        }
    }
};