class Solution {
    int r, c;
    vector<vector<int>> dp;

    int func(int i, int j, vector<vector<int>>& grid) {
        if (i >= r || j >= c) return 0;

        // If obstacle, no path
        if (grid[i][j] == 1) return 0;

        // If reached destination
        if (i == r - 1 && j == c - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int right = func(i, j + 1, grid);
        int down  = func(i + 1, j, grid);

        return dp[i][j] = right + down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        // If starting cell is blocked
        if (grid[0][0] == 1) return 0;

        dp = vector<vector<int>>(r, vector<int>(c, -1));

        return func(0, 0, grid);
    }
};
