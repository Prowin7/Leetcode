class Solution {
    int func(int s,int e,vector<int> & nums,vector<int> &dp){
        if(s>e) return 0;
        if(dp[s]!=-1) return dp[s];
        int take=nums[s]+func(s+2,e,nums,dp);
        int nottake=func(s+1,e,nums,dp);
        return dp[s] = max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        return max(func(0,nums.size()-2,nums,dp1),func(1,nums.size()-1,nums,dp2));
    }
};