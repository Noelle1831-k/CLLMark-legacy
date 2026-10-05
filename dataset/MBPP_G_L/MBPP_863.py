def find_longest_conseq_subseq(arr, n):
    if n == 0:
        return 0
    arr = list(set(arr))
    arr.sort()
    max_len = 1
    current_len = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1] + 1:
            current_len += 1
        else:
            max_len = max(max_len, current_len)
            current_len = 1
    return max(max_len, current_len)