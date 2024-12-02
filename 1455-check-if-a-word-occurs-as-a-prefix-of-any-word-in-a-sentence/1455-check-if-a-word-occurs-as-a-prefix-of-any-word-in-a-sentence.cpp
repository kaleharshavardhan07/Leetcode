class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        std::vector<std::string> words;
        std::istringstream stream(sentence);
        std::string word;
        int k = searchWord.length();
        // Extract words from the string
        while (stream >> word) {
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            if (s.length() > k) {
                if (s.substr(0, k) == searchWord)
                    return i+1;
            }
        }
        return -1;
    }
};