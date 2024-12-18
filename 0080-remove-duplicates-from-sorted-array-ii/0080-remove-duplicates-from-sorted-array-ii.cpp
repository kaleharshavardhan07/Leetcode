class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ret;
        int c = 0;
        int k=0;
        ret.push_back(nums[0]);
        k++;
        if (nums.size() > 1) {
            ret.push_back(nums[1]);
            k++;
            for (int i = 2; i < nums.size(); i++) {
                 if( nums[i]==ret[k-1] && ret[k-2]==nums[i]){
                    continue;
                 }
                 else{
                    ret.push_back(nums[i]);
                    k++;
                 }
            }
        }
        for( int i=0;i<k;i++){
            nums[i]=ret[i];
        }
        return k;
    }
};