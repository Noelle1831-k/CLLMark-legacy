function coinChange(s, m, n) {
    let dp = Array(n + 1).fill(0);
    dp[0] = 1;
    for (let i = 0; i < m; i++) {
      for (let j = s[i]; j <= n; j++) {
        dp[j] += dp[j - s[i]];
      }
    }
    return dp[n];
}
