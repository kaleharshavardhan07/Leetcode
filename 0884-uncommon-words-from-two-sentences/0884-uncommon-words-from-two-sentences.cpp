#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> countMap1;
        unordered_map<string, int> countMap2;
        string temp;
        
        // Count words in s1
        for (char c : s1) {
            if (c == ' ' && !temp.empty()) {
                countMap1[temp]++;
                temp.clear();
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            countMap1[temp]++;
        }
        temp.clear();
        
        // Count words in s2
        for (char c : s2) {
            if (c == ' ' && !temp.empty()) {
                countMap2[temp]++;
                temp.clear();
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            countMap2[temp]++;
        }
        temp.clear();
        
        vector<string> result;
        
        // Add uncommon words from s1
        for (const auto& [word, count] : countMap1) {
            if (count == 1 && countMap2.find(word) == countMap2.end()) {
                result.push_back(word);
            }
        }
        
        // Add uncommon words from s2
        for (const auto& [word, count] : countMap2) {
            if (count == 1 && countMap1.find(word) == countMap1.end()) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
