#include <string>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length();
        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int leftScore = std::count(s.begin(), s.begin() + i, '0');
            int rightScore = std::count(s.begin() + i, s.end(), '1');

            maxScore = std::max(maxScore, leftScore + rightScore);
        }

        return maxScore;
    }
};
