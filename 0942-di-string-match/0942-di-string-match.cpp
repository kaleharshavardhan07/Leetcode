class Solution {
public:
    vector<int> diStringMatch(string s) {
        int j = s.length();
        vector<int> ret;
        int i = 0;

        for (int l = 0; l <=s.length(); l++) {
            if (l < s.length() && s[l] == 'I') {
                ret.push_back(i);
                i++;

            } else  {
                ret.push_back(j);
                j--;
            }
        }
       
        return ret;
    }
};