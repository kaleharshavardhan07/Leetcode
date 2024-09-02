#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unsigned long long totsum = 0;
        unsigned long long temp = 0;

       
        for (int i = 0; i < n; ++i) {
            totsum += nums[i];
            temp += i * nums[i];
        }

        unsigned long long maxi = temp;

        for (int i = 1; i < n; ++i) {
            temp = temp + totsum - n * nums[n - i];
            maxi = max(maxi, temp);
        }

        return static_cast<int>(maxi);
    }
};
