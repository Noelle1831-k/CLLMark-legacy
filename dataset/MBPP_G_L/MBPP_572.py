def two_unique_nums(nums):
    num_count = {}
    for num in nums:
        num_count[num] = num_count.get(num, 0) + 1
    result = [num for num in nums if num_count[num] == 1]
    return result