def harmonic_sum(n):
    return sum((1 / i for i in range(1, n)))
print(harmonic_sum(10))
print(harmonic_sum(4))
print(harmonic_sum(7))