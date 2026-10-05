def tuple_intersection(test_list1, test_list2):
    set1 = {tuple(sorted(t)) for t in test_list1}
    set2 = {tuple(sorted(t)) for t in test_list2}
    return set1.intersection(set2)