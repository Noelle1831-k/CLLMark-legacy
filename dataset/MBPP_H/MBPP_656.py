def find_Min_Sum(a, b, n):
    a.sort()
    b.sort()
    total_sum = 0
    for i in range(n):
        total_sum = total_sum + abs(a[i] - b[i])
    return total_sum