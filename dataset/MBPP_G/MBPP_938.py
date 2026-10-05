def find_closet(A, B, C, p, q, r):
    i = j = k = 0
    diff = float('inf')
    closest_triplet = (0, 0, 0)
    while i < p and j < q and (k < r):
        maximum = max(A[i], B[j], C[k])
        minimum = min(A[i], B[j], C[k])
        if maximum - minimum < diff:
            diff = maximum - minimum
            closest_triplet = (A[i], B[j], C[k])
        if diff == 0:
            break
        if minimum == A[i]:
            i += 1
        elif minimum == B[j]:
            j += 1
        else:
            k += 1
    return closest_triplet