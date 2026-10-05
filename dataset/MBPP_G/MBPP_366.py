def adjacent_num_product(list_nums):
    return max((list_nums[i] * list_nums[i + 1] for i in range(len(list_nums) - 1)))