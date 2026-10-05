def position_max(list1):
    max_value = max(list1)
    return [i for i, value in enumerate(list1) if value == max_value]