class Solution {
public:
int func(int n,vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int square=i*i;
        ans=min(ans,1+func(n-square,dp));
    }
    return dp[n]=ans;
}
    int numSquares(int n) {

        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};