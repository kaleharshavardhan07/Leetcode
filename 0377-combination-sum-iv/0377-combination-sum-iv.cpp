#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> ret(target + 1, 0); 
        ret[0] = 1; 

     
        for (int i = 1; i <= target; i++) {
          
            for (int n : nums) {
                if (i - n >= 0) { 
                    ret[i] += ret[i - n];
                }
            }
        }

        return static_cast<int>(ret[target]); 
    }
};
