class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;
        int i=0;
       while( i< s.length()) {
            if (i + k < s.length()) {
                string m = s.substr(i,k);
                ret.push_back(m);
            }
            else {
                string m=s.substr(i);
                while( m.length()<k){
                    m=m+fill;
                }
                ret.push_back(m);
            }
            i=i+k;

        }

        return ret;
    }
};