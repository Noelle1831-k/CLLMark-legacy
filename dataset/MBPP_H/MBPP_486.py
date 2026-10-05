def binomial_probability(n, k, p):
    def nCr(n, r):
        if r > n / 2:
            r = n - r
        answer = 1
        for i in range(1, r + 1):
            answer *= (n - r + i)
            answer //= i
        return answer
    return nCr(n, k) * pow(p, k) * pow(1 - p, n - k)