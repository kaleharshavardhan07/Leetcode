class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        int mini=INT_MAX;
        for( int n: nums){
           mp[n]++;
           mini=min(mini,n);
        }
        if( k>mini){
            return -1;
        }
        if(mp.find(k)==mp.end()){
            return mp.size();
        }
        return mp.size()-1;

    }
};