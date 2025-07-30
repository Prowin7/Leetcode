class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][c-1]=='O') q.push({i,c-1});
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[r-1][i]=='O') q.push({r-1,i});
        }
        
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                if (board[cr][cc] != 'O') continue;
                board[cr][cc]='#';
                for(auto d:dir){
                    int row=cr+d.first;
                    int col=cc+d.second;
                    if(row<0||col<0||row==r||col==c||board[row][col]!='O'){
                        continue;
                    }
                    q.push({row,col});
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
        return ;
    }
};