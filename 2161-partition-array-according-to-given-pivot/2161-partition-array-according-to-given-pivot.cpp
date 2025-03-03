class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> ret;
        vector<int>r;
        vector<int> reti;
        for (int n : nums) {
            if (n < pivot) {
                ret.push_back(n);

            } else if (n == pivot) {
                r.push_back(n);
            } else {
                reti.push_back(n);
            }
        }
        ret.insert(ret.end(), r.begin(), r.end());
        ret.insert(ret.end(), reti.begin(), reti.end());

        return ret;
    }
};