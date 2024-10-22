class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=INT_MIN;
        double tot=0;

        int s= nums.size();
        if( s<k)return -1;
        for( int i=0;i<k;i++){
            tot=tot+nums[i];
        }
        avg=max(avg,tot/k);

        for( int i=k;i<s;i++){
               tot=tot+ nums[i]-nums[i-k];
                  avg=max(avg,tot/k);
        }
        return avg;
    }
};