def div_of_nums(nums, m, n):
    return list(filter(lambda x: x % m == 0 and x % n == 0, nums))