def move_zero(num_list):
    non_zeros = [num for num in num_list if num != 0]
    zeros = [0] * num_list.count(0)
    return non_zeros + zeros