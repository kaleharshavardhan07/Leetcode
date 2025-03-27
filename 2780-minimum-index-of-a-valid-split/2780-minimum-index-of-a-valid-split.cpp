class Solution {
public:
    vector<vector<int>> solve(vector<int>& arr,vector<int>&reti) {
        unordered_map<int, int> freq; // Frequency map
        set<int> maxElements;         // Set to track max frequency elements
        int maxFreq = 0;              // Track max frequency
        vector<vector<int>> result;   // 2D array to store answers

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;

            if (freq[arr[i]] > maxFreq) {
                maxFreq = freq[arr[i]];
                maxElements.clear();
                maxElements.insert(arr[i]);
            } else if (freq[arr[i]] == maxFreq) {
                maxElements.insert(arr[i]);
            }
         reti.push_back(maxFreq);
            result.push_back(
                vector<int>(maxElements.begin(), maxElements.end()));
        }

        return result;
    }
    vector<vector<int>> solve2(vector<int>& arr ,vector<int>&reti) {
        unordered_map<int, int> freq; // Frequency map
        set<int> maxElements;         // Set to track max frequency elements
        int maxFreq = 0;              // Track max frequency
        vector<vector<int>> result;   // 2D array to store answers

        for (int i = arr.size() - 1; i >= 0; i--) {
            freq[arr[i]]++;

            if (freq[arr[i]] > maxFreq) {
                maxFreq = freq[arr[i]];
                maxElements.clear();
                maxElements.insert(arr[i]);
            } else if (freq[arr[i]] == maxFreq) {
                maxElements.insert(arr[i]);
            }

            reti.push_back(maxFreq);

            result.push_back(
                vector<int>(maxElements.begin(), maxElements.end()));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int minimumIndex(vector<int>& nums) {

        vector<int>reti1; vector<int>reti2;

        vector<vector<int>> ret = solve(nums,reti1);
        vector<vector<int>> ret1 = solve2(nums,reti2);

        for (int i = 0; i < nums.size() - 1; i++) {

            if (ret[i][0] == ret1[i + 1][0] && ret[i].size()==1 && ret1[i+1].size()==1 ) {

                int a;
               

                if( reti1[i]>=(i+1)/2 && reti2[i]>=(nums.size()-i)/2){
                return i;
                break;}
            }
        }

        return -1;
    }
};