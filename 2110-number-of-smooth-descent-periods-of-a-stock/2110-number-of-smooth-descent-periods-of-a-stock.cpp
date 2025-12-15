class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        long long c = 0;
        int n= prices.size();
        long long curr = 0;
        for (int i = 1; i < n; i++) {

            if (prices[i] + 1 == prices[i - 1]) {
                curr++;
            } else {

                long long m = (curr * (curr + 1)) / 2;
                 curr = 0;

                c = c + m;
            }
        }
  long long m = (curr * (curr + 1)) / 2;
  c = c + m;
        c=c+ prices.size();

        return c;

    }
};