def count_integer(list1):
    return sum((1 for item in list1 if isinstance(item, int)))