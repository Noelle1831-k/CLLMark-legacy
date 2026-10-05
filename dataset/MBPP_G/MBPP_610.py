def remove_kth_element(list1, k):
    if 0 <= k < len(list1):
        del list1[k]
    return list1