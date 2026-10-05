def first(arr, x, n):
    if n == 0:
        return -1
    low = 0
    high = n - 1
    res = -1
    while (low <= high):
        mid = (low + high) // 2
        if arr[mid] > x:
            high = mid - 1
        elif arr[mid] < x:
            low = mid + 1
        else:
            res = mid
            high = mid - 1
    return res