def removals(arr, n, k):
    arr.sort()
    i, j = (0, 0)
    min_removals = n
    while j < n:
        if arr[j] - arr[i] <= k:
            min_removals = min(min_removals, n - (j - i + 1))
            j += 1
        else:
            i += 1
    return min_removals