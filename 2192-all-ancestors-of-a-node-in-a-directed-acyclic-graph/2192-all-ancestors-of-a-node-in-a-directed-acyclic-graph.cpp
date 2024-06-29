class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         // Step 1: Build graph adjacency list
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[to].push_back(from);
        }
        
        // Step 2: Function to perform DFS and collect ancestors
        unordered_map<int, vector<int>> ancestors;
        function<vector<int>(int)> dfs = [&](int node) {
            if (ancestors.count(node))
                return ancestors[node];
            unordered_set<int> result;
            for (int parent : graph[node]) {
                result.insert(parent);
                auto parent_ancestors = dfs(parent);
                result.insert(parent_ancestors.begin(), parent_ancestors.end());
            }
            vector<int> sorted_ancestors(result.begin(), result.end());
            sort(sorted_ancestors.begin(), sorted_ancestors.end());
            ancestors[node] = sorted_ancestors;
            return ancestors[node];
        };
        
        // Step 3: Collect ancestors for each node
        vector<vector<int>> answer(n);
        for (int node = 0; node < n; ++node) {
            answer[node] = dfs(node);
        }
        
        return answer;
    }
};