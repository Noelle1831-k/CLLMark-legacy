def find_last_occurrence(A, x):
    left, right = (0, len(A) - 1)
    result = -1
    while left <= right:
        mid = left + (right - left) // 2
        if A[mid] == x:
            result = mid
            left = mid + 1
        elif A[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return result