def sub_lists(my_list):
    from itertools import combinations
    result = []
    for i in range(len(my_list) + 1):
        result.extend(combinations(my_list, i))
    return [list(sublist) for sublist in result]