class Solution {
public:
    int addDigits(int num) {
        while (num >=10) {
            int temp = num;
            int k=0;

            while (temp > 0) {
                k = k + temp % 10;
                temp = temp / 10;
            }
            num = k;
        }
        return num;
    }
};