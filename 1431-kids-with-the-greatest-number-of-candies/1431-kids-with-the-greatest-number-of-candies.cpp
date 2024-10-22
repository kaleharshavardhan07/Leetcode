class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        for( int n: candies){
            maxi=max(n,maxi);
        }
        vector<bool>ret;
        for( int n:candies){
            if( n+extraCandies>=maxi){
                ret.push_back(true);
            }
            else ret.push_back(false);
        }
        return ret;
    }
};