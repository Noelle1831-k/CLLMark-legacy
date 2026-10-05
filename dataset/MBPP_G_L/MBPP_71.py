def comb_sort(nums):
    gap = len(nums)
    shrink = 1.3
    sorted = False
    while not sorted:
        gap = int(gap / shrink)
        if gap <= 1:
            gap = 1
            sorted = True
        index = 0
        while index + gap < len(nums):
            if nums[index] > nums[index + gap]:
                nums[index], nums[index + gap] = (nums[index + gap], nums[index])
                sorted = False
            index += 1
    return nums