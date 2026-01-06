class Solution {
    int n;
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col,diag1,diag2;
    void backtrack(int row){
        if(row==n) {
            ans.push_back(board);
            return ;
        }
        for(int c=0;c<n;c++){
            if(col[c] || diag1[row-c+n-1] || diag2[row+c] ) continue;
            board[row][c]='Q';
            diag1[row-c+n-1]=diag2[row+c]=col[c]=1;
            backtrack(row+1);
            board[row][c]='.';
            diag1[row-c+n-1]=diag2[row+c]=col[c]=0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n,string(n,'.'));
        col = vector<int>(n,0);
        diag1 = vector<int>(2*n-1,0);
        diag2 = vector<int>(2*n-1,0);
        backtrack(0);
        return ans;
    }
};