#include <vector>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        int lastOneIndex = -k-1; 
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - lastOneIndex <= k) {
                    return false;
                }
                lastOneIndex = i;
            }
        }
        
        return true;
    }
};
