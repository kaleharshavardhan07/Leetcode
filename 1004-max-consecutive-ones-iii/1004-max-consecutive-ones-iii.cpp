class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = nums.size();
        int count = large(nums, k, 0, 0);
        return count;
    }
    int large(vector<int>& nums, int k, int p, int countmax) {
        
        int s = nums.size();
        int count = 0;
        int counto = 0;
        for (int i = p; i < s; i++) {
               int temp;
            if (nums[i] == 1) {
                count++;
                if (count >= countmax) {
                        countmax = count;}
            } else if (nums[i] == 0) {
                if(counto==0){
                    temp=i+1;

                }
                if (counto < k) {
                    count++;
                    counto++;
                    
                    if (count >= countmax) {
                        countmax = count;}

                } else {
                    if (count >= countmax) {
                        countmax = count;
                    } 
                    counto=0;
   
                    return large(nums, k, temp, countmax);
                }
            }
        }return countmax;
    }
    
};