class Solution {
    vector<vector<int>> dp;
    int func(int n,int m, string &s1,string &s2){
        if(n==0||m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+func(n-1,m-1,s1,s2);
        }
        return dp[n][m]=max(func(n-1,m,s1,s2),func(n,m-1,s1,s2));
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp=vector<vector<int>> (n+1,vector<int>(m+1,-1));
        int len=func(n,m,s1,s2);
        return (n-len)+(m-len);
    }
};