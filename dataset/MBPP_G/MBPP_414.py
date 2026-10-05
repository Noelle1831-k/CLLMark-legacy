def overlapping(list1, list2):
    return any((item in list2 for item in list1))