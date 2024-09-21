class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
          
            ret.push_back( to_string(i));
        }
        vector<int> reti;

        sort(ret.begin(), ret.end());
        for (string k : ret) {
            reti.push_back(stoi(k));
        }
        return reti;
    }
};