class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> adj[4];
        set<string>ret;
       vector<string>reti;
        if(s.length()<10)return reti; 
        for (int i = 0; i < s.length() - 9; i++) {
            char c = s[i];
            if (c == 'A')
                adj[0].push_back(i);
            else if (c == 'C')
                adj[1].push_back(i);
            else if (c == 'G')
                adj[2].push_back(i);
            else if (c == 'T')
                adj[3].push_back(i);
        }
        
        for (int i = 0; i < s.length() - 9; i++) {
            char c = s[i];
            string cur = s.substr(i, 10);
            int count = 0;
            if (c == 'A') {
                for (int n : adj[0]) {
                    string sub = s.substr(n, 10);
                    if (sub == cur) {
                        count++;
                    }
                }
                if (count > 1) {
                    ret.insert(cur);
                }
            }
            if (c == 'C') {
                for (int n : adj[1]) {
                    string sub = s.substr(n, 10);
                    if (sub == cur) {
                        count++;
                    }
                }
                if (count > 1) {
                    ret.insert(cur);
                }
            }
            if (c == 'G') {
                for (int n : adj[2]) {
                    string sub = s.substr(n, 10);
                    if (sub == cur) {
                        count++;
                    }
                }
                if (count > 1) {
                    ret.insert(cur);
                }
            }

            if (c == 'T') {
                for (int n : adj[3]) {
                    string sub = s.substr(n, 10);
                    if (sub == cur) {
                        count++;
                    }
                }
                if (count > 1) {
                    ret.insert(cur);
                }
            }
        }
        vector<string> myVector(ret.begin(), ret.end());
        return myVector;
    }
};