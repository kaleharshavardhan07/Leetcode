class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), cmp); int count = 1;
        int min = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (min < pairs[i][0]) {
                count++;
                min = pairs[i][1];
            }
        }
        return count;
    }
};