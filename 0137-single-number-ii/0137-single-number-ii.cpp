class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mapi;
        for(int num :nums){
            mapi[num]++;

        }
       int ans;
        for( const auto &k:mapi){
            if(k.second==1){
                ans=k.first;
            }
        }
        return ans;
    }
};