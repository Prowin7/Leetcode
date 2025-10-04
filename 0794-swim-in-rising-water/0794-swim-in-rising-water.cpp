class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}}); // {t,{x,y}}

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> vis(r, vector<int>(c, 0));
        vis[0][0]=1;
        while (!pq.empty()) {
            int t = pq.top().first;
            int cx = pq.top().second.first;
            int cy = pq.top().second.second;

            if (cx == r - 1 && cy == c - 1)
                return t;
            pq.pop();

            for (auto d : dir) {
                int nx = cx + d.first;
                int ny = cy + d.second;
                if (nx < 0 || ny < 0 || nx >= r || ny >= c || vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                if (grid[nx][ny] <= t) {
                    pq.push({t, {nx, ny}});
                } else {
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        return -1;
    }
};