class Solution {
public:
vector<vector<vector<int>>> dp;
long long func(int i,int buy,int t,const vector<int> &prices){
    if(i==prices.size())  {
        if(buy==1) return INT_MIN;
        return 0;
    }

    if(t==2) return 0;

    if(dp[i][t][buy]!=-1) return dp[i][t][buy];
   long long res=0;
    if(!buy){
        res=max(res,-prices[i]+func(i+1,1,t,prices));
    }
    else{
        res=max(res,prices[i]+func(i+1,0,t+1,prices));
    }
    res=max(res,func(i+1,buy,t,prices));
    dp[i][t][buy]=res;
    return res;
     
    
}
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        dp.assign(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return func(0,0,0,prices);
    }
};