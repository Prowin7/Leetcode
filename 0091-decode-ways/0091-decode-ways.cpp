class Solution {
    vector<int> dp;
    int solve(int i, string s){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ways = solve(i+1,s);
        if(i+1<s.size()){
            int two = (s[i]-'0')*10 + (s[i+1]-'0');
            if(two>=10 && two<=26){
                ways+=solve(i+2,s);
            }

        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        dp = vector<int>(n+1,-1);
        return solve(0,s);
        
    }
};