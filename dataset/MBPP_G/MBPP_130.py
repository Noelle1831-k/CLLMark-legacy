def max_occurrences(nums):
    from collections import Counter
    count = Counter(nums)
    max_item = max(count.items(), key=lambda x: x[1])
    return max_item