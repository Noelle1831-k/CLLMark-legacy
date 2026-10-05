def intersection_nested_lists(l1, l2):
    return [list(set(sublist) & set(l1)) for sublist in l2]