#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // Min-heap: {cost, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        // dist[node][stops] = min cost to reach node with stops
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            // If destination reached within allowed stops
            if (u == dst) return cost;

            // If we can still take more flights
            if (stops <= k) {
                for (auto &[v, w] : adj[u]) {
                    int newCost = cost + w;
                    if (newCost < dist[v][stops+1]) {
                        dist[v][stops+1] = newCost;
                        pq.push({newCost, v, stops+1});
                    }
                }
            }
        }

        return -1; // No valid path
    }
};
