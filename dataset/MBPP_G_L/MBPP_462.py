def combinations_list(list1):
    from itertools import combinations
    result = []
    for r in range(len(list1) + 1):
        for comb in combinations(list1, r):
            result.append(list(comb))
    return result