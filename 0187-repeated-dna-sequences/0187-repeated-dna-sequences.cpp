// 


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Initialize sets to track seen sequences and repeated sequences
        set<string> seen;
        set<string> repeated;
        
        // Resultant vector to return repeated sequences
        vector<string> result;

        // Edge case: If the input string is less than 10 characters, no 10-letter sequences can be formed
        if (s.length() < 10) return result;

        // Slide a window of size 10 over the string
        for (int i = 0; i <= s.length() - 10; i++) {
            // Extract the current 10-letter sequence
            string cur = s.substr(i, 10);

            // If the sequence has been seen before, add it to the repeated set
            if (seen.find(cur) != seen.end()) {
                repeated.insert(cur);
            } else {
                // Otherwise, add it to the seen set
                seen.insert(cur);
            }
        }

        // Convert the set of repeated sequences to a vector
        result.assign(repeated.begin(), repeated.end());

        return result;
    }
};
