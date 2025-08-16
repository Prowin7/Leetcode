class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                    int cnt=0;
                    while(!q.empty()){
                        int cr=q.front().first;
                        int cc=q.front().second;
                        q.pop();
                        cnt++;
                        for(auto d:dir){
                            int row=cr+d.first;
                            int col=cc+d.second;
                            if(row<0||col<0||row>=r||col>=c||grid[row][col]!=1)
                            continue;
                            grid[row][col]=0;
                            q.push({row,col});
                        }
                    }
                    ans=max(cnt,ans);
                }
            }
        }
        
       
       
        return ans;
    }
};