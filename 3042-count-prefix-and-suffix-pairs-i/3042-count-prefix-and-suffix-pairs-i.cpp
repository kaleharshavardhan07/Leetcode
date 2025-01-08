class Solution {
public:
    bool solve( string s1, string s2){
        if( s1.length()<=s2.length()){
            string temp=s2.substr(0,s1.length());
            string t1=s2.substr(s2.length()-s1.length());
            if( temp==t1 && t1 ==s1){
                return true;
            }
            
        }
        // else{
        //     string temp=s1.substr(0,s2.length());
        //     string t1=s1.substr(s1.length()-s2.length());
        //     if( temp==t1 && t1 ==s2){
        //         return true;
        //     }

        // }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for( int i=0;i<words.size();i++){
            for( int j=i+1;j<words.size();j++){
                if( solve( words[i],words[j])){
                    c++;
                }
            }
        }
        return c;
    }
};