class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort( nums.begin(),nums.end());
        int c=0;
       
        for( int i=0;i< nums.size();i++){
            if( nums[i]<0)continue;
            else{
                if( i==0)c+=nums[i];
                if( i!=0 &&  nums[i]!=nums[i-1]){
                    c+=nums[i];
                }

            }
        }
        if( c==0){
            if( nums[nums.size()-1]==0)return c;
            else {
                return nums[nums.size()-1];
            }
        }
        
        return c;
    }
};