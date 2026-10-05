def find_Diff(arr, n):
    arr.sort()
    count = 1
    max_count = 0
    min_count = n
    for i in range(0, (n - 1)):
        if arr[i] == arr[i + 1]:
            count += 1
            continue
        else:
            max_count = max(max_count, count)
            min_count = min(min_count, count)
            count = 1
    max_count = max(max_count, count)
    min_count = min(min_count, count)
    return max_count - min_count if max_count != 0 else 0