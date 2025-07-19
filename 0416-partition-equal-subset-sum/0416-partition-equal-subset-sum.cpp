class Solution {
public:
vector<vector<int>> dp;
bool func(int i,int sum,vector<int>& nums){
    if(sum==0) return true;
    if(i==nums.size()) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool pick=false;
    if(nums[i]<=sum)
    pick=func(i+1,sum-nums[i],nums);
    bool notPick=func(i+1,sum,nums);
    return dp[i][sum] = pick||notPick;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%2==1) return false;
        dp=vector<vector<int>>(n+1,vector<int> (sum/2+1,-1));
        return func(0,sum/2,nums);
    }
};