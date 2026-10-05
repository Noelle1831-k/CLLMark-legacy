def func(nums, k):
    from collections import Counter
    from heapq import nlargest
    freq = Counter()
    for lst in nums:
        freq.update(lst)
    return [item for item, _ in nlargest(k, freq.items(), key=lambda x: x[1])]