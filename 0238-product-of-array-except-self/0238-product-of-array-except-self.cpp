class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product=1;
        long long pr;
        int count=0;
        for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    count++;
                }
                else{
                product=product*nums[i];}
        }
        vector<int>ret;
        if(count>=1){
            
            pr=product;
            product=0;


        }
        for(int i=0;i<nums.size();i++){
                if(count==1 && nums[i]==0){
                    ret.push_back(pr);

                }
                else if (count>1){
                     ret.push_back(0);
                }
                else {
                         ret.push_back(product/nums[i]);
                }
        }
        return ret;
    }
};