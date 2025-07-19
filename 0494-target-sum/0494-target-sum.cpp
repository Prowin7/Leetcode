class Solution {
    int func(int i,int sum,vector<int>& nums,int target){
        if(i==nums.size()){
            return sum==target;
        }
        int plus=func(i+1,sum-nums[i],nums,target);
        int minus=func(i+1,sum+nums[i],nums,target);
        return plus+minus;
    }
public: 
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0,0,nums,target);
    }
};