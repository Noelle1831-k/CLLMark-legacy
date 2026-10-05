def radix_sort(nums):
    if len(nums) == 0:
        return nums
    max_num = max(nums)
    exp = 1
    while max_num // exp > 0:
        count = [0] * 10
        output = [0] * len(nums)
        for num in nums:
            index = num // exp % 10
            count[index] += 1
        for i in range(1, 10):
            count[i] += count[i - 1]
        for num in reversed(nums):
            index = num // exp % 10
            output[count[index] - 1] = num
            count[index] -= 1
        nums = output
        exp *= 10
    return nums