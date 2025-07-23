class Solution {
    vector<vector<int>> dp;
    string s;
public:
    int func(int n, int m, string &s1, string &s2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        s = "";
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        func(n, m, str1, str2);

        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                s.push_back(str1[i - 1]);
                i--;
            } else {
                s.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            s.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            s.push_back(str2[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};
