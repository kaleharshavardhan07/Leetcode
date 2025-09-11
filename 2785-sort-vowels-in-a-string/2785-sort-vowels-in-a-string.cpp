class Solution {
public:
    string sortVowels(string s) {
        vector<char>ret;
        for (char c : s) {
            if (tolower(c) == 'a' || tolower(c) == 'e' ||
                tolower(c) == 'i' || tolower(c) == 'o' ||
                tolower(c) == 'u') {
                ret.push_back(c);
            }
        }
        sort(ret.begin(), ret.end(),greater<>());

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (tolower(c) == 'a' || tolower(c) == 'e' ||
                tolower(c) == 'i' || tolower(c) == 'o' ||
                tolower(c) == 'u') {
                char k = ret.back();
                ret.pop_back();

                s[i] = k;
            }
        }
        return s;
    }
};