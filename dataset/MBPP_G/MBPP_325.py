def get_Min_Squares(n):
    if n <= 3:
        return n
    dp = [float('inf')] * (n + 1)
    dp[0], dp[1], dp[2], dp[3] = (0, 1, 2, 3)
    for i in range(4, n + 1):
        for x in range(1, int(i ** 0.5) + 1):
            square = x * x
            if square > i:
                break
            dp[i] = min(dp[i], 1 + dp[i - square])
    return dp[n]