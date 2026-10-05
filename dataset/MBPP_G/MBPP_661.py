def max_sum_of_three_consecutive(arr, n):
    if n == 0:
        return 0
    if n == 1:
        return arr[0]
    if n == 2:
        return arr[0] + arr[1]
    dp = [0] * n
    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    dp[2] = max(arr[2] + arr[0], arr[2] + arr[1], dp[1])
    for i in range(3, n):
        dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3], dp[i - 1])
    return dp[n - 1]