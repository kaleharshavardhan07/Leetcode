class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for( int n: nums){
            string t=to_string(n);
            if(t.size()%2==0)c++;
        }
        return c;
    }
};