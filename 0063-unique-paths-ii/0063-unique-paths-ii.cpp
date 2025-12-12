class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<long long> dp(c, 0);

        if (grid[0][0] == 1) return 0;   // start blocked
        dp[0] = 1;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == 1) {  
                    dp[j] = 0;          // obstacle = no paths
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1]; // from left + from up(dp[j])
                }
            }
        }

        return dp[c - 1];
    }
};
