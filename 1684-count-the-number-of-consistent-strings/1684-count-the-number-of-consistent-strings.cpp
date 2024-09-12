class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>fr(26,0);
        for( char c: allowed){
            fr[c-'a']=1;

        }
        int co=0;
        for( string s: words){
            int flag =0;
            for( char c: s){
                if(fr[c-'a']==0){
                    flag=1;
                    break;
                }
            }
            if( flag==0)co++;
        }
        return co;
    }
};