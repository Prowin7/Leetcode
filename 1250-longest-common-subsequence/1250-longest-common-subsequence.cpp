class Solution {
    int func(string &t1,string &t2,int s1,int s2) {

        if(s1==0||s2==0) return 0;
        if(s1<0||s2<0) return 0;
        if(dp[s1][s2]!=-1) return dp[s1][s2];
        if(t1[s1-1]==t2[s2-1]){
            return dp[s1][s2]=1+func(t1,t2,s1-1,s2-1);
        }
        else {
            return dp[s1][s2]=max(func(t1,t2,s1-1,s2),func(t1,t2,s1,s2-1));
        } 

    }

public:
vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp=vector<vector<int>> (text1.size()+1,vector<int>(text2.size()+1,-1));

        return func(text1,text2,text1.size(),text2.size());
    }
};