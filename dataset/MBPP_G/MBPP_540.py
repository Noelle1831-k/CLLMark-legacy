def find_Diff(arr, n):
    from collections import Counter
    freq = Counter(arr)
    max_freq = max(freq.values())
    min_freq = min(freq.values())
    return max_freq - min_freq