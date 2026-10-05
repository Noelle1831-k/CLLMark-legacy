def max_occurrences(nums):
    from collections import defaultdict
    dict = defaultdict(int)
    for i in nums:
        dict[i] += 1
    result = max(dict.items(), key=lambda x: x[1])
    return result