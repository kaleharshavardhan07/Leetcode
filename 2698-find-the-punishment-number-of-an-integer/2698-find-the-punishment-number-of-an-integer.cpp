class Solution {
public:
    bool solve(string sq, int sum, int curr, int index) {
        if (index == sq.size()) {
            return curr == sum;
        }

        int num = 0;
        for (int i = index; i < sq.size(); i++) {
            num = num * 10 + (sq[i] - '0');
            if (solve(sq, sum, curr + num, i + 1)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (solve(to_string(i * i), i, 0, 0)) {
                sum = sum + (i * i);
            }
        }
        return sum;
    }
};