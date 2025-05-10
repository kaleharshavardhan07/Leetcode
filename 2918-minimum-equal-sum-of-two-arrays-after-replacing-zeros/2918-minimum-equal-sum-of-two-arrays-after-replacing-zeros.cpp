class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int c1 = 0, c2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int n : nums1) {
            if (n == 0)
                c1++;
            else
                sum1 += n;
        }

        for (int n : nums2) {
            if (n == 0)
                c2++;
            else
                sum2 += n;
        }

        if (c2 > 0 && c1 > 0) {
            return max(sum1 + c1, sum2 + c2);
            // if (sum1 == sum2) {
            //     return sum1 + max(c1, c2);
            // }
            // if (sum1 > sum2) {
                
            //     return sum1 + c1;
            // }
            // if (sum1 < sum2)
            //     return sum2 + c2;
        }
       else if (c2 == 0 && c1 > 0) {
            if (sum1 == sum2) {
                return -1;
            }
            if (sum1 > sum2) {
                return -1;
            }
            if (sum1 < sum2){
                if(sum1+c1>sum2)return -1;
                return sum2;
            }
                
        }
         else if (c2 > 0 && c1 == 0) {
            if (sum1 == sum2) {
                return -1;
            }
            if (sum1 > sum2) {
                if(sum2+c2>sum1)return -1;
                return sum1;
            }
            if (sum1 < sum2)
                return -1;
        }

        else {
            if( sum1==sum2)return sum1;
        }

        return -1;
    }
};
