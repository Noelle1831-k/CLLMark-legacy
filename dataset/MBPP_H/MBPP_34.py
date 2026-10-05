def find_missing(ar, N):
    l = 0
    r = N - 1
    while (l <= r):
        mid = (l + r) // 2
        if (ar[mid] != mid + 1 and (mid == 0 or ar[mid - 1] == mid)):
            return (mid + 1)
        elif (ar[mid] != mid + 1):
            r = mid - 1
        else:
            l = mid + 1
    return (-1)