class Solution {
public:
    int fact(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * fact(n - 1);
    }
     string getPermutation(int n, int k) {
        vector<char> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back('0' + i); 
        }
        
        string result;
        k--;
        while (n > 0) {
            int factorial = fact(n - 1);
            int index = k / factorial;
            result.push_back(nums[index]);
            nums.erase(nums.begin() + index); // remove used number
            k = k % factorial;
            n--;
        }
        
        return result;
    }
    // string getPermutation(int n, int k) {
    //     vector<char> out;
    //     for (int i = 1; i <= n; i++) {
    //         out.push_back(char(i));
    //     }
    //     int i = 0;
    //     string s;
    //     int sum = 0;
    //     while (out.size() != 0) {
    //         sum = sum + fact(out.size() - 1);
    //         if (sum == k) {
    //             s.push_back(out[i]);
    //             out.erase(out.begin() + i);
    //             out.shrink_to_fit();
    //             i--;
    //             for (int j = out.size() - 1; j >= 0; j--) {
    //                 s.push_back(out[j]);
    //             }
    //             return s;

    //         } else if (sum > k) {
    //             sum = sum - fact(out.size() - 1);
    //             s.push_back(out[i]);
    //             out.erase(out.begin() + i);
    //             out.shrink_to_fit();
    //             i--;
    //         }
    //     }
    //     return s;
    // }
};