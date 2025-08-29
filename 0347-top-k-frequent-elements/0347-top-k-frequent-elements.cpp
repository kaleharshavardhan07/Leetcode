class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number.
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Move the map's contents to a vector of pairs for sorting.
        vector<pair<int, int>> freqVector;
        for (auto &p : freqMap) {
            freqVector.push_back(p);
        }

        // Step 3: Sort the vector in descending order based on frequency (the second element of the pair).
        // The lambda function defines our custom sorting rule.
        sort(freqVector.begin(), freqVector.end(),
             [](pair<int,int> &a, pair<int,int> &b) {
                 return a.second > b.second; // Sort by frequency (highest first)
             });

        // Step 4: Extract the top k elements from the sorted vector.
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVector[i].first); // The first element of the pair is the number
        }

        return result;
    }
};