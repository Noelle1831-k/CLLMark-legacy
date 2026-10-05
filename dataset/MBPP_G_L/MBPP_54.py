def counting_sort(my_list):
    if not my_list:
        return my_list
    max_val = max(my_list)
    min_val = min(my_list)
    count_range = max_val - min_val + 1
    count = [0] * count_range
    output = [0] * len(my_list)
    for num in my_list:
        count[num - min_val] += 1
    total = 0
    for i in range(count_range):
        count[i], total = (total, total + count[i])
    for num in my_list:
        output[count[num - min_val]] = num
        count[num - min_val] += 1
    return output