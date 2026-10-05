def minimum_Length(s):
    from collections import Counter
    count = Counter(s)
    max_occurrence = max(count.values())
    return len(s) - max_occurrence