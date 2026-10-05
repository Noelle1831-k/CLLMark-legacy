def average_Even(n):
    if n % 2 != 0:
        raise ValueError('Input must be an even number.')
    count = n // 2
    total = (2 + n) * count // 2
    return total // count if count != 0 else 0