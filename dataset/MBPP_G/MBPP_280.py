def sequential_search(dlist, item):
    for index, value in enumerate(dlist):
        if value == item:
            return (True, index)
    return (False, -1)