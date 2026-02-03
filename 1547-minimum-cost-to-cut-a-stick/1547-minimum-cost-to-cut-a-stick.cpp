class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k = i+1;k<j;k++){
            int cost = (cuts[j]-cuts[i]) + solve(i,k,cuts) + 
                        solve(k,j,cuts);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        dp = vector<vector<int>>(m,vector<int>(m,-1));
        
        sort(cuts.begin(), cuts.end());
        return solve(0,m-1,cuts);
    }
};