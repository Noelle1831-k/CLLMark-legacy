def pancake_sort(nums):
    def flip(sublist, k):
        sublist[0:k] = reversed(sublist[0:k])
    n = len(nums)
    for i in range(n, 1, -1):
        max_idx = nums.index(max(nums[0:i]))
        if max_idx != i - 1:
            if max_idx != 0:
                flip(nums, max_idx + 1)
            flip(nums, i)
    return nums