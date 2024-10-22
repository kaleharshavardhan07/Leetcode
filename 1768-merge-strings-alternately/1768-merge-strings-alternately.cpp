class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int mini = min(word1.length(), word2.length());
        int maxi = max(word1.length(), word2.length());
        for (int i = 0; i < mini; i++) {
            s = s + word1[i] + word2[i];
        }
        if (word1.length() > mini) {
            s += word1.substr(mini);
        } else if (word2.length() > mini) {
            s += word2.substr(mini);
        }
        return s;
    }
};