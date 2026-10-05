def count_element_freq(test_tuple):
    freq_dict = {}
    for elem in test_tuple:
        if isinstance(elem, tuple):
            for sub_elem in elem:
                freq_dict[sub_elem] = freq_dict.get(sub_elem, 0) + 1
        else:
            freq_dict[elem] = freq_dict.get(elem, 0) + 1
    return freq_dict