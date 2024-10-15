class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>e,o;
        for( int n:nums){
            if( n%2==0)e.push_back(n);
            else o.push_back(n);

        }
        for( int i=0;i<nums.size();i++){
            if( i%2==0){nums[i]=e.back();
            e.pop_back();}
            else {nums[i]=o.back();
            o.pop_back();}
        }
        return nums;
    }
};