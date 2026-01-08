class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i<0||j<0) return INT_MIN;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int take = nums1[i]*nums2[j] + max(0,solve(i-1,j-1,nums1,nums2));
        int skip1 = solve(i-1,j,nums1,nums2);
        int skip2 = solve(i,j-1,nums1,nums2);
        return dp[i][j] = max({take,skip1,skip2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp = vector<vector<int>>(n+1,vector<int>(m+1,INT_MIN));
       return solve(n-1,m-1,nums1,nums2);
        
    }
};