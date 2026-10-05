def find_Sum(arr, n):
    element_count = {}
    sum_repeated = 0
    for num in arr:
        if num in element_count:
            element_count[num] += 1
        else:
            element_count[num] = 1
    for num, count in element_count.items():
        if count > 1:
            sum_repeated += num
    return sum_repeated