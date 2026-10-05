def most_common_elem(s, a):
    from collections import Counter
    counts = Counter(s)
    return counts.most_common(a)