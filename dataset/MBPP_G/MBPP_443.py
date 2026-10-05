def largest_neg(list1):
    return max((x for x in list1 if x < 0), default=None)