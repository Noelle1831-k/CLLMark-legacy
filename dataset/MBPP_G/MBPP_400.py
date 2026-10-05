def extract_freq(test_list):
    unique_tuples = {tuple(sorted(tup)) for tup in test_list}
    return len(unique_tuples)