class Solution {
    vector<vector<int>> dp;
    int r;
    int c;
    int func(int i,int j){
        if(i==r-1&&j==c-1) return 1;
        if(i>=r||j>=c) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=func(i+1,j)+func(i,j+1);
    }
public:
    int uniquePaths(int m, int n) {
        r=m;
        c=n;
       dp=vector<vector<int>>(m,vector<int>(n,-1));
       return func(0,0); 
    }
};