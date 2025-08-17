class Solution {
    vector<vector<int>> dp;
    int func(int i,int amount,vector<int>&coins){
        if(amount==0) return 0;
        if(i>=coins.size()) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int pick=INT_MAX;
        if(amount-coins[i]>=0){
            int res=func(i,amount-coins[i],coins);
            if(res!=INT_MAX)
            pick=1+res;
        }
        int notPick=func(i+1,amount,coins);
        return dp[i][amount] = min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
        if(func(0,amount,coins)!=INT_MAX) return func(0,amount,coins);
        return -1;
    }
};