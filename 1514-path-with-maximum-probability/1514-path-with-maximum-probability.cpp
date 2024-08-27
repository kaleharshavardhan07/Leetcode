class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[a].emplace_back(b, prob);
            graph[b].emplace_back(a, prob);
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto [prob, node] = pq.top();

            pq.pop();

            if (node == end_node)
                return prob;
            for (auto [next, p] : graph[node]) {
                if (maxProb[next] < prob * p) {
                    maxProb[next] = prob * p;
                    pq.push({maxProb[next], next});
                }
            }
        }
        return 0.0;
    }
};