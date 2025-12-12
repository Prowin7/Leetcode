class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    if(i==0||j==0)
                    dp[i][j]=1;
                    else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                res+=dp[i][j];
                }
            }
        }
        return res;
    }
};