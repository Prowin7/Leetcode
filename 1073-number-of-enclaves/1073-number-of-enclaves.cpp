class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int total=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) total++;
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            if(grid[i][0]==1) q.push({i,0});
            if(grid[i][c-1]==1) q.push({i,c-1});
        }
        for(int i=0;i<c;i++){
            if(grid[0][i]==1) q.push({0,i});
            if(grid[r-1][i]==1) q.push({r-1,i});
        }
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                if(grid[cr][cc] != 1) continue;
                cnt++;
                grid[cr][cc]=0;
                for(auto d:dir){
                    int row=cr+d.first;
                    int col=cc+d.second;
                    if(row<0||col<0||row==r||col==c||grid[row][col]!=1)
                    continue;
                    q.push({row,col});
                }
            }
        }
        return total-cnt;
    }
};