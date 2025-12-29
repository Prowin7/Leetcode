class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;

        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;   // FIX: base case

        for (int i = 0; i < nums.size(); i++) {
            for (int s = sum; s >= nums[i]; s--) {
                dp[s] = dp[s] || dp[s - nums[i]];
            }
        }
        return dp[sum];
    }
};
