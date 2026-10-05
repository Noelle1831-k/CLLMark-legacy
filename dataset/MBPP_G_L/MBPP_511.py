def find_Min_Sum(num):
    def find_factors(n):
        factors = []
        for i in range(1, int(n ** 0.5) + 1):
            if n % i == 0:
                factors.append((i, n // i))
        return factors
    factors = find_factors(num)
    return min((sum(pair) for pair in factors))