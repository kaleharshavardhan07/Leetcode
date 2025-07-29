class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mp;
        int a, b;
        int sum = 0;
        int maxi = 0;
        for (auto it : grid) {
            for (int n : it) {
                mp[n]++;
                maxi = max(maxi, n);
                if (mp[n] > 1)
                    b = n; // fixed here
                else
                    sum += n;
            }
        }
        int l = maxi * (maxi + 1) / 2;
        if (l - sum > 0)
            return { b,l - sum};

        return { b,maxi+1};
    }
};
