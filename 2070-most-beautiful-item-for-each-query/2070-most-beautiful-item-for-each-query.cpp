class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Build a map where mapi[key] is the maximum beauty for each price key
        map<int, int> mapi;
        for (auto& it : items) {
            // For each price, keep the maximum beauty value
            mapi[it[0]] = max(mapi[it[0]], it[1]);
        }

        // Step 2: Build a sorted vector from the map to make it easier to accumulate maximum beauty
        vector<vector<int>> ret;
        for (auto& it : mapi) {
            ret.push_back({it.first, it.second});
        }

        // Sort by the price (already sorted because map keys are sorted, but we’ll keep it for generality)
        sort(ret.begin(), ret.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 3: Accumulate the maximum beauty up to each price
        int maxi = INT_MIN;
        for (auto& it : ret) {
            // Update the current beauty to be the maximum so far
            it[1] = maxi = max(maxi, it[1]);
        }

        // Step 4: Answer each query by finding the maximum beauty available for each price in queries
        vector<int> result;
        for (int q : queries) {
            // Binary search for the largest price <= q
            auto it = upper_bound(ret.begin(), ret.end(), vector<int>{q, INT_MAX}, 
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[0] < b[0];
                                  });
            if (it == ret.begin()) {
                // If no price is <= q, beauty is 0
                result.push_back(0);
            } else {
                // Move one step back to get the highest valid price <= q
                --it;
                result.push_back((*it)[1]);
            }
        }

        return result;
    }
};
