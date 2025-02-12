class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        vector<vector<int>> ret(100, vector<int>(2, -1)); // Extend to handle larger sums

        for (int num : nums) {
            int t = digitSum(num);

            if (ret[t][0] == -1) {
                ret[t][0] = num;  
            } else if (ret[t][1] == -1) {
                ret[t][1] = num;  
                if (ret[t][0] < ret[t][1]) 
                    swap(ret[t][0], ret[t][1]);
            } else {
                if (num > ret[t][0]) {
                    ret[t][1] = ret[t][0];
                    ret[t][0] = num;
                } else if (num > ret[t][1]) {
                    ret[t][1] = num;
                }
            }
        }

        for (int i = 0; i < 100; i++) {
            if (ret[i][0] != -1 && ret[i][1] != -1) {
                maxi = max(maxi, ret[i][0] + ret[i][1]);
            }
        }
        return maxi;
    }
};
