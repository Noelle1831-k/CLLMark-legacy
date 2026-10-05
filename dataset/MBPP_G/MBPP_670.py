def decreasing_trend(nums):
    return all((x <= y for x, y in zip(nums, nums[1:])))