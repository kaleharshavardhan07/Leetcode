class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        // Pick the first non-9 digit to replace with 9 for max
        char toReplaceMax = '\0';
        for (char ch : s) {
            if (ch != '9') {
                toReplaceMax = ch;
                break;
            }
        }

        // Pick the first digit to replace with 0 for min
        char toReplaceMin = s[0];

        string maxStr = s;
        string minStr = s;

        if (toReplaceMax != '\0') {
            for (char &ch : maxStr) {
                if (ch == toReplaceMax) ch = '9';
            }
        }

        for (char &ch : minStr) {
            if (ch == toReplaceMin) ch = '0';
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};
