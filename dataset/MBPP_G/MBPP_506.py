def permutation_coefficient(n, k):
    result = 1
    for i in range(k):
        result *= n - i
    return result