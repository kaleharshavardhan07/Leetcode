class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {

        int n = words.size();
        vector<string> ret;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            temp.push_back(words[i]);
            int curr = groups[i];
            for (int j = i + 1; j < n; j++) {
                if (groups[j] != curr) {
                    temp.push_back(words[j]);
                    curr = groups[j];
                }
            }
            if (temp.size() > ret.size()) {
                ret = temp;
            }
        }
        return ret;
    }
};