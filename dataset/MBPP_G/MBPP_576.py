def is_Sub_Array(A, B, n, m):
    if m > n:
        return False
    for i in range(n - m + 1):
        if A[i:i + m] == B:
            return True
    return False