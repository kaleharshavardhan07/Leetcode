class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char , int>mapi;
        for(char c: s){
            mapi[c]++;

        }
        for( int i=0;i<s.length();i++){
            char c=s[i];
            if( mapi[c]==1){

                return i;
            }
        }
        return -1;
    }
};