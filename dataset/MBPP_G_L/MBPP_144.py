def sum_Pairs(arr, n):
    total_sum = 0
    for i in range(n):
        for j in range(i + 1, n):
            total_sum += abs(arr[i] - arr[j])
    return total_sum