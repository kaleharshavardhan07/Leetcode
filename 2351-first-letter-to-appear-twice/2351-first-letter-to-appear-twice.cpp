class Solution {
public:
    char repeatedCharacter(string s) {
        int ary[26]={0};
        char k;
        for(char c:s){
            if(ary[c-'a']==1){
                k=c;
                break;
            }
            else{
                ary[c-'a']++;
            }
        }
        return k;
    }
};