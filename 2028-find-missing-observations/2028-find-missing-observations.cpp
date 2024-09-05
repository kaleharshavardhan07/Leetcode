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
        if (  sumn<n || sumn / n > 6) {
            return {};
        }
        

        vector<int> ret(n, 1);
        sumn -= n;
        for (int i = 0; i < n; i++) {
            int a = min(5, sumn);
            ret[i] += a; sumn -= a;
        }

        // while (sumn > 0 && maxi>0) {
        //     if (sumn - maxi > 0) {
        //         sumn -= maxi;
        //         reti.push_back(maxi);
        //     }  if (sumn - maxi == 0) {
        //         reti.push_back(maxi);
        //         break;
        //     } else {
        //         maxi--;
        //     }
        // }
        return ret;
    }
};