class Solution {
    vector<int> dp;

    int tryAllSquares(int i, int rem) {
        if (i * i > rem) return INT_MAX;
        int res = func(rem - i * i);
        int pick = (res == INT_MAX) ? INT_MAX : 1 + res;
        int notPick = tryAllSquares(i + 1, rem);
        return min(pick, notPick);
    }

    int func(int rem) {
        if (rem == 0) return 0;
        if (rem < 0) return INT_MAX;
        if (dp[rem] != -1) return dp[rem];

        return dp[rem] = tryAllSquares(1, rem);
    }

public:
    int numSquares(int n) {
        dp = vector<int>(n + 1, -1);
        return func(n);
    }
};
