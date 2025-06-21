class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> freqs;
        for (auto& [ch, count] : freq) {
            freqs.push_back(count);
        }

        sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int res = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int deletions = 0;
            int minAllowed = freqs[i];
            int maxAllowed = minAllowed + k;

            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];
            }

            for (int j = i; j < n; ++j) {
                if (freqs[j] > maxAllowed) {
                    deletions += freqs[j] - maxAllowed;
                }
            }

            res = min(res, deletions);
        }

        return res;
    }
};
