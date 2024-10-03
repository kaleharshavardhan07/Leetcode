class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ret;
        for( int n:nums){
           string s=to_string(n);
            for( char c: s){
                ret.push_back(int(c-'0'));
            }
        }
        return ret;
    }
};