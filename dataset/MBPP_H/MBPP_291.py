dp = [0] * (n + 1)
total = k
mod = 1000000007
dp[0] = 0
if n > 0:
    dp[1] = k
if n > 1:
    dp[2] = k * k
for i in range(3, n + 1):
    dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod
return dp[n]