class Solution {
    vector<vector<int>> dp;
    int func(int n,int m,string &s,string &t){
        if(n==0||m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]){
            return dp[n][m]=1+func(n-1,m-1,s,t);
        }
        return dp[n][m]=max(func(n-1,m,s,t),func(n,m-1,s,t));
    }
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp=vector<vector<int>> (n+1,vector<int>(m+1,-1));
        return func(n,m,s,t)==n;
    }
};