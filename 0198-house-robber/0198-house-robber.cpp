class Solution {
    vector<int> dp;
    int func(int i,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = nums[i]+max(func(i+2,nums),func(i+3,nums));
    }
public:
    int rob(vector<int>& nums) {
        dp=vector<int>(nums.size()+1,-1);
        int m = max(func(0,nums), func(1,nums));
        return m;
    }
};