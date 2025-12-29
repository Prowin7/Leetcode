class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(auto it:stones) total+=it;
        vector<int> dp(total+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int s = total ;s>=stones[i];s--){
                dp[s] = dp[s]||dp[s-stones[i]];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=total/2;i++){
            if(dp[i])
            ans=min(ans,total-2*i);
        }
        return ans;
    }
};