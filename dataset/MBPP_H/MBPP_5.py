A = [0] * (2 + 1)
B = [0] * (2 + 1)
def count_ways(n):
    A[0] = 1
    A[1] = 0
    B[0] = 0
    B[1] = 1
    for i in range(2, n + 1):
        if len(A) <= i:
            A.append(0)
        if len(B) <= i:
            B.append(0)
        A[i] = A[i - 2] + 2 * B[i - 1]
        B[i] = A[i - 1] + B[i - 2]
    return A[n]