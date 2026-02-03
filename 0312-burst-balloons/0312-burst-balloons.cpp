class Solution {
    vector<vector<int>> dp;
    int func(int i, int j , vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1]+
                        func(i,k-1,nums)+func(k+1,j,nums);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n =  nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        dp = vector<vector<int>>(n+2,vector<int>(n+2,-1));
        return func(1,n,nums);
    }
};