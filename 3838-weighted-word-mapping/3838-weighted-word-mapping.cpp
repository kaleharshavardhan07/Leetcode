class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ret;
        for( string s: words){
            int m=0;
            for( char c: s){
                m=m+ weights[c-'a'];
                
            }
            m=m%26;
            int ff=26-m-1;
           ret.push_back('a' + ff);
        }
            return ret;

        
    }
};