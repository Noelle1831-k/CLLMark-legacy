def odd_position(nums):
    return all((nums[i] % 2 != 0 for i in range(1, len(nums), 2)))