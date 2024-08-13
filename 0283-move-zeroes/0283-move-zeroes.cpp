class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         for(int j=i;j<nums.size()-1;j++){
        //              swap(nums[j],nums[j+1]);
        //         }
        //     }
        // }
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[last], nums[i]);
                last++;
            }
        }
    }
};