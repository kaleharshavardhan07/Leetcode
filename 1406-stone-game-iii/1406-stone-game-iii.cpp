// class Solution {
// public:
//     void solve(int a, int b, vector<int>& v, int f, int curr,
//                map<string, int>& mp) {
//         if (curr >= v.size()) {

//             if (a > b) {

//                 mp["a"]++;
//                 return;
//             }
//             if (b > a) {
//                 mp["b"]++;
//                 return;
//             }

//             return;
//         }
//         if (f == 0) {
//             int temp = 0;
//             for (int i = 0; i < 3 && curr + i < v.size(); i++) {
//                 temp=temp+v[curr+i];
//                 solve(a + temp, b, v, 1, curr + 1 + i,mp);
//             }
//         } else {
//             int temp = 0;
//             for (int i = 0; i < 3 && curr + i < v.size(); i++) {
//                  temp=temp+v[curr+i];
//                 solve(a, b +temp, v, 0, curr + 1 + i,mp);
//             }
//         }
//     }
//     string stoneGameIII(vector<int>& stoneValue) {
//         int ali = 0;
//         int bob = 0;
//         int flag = 0;
//         map<string,int>mp;

//         solve(ali, bob, stoneValue, flag, 0,mp);
//         if (mp["a"] > mp["b"])
//             return "Alice";
//         if (mp["a"] == mp["b"])
//             return "Tie";
//         return "Bob";
//     }
// };


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};