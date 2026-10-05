def sub_lists(my_list):
    from itertools import combinations
    subs = []
    for i in range(0, len(my_list) + 1):
        temp = [list(x) for x in combinations(my_list, i)]
        subs.extend(temp)
    return subs