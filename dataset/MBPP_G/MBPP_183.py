def count_pairs(arr, n, k):
    arr_set = set(arr)
    count = 0
    seen = set()
    for num in arr_set:
        if num + k in arr_set and num not in seen:
            count += 1
            seen.update([num, num + k])
        if num - k in arr_set and num - k not in seen:
            count += 1
            seen.update([num, num - k])
    return count