def max_occurrences(nums):
    from collections import Counter
    count = Counter(nums)
    max_count = max(count.values())
    return ','.join(map(str, [num for num, freq in count.items() if freq == max_count]))