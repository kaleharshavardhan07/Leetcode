class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string s = "1";
        for (int i = 1; i < n; i++) {
            string sl;
            int count = 1;
            char cur = s[0];
            for (int j = 1; j < s.length(); j++) {
                if (s[j] == cur) {
                    count++;
                } else {
                    sl += to_string(count) + cur;
                    cur = s[j];
                    count = 1;
                }
            }
            sl += to_string(count) + cur; 
            s = sl;
        }
        return s;
    }
};
