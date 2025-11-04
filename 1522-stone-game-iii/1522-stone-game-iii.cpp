class Solution {
    
  
public:
    string stoneGameIII(vector<int>& stoneValue) {
       
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);  // dp[i] = max score difference from i
        // dp[n] = 0 (base case) already set

        // Go backwards: from n-1 → 0
        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            int best = INT_MIN;
            // try taking 1, 2, 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                best = max(best, take - dp[i + k + 1]);
            }
            dp[i] = best;
        }

        int diff = dp[0];
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};