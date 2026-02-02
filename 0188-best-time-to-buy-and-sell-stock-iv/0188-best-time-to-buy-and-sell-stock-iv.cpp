class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0; // Edge case: No prices or transactions

        vector<int> buy(k + 1, INT_MIN);  // Buy states
        vector<int> sell(k + 1, 0);       // Sell states

        for (int price : prices) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - price);
                sell[j] = max(sell[j], buy[j] + price);
            }
        }

        return sell[k];
    }
};
