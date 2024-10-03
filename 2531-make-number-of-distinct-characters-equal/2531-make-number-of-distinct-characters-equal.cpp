class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> count1(26, 0), count2(26, 0);
        
        // Count the frequency of each character in both words
        for (char c : word1) count1[c - 'a']++;
        for (char c : word2) count2[c - 'a']++;
        
        // Try swapping each possible pair of characters
        for (int i = 0; i < 26; i++) {
            if (count1[i] == 0) continue;
            for (int j = 0; j < 26; j++) {
                if (count2[j] == 0) continue;
                
                // Simulate the swap
                count1[i]--; count1[j]++;
                count2[j]--; count2[i]++;
                
                // Count distinct characters after swap
                int distinct1 = 0, distinct2 = 0;
                for (int k = 0; k < 26; k++) {
                    if (count1[k] > 0) distinct1++;
                    if (count2[k] > 0) distinct2++;
                }
                
                // Check if the number of distinct characters is equal
                if (distinct1 == distinct2) return true;
                
                // Undo the swap
                count1[i]++; count1[j]--;
                count2[j]++; count2[i]--;
            }
        }
        
        return false;
    }
};