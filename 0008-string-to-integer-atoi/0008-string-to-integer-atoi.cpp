#include <string>
class Solution {
public:
    int myAtoi(string s) {
        int k = s.length();
        string digit;
        string symbol;
        int i = 0;
        while (i < k && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // if('a'<=s[i]<='z' || 'A'<=s[i]<='B'){
        //     return 0;
        // }
        long long ret = 0;
        while (i < k && isdigit(s[i])) {
            ret = ret * 10 + (s[i] - '0');
            if (ret * sign > INT_MAX) {
                return INT_MAX;
            }
            if (ret * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return static_cast<int>(ret * sign);
    }
};