class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ret;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 1;
        ret.push_back(intervals[0]);
        while (i < intervals.size()) {

            if (intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = max(intervals[i][1], ret.back()[1]);

            } else {
                ret.push_back(intervals[i]);
            }
            i++;
        }
        return ret;
    }
};
