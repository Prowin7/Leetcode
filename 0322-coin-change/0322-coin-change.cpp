class Solution {
public:
int func(int i,vector<int> &coins,int amount,vector<vector<int>> &dp){
    if(amount==0) return 0;
    if(i>=coins.size()||amount<0) return INT_MAX;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=func(i,coins,amount-coins[i],dp);
    if(take!=INT_MAX) take+=1;
    int nott=func(i+1,coins,amount,dp);
    return dp[i][amount]=min(take,nott);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int result=func(0,coins,amount,dp);
        
        return (result==INT_MAX)?-1:result;

    }
};