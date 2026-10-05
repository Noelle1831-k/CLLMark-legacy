def is_subset(arr1, m, arr2, n):
    set_arr1 = set(arr1)
    set_arr2 = set(arr2)
    return set_arr2.issubset(set_arr1)