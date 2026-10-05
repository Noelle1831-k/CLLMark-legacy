def diff_consecutivenums(nums):
    return [nums[i + 1] - nums[i] for i in range(len(nums) - 1)]