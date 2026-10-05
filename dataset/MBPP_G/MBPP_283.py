def validate(n):
    from collections import Counter
    counts = Counter(str(n))
    return all((count <= int(digit) for digit, count in counts.items()))