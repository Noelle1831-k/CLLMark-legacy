def modular_sum(arr, n, m):
    if n > m:
        return True
    dp = [False] * m
    for i in range(n):
        if dp[0]:
            return True
        temp = [False] * m
        for j in range(m):
            if dp[j]:
                temp[(j + arr[i]) % m] = True
        for j in range(m):
            if temp[j]:
                dp[j] = True
        dp[arr[i] % m] = True
    return dp[0]