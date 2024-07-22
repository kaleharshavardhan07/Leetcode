#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> goodIndices(std::vector<int>& nums, int k) {
        std::vector<int> ret;
        int n = nums.size();

        if (k <= 0 || n < 2 * k + 1) {
            return ret;
        }

        std::vector<int> nonIncreasing(n, 0);
        std::vector<int> nonDecreasing(n, 0);

        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                nonIncreasing[i] = nonIncreasing[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                nonDecreasing[i] = nonDecreasing[i + 1] + 1;
            }
        }

        for (int i = k; i < n - k; ++i) {
            if (nonIncreasing[i - 1] >= k - 1 && nonDecreasing[i + 1] >= k - 1) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
