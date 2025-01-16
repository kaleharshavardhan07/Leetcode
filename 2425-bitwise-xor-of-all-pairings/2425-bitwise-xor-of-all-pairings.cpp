class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int n1=0;
        int n2=0;
        if( m%2!=0){
            for(int j: nums1){
                n1=n1^j;
            }
        }
        if(    n%2!=0){
            for( int j: nums2){
                n2=n2^j;
            }
        }

        return n2^n1;

    }
};