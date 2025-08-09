class Solution {
    const int MOD = 100000;
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;  // Already at target
        
        vector<int> dist(MOD, 1e9);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : arr) {
                int num = (node * it) % MOD;

                if (dist[node] + 1 < dist[num]) {
                    dist[num] = dist[node] + 1;
                    if (num == end) return dist[num];
                    q.push(num);
                }
            }
        }
        return -1;
    }
};
