class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mapi;
        for (int a : nums) {
            mapi[a]++;
        }
        int k = 0;
        for (auto a : mapi) {
            if (a.second > (nums.size() / 2)) {
                k = a.first;
                break;
            }
        }

        return k;
    }
};