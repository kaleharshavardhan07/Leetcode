class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int i=0;
        vector<int>ret;
        for( string s : words){
            for( char c: s){
                if( c==x){
                    ret.push_back(i);
                    break;
                }
            }
            i++;
        }

        return ret;
    }
};