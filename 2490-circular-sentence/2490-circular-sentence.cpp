class Solution {
public:
    bool isCircularSentence(string sentence) {
        string s = "";
        vector<string> ret;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                ret.push_back(s);
                s = "";

            } else {
                s = s + sentence[i];
            }
        }
        ret.push_back(s);
        if (ret.size() == 1){
            if( ret[0].front()!=ret[0].back())return false;
        }
          
        for (int i = 0; i < ret.size() - 1; i++) {
            string k = ret[i];
            string m = ret[i + 1];
            if (k.back() != m.front())
                return false;
        }
        if( ret[0].front()!=ret[ret.size()-1].back())return false;

        return true;
    }
};