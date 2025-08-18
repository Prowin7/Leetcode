class Solution {
    vector<int> dp;
    int func(int i,vector<int>&cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = min(cost[i]+func(i+1,cost),cost[i]+func(i+2,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,-1);
        return min(func(0,cost),func(1,cost));
    }
};