class Solution {
public:
int func(int ind,vector<int> &cost,vector<int>& dp){
    if(ind>=cost.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int s=func(ind+1,cost,dp);
    int d=func(ind+2,cost,dp);
    return dp[ind]=cost[ind]+min(s,d);

}
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int start1=func(0,cost,dp);
        int start2=func(1,cost,dp);
        return min(start1,start2);
    }
};