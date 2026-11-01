class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini =INT_MAX;
        int tot=0;
        for( int i: nums)
        mini=min(mini, i);
        for( int i:nums){tot=tot+(i-mini);}
        return tot;
        
    }
};