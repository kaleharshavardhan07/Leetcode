// class Fancy {
// public:
//     const long long mod = 1000000007;
//     vector<long long> ret;
//     vector<vector<long long>> reti; // size , (mul 1 , add 0 ), int num
//     Fancy() {}

//     void append(int val) { ret.push_back(val); }

//     void addAll(int inc) {
//         int size = ret.size();
//         reti.push_back({size, 0, inc});
//     }

//     void multAll(int m) {
//         int size = ret.size();
//         reti.push_back({size, 1, m});
//     }
//     int findStart(int idx) {
//         int l = 0, r = reti.size() - 1;
//         int ans = reti.size();

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (reti[mid][0] > idx) {
//                 ans = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return ans;
//     }

//     int getIndex(int idx) {
//         if (idx >= ret.size())
//             return -1;

//         long long num = ret[idx];

//         int start = findStart(idx);

//         for (int i = start; i < reti.size(); i++) {
//             if (reti[i][1] == 0) {
//                 num = (num + reti[i][2]) % mod;
//             } else {
//                 num = (1LL * num * reti[i][2]) % mod;
//             }
//         }

//         return num % mod;
//     }
// };

// /**
//  * Your Fancy object will be instantiated and called as such:
//  * Fancy* obj = new Fancy();
//  * obj->append(val);
//  * obj->addAll(inc);
//  * obj->multAll(m);
//  * int param_4 = obj->getIndex(idx);
//  */  
class Fancy {
    const long long MOD = 1e9 + 7;
    
    // Each element stores its value and the (mul, add) state at append time
    vector<long long> vals;
    vector<pair<long long,long long>> snap; // (mul, add) when appended
    
    long long curMul = 1, curAdd = 0;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

public:
    Fancy() {}

    void append(int val) {
        vals.push_back(val);
        snap.push_back({curMul, curAdd});
    }

    void addAll(int inc) {
        curAdd = (curAdd + inc) % MOD;
    }

    void multAll(int m) {
        curMul = curMul * m % MOD;
        curAdd = curAdd * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)vals.size()) return -1;

        auto [snapMul, snapAdd] = snap[idx];
        
        // Current state applied to element v gives: v * curMul/snapMul + (curAdd - snapAdd)
        // Use modular inverse to divide by snapMul
        long long invSnapMul = power(snapMul, MOD - 2, MOD);
        
        long long result = vals[idx] % MOD;
        result = result * curMul % MOD * invSnapMul % MOD;
        result = (result + curAdd - snapAdd % MOD * curMul % MOD * invSnapMul % MOD + MOD * 2) % MOD;
        
        return result;
    }
};