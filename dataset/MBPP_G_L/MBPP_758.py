def unique_sublists(list1):
    sublist_count = {}
    for sublist in list1:
        tuple_sublist = tuple(sublist)
        sublist_count[tuple_sublist] = sublist_count.get(tuple_sublist, 0) + 1
    return sublist_count