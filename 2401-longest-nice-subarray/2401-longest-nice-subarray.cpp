class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxi=1;
        int l=0;
        int used=0;
        int r=0;
        while( r<n){
            if((used & nums[r])==0){
                    used|=nums[r];
                    maxi=max(maxi,r-l+1);
                    r++;
            }
            else{
                used^=nums[l];
                l++;
            }
        }

        return maxi;
       
        
    }
};