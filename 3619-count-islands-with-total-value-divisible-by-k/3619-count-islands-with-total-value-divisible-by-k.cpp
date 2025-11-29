class Solution {
    int r,c;
    vector<vector<int>> vis;
    vector<pair<int,int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    long long dfs(int i,int j,vector<vector<int>>& grid){
        vis[i][j] = 1;
        long long sum = grid[i][j];
        for(auto it:dir){
            int row = i+it.first;
            int col = j+it.second;
            if(row<r && col<c && row>=0 && col>=0 && !vis[row][col] && grid[row][col]!=0){
                sum+=dfs(row,col,grid);
            }
        }
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        r = grid.size();
        c = grid[0].size();
        
        vis = vector<vector<int>>(r,vector<int>(c,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if(!vis[i][j]&&grid[i][j]!=0){
                    long long sum = dfs(i,j,grid);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};