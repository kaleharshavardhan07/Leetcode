#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
    bool static sortbysec(const pair<int, int>& a, const pair<int, int>& b) {

        if (a.second == b.second) {
            return (a.first > b.first);
        }
        return (a.second < b.second);
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mapi;
        for (int i : nums) {
            mapi[i]++;
        }
        vector<pair<int, int>> vec(mapi.begin(), mapi.end());
        sort(vec.begin(), vec.end(), sortbysec);
        vector<int> ret;
        for (auto it : vec) {
            for (int i = 0; i < it.second; i++)
                ret.push_back(it.first);
        }
        return ret;
    }
};