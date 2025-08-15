#include <cmath>
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;  
        double val = log10(n) / log10(4); 
        return fabs(val - round(val)) < 1e-10;
    }
};
