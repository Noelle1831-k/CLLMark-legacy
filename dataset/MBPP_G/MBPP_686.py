def freq_element(test_tup):
    freq_dict = {}
    for item in test_tup:
        freq_dict[item] = freq_dict.get(item, 0) + 1
    return str(freq_dict)