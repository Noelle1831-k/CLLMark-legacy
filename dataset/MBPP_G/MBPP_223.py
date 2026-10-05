def is_majority(arr, n, x):
    first_occurrence = binary_search(arr, 0, n - 1, x, True)
    if first_occurrence == -1:
        return False
    last_occurrence = binary_search(arr, 0, n - 1, x, False)
    count = last_occurrence - first_occurrence + 1
    return count > n // 2

def binary_search(arr, low, high, x, search_first):
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == x:
            if search_first:
                if mid == low or arr[mid - 1] < x:
                    return mid
                high = mid - 1
            else:
                if mid == high or arr[mid + 1] > x:
                    return mid
                low = mid + 1
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1