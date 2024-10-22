class Solution {
public:
    static bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> count;
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i]]++;
        }
        vector<pair<int, int>> vec(count.begin(), count.end());

        sort(vec.begin(), vec.end(), sortBySecondValue);
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i].second == vec[i + 1].second) {
                return false;
            }
        }
        return true;
    }

    static bool sortBySecondValue(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};