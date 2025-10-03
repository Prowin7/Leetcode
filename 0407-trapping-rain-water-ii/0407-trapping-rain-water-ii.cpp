class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        if (m <= 2 || n <= 2) return 0; 

        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;

        // Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({h[i][0], {i, 0}});
            pq.push({h[i][n-1], {i, n-1}});
            vis[i][0] = vis[i][n-1] = 1;
        }
        for (int j = 0; j < n; j++) {
            pq.push({h[0][j], {0, j}});
            pq.push({h[m-1][j], {m-1, j}});
            vis[0][j] = vis[m-1][j] = 1;
        }

        int water = 0;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int ht = cur.first;
            int x  = cur.second.first;
            int y  = cur.second.second;

            for (auto d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) continue;
                vis[nx][ny] = 1;

                if (h[nx][ny] < ht) {
                    water += ht - h[nx][ny];
                    pq.push({ht, {nx, ny}});
                } else {
                    pq.push({h[nx][ny], {nx, ny}});
                }
            }
        }
        return water;
    }
};
