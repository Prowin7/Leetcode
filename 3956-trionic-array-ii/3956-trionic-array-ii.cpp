class Solution {
public:
    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();
        if (n < 4) return 0; // need at least 4 elements to form a trionic subarray

        // dp[phase][i]:
        // phase 0 -> start
        // phase 1 -> first increasing
        // phase 2 -> decreasing
        // phase 3 -> second increasing
        vector<vector<long long>> dp(4, vector<long long>(n, -1e18));

        long long ans = -1e18;

        for (int i = 0; i < n; i++) {
            // Every element can start a new subarray
            dp[0][i] = a[i];

            if (i > 0) {
                // Phase 1: first increasing
                if (a[i] > a[i - 1]) {
                    dp[1][i] = max(dp[0][i - 1] + a[i],   // start new increasing
                                   dp[1][i - 1] + a[i]); // continue increasing
                }

                // Phase 2: decreasing
                if (a[i] < a[i - 1]) {
                    dp[2][i] = max(dp[1][i - 1] + a[i],   // start decreasing
                                   dp[2][i - 1] + a[i]); // continue decreasing
                }

                // Phase 3: second increasing
                if (a[i] > a[i - 1]) {
                    dp[3][i] = max(dp[2][i - 1] + a[i],   // start 2nd increasing
                                   dp[3][i - 1] + a[i]); // continue 2nd increasing
                }
            }

            // Only phase 3 counts as a valid trionic subarray
            ans = max(ans, dp[3][i]);
        }

        return (ans == -1e18 ? 0 : ans); // if no valid trionic subarray, return 0
    }
};
