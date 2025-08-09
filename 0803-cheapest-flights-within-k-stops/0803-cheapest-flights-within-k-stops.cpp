class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Run k+1 relaxations
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist; // Copy to avoid using updated values in same round
            for (auto &it : flights) {
                int u = it[0], v = it[1], w = it[2];
                if (dist[u] != 1e9 && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
