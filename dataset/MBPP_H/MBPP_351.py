def first_Element(arr, n, k):
    count_map = {}
    for i in range(0, n):
        if (arr[i] in count_map):
            count_map[arr[i]] += 1
        else:
            count_map[arr[i]] = 1
    for i in range(0, n):
        if (count_map[arr[i]] == k):
            return arr[i]
    return -1