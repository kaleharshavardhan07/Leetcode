class Solution {
public:
    int maximum69Number (int num) {
        string s= to_string(num);
        for( int i=0;i< s.length();i++){
            if( s[i]=='9')continue;
            else{
                s[i]='9';
                break;
            }
        }

        int k=stoi(s);
        return k;
        
    }
};