class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int k = temperatures.size();
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            int l = i + 1;
            while (l < k) {
                if (temperatures[l] > temperatures[i])
                    break;
                l++;
            }
            if (l == k) {
                ret.push_back( 0);
            } else {
                ret.push_back(l-i);
            }
        }
        return ret;
    }
};