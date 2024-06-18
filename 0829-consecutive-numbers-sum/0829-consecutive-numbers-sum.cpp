// class Solution {
// public:
//     int consecutiveNumbersSum(int n) {
//         int curr = 1;
//         int first = curr;
//         int count = 1;
//         int sum = 0;
//          if (n == 1) 
//             return 1;
//         if(n==2){
//             return 1;
//         }
//         while (curr <= (n / 2) + 1) {

//             sum += curr;
//             while (sum > n) {
//                 sum = sum - first;
//                 first++;
//             }

//             if (sum == n) {
//                 count++;
//             }
//             curr++;
//         }

//         return count;
//     }
// };

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int k = 1; k * (k - 1) < 2 * n; ++k) {
            if ((n - k * (k - 1) / 2) % k == 0)
                count++;
        }
        return count;
    }
};

