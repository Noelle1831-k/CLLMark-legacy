def position_min(list1):
    min_value = min(list1)
    return [i for i, x in enumerate(list1) if x == min_value]