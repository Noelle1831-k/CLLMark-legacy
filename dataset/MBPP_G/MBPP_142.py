def count_samepair(list1, list2, list3):
    return sum((1 for x, y, z in zip(list1, list2, list3) if x == y == z))