def get_Number(n, k):
    odd = [i for i in range(1, n + 1) if i % 2 != 0]
    even = [i for i in range(1, n + 1) if i % 2 == 0]
    combined = odd + even
    return combined[k - 1]