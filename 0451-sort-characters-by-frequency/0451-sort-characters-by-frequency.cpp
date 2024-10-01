class Solution {
public:
   static bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;  
        return a.second > b.second;   
    }
    string frequencySort(string s) {
        unordered_map<char, int> mapi;
        for (char c : s) {
            mapi[c]++;
        }

        vector<pair<char, int>> freqVector;
        for (auto it : mapi) {
            freqVector.push_back(it);
        }

        sort(freqVector.begin(), freqVector.end(), cmp);

        string result;
        for (auto it : freqVector) {
            result += string(it.second, it.first);
        }

        return result;
    }
};