class Solution {
    vector<vector<int>> dp;
    int func(int i,int j,string &s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+func(i+1,j-1,s);
        }
        return dp[i][j]=max(func(i+1,j,s),func(i,j-1,s));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        return func(0,n-1,s);
    }
};