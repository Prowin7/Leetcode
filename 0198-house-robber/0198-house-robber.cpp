class Solution {
int func(int i,vector<int> &nums,vector<int> &dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];

    int pick=nums[i]+func(i+2,nums,dp);
    int notPick=func(i+1,nums,dp);
    return dp[i]=max(pick,notPick);

}
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return func(0,nums,dp);
    }
};