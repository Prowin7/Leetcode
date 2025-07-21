class Solution {
    int func(int i,int left,vector<int> &coins){
        if(left==0) return 1;
        if(i>=coins.size()) return 0;
        if(left<0) return 0;
        if(dp[i][left]!=-1) return dp[i][left];
        int pick=func(i,left-coins[i],coins);
        int notPick=func(i+1,left,coins);
        return dp[i][left]=pick+notPick;
    }
public:
vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp=vector<vector<int>>(n+1,vector<int>(amount+1,-1));
        return func(0,amount,coins);
    }
};