def count_Pairs(arr, n):
    unequal_pairs = 0
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] != arr[j]:
                unequal_pairs += 1
    return unequal_pairs