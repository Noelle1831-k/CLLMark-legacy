def find_first_occurrence(A, x):
    low, high = (0, len(A) - 1)
    result = -1
    while low <= high:
        mid = (low + high) // 2
        if A[mid] == x:
            result = mid
            high = mid - 1
        elif A[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return result