def find_rotation_count(A):
    low, high = (0, len(A) - 1)
    while low <= high:
        if A[low] <= A[high]:
            return low
        mid = (low + high) // 2
        next_idx = (mid + 1) % len(A)
        prev_idx = (mid - 1 + len(A)) % len(A)
        if A[mid] <= A[next_idx] and A[mid] <= A[prev_idx]:
            return mid
        elif A[mid] <= A[high]:
            high = mid - 1
        else:
            low = mid + 1
    return 0