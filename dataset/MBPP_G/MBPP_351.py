def first_Element(arr, n, k):
    count_dict = {}
    for num in arr:
        count_dict[num] = count_dict.get(num, 0) + 1
        if count_dict[num] == k:
            return num
    return -1