class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ret;
        for(int i=0;i<n;i++){
           int  sum=0;
            for(int j=i; j<n;j++){
                sum+=nums[j];
                ret.push_back(sum);
            }

        }
        sort(ret.begin(),ret.end());
        int sumo=0;
        for(int i=left-1 ;i<right;i++){
            sumo+=ret[i];
        }
        return sumo;
    }
};