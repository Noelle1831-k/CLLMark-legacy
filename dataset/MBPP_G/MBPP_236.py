def No_of_Triangle(N, K):
    if K > N:
        return -1
    return (N - K + 1) * (N - K + 2) // 2 * K // N