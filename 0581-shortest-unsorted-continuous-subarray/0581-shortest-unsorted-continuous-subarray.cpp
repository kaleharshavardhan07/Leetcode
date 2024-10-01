class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>ret;
        for( int n: nums){
            ret.push_back(n);
        }
        sort( ret.begin(),ret.end());
       int left=0;
       int right=nums.size()-1;
       while( left<nums.size()){
        if( ret[left]!=nums[left]){
            break;
        }
        left++;
       }
       if( left==right+1)return 0;
       while( right>=0){
        if( ret[right]!=nums[right]){
            break;
        }
        right--;
       }
       
       return right-left+1;
    }
};