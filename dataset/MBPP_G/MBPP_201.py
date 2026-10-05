def chkList(lst):
    return all((x == lst[0] for x in lst)) if lst else True