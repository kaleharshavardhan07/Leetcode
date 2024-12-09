class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ret;
        int c=0;
        ret.push_back(0);
        for( int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                c++;
                ret.push_back(c);
            }
            else{
                ret.push_back(c);
            }
        }
        vector<bool>reti;
        for( auto it:queries){
            if(ret[it[1]]==ret[it[0]]){
                reti.push_back(true);
            }
            else{ reti.push_back(false);}
        }
        return reti;
    }
};