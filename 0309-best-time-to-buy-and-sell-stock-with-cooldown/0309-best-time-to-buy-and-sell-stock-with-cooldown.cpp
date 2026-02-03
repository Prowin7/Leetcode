class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int hold = -prices[0]; // Buying on first day
        int sell = 0;          // No profit initially
        int prev_sell = 0;     // Previous sell state for cooldown

        for (int i = 1; i < prices.size(); i++) {
            int new_hold = max(hold, prev_sell - prices[i]); // Buy or keep holding
            prev_sell = sell; // Save previous sell before updating
            sell = max(sell, hold + prices[i]); // Sell or stay in cooldown
            hold = new_hold; // Update hold state
        }

        return sell; // Maximum profit will be in sell state
    }
};
