def max_occurrences(list1):
    if not list1:
        return None
    max_val = 0
    result = list1[0]
    for i in list1:
        occu = list1.count(i)
        if occu > max_val:
            max_val = occu
            result = i
    return result