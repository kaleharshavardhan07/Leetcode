class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        for( int n: nums){
            maxi=max(maxi,n);
        }
        int sum=0;
        for( int i: nums){
            sum=sum+(abs(maxi-i));
        }
        return sum;
    }
};