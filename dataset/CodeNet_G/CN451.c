int longest_common_substring_length(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxLen = 0;
    int dp[4001][4001] = {0};
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}