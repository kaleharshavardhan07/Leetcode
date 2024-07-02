class Solution {
public:
    bool isValid(string s) {
        vector<char> ret;
        for (char c : s) {
            if (ret.size() == 0) {
                if (c == '}' || c == ']' || c == ')') {
                    return false;
                } else {
                    ret.push_back(c);
                }
            } else {
                if (c == '}' || c == ']' || c == ')') {
                    char k = ret.back();
                    if (k == '(' && c == ')' || k == '[' && c == ']' ||
                        k == '{' && c == '}') {
                        ret.pop_back();
                    } else {
                        return false;
                    }
                } else {
                    ret.push_back(c);
                }
            }
        }
        if (ret.size() == 0) {
            return true;
        }
        return false;
    }
};
