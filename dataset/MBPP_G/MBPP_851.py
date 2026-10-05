def Sum_of_Inverse_Divisors(N, Sum):
    inverses = sum((1 / d for d in range(1, N + 1) if N % d == 0))
    return round(Sum / inverses, 2)