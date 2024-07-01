class Solution {
public:
    int minOperations(int n) {
        if(n==0 ||n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        int mid;
        int count = 0;
        int lastval = (n - 1) * 2 + 1;
        if (n % 2 == 0) {
            int i = (n / 2) * 2 + 1;
            int j = (n / 2 - 1) * 2 + 1;
            mid =( i + j) / 2;

            for (int k = 0; k < n / 2;k++) {
                int temp = (2 * k) + 1;
                count += (mid - temp);
            }
        } else {
            mid = (n / 2) * 2 + 1;
            for (int k = 0; k < n / 2;k++) {
                int temp = (2 * k) + 1;
                count += (mid - temp);
            }
        }
        return count;
    }
};