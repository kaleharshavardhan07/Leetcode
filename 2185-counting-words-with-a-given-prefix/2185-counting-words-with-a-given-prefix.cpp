class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for( string w:words){
            if(w.length()>=pref.length()){
                if(w.substr(0,pref.length())==pref)c++;
            }
        }
        return c;
    }
};