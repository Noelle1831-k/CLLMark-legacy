def rearrange_numbs(array_nums):
    return sorted(array_nums, key=lambda x: (x < 0, abs(x)))