def first_odd(nums):
    for num in nums:
        if num % 2 != 0:
            return num
    return None