class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int c = coins[i]; c <= amount; c++) {
                if (dp[c] <= INT_MAX - dp[c - coins[i]]) {
                    dp[c] += dp[c - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
