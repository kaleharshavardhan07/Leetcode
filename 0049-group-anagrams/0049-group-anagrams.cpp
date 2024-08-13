class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // int c = 0;
        map<string, vector<string>> mapi;
        vector<vector<string>> ret;
        for (string s : strs) {
            string r = s;
            sort(r.begin(), r.end());
            if (mapi.find(r) != mapi.end()) {
                mapi[r].push_back(s);

            } else {
                mapi[r] = {s};
            }
        }
        for(auto it :mapi){
            ret.push_back(it.second);
        }
        return ret;
    }
};