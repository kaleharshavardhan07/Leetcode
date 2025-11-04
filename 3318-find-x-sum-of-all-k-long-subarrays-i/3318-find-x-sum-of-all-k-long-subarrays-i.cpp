class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0)
                    freq.erase(nums[i - k]);
            }

            if (i >= k - 1) {
              
                vector<pair<int, int>> elements(freq.begin(), freq.end());
                sort(elements.begin(), elements.end(), [](auto &a, auto &b) {
                    if (a.second == b.second)
                        return a.first > b.first;
                    return a.second > b.second;
                });

                int sum = 0;
                for (int j = 0; j < min(x, (int)elements.size()); j++)
                    sum += elements[j].first;

                ans.push_back(sum);
            }
        }

        return ans;
    }
};
