class Solution {
public:
    void call(vector<int>& candidates, int target, vector<int>& current,
              vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
                    if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                call(candidates, target - candidates[i], current, result, i+1);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        call(candidates, target, current, result, 0);
        return result;
    }
};