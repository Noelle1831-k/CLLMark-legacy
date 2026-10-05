def zero_count(nums):
    n = len(nums)
    n1 = 0
    for x in nums:
        if x == 0:
            n1 += 1
    return round(n1 / n, 2)