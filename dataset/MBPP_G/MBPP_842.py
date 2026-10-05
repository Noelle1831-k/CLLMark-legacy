def get_odd_occurence(arr, arr_size):
    result = 0
    for i in range(arr_size):
        result ^= arr[i]
    return result