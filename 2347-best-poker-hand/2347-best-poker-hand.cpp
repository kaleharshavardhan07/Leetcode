class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> ra;
        map<char, int> su;
        for (int i : ranks)
            ra[i]++;
        for (char c : suits) {
            su[c]++;
        }
        if (su.size() == 1) {
            return "Flush";
        } else if (ra.size() == 5)
            return "High Card";
        else {
            int two = 0;

            for (auto it : ra) {
                if (it.second == 2) {
                    two = 1;
                }
                if (it.second >= 3) {

                    return "Three of a Kind";
                }
            }
            if (two == 1) {
                return "Pair";
            }
        }
        return "";
    }
};