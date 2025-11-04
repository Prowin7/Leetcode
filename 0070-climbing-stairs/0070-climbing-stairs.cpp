class Solution {
     vector<int> dp;
    int func(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = func(n-1)+func(n-2);
    }
public:
    int climbStairs(int n) {
       dp = vector<int>(n+1,-1);
        return func(n);
    }
};