class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int func(int day,int k, int canBuy,vector<int>& prices){
        if(day==n || k==0) return 0;
        if(dp[day][k][canBuy]!=-1) return dp[day][k][canBuy];
        int profit=0;
        if(canBuy){
            int buy = -prices[day] + func(day+1,k,0,prices); //make 0 
            int rest = func(day+1,k,1,prices);
            profit = max(rest,buy);
        }
        else{ // sell
            int sell = prices[day] + func(day+1,k-1,1,prices);           
            int rest = func(day+1,k,0,prices);
            profit = max(sell,rest);
        }
        
        return dp[day][k][canBuy]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
     return func(0,k,1,prices);   
    }
};