class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        if( s.length()<k)return false;
        for( int i=0;i< s.length()-k+1;i++){
            string m= s.substr(i,k);
            st.insert(m);
        }
        if( pow(2,k) == st.size())return true;
        return false;
    }
};