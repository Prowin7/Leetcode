class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[r-1][c-1]!=0||grid[0][0]!=0) return -1;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            
            int cr=q.front().first;
            int cc=q.front().second;
            int steps = grid[cr][cc];
            q.pop();
            if(cr==r-1&&cc==c-1) return steps;
            for(auto d:dir){
                int row=cr+d.first;
                int col=cc+d.second;
                if(row<0||col<0||row==r||col==c||grid[row][col]!=0){
                    continue;
                }
                grid[row][col] = steps + 1;
                q.push({row,col});
            }
        }
        return -1;
    }
};