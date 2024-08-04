class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int ,int>mapi;
        for(int s: nums){
            mapi[s]++;

        }
        int count=0;
        for(auto it : mapi){
            int n= it.second;
            count=count+(n*(n-1)/2);
        }
        return count;
    }
};