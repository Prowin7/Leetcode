class Solution {
    int n;
    vector<vector<int>> dp;
    int func(int curLen, int pasteLen){
        if(curLen==n) return 0;
        if(curLen>n) return  1000;
        if(dp[curLen][pasteLen]!=-1) return dp[curLen][pasteLen];
        // copy and paste
        int opt1 = 2 + func(curLen*2, curLen);
        // paste
        int opt2 = 1 + func(curLen+pasteLen,pasteLen);
        return dp[curLen][pasteLen] = min(opt1, opt2);
    }
public:
    int minSteps(int n) {
        this->n=n;
        if(n==1) return 0;
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        string s;
        return 1+func(1,1); //(curLen, pasteLen)
    }
};