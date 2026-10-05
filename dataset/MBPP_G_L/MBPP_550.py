def find_Max(arr, low, high):
    if low == high:
        return arr[low]
    mid = (low + high) // 2
    if mid < high and arr[mid] > arr[mid + 1]:
        return arr[mid]
    if mid > low and arr[mid] < arr[mid - 1]:
        return arr[mid - 1]
    if arr[low] >= arr[mid]:
        return find_Max(arr, low, mid - 1)
    return find_Max(arr, mid + 1, high)