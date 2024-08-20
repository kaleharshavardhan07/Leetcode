#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> distinct_nums;

        for (int num : nums) {
            distinct_nums.insert(num);
            if (distinct_nums.size() > 3) {
                distinct_nums.erase(distinct_nums.begin());
            }
        }

        if (distinct_nums.size() < 3) {
            return *distinct_nums.rbegin();  // Return the maximum element
        } else {
            return *distinct_nums.begin();  // Return the third maximum element
        }
    }
};
