class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, -1);  // Store the last index of each character
        vector<int> result;

        // Step 1: Find the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Partition the string
        int maxLast = 0, partitionStart = 0;
        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, lastIndex[s[i] - 'a']);
            
            if (i == maxLast) {  // End of partition
                result.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }

        return result;
    }
};
