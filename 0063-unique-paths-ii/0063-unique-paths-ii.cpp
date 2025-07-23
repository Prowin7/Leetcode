class Solution {
    vector<vector<int>> dp;
public:
    int path(int m, int n, vector<vector<int>>& obstacleGrid) {
        if (m < 0 || n < 0) return 0; // Out of bounds
        if (obstacleGrid[m][n] == 1) return 0; // Obstacle present
        if (m == 0 && n == 0) return 1; // Reached start position
        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n]=path(m - 1, n, obstacleGrid) + path(m, n - 1, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return path(m - 1, n - 1, obstacleGrid);
    }
};
