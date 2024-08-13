class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int tot = 0;
        int curr = 0;
        int st = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr += (gas[i] - cost[i]);
            tot += (gas[i] - cost[i]);
            if (curr < 0) {
                curr = 0;
                st = i + 1;
            }
        }
        if(tot>=0)return st;
        return -1;
    }
};

// class Solution {
// public:
//     int solve(int st, vector<int>& gas, vector<int>& cost) {

//         int sum = gas[st] - cost[st];
//         for (int i = 0; i < gas.size(); i++) {
//             st++;
//             st = st % gas.size();
//             sum += (gas[st] - cost[st]);
//             if (sum < 0) {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int k = gas.size();
//         vector<int> ret;
//         for (int i = 0; i < k; i++) {
//             if (gas[i] >= cost[i]) {
//                 ret.push_back(i);
//             }
//         }

//         for (int i : ret) {

//             int j = solve(i, gas, cost);
//             if (j == 1) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };