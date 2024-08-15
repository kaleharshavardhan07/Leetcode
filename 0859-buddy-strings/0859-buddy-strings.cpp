class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s == goal) {
           
            vector<int> charCount(26, 0);
            for (char c : s) {
                if (++charCount[c - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        }
        
        int a[2], b[2];
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (count >= 2) {
                    return false;
                }
                a[count] = s[i];
                b[count] = goal[i];
                count++;
            }
        }
        
        return (count == 2 && a[0] == b[1] && a[1] == b[0]);
    }
};
