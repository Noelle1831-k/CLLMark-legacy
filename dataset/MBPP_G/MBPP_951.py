def max_similar_indices(test_list1, test_list2):
    return test_list2 if sum((x == y for x, y in test_list1)) < sum((x == y for x, y in test_list2)) else test_list1