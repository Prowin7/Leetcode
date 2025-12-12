class Solution {
    vector<int> dp;
    int func(int i, vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + func(i+2,nums);
        int nottake = func(i+1,nums);
        return dp[i] = max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1,-1);
        return func(0,nums);
    }
};