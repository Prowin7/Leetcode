class Solution {
    int func(int i,int left,vector<int>& coins){
        if(left==0) return 0;
        if(i==coins.size()) return INT_MAX;
        if(dp[i][left]!=-1) return dp[i][left];
        int notPick=func(i+1,left,coins);
        int pick=INT_MAX;
        if(coins[i]<=left){
            int res=func(i,left-coins[i],coins);
            if(res!=INT_MAX)
            pick=1+res;
        }
        return dp[i][left]=min(pick,notPick);
    }
public:
vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp=vector<vector<int>> (coins.size()+1,vector<int>(amount+1,-1));

        int res=func(0,amount,coins);
        return (res==INT_MAX)?-1:res;
    }
};