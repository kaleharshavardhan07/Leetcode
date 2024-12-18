class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        if(dividend==divisor){
            return 1;
        }
        if(dividend==0){
            return 0;
        }
        if(divisor==1){
            return dividend;
        }
        if (dividend > 0 && divisor > 0) {
            while (dividend - divisor >= 0) {
                dividend -= divisor;
                if(count==INT_MAX)return INT_MAX;
                count++;
            }
        } else if (dividend > 0 && divisor < 0) {
            while (dividend + divisor >= 0) {
                dividend += divisor;
                if(count==INT_MIN)return INT_MIN;
                count--;
            }
        } else if (dividend < 0 && divisor < 0) {
            while (dividend - divisor <= 0) {
                dividend -= divisor;
                if(count==INT_MAX)return INT_MAX;
                count++;
            }
        } else if (dividend < 0 && divisor > 0) {
            while (dividend + divisor <= 0) {
                dividend += divisor;
                if(count==INT_MIN)return INT_MIN;
                count--;
            }
        }
        return count;
    }
};