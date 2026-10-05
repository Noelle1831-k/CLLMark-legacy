def right_insertion(a, x):
    low, high = (0, len(a))
    while low < high:
        mid = (low + high) // 2
        if a[mid] <= x:
            low = mid + 1
        else:
            high = mid
    return low
print(right_insertion([1, 2, 4, 5], 6))
print(right_insertion([1, 2, 4, 5], 3))
print(right_insertion([1, 2, 4, 5], 7))