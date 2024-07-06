#include <vector>
#include <algorithm>
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0;
        int cur=0;
        int jump=0;
        int n=nums.size();
        if(n<2)return 0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, nums[i]+i);
            if(i==cur){
                jump++;
                cur=maxi;
            }
            if(cur>=n-1){
                break;
            }

        }
        return jump;
    }
};