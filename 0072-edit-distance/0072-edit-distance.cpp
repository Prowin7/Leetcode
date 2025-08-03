class Solution {
    vector<vector<int>> dp;
    int func(int i,int j,string &s1,string &s2){
        if(i<0) return j+1; // insert extra to s1
        if(j<0) return i+1; // delete this from s1
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=func(i-1,j-1,s1,s2);
        }
        int insert=func(i,j-1,s1,s2);
        int del=func(i-1,j,s1,s2);
        int replace=func(i-1,j-1,s1,s2);
        return dp[i][j]=1+min({insert,del,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        return func(n-1,m-1,word1,word2);
    }
};