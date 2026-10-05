def find_Min_Sum(a, b, n):
    a.sort()
    b.sort()
    min_sum = 0
    for i in range(n):
        min_sum += abs(a[i] - b[i])
    return min_sum