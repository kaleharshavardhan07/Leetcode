class Solution {
public:
     double ro(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        double half = ro(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
    double myPow(double x, int n) {
        double ans;
        if (x == 0 || n == 1)
            return x;
        else if (x > 0 && n > 0) {

            ans = ro(x, n);

        } else if (x > 0 && n < 0) {
            x = 1 / x;

            n = n * (-1);
            ans = ro(x, n);
        } else if (x < 0 && n > 0) {
            if (n % 2 == 0) {
                ans = ro(x, n);

            } else {
                ans = (-1) * ro(x, n);
            }
        } else {
            x = 1 / x;

            n = n * (-1);
            if (n % 2 == 0) {
                ans = ro(x, n);

            } else {
                ans = (-1) * ro(x, n);
            }
        }
        return ans;
    }
};