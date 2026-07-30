class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        int i = 0;
        int sum = 0;
        //    int j=1;
        while (i < freq.size()) {
            int temp = (i / 8) + 1;
            sum = sum + (temp * freq[i]);
            i++;
        }
        return sum;
    
    }
};