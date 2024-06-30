class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int sign = 1;
        if (s[0] == '-') {
            sign = -1;
            s.erase(s.begin() + 0);
        }

        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
        long long a = stoll(s);
        a = a * sign;
        if (a > INT32_MAX || a < INT32_MIN) {
            return 0;
        }
        return a;
    }
};