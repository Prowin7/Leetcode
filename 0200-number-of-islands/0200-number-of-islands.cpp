class Solution {
public:
    int r,c;
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> vis;
    void dfs(int i,int j,vector<vector<char>>&grid){
        vis[i][j]=1;
        for(auto it:dir){
            int row = it.first + i;
            int col = it.second + j;
            if(row>=0 && col>=0 && row<r && col<c && !vis[row][col] && grid[row][col]!='0'){
                dfs(row,col,grid);
            }
        }
       
    }
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c =  grid[0].size();
        vis = vector<vector<int>>(r,vector<int>(c,0));
        int cnt =0;
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};