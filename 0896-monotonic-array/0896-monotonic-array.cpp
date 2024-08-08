class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                 if(flag==0){
                    return false;
                 }
                 else if( flag==-1){
                    flag=1;
                 }
                 else continue;
            }
            else  if(nums[i]<nums[i-1]){
                 if(flag==1){
                    return false;
                 }
                 else if( flag==-1){
                    flag=0;
                 }
                 else continue;
            }
        }
        return true;
    }
};