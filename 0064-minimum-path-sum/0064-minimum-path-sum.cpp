class Solution {
    vector<vector<int>> dp;
    int func(int i,int j,vector<vector<int>>&grid){
        if(i==grid.size()-1 && j== grid[0].size()-1) return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=func(i+1,j,grid);
        int right=func(i,j+1,grid);
        return dp[i][j]=grid[i][j] + min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        return func(0,0,grid);
    }
};