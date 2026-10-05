def find_Divisor(x, y):
    from collections import defaultdict
    divisor_count = defaultdict(int)
    for num in range(x, y + 1):
        for divisor in range(1, num + 1):
            if num % divisor == 0:
                divisor_count[divisor] += 1
    max_occurrences = max(divisor_count.values())
    for divisor in sorted(divisor_count):
        if divisor_count[divisor] == max_occurrences:
            return divisor