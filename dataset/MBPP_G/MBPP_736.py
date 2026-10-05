def left_insertion(a, x):
    low, high = (0, len(a))
    while low < high:
        mid = (low + high) // 2
        if a[mid] < x:
            low = mid + 1
        else:
            high = mid
    return low