class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto it:stones) sum+=it;
        int n = stones.size();
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int s = sum ; s>=stones[i];s--){
                dp[s] = dp[s]||dp[s-stones[i]];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[i])
            ans=min(ans,sum-2*i);
        }
        return ans;
    }
};