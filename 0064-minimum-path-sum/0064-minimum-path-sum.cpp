class Solution {
    int r,c;
    vector<vector<int>> dp;
    int func(int i,int j, vector<vector<int>>&grid){
        if(i==r-1&&j==c-1) return grid[r-1][c-1];
        if(i>=r||j>=c) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = func(i,j+1,grid);
        int down = func(i+1,j,grid);
        return dp[i][j] = grid[i][j] + min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        dp = vector<vector<int>>(r,vector<int>(c,-1));
        return func(0,0,grid);
    }
};