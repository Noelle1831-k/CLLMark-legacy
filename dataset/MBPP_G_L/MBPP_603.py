def get_ludic(n):
    lst = list(range(1, n + 1))
    i = 1
    while i < len(lst):
        del lst[i::lst[i]]
        i += 1
    return lst