function minSumPath(a) {
const n = a.length;
  const dp = a[n - 1].slice();
  for (let i = n - 2; i >= 0; i--) {
    for (let j = 0; j <= i; j++) {
      dp[j] = a[i][j] + Math.min(dp[j], dp[j + 1]);
    }
  }
  return dp[0];
}
