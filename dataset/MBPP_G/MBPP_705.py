def sort_sublists(list1):
    return sorted(list1, key=lambda x: (len(x), x))