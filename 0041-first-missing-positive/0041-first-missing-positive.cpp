class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sum=0;
        int i=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int n:nums){
            if(n>0){
                i++;
                mini=min(mini,n);
                maxi=max(maxi,n);
            sum+=n;}
            
        }
       
       if(mini>1){
        return 1;
       }
        int temp=((i)*(i+1)/2 );
       if(sum==temp)return i+1;
       if(sum>temp)return sum-temp;

       return temp-sum;




    }
};