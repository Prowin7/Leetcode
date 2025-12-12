class Solution {
    int func(int left, int right, vector<int>& nums){
        int prev1=0, prev2=0;
        for(int i =left;i<=right;i++){
            int take = nums[i] + prev2;
            int skip = prev1;
            int cur=max(take,skip);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(func(0,n-2,nums), func(1,n-1,nums));
    }
};