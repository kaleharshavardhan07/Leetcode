class Solution {
public:
    vector<int> solve(string str) {
        vector<int> ret;
        stringstream ss(str);
        string token;
        while (getline(ss, token, '.')) {
                int k = token.empty() ? 0 : stoi(token);
            ret.push_back(k);
            // int co = 0;
            // for (char c : token) {
            //     if (c == '0') {
            //         co++;
            //     } else {
            //         break;
            //     }
            // }
            // string temp = token.substr(co);
            // int k = stoi(temp); 
            // ret.push_back(k);
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> r1 = solve(version1);
        vector<int> r2 = solve(version2);

        int l = r1.size();
        int r = r2.size();
        for (int i = 0; i < max(l, r); i++) {
            int l1 = 0;
            int l2 = 0;
            if (i < r) {
                l2 = r2[i];
            }
            if (i < l) {
                l1 = r1[i];
            }

            if (l1 > l2)
                return 1;
            if (l2 > l1)
                return -1;
        }
        return 0;
    }
};