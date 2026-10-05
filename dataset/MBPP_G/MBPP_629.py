def Split(list):
    return [x for x in list if isinstance(x, int) and x % 2 == 0]