def get_Pairs_Count(arr, n, sum_value):
    count = 0
    for i in range(0, n):
        for j in range(i + 1, n):
            if arr[i] + arr[j] == sum_value:
                count += 1
    return count