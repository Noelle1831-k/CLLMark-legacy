def get_Odd_Occurrence(arr, arr_size):
    res = 0
    for i in range(arr_size):
        res ^= arr[i]
    return res