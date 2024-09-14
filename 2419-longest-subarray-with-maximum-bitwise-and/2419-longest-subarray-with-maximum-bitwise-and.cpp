class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(int n: nums){
            maxi=max(maxi,n);
        }
        int maxl=0;
        int curl=0;

        for( int n:nums){
            if(n==maxi){
                curl++;

            }
            else {
                maxl=max(curl,maxl);
                curl=0;
            }
        }
        return max(curl,maxl);
        

    }
};