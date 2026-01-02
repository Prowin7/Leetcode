class Solution {
    static const int mod = 1000000007;
    vector<vector<int>> dp;

    int solve(int i, int j, string &s) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        if (s[i] == s[j]) {
            int l = i + 1, r = j - 1;

            // find first same char as s[i] from left
            while (l <= r && s[l] != s[i]) l++;
            // find first same char as s[j] from right
            while (l <= r && s[r] != s[j]) r--;

            if (l > r) {
                // no same char inside
                ans = 2LL * solve(i + 1, j - 1, s) + 2;
            } else if (l == r) {
                // exactly one same char inside
                ans = 2LL * solve(i + 1, j - 1, s) + 1;
            } else {
                // more than one same char inside
                ans = 2LL * solve(i + 1, j - 1, s)
                      - solve(l + 1, r - 1, s);
            }
        } else {
            ans = solve(i + 1, j, s)
                + solve(i, j - 1, s)
                - solve(i + 1, j - 1, s);
        }

        ans = (ans % mod + mod) % mod;
        return dp[i][j] = (int)ans;
    }

public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};
