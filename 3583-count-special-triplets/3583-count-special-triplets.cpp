// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         unordered_map<int, long long> prev;
//         unordered_map<int, long long> nxt;
//         for (int i : nums)
//             nxt[i]++;
//         long long count = 0;
//         nxt[nums[0]]--;
//         if (nxt[nums[0]] == 0)
//             nxt.erase(nums[0]);
//         prev[nums[0]]++;

//         for (int i = 1; i < nums.size() - 1; i++) {
//             int curr = nums[i];
//             nxt[curr]--;
//             if (nxt[curr] == 0)
//                 nxt.erase(curr);
//             long long d = curr * 2;
//             if (prev.find(d) != prev.end() && nxt.find(d) != nxt.end()) {
//                 count += 1LL * prev[d] * nxt[d]; 
//             }
//             prev[curr]++;
//         }
//         return (int)count;
//     }
// };

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

      
        unordered_map<int, long long> prev;
        unordered_map<int, long long> nxt;

      
        for (int x : nums) {
            nxt[x]++;
        }

        long long count = 0;
        int n = (int)nums.size();
        if (n < 3) return 0;

       
        nxt[nums[0]]--;
        if (nxt[nums[0]] == 0) nxt.erase(nums[0]);
        prev[nums[0]]++;

      
        for (int i = 1; i < n - 1; i++) {
            int curr = nums[i];

           
            nxt[curr]--;
            if (nxt[curr] == 0) nxt.erase(curr);

            long long d_ll = 1LL * curr * 2;        // compute in long long
            int d = (int)d_ll;                      // key type is int

            auto itL = prev.find(d);
            auto itR = nxt.find(d);
            if (itL != prev.end() && itR != nxt.end()) {
                long long ways = (itL->second % MOD) * (itR->second % MOD) % MOD;
                count = (count + ways) % MOD;
            }

            prev[curr]++;
        }

        return (int)(count % MOD);
    }
};
