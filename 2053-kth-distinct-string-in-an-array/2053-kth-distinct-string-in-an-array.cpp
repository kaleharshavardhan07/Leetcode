class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freqMap;
        
        for(const string& str : arr) {
            freqMap[str]++;
        }
        
        vector<string> distinctStrings;
        
        for(const string& str : arr) {
            if(freqMap[str] == 1) {
                distinctStrings.push_back(str);
            }
        }
        
        if(distinctStrings.size() < k) {
            return "";
        }
        
        return distinctStrings[k - 1];
    }
};
