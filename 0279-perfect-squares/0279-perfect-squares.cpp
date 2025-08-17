class Solution {
    vector<int> dp;
    int func(int n){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+func(n-i*i));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        dp=vector<int> (n+1,-1);
        return func(n);
    }
};