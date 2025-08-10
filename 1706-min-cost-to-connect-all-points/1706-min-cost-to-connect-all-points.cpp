class Solution {
    typedef pair<int,int> P; // {weight, node}
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Step 1: Precompute Manhattan distances
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            auto &a = points[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    auto &b = points[j];
                    dist[i][j] = abs(a[0] - b[0]) + abs(a[1] - b[1]);
                }
            }
        }

        vector<bool> vis(n, false);
        priority_queue<P, vector<P>, greater<P>> pq; 

        pq.push({0, 0}); // Start with node 0 and cost 0
        int totalWeight = 0;

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (vis[u]) continue; // Skip already visited nodes

            vis[u] = true;
            totalWeight += wt;

            // Instead of adj[u], use dist[u] to add neighbors
            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    pq.push({dist[u][v], v});
                }
            }
        }

        return totalWeight;
    }
};
