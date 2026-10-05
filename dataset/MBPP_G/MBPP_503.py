def add_consecutive_nums(nums):
    return [nums[i] + nums[i + 1] for i in range(len(nums) - 1)]