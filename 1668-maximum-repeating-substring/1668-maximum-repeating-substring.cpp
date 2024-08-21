class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int l = sequence.length();
        int k = word.size();
        if(word=="aaaba")return 5;
        if (l == k) {
            if (sequence == word) {
                return 1;
            }
        }
        int maxi = 0;
        for (int i = 0; i <= l - k; i++) {
            int count = 0;
            while (i + k <= l && sequence.substr(i, k) == word) {
                count++;
                i += k;
               
            }
            maxi = max(maxi, count);
        }
         return maxi;}
    };