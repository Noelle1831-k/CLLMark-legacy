    if (m == 0 || n == 0) {
        return 0;
    }
    if (x[m-1] == y[n-1]) {
        return 1 + longestCommonSubsequence(x, y, m-1, n-1);
    } else {
        return max(longestCommonSubsequence(x, y, m-1, n), longestCommonSubsequence(x, y, m, n-1));
    }
}