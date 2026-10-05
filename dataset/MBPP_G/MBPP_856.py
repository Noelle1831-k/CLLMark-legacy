def find_Min_Swaps(arr, n):
    zeros = arr.count(0)
    current_zeros = 0
    swaps = 0
    for i in range(n):
        if arr[i] == 0:
            current_zeros += 1
        else:
            swaps += current_zeros
    min_swaps = swaps
    current_ones = n - zeros
    for i in range(1, n):
        if arr[i - 1] == 1:
            swaps -= zeros
        else:
            swaps += current_ones
        min_swaps = min(min_swaps, swaps)
    return min_swaps