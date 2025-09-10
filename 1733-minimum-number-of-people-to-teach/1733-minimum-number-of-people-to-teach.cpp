class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& langs, vector<vector<int>>& fr) {
        int m = langs.size();
        vector<unordered_set<int>> know(m + 1);

        for (int i = 0; i < m; i++) {
            for (int x : langs[i]) know[i + 1].insert(x);
        }

        unordered_set<int> bad;
        for (auto &p : fr) {
            int a = p[0], b = p[1];
            bool ok = false;
            for (int x : know[a]) {
                if (know[b].count(x)) { ok = true; break; }
            }
            if (!ok) { bad.insert(a); bad.insert(b); }
        }

        if (bad.empty()) return 0;

        int ans = INT_MAX;
        for (int l = 1; l <= n; l++) {
            int cnt = 0;
            for (int u : bad) {
                if (!know[u].count(l)) cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
