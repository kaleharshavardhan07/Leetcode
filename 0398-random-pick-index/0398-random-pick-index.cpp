class Solution {
public:
    vector<int> n;
    int key;
    Solution(vector<int>& nums) {
        n = nums;
        key = nums.size();
    }

    int pick(int target) {
        vector<int> ret;
        for (int i = 0; i < key; i++) {
            if (n[i] == target) {
                ret.push_back(i);
            }
        }
        if( ret.empty())return -1;
        std::srand(std::time(0));
        int randomIndex = std::rand() % ret.size();
        return ret[randomIndex];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */