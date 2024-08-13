#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> st;
        stringstream ss(s);
        char delimiter = ' ';
        string it;
        while (getline(ss, it, delimiter)) {
            st.push_back(it);
        }
        if (pattern.length() != st.size())
            return false;
        unordered_map<char, string> mapi;
          unordered_map<string, char> mapi1;
        for (int i = 0; i < st.size(); i++) {
            if (mapi.find(pattern[i]) != mapi.end()) {
                if (mapi[pattern[i]] != st[i])
                    return false;

            } else {
                mapi[pattern[i]] = st[i];
            }
             if (mapi1.find(st[i]) != mapi1.end()) {
                if (mapi1[st[i]] != pattern[i])
                    return false;

            } else {
                mapi1[st[i]] = pattern[i];
            }
        }
        return true;
    }
};