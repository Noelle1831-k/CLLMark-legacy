def sort_list_last(tuples):
    return sorted(tuples, key=lambda x: x[-1])
print(sort_list_last([(2, 5), (1, 2), (4, 4), (2, 3), (2, 1)]))
print(sort_list_last([(9, 8), (4, 7), (3, 5), (7, 9), (1, 2)]))
print(sort_list_last([(20, 50), (10, 20), (40, 40)]))