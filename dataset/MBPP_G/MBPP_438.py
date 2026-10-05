def count_bidirectional(test_list):
    pair_set = set()
    count = 0
    for a, b in test_list:
        if (b, a) in pair_set:
            count += 1
        pair_set.add((a, b))
    return str(count)