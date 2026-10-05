def get_max_sum(n):
    memo = {0: 0}

    def f(x):
        if x in memo:
            return memo[x]
        memo[x] = max(f(x // 2) + f(x // 3) + f(x // 4) + f(x // 5), x)
        return memo[x]
    return f(n)