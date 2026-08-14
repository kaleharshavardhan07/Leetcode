class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=1;
        for (int i = 0; i < s.length(); i++) {
            map<char, int> mp;
            mp[s[i]]++;
            
            for (int j = i + 1; j < s.length(); j++) {
                mp[s[j]]++;
                if (mp[s[j]] <= 2) {
                    maxi = max(maxi, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxi;
    }
};