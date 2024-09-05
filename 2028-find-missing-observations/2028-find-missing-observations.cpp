class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int m = rolls.size();
        int summ = 0;
        for (int nq : rolls) {
            summ += nq;
        }
        int tot = mean * (m + n);
        int sumn = tot - summ;
        if (  sumn < n || sumn  > 6*n) {
            return {};
        }
        

        vector<int> ret(n, 1);
        sumn -= n;
        for (int i = 0; i < n; i++) {
            int a = min(5, sumn);
            ret[i] += a; sumn -= a;
        }

      
        return ret;
    }
};