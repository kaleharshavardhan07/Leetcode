class Solution {
public:
    long long flowerGame(int n, int m) {
         long long ot = (n + 1) / 2;
        long long et = n / 2;
        long long od = (m + 1) / 2;
        long long ed = m / 2;
        
        return ot * ed + od * et;

    }
};