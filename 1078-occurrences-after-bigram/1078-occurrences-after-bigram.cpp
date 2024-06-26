class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        std::vector<std::string> words;
        std::stringstream ss(text);
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }
        vector<string>ret;
        for(int i=0;i<words.size()-2;i++){
            if(words[i]==first && words[i+1]==second)
            ret.push_back(words[i+2]);

        }
        return ret;
    }
};