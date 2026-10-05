def max_len_sub(arr, n):
    if n <= 1:
        return n
    max_len = 1
    current_len = 1
    for i in range(1, n):
        if abs(arr[i] - arr[i - 1]) <= 1:
            current_len += 1
        else:
            max_len = max(max_len, current_len)
            current_len = 1
    return max(max_len, current_len)