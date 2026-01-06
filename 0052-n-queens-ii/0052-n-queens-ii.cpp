class Solution {
    vector<int> col,diag1,diag2;
    int ans = 0;
    int n;
    vector<string> board;
    void backtrack(int row){
        if(n==row){
            ans++;
            return;
        }
        for(int c=0;c<n;c++){
            if(col[c]||diag1[row-c+n-1]||diag2[row+c]) continue;
            board[row][c]='Q';
            col[c]=diag1[row-c+n-1]=diag2[row+c]=1;
            backtrack(row+1);
            board[row][c]='.';
            col[c]=diag1[row-c+n-1]=diag2[row+c]=0;
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        board = vector<string>(n,string(n,'.'));
        col = vector<int>(n,0);
        diag1 = vector<int>(2*n-1,0);
        diag2 = vector<int>(2*n-1,0);
        backtrack(0);
        return ans;
    }
};