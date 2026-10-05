def no_of_subsequences(arr, k):
    n = len(arr)
    count = 0
    for i in range(1 << n):
        product = 1
        for j in range(n):
            if i & 1 << j:
                product *= arr[j]
                if product >= k:
                    break
        else:
            count += 1
    return count - 1