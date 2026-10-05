def check_min_heap(arr, i):
    n = len(arr)
    if i >= (n - 2) // 2:
        return True
    if arr[i] <= arr[2 * i + 1] and (2 * i + 2 == n or arr[i] <= arr[2 * i + 2]):
        return check_min_heap(arr, 2 * i + 1) and (2 * i + 2 == n or check_min_heap(arr, 2 * i + 2))
    return False