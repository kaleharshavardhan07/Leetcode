class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string concatenated = "";
        
        for (string word : words) {
            concatenated += word;
            
            if (concatenated.length() > s.length()) {
                return false;
            }

            if (concatenated == s) {
                return true;
            }
        }

        return false;
    }
};
