class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum=0;
        int c=0;
        for( int i=0;i<arr.size();i++){
            sum+=arr[i];
            int k=i;
            int temp = k*(k+1)/2;

            if(temp==sum)c++;

        }
        return c;
    }
};