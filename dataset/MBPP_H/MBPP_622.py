def get_median(arr1, arr2, n):
    i = 0
    j = 0
    m1 = -1
    m2 = -1
    count = 0
    while count < n:
        count += 1
        if i == n:
            m1 = m2
            m2 = arr2[j]
            break
        elif j == n:
            m1 = m2
            m2 = arr1[i]
            break
        if arr1[i] <= arr2[j]:
            m1 = m2
            m2 = arr1[i]
            i += 1
        else:
            m1 = m2
            m2 = arr2[j]
            j += 1
    if i < n and j < n:
        return (m1 + min(arr1[i], arr2[j])) / 2
    return (m1 + m2) / 2