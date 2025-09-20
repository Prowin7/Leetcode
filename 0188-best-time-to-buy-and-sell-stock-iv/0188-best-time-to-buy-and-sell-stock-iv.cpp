class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int index, int k, bool canBuy, vector<int>& prices) {
        // Base case: no more days or transactions
        if (index == n || k == 0) return 0;

        // Check memo
        if (dp[index][k][canBuy] != -1) return dp[index][k][canBuy];

        int profit = 0;
        if (canBuy) {
            // Option 1: Buy today
            int buy = -prices[index] + solve(index + 1, k, false, prices);
            // Option 2: Skip today
            int skip = solve(index + 1, k, true, prices);
            profit = max(buy, skip);
        } else {
            // Option 1: Sell today
            int sell = prices[index] + solve(index + 1, k - 1, true, prices);
            // Option 2: Skip today
            int skip = solve(index + 1, k, false, prices);
            profit = max(sell, skip);
        }

        return dp[index][k][canBuy] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, k, true, prices);
    }
};
