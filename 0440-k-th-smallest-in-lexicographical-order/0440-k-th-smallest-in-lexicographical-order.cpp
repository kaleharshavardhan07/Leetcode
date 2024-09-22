// class Solution {
// public:
//     vector<int> v;
//     void dfs(int num, int n, int& count, int k) {

//         for (int i = 0; i <= 9; i++) {
//             if (count >= k)
//                 return;
//             int x = num;
//             x = x * 10 + i;
//             if (x > n)
//                 return;
//             v.push_back(x);
//             count++;
//             dfs(x, n,count ,k);
//         }
//     }
//     int findKthNumber(int n, int k) {
//         int count = 0;

//         for (int i = 1; i <= 9; i++) {
//             if (count >= k)
//                 break;
//             if (i > n)
//                 break;
//             v.push_back(i);
//             count++;
//             dfs(i, n,count ,k);
//         }
//         return v[k-1];
//     }
// };

class Solution {
public:
    int countSteps(int prefix, int n) {
        long long curr = prefix;
        long long next = prefix + 1;
        int steps = 0;
        
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        
        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
