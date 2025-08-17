class Solution {
    vector<vector<int>> dp;
    int func(int i, int target, vector<int>& nums) {
        if (target == 0) return 1;        // valid sequence
        if (i >= nums.size()) return 0;   // no more choices
        if(dp[i][target]!=-1) return dp[i][target];

        int pick = 0;
        if (target - nums[i] >= 0) {
            // restart from 0 because order matters
            pick = func(0, target - nums[i], nums);
        }

        int notPick = func(i + 1, target, nums);

        return dp[i][target] = pick + notPick;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        dp=vector<vector<int>>(n,vector<int>(target+1,-1));
        return func(0, target, nums);
    }
};
