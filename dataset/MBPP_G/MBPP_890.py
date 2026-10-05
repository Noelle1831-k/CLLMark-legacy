def find_Extra(arr1, arr2, n):
    for i in range(n):
        if i >= len(arr2) or arr1[i] != arr2[i]:
            return i
    return n