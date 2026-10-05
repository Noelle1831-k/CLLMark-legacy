def consecutive_duplicates(nums):
    result = []
    for num in nums:
        if not result or num != result[-1]:
            result.append(num)
    return result