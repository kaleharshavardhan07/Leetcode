class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>ret=nums;
        while(ret.size()>1){
            vector<int>r(ret.size()-1);
            for(int i=0;i<ret.size()-1;i++){
                int t=ret[i]+ret[i+1];
                r[i]=t%10;
            }
           ret=r;
        }
        if(ret.size()==0){
            return -1;
        }
        return ret[0];
    }
};