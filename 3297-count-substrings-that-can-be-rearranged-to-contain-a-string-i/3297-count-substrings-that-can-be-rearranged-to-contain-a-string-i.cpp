class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> need(26, 0), have(26, 0);

        // count frequency of word2
        for (char c : word2) need[c - 'a']++;

        int required = 0;
        for (int x : need) if (x > 0) required++;

        int formed = 0; // number of chars meeting requirement
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            char c = word1[r];
            have[c - 'a']++;

            if (need[c - 'a'] > 0 && have[c - 'a'] == need[c - 'a'])
                formed++;

            while (formed == required) {
                // All substrings from l..r, l..r+1, ... l..n-1 are valid
                ans += (n - r);

                char leftChar = word1[l];
                if (need[leftChar - 'a'] > 0 && have[leftChar - 'a'] == need[leftChar - 'a'])
                    formed--;

                have[leftChar - 'a']--;
                l++;
            }
        }
        return ans;
    }
};
