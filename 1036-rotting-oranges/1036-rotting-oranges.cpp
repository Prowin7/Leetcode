class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(!q.empty()&&fresh) {
            time++;
            int s=q.size();
            while(s--){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                for(auto d:dir){
                    int row=cr+d.first;
                    int col=cc+d.second;
                    if(row<0||col<0||row==m||col==n||grid[row][col]!=1)
                    continue;
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
        }
        return fresh?-1:time;
    }
};