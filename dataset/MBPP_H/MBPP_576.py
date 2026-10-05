def is_Sub_Array(A, B, n, m):
    i = 0
    j = 0
    while (i < n and j < m):
        if (A[i] == B[j]):
            j += 1
            i += 1
            if (j == m):
                return True
        else:
            i = i - j + 1
            j = 0
    return False