class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(), skill.end());
        int r = skill.size() - 1;
        int l = 0;
        long long tot;
        int maxi = -1;
        int c = 0;

        while (l < r) {
            if (maxi == -1) {
                maxi = skill[l] + skill[r];
                tot = skill[l] * skill[r];

            } else {
                if (maxi == skill[l] + skill[r]) {
                    tot += skill[l] * skill[r];
                    c++;
                } else {
                    return -1;
                }
            }
            l++;
            r--;
        }
        return tot;
    }
};