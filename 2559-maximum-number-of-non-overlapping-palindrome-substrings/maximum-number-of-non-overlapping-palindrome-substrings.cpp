class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = whether s[i..j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using the first i characters
        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; ++r) {
            // Don't take a palindrome ending at r
            dp[r + 1] = dp[r];

            // Try every palindrome s[l..r]
            for (int l = 0; l <= r - k + 1; ++l) {
                if (pal[l][r]) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};
