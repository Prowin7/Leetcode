class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionRank(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);
        if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        } else if (rank[par_v] < rank[par_u]) {
            parent[par_v] = par_u;
        } else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ds.unionRank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i) cnt++;
        }
        return cnt;
    }
};