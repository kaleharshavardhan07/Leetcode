class Solution {
public:
    int rearrangeCharacters(string s, string target) {
         std::unordered_map<char, int> freq_s;
    std::unordered_map<char, int> freq_target;

    for (char c : s) {
        freq_s[c]++;
    }

    for (char c : target) {
        freq_target[c]++;
    }

    int max_copies = INT_MAX;
    for (const auto& entry : freq_target) {
        char c = entry.first;
        int count_in_target = entry.second;
        if (freq_s.find(c) != freq_s.end()) {
            max_copies = std::min(max_copies, freq_s[c] / count_in_target);
        } else {

            return 0;
        }
    }

    return max_copies;
    }
};