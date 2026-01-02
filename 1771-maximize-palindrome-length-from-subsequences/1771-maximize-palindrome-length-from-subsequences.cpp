class Solution {
    vector<vector<int>> dp;
    int n1;  // length of word1

    int solve(int i, int j, string &s, int &ans) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res;
        if (s[i] == s[j]) {
            res = 2 + solve(i + 1, j - 1, s, ans);

            // ensure palindrome uses both strings
            if (i < n1 && j >= n1) {
                ans = max(ans, res);
            }
        } else {
            res = max(
                solve(i + 1, j, s, ans),
                solve(i, j - 1, s, ans)
            );
        }

        return dp[i][j] = res;
    }

public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        n1 = word1.size();

        dp.assign(n, vector<int>(n, -1));
        int ans = 0;

        solve(0, n - 1, s, ans);
        return ans;
    }
};
