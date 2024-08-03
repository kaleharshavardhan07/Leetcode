class Solution {
public:
    bool dfs(vector<int> ary[],vector<bool>& visited, int s, int f) {
        if (s == f)
            return true;
        if (visited[s])
            return false;
        visited[s] = true;
        for (int i = 0; i < ary[s].size(); i++) {

            if (dfs(ary,visited, ary[s][i], f))
                return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<int> ary[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {
            ary[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> ret;
        for (int i = 0; i < queries.size(); i++) {
            vector<bool> visited(numCourses, false);
            ret.push_back(dfs(ary,visited, queries[i][0], queries[i][1]));
        }
        return ret;
    }
};