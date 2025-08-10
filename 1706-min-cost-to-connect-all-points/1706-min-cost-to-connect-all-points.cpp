class Solution {
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

        // Step 2: Prim's MST using dist[][] directly
        vector<int> minDist(n, INT_MAX);
        vector<int> vis(n, 0);
        minDist[0] = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            // Find unvisited node with smallest minDist
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            vis[u] = 1;
            sum += minDist[u];

            // Update distances for remaining nodes
            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    minDist[v] = min(minDist[v], dist[u][v]);
                }
            }
        }

        return sum;
    }
};
