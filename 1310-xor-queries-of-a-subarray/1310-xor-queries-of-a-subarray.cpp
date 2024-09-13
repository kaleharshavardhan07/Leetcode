class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];

        
        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        vector<int> result;

        
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];

        
            if (l == 0) {
                result.push_back(prefixXor[r]);
            } else {
                result.push_back(prefixXor[r] ^ prefixXor[l - 1]);
            }
        }

        return result;
    }
};