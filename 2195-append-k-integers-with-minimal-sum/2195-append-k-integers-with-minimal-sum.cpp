class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int num = 1;
        int count = 0;
        while (count < k && i < nums.size()) {
            if (nums[i] == num) {
                i++;
                num++;

            } else if (nums[i] > num) {
                sum += num;
                num++;
                count++;
            }
            else{
                i++;
            }
        }

       if (count < k) {
           long long n=k-count;
           long long sume= (2*num+(n-1))*n/2;
            sum = sum + sume; 
           
        }
        return sum;
    }
};