class Solution {
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,string t1,string t2){
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j] = 1+solve(i+1,j+1,t1,t2);
        }
        return dp[i][j] = max(solve(i+1,j,t1,t2),solve(i,j+1,t1,t2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return solve(0,0,text1,text2);
    }
};