class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            ret.push_back(s);
        }
        vector<int> reti;

        sort(ret.begin(), ret.end());
        for (string k : ret) {
            reti.push_back(stoi(k));
        }
        return reti;
    }
};