class Solution {
public:
    int minChanges(string s) {
        
        int n= s.length();
        int i=0;
        int c=0;
        while( i< n){
            if( s[i]!=s[i+1]){
                c++;
            }
            i=i+2;
        }
        return c;
    }
};