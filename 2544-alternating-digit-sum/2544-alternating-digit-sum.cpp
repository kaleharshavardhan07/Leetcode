class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.length();i++ ){
            char c=s[i];
              if( i%2==0){
                sum+=int(c-'0');
              }
              else {
                sum-=int(c-'0');
              }
        }
        return sum;
    }
};