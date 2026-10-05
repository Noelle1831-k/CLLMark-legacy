def largest_pos(list1):
    return max([x for x in list1 if x > 0]) if any((x > 0 for x in list1)) else None