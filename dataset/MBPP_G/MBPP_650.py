def are_Equal(arr1, arr2, n, m):
    if n != m:
        return False
    return sorted(arr1) == sorted(arr2)