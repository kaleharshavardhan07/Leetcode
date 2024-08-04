class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ret;
        const int MOD = 1000000007;
        for(int i=0;i<n;i++){
           int  sum=0;
            for(int j=i; j<n;j++){
                sum+=nums[j] ;
                sum=sum%MOD;
                ret.push_back(sum);
            }

        }
        sort(ret.begin(),ret.end());
        int sumo=0;
        for(int i=left-1 ;i<right;i++){
            sumo+=ret[i];
            sumo=sumo%MOD;
        }
        return sumo;
    }
};