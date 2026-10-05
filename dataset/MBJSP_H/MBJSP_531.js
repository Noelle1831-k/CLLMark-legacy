function minCoins(coins, m, v) {
  if (m === 0) return 0;
  if (coins[m-1] > v) return minCoins(coins, m - 1, v);
  return 1 + minCoins(coins, m - 1, v - coins[m-1]);
}
