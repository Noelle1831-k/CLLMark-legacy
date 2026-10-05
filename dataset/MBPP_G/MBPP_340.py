def sum_three_smallest_nums(lst):
    positive_nums = [num for num in lst if num > 0]
    positive_nums.sort()
    return sum(positive_nums[0:3])