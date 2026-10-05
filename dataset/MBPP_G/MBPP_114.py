def assign_freq(test_list):
    freq_dict = {}
    result = []
    for tup in test_list:
        freq_dict[tup] = freq_dict.get(tup, 0) + 1
    for tup in freq_dict:
        result.append(tup + (freq_dict[tup],))
    return str(result)