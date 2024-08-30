// problem link : https://leetcode.com/problems/path-with-maximum-probability/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            // creating a undirected graph
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        // max-heap 
        priority_queue<pair<double, int>> pq;

        // initialise max-probabilities of each with 0.0
        vector<double> maxProb(n, 0.0);

        pq.push({1.0, start_node});
        maxProb[start_node] = 1.0;

        while (!pq.empty()) {
            double currentProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) {
                return currentProb;
            }

            for (auto neighbor : graph[node]) {
                int node = neighbor.first;
                double edgeProbability = neighbor.second;

                double newProb = currentProb * edgeProbability;

                if (newProb > maxProb[node]) {
                    maxProb[node] = newProb;
                    pq.push({newProb, node});
                }
            }
        }

        return 0.0;
    }
};