class Solution {
public:
    void proc(vector < vector<int>>&mini) {
       int  n = 26;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mini[i][k] != INT_MAX && mini[k][j] != INT_MAX) {
                        mini[i][j] = min(mini[i][j], mini[i][k] + mini[k][j]);
                    }
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,vector<char>& changed, vector<int>& cost) {
        vector <vector<int>>mini(26,vector<int>(26, INT_MAX));
        for (int i = 0; i < original.size(); i++) {
            mini[original[i] - 'a'][changed[i] - 'a'] = cost[i];
        }
        proc(mini);
        long long count = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                long long k = mini[source[i] - 'a'][target[i] - 'a'];
                if (k != INT_MAX) {
                    count += k;
                } else {
                    return -1;
                }
            }
        }
        return count;
    }
};