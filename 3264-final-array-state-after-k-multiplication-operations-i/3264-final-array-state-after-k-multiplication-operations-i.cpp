class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for( int i=0;i<k;i++){
            int min=INT_MAX;
            int tok=-1;
            for( int j=0;j<nums.size();j++){
                if( nums[j]<min){
                    tok=j;
                    min=nums[j];
                }
            }
            nums[tok]*=multiplier;

        }
        return nums;
    }
};