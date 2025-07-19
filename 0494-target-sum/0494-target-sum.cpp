class Solution {
    int func(int i,int sum,vector<int>& nums,int target){
        if(i==nums.size()){
            return sum==target;
        }
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int plus=func(i+1,sum-nums[i],nums,target);
        int minus=func(i+1,sum+nums[i],nums,target);
        return dp[i][sum+offset]=plus+minus;
    }

public: 
vector<vector<int>> dp;
int offset;
    int findTargetSumWays(vector<int>& nums, int target) {
        offset=accumulate(nums.begin(),nums.end(),0);
        dp=vector<vector<int>>(nums.size()+1,vector<int>(2*offset+1,-1));
        return func(0,0,nums,target);
    }
};