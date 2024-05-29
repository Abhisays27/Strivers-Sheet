class Solution {
    int dp[1001][1001];
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        memset(dp, 0, sizeof(dp));

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Reconstruct the Shortest Common Supersequence from the dp table
        string result;
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                result += str1[i-1];
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                result += str1[i-1];
                i--;
            } else {
                result += str2[j-1];
                j--;
            }
        }

        // Add remaining characters of str1 or str2
        while (i > 0) {
            result += str1[i-1];
            i--;
        }
        while (j > 0) {
            result += str2[j-1];
            j--;
        }

        // The result string is constructed in reverse order
        reverse(result.begin(), result.end());

        return result;
    }
};

      

   