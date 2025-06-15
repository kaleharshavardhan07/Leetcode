class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string k = s;
        char l, m;
        if (s[0] != '1') {
            l = s[0];
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == l) {
                    s[i] = '1';
                }
            }
        } else {
            int flag = 0;
            for (char c : s) {
                if (c != '1' && c != '0') {
                    l = c;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] == l) {
                        s[i] = '0';
                    }
                }
            }
        }

        if (k[0] != '9') {
            l = k[0];
            for (int i = 0; i < k.length(); i++) {
                if (k[i] == l) {
                    k[i] = '9';
                }
            }
        } else {
            for (char c : k) {
                if (c != '9') {
                    l = c;
                    break;
                }
            }
            for (int i = 0; i < k.length(); i++) {
                if (k[i] == l) {
                    k[i] = '9';
                }
            }
        }

        int min = stoi(s);
        int max = stoi(k);
        return max - min;
    }
};