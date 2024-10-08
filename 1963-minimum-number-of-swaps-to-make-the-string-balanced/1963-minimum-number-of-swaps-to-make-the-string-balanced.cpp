class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, swaps = 0;
        for (char ch : s) {
            if (ch == '[') {
                open++;
            } else {
                close++;
            }

          
            if (close > open) {
                swaps++;
                open++;  
                close--; 
            }
        }
        return swaps;
    }
};
