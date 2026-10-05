def max_sum_rectangular_grid(grid, n):
    if n == 0:
        return 0
    if n == 1:
        return max(grid[0][0], grid[1][0])
    dp = [0] * n
    dp[0] = max(grid[0][0], grid[1][0])
    dp[1] = max(dp[0], grid[0][1], grid[1][1])
    for i in range(2, n):
        dp[i] = max(dp[i - 1], dp[i - 2] + max(grid[0][i], grid[1][i]))
    return dp[-1]