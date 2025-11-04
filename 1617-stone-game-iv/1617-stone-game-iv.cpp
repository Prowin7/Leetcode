class Solution {
    vector<int> dp;
    bool canWin(int n){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i =1; i*i<=n;i++){
            if(!canWin(n-i*i)){
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        dp = vector<int>(n+1,-1);
        return canWin(n);
    }
};