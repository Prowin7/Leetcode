class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else 
                    mat[i][j]=-1;
            }
        }
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                for(auto d:dir){
                    int row=cr+d.first;
                    int col=cc+d.second;
                    if(row<0||col<0||row==r||col==c||mat[row][col]!=-1){
                        continue;
                    }
                    mat[row][col]=mat[cr][cc]+1;
                    q.push({row,col});
                }
            }
        }
        return mat;
    }
};