class Solution {
    vector<int> dp;
    const int MOD = 1e9+7;
    int dfs(int i, string &s, int k){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        long num = 0;
        for(int j = i;j<s.size();j++){
            num = num*10 + (s[j]-'0');
            if(num>k) break;
            ans = (ans + dfs(j+1,s,k))%MOD;
        }
        return dp[i] = ans;
    }
public:
    int numberOfArrays(string s, int k) {
        dp = vector<int>(s.size(),-1);
        return dfs(0,s,k);
    }
};