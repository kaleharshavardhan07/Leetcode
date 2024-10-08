class Solution {
public:
    int minSwaps(string s) {
        int op=0;
        int cl=0;
        int c=0;
        // int swap=0;
        for( int i=0;i<s.length();i++){
            if( s[i]=='['){
                op++;
            }
            else {
                cl++;
            }

            if( cl>op){
                // swap(s[i],s[s.length()-1-i]);
                c++;
                op++;
                cl--;

                
            }

        }
        return c;
    }
};