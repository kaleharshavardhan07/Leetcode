class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        vector<int>arr(101,0);
        for( int n: nums){
            arr[n]++;
        }

        sort( arr.begin(),arr.end());
        int cont=arr[100];
        for( int i=99;i>=0;i--){

            if( arr[i]==arr[i+1]){
                cont+=arr[i];
            }
            else{
                break;
            }

        }
        return cont;


    }
};